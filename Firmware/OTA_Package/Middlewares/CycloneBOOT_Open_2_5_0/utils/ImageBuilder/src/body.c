/**
 * @file body.c
 * @brief Generate the body section of an update image
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

#include <stdio.h>
#include "main.h"
#include "utils.h"
#include "header.h"
#include "body.h"

char *cipher_input = NULL;
size_t cipher_input_size = 0;

/**
 * @brief Make the image body
 * @param[in] header Pointer to the image header
 * @param[in] body Pointer to the image body
 * @param[in] CipherInfo Crypto related settings for cipher operations
 * @return Status code
 **/
int bodyMake(ImageHeader *header, ImageBody *body, CipherInfo cipherInfo) {
    error_t status = NO_ERROR;
    uint32_t cipherMagicNumberCRC;

    // Encrypt the image if necessary
    if(cipherInfo.cipherKey != NULL)
    {
        //Reallocate blockified padding + input binary buffer to add space for cipher magic number crc (used for aes key validation)
        blockified_padding_and_input_binary = (uint8_t*) realloc(blockified_padding_and_input_binary, blockified_padding_and_input_binary_size+16);
        //Moved blockified padding + input binary buffer content 16 bytes further to make room for cipher magic number crc (+ padding to achieve 16bytes)
        memcpy(blockified_padding_and_input_binary+16, blockified_padding_and_input_binary, blockified_padding_and_input_binary_size);
        //Set to zero first 16 bytes
        memset(blockified_padding_and_input_binary, 0x00, 16);
        //Update blockified padding + input binary size
        blockified_padding_and_input_binary_size += 16;

        //Allocate memory for encryption output buffer
        cipher_input = malloc(blockified_padding_and_input_binary_size); // TODO: free(cipher_input_binary) after writing to disk.

        //Compute magic number crc
        status = CRC32_HASH_ALGO->compute(CIPHER_MAGIC_NUMBER, CIPHER_MAGIC_NUMBER_SIZE, (uint8_t*)&cipherMagicNumberCRC);
        if(status)
        {
            printf("bodyMake: failed to compute cipher magic number crc.\n");
            return EXIT_FAILURE;
        }

        //Copy cipher magic number crc to the beginning of blockified padding + input binary buffer
        memcpy(blockified_padding_and_input_binary, (uint8_t*)&cipherMagicNumberCRC, CRC32_DIGEST_SIZE);

        status = encrypt(blockified_padding_and_input_binary,
                         blockified_padding_and_input_binary_size,
                         cipher_input,
                         cipherInfo);

        cipherInfo.cipherKey = NULL;
        cipherInfo.cipherKeySize = 0;

        if(status) {
            printf("bodyMake: failed to encrypt input binary.\n");
            return EXIT_FAILURE;
        }

        cipher_input_size = blockified_padding_and_input_binary_size;
        header->dataSize = blockified_padding_and_input_binary_size-CIPHER_MAGIC_NUMBER_SIZE; //first 16bytes cipher magic number crc + padding are not part of data size

        body->binary = cipher_input;
        body->binarySize = cipher_input_size;
    } else {
        body->binary = (uint8_t *)padding_and_input_binary;
        body->binarySize = padding_and_input_binary_size;
    }

    return EXIT_SUCCESS;
}
