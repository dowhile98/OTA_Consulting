#!/usr/bin/env python3
import os
import sys
import struct

RES_TYPE_DIR  = 1
RES_TYPE_FILE = 2

TRESENTRY_BASE_SIZE = 1 + 4 + 4 + 1
TRESHEADER_SIZE = 4 + TRESENTRY_BASE_SIZE

def align4(x):
    return ((x + 3) // 4) * 4

class ResourceCompiler:
    def __init__(self, max_size=1024*1024):
        self.max_size = max_size
        self.buf = bytearray(max_size)
        self.total_size = TRESHEADER_SIZE
        self._write_u32(0, self.total_size)
        self._write_entry(4, RES_TYPE_DIR, self.total_size, 0, b'')

    def _ensure_space(self, needed):
        if self.total_size + needed > self.max_size:
            raise MemoryError("Maximum size exceeded")

    def _write_u8(self, off, val):
        self.buf[off:off+1] = struct.pack('<B', val)

    def _write_u32(self, off, val):
        self.buf[off:off+4] = struct.pack('<I', val)

    def _write_bytes(self, off, bts):
        self.buf[off:off+len(bts)] = bts

    def _write_entry(self, off, type_, dataOffset, dataLength, name_bytes):
        name_len = len(name_bytes)
        self._write_u8(off + 0, type_)
        self._write_u32(off + 1, dataOffset)
        self._write_u32(off + 5, dataLength)
        self._write_u8(off + 9, name_len)
        if name_len:
            self._write_bytes(off + TRESENTRY_BASE_SIZE, name_bytes)

    def add_file_contents(self, filename):
        with open(filename, 'rb') as f:
            f.seek(0, os.SEEK_END)
            length = f.tell()
            f.seek(0)
            if self.total_size + length > self.max_size:
                raise MemoryError("Maximum size exceeded")
            data = f.read()
            self._write_bytes(self.total_size, data)
            offset = self.total_size
            self.total_size += length
            # DEBUG: print file info
            print(f"[FILE]  {filename}  ({length} bytes)")
            return offset, length

    def add_directory(self, parentOffset, parentSize, directory):
        pos = self.total_size
        i = pos
        dir_length = 0

        # DEBUG: print directory info
        print(f"[DIR]   {directory}")

        # '.' entry
        self._ensure_space(TRESENTRY_BASE_SIZE + 1)
        self._write_entry(i, RES_TYPE_DIR, 0, 0, b'.')
        i += TRESENTRY_BASE_SIZE + 1
        dir_length += TRESENTRY_BASE_SIZE + 1

        # '..' entry
        if parentOffset and parentSize:
            self._ensure_space(TRESENTRY_BASE_SIZE + 2)
            self._write_entry(i, RES_TYPE_DIR, 0, 0, b'..')
            i += TRESENTRY_BASE_SIZE + 2
            dir_length += TRESENTRY_BASE_SIZE + 2

        entries = sorted(os.listdir(directory))
        for name in entries:
            if name in ('.', '..'):
                continue
            fullpath = os.path.join(directory, name)
            entry_type = RES_TYPE_DIR if os.path.isdir(fullpath) else RES_TYPE_FILE
            name_bytes = name.encode('utf-8')
            self._ensure_space(TRESENTRY_BASE_SIZE + len(name_bytes))
            self._write_entry(i, entry_type, 0, 0, name_bytes)
            i += TRESENTRY_BASE_SIZE + len(name_bytes)
            dir_length += TRESENTRY_BASE_SIZE + len(name_bytes)

        self.total_size += dir_length

        read_ptr = pos
        remaining = dir_length
        while remaining > 0:
            type_ = struct.unpack_from('<B', self.buf, read_ptr)[0]
            nameLength = struct.unpack_from('<B', self.buf, read_ptr + 9)[0]
            name_bytes = bytes(self.buf[read_ptr + TRESENTRY_BASE_SIZE: read_ptr + TRESENTRY_BASE_SIZE + nameLength])
            name = name_bytes.decode('utf-8') if nameLength else ''

            if name == '.':
                self._write_u32(read_ptr + 1, pos)
                self._write_u32(read_ptr + 5, dir_length)
            elif name == '..':
                self._write_u32(read_ptr + 1, parentOffset)
                self._write_u32(read_ptr + 5, parentSize)
            else:
                aligned = align4(self.total_size)
                if aligned != self.total_size:
                    pad_len = aligned - self.total_size
                    self._ensure_space(pad_len)
                    self.total_size = aligned

                self._write_u32(read_ptr + 1, self.total_size)
                fullpath = os.path.join(directory, name)
                if type_ == RES_TYPE_DIR:
                    sub_offset, sub_len = self.add_directory(pos, dir_length, fullpath)
                    self._write_u32(read_ptr + 5, sub_len)
                else:
                    off, length = self.add_file_contents(fullpath)
                    self._write_u32(read_ptr + 5, length)

            step = TRESENTRY_BASE_SIZE + nameLength
            remaining -= step
            read_ptr += step

        return pos, dir_length

    def finalize_and_write(self, dest_file):
        self._write_u32(0, self.total_size)
        ext = os.path.splitext(dest_file)[1].lower()
        if ext in ('.c', '.h'):
            base = os.path.splitext(os.path.basename(dest_file))[0]
            with open(dest_file, 'w', newline='\n') as f:
                f.write(f"const unsigned char {base}[] =\n{{\n")
                for i in range(self.total_size):
                    if (i % 16) == 0:
                        f.write("   ")
                    f.write(f"0x{self.buf[i]:02X}")
                    if i == (self.total_size - 1):
                        f.write("\n")
                    elif (i % 16) == 15:
                        f.write(",\n")
                    else:
                        f.write(", ")
                f.write("};\n")
        else:
            with open(dest_file, 'wb') as f:
                f.write(self.buf[:self.total_size])

def usage():
    print("Usage: rc.py input_dir output_file [maxsize]")

def main():
    if len(sys.argv) not in (3,4):
        usage()
        return 1
    src = sys.argv[1]
    dest = sys.argv[2]
    maxsize = int(sys.argv[3]) if len(sys.argv) == 4 else 1024*1024

    if not os.path.isdir(src):
        print("Error: input is not a directory")
        return 1

    rc = ResourceCompiler(max_size=maxsize)
    try:
        path = os.path.abspath(src)
        pos, length = rc.add_directory(0, 0, path)
        rc._write_u32(4 + 5, length)
        rc.finalize_and_write(dest)
    except MemoryError as e:
        print("Error:", e)
        return 1
    except Exception as e:
        print("Unhandled error:", e)
        return 1

    print("---------------------------------------------------------\r\n")
    print("Resource compilation completed successfully")
    print(f"{rc.total_size} bytes successfully written to {dest} !")
    print(f"Resource directory: {src}")
    print(f"Output file: {dest}")
    print("---------------------------------------------------------\r\n")
    return 0

if __name__ == '__main__':
    sys.exit(main())
