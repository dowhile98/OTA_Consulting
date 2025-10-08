/**
 * @file cli.h
 * @brief Front-end to the CLI to fetch user parameters
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

#ifndef __CLI_H
#define __CLI_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lib/cargs/include/cargs.h"
#include "utils.h"

// Error code to signify a 'correct' CLI config, even when 'required' options are not present.
// For example, -v or --version and -h or --help
#define CLI_OK 2

/**
 * This is a custom project configuration structure where you can store the
 * parsed information.
 */
struct builder_cli_configuration {
    const char *input;               // Required
    const char *output;              // Required
    const char *firmware_index;      // Optional
    const char *vtor_align;          // Optional, specifies VTOR offset padding. Default value 1024 bytes.
    const char *firmware_version;    // Optional, unless using anti-rollback
    const char *encryption_algo;     // Optional, unless encryption is required. AES-CBC by default as of v1
    const char *encryption_key_ascii;      // Optional
    const char *encryption_key_hex;      // Optional
    uint8_t *encryption_key;      // Optional
    size_t encryption_key_len;       // Optional
    const char *authentication_algo; // Optional, unless authentication is required. Supported algorithms: HMAC-[md5,sha256,sha512]
    const char *authentication_key_ascii;  // Optional
    const char *authentication_key_hex;  // Optional
    uint8_t *authentication_key;  // Optional
    size_t authentication_key_len;  // Optional
    const char *signature_algo;      // Optional
    const char* signature_key;       // Optional, unless signature is required. Supported algorithms: ecdsa-sha256, rsa-sha256,
    const char* integrity_algo;      // Optional. CRC32 is chosen by default. Supported algorithms: MD5, SHA26, SHA512
    bool verbose;                    // if passed, extra output will be passed to STDOUT
    bool version;                    // if passed, CLI version will be passed to STDOUT
    bool help;                      // if passed, a help message will be passed to STDOUT
};

static struct cag_option printable_options[] = {

        {.identifier = 'i',
                .access_letters = "iI",
                .access_name = "input",
                .value_name = "<firmware.bin>",
                .description = "[REQUIRED] Path to firmware binary"},

        {.identifier = 'o',
                .access_letters = "oO",
                .access_name = "output",
                .value_name = "<firmware_update.img>",
                .description = "[REQUIRED] Path to save firmware update image"},

        {.identifier = 'p',
                .access_letters = NULL,
                .access_name = "vtor-align",
                .value_name = NULL,
                .description = "[OPTIONAL] Set the vector table alignment when necessary"},

        {.identifier = 'f',
                .access_letters = NULL,
                .access_name = "firmware-version",
                .value_name = "X.X.X",
                .description = "[OPTIONAL] Firmware Version, mandatory for anti-rollback support"},

        {.identifier = 'e',
                .access_letters = NULL,
                .access_name = "enc-algo",
                .value_name = "<aes-cbc>",
                .description = "[OPTIONAL] Encryption Algorithm to be used if encryption is required"},

        {.identifier = 'k',
                .access_letters = NULL,
                .access_name = "enc-key-ascii",
                .value_name = "<encryption_key_in_ascii>",
                .description = "[OPTIONAL] Encryption Key if encryption is required"},

        {.identifier = 'd',
                .access_letters = NULL,
                .access_name = "enc-key-hex",
                .value_name = "<encryption_key_in_hex>",
                .description = "[OPTIONAL] Encryption Key if encryption is required"},

        {.identifier = 'a',
                .access_letters = NULL,
                .access_name = "auth-algo",
                .value_name = "<hmac-md5|hmac-sha256|hmac-sha512>",
                .description = "[OPTIONAL] Authentication Algorithm to be used if authentication is chosen"},

        {.identifier = 'u',
                .access_letters = NULL,
                .access_name = "auth-key-ascii",
                .value_name = "<auth_key_in_ascii>",
                .description = "[OPTIONAL] Authentication Key if authentication is chosen"},

        {.identifier = 'j',
                .access_letters = NULL,
                .access_name = "auth-key-hex",
                .value_name = "<my_auth_key_in_hex>",
                .description = "[OPTIONAL] Authentication Key if authentication is chosen"},

        {.identifier = 's',
                .access_letters = NULL,
                .access_name = "sign-algo",
                .value_name = "<ecdsa-sha256|rsa-sha256>",
                .description = "[OPTIONAL] Signature Algorithm to be used if signature is chosen"},

        {.identifier = 'g',
                .access_letters = NULL,
                .access_name = "sign-key",
                .value_name = "<sign_key.pem>",
                .description = "[OPTIONAL] Private Signature Key if signature is chosen"},

        {.identifier = 'n',
                .access_letters = NULL,
                .access_name = "integrity-algo",
                .value_name = "<crc32|md5|sha1|sha224|sha256|sha384|sha512>",
                .description = "[OPTIONAL] Integrity Algorithm to be used if integrity check is chosen"},

        {.identifier = 'b',
                .access_letters = NULL,
                .access_name = "verbose",
                .value_name = NULL,
                .description = "[OPTIONAL] Verbose mode"},

        {.identifier = 'v',
                .access_letters = "vV",
                .access_name = "version",
                .value_name = NULL,
                .description = "Show CLI version"},

        {.identifier = 'h',
                .access_letters = "h",
                .access_name = "help",
                .description = "Show the help message"}
};

// function to iterate over user parameters and copy to those to a struct
int parse_options(int argc, char **argv, struct builder_cli_configuration *cli_options);

#endif // __CLI_H
