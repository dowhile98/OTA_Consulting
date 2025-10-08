/**
 * @file fatfs_layer.c
 * @brief CycloneBOOT FATFS file system layer
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneBOOT Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.5.0
 **/

//Switch to the appropriate trace level
#define TRACE_LEVEL CBOOT_TRACE_LEVEL

//Dependencies
#include "core/fs.h"
#include "fatfs_layer.h"

/**
 * @brief FatFS driver
 **/

error_t FatFsDriverInit(void);
FsFileHandler* FatFsOpen(const char* path, uint8_t mode);
error_t FatFsDriverWrite(FsFileHandler *fp, uint8_t offset, uint8_t *data, size_t length);
error_t FatFsDriverRead(FsFileHandler *fp, uint8_t offset, uint8_t* data, size_t length);
error_t FatFsClose(FsFileHandler *fp);
error_t FatFsDriverErase(FsFileHandler *fp, uint8_t offset, size_t length);
error_t FatFsGetInfo(const FsInfo **fsInfo);
error_t FatFsGetStatus(FsStatus *fsStatus);
error_t FatFsDriverDeInit(void);


/**
 * @brief Memory Information
 **/

const FsInfo fileSystemDriverInfo =
{
   FS_DRIVER_VERSION,
   FAT_FS_NAME,
   FAT_FS_PATH,
   FAT_FS_SIZE,
   0
};


const FsDriver fat_fs_driver =
{
    FatFsDriverInit,
    FatFsDriverDeInit,
    FatFsGetInfo,
    FatFsGetStatus,
    FatFsOpen,
    FatFsClose,
    FatFsDriverWrite,
    FatFsDriverRead,
    FatFsDriverErase,
};

/**
 * @brief Fs initialization function
 **/

error_t FatFsDriverInit(void) {
    return ERROR_NOT_IMPLEMENTED;
};

/**
 * @brief Fs file open function
 **/

FsFileHandler* FatFsOpen(const char* path, uint8_t mode) {
    return (FsFileHandler*)NULL;
};


error_t FatFsGetInfo(const FsInfo **fsInfo)
{
    //Set File System information pointeur
    *fsInfo = (const FsInfo*) &fileSystemDriverInfo;

    //Successfull process
    return NO_ERROR;
}


/**
 * @brief Fs status function
 **/

error_t FatFsGetStatus(FsStatus *fsStatus) {
    return ERROR_NOT_IMPLEMENTED;
};

/**
 * @brief Write Data into Fs function
 **/

error_t FatFsDriverWrite(FsFileHandler *fp, uint8_t offset, uint8_t *data, size_t length) {
    return ERROR_NOT_IMPLEMENTED;
}

/**
 * @brief Read Data from Fs function
 **/

error_t FatFsDriverRead(FsFileHandler *fp, uint8_t offset, uint8_t* data, size_t length) {
    return ERROR_NOT_IMPLEMENTED;
}

/**
 * @brief Close file function
 **/

error_t FatFsClose(FsFileHandler *fp) {
    return ERROR_NOT_IMPLEMENTED;
}

/**
 * @brief Erase Data from Fs function
 **/

error_t FatFsDriverErase(FsFileHandler *fp, uint8_t offset, size_t length) {
    return ERROR_NOT_IMPLEMENTED;
}

/**
 * @brief Fs initialization function
 **/

error_t FatFsDriverDeInit(void) {
    return ERROR_NOT_IMPLEMENTED;
};
