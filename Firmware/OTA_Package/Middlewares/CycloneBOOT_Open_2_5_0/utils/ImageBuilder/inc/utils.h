/**
 * @file utils.h
 * @brief Utility functions used throughout the application
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
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

#ifndef __UTILS_H
#define  __UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/crypto.h"
#include "cipher_modes/cbc.h"
#include "cipher/aria.h"
#include "cipher/cipher_algorithms.h"
#include "rng/yarrow.h"
#include "main.h"
#include "header.h"
#include "body.h"

#define ARRAY_BYTES(arr)        (sizeof((arr)[0]) * ARRAY_SIZE(arr))
#define ARRAY_SBYTES(arr)       ((ssize_t)ARRAY_BYTES(arr))

#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))
#define ARRAY_SSIZE(arr)    ((ptrdiff_t)ARRAY_SIZE(arr))

// Magic number used to check cipher key
#define CIPHER_MAGIC_NUMBER "5ef41578fcfbb9a98ffc218dde463d44"
#define CIPHER_MAGIC_NUMBER_SIZE 16

typedef struct {
    ImageHeader *header;
    ImageBody *body;
} UpdateImage;

int read_file(const char *file_path, char **file_contents, size_t *file_size);
int blockify(size_t blockSize, char* input, size_t inputSize, char** output, size_t* outputSize);
int init_crypto(CipherInfo *cipherInfo);
int encrypt(char *plainData, size_t plainDataSize, char* cipherData, CipherInfo cipherInfo);
int sign(CipherInfo *cipherInfo, CheckDataInfo *checkDataInfo, char *data, size_t dataLen, char **signData, size_t *signDataLen);
int write_image_to_file(UpdateImage *image, CipherInfo *cipherInfo, const char *output_file_path);

void dump_buffer(void *buffer, size_t buffer_size);
void dump_buffer_2(void *buffer, size_t buffer_size, size_t columSize);
void dumpHeader(ImageHeader* header);
void dumpBody(ImageBody* body);
void dumpFooter(char *check_data, size_t check_data_size);
void seedInitVector(uint8_t *buffer, size_t length);

int is_hex(const char *str);
int hex_string_to_byte_array(const char* hexString, unsigned char** byteArray, size_t* byteArraySize);

#endif
