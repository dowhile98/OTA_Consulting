/**
 * @file main.h
 * @brief CycloneBOOT compatible Update Image Builder
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

#ifndef __MAIN_H
#define __MAIN_H

#include "core/crypto.h"
#include "rng/yarrow.h"

#define SEED_LENGTH 32         // length of Crypto seed
#define CHECK_DATA_LENGTH 256  // length of check data field
#define INIT_VECTOR_LENGTH 16  // length of initialization vector for AES-CBC

/**
 * Stores the information about encryption operations.
 * Encryption Key, Initialization Vector (IV), Size of IV and Size of Encryption Key.
*/
typedef struct {
    const char* iv;
    size_t ivSize;
    uint8_t * cipherKey;
    size_t cipherKeySize;
    PrngAlgo *prngAlgo;
    YarrowContext *yarrowContext;
    char seed[SEED_LENGTH];
} CipherInfo;

/**
 * Stores the information about application check data field.
*/
typedef struct {
    int signature;
    int authentication;
    int integrity;
    const char* auth_algo;
    const char* integrity_algo;
    const char* authKey;
    size_t authKeySize;
    const char* sign_algo;
    const char *signKey;
    size_t signKeySize;
    const HashAlgo *signHashAlgo;
} CheckDataInfo;

// Global variables
extern char *input_binary;
extern size_t input_binary_size;
extern char *blockified_padding_and_input_binary;
extern size_t blockified_padding_and_input_binary_size;
extern char *cipher_input;
extern size_t cipher_input_size;
extern char *padding_and_input_binary;
extern uint32_t padding_and_input_binary_size;

#endif // __MAIN_H
