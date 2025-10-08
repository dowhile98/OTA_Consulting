/**
 * @file main.c
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

#include <stdio.h>
#include "cli.h"
#include "header.h"
#include "body.h"
#include "footer.h"
#include "utils.h"
#include "main.h"
#include "config/ImageBuilderConfig.h"

/**
 * Main entry point of the program.
 */
int main(int argc, char *argv[])
{
    // flags
    error_t status;

    status = NO_ERROR;
    uint8_t encrypted = 0;
    uint32_t required_padding_in_bytes = 0;

    // structures
    ImageHeader header = {0};
    ImageBody body = {0};
    UpdateImage updateImage = {0};

    CipherInfo cipherInfo = {0};
    CheckDataInfo checkDataInfo = {0};
    struct builder_cli_configuration cli_config = {0};

    YarrowContext yarrowContext = {0};

    // buffers
    char check_data[CHECK_DATA_LENGTH] = {0};
    long imgIdx = 0;
    char *imgIdx_char;

    char iv[INIT_VECTOR_LENGTH];
    size_t ivSize = INIT_VECTOR_LENGTH;

    // Generate an initialization vector for cipher operations (AES-CBC)
    seedInitVector((char *)iv,INIT_VECTOR_LENGTH);

    // Get command-line options supplied by the user
    status = parse_options(argc, argv, &cli_config);

    if (status == ERROR_FAILURE)
    {
        printf("Something went wrong while parsing command line options.\n");
        return ERROR_FAILURE;
    }

    if (status == CLI_OK)
        return NO_ERROR;

    // Should the image be encrypted?
    if (cli_config.encryption_key != NULL)
    {
        encrypted = 1;
    }

    // Calculate the index of the update image
    if (!cli_config.firmware_index)
        cli_config.firmware_index = "0"; // cannot be NULL
    imgIdx = strtol(cli_config.firmware_index, &imgIdx_char, 10);

    // Initialize Crypto stuff
    if (encrypted)
    {

        cipherInfo.yarrowContext = &yarrowContext;
        cipherInfo.prngAlgo = (PrngAlgo *)YARROW_PRNG_ALGO;

        cipherInfo.cipherKey = cli_config.encryption_key;
        cipherInfo.cipherKeySize = cli_config.encryption_key_len;

        cipherInfo.iv = iv;
        cipherInfo.ivSize = ivSize;

        status = init_crypto(&cipherInfo);
        if (status != NO_ERROR)
        {
            printf("Something went wrong in init_crypto.\r\n");
            return ERROR_FAILURE;
        }
    }
    else
    {
        cipherInfo.yarrowContext = &yarrowContext;
        cipherInfo.prngAlgo = (PrngAlgo *)YARROW_PRNG_ALGO;

        status = init_crypto(&cipherInfo);
        if (status != NO_ERROR)
        {
            printf("Something went wrong in init_crypto.\r\n");
            return ERROR_FAILURE;
        }
    }

    // Convert the user-supplied padding amount to an integer
    if(cli_config.vtor_align) {
        char * pad;
        required_padding_in_bytes = strtol(cli_config.vtor_align, &pad, 10);
    } else {
        required_padding_in_bytes = 0;
    }

    // Make header
    status = headerMake(&header,
                        cli_config.input,
                        (int)imgIdx,
                        cli_config.firmware_version,
                        required_padding_in_bytes,
                        encrypted);

    if (status != NO_ERROR)
    {
        printf("Something went wrong while making the header.\n");
        return ERROR_FAILURE;
    }
    // Make body
    status = bodyMake(&header, &body, cipherInfo);
    if (status != NO_ERROR)
    {
        printf("Something went wrong while making the body.\n");
        return ERROR_FAILURE;
    }
    // Make footer
    // Determine which check data mechanism to use based on user-supplied parameters
    // simple integrity?
    if (cli_config.integrity_algo != NULL)
    {
        checkDataInfo.integrity = 1;
        checkDataInfo.integrity_algo = cli_config.integrity_algo;
    }
    // authentication required?
    if (cli_config.authentication_algo != NULL)
    {
        checkDataInfo.authentication = 1;
        checkDataInfo.auth_algo = cli_config.authentication_algo;
        checkDataInfo.authKey = cli_config.authentication_key;
        checkDataInfo.authKeySize = strlen(cli_config.authentication_key);
    }
    // signature required ?
    if (cli_config.signature_algo != NULL)
    {
        checkDataInfo.signature = 1;
        checkDataInfo.sign_algo = cli_config.signature_algo;
        checkDataInfo.signKey = cli_config.signature_key;
        checkDataInfo.signKeySize = strlen(cli_config.signature_key);
        checkDataInfo.signHashAlgo = SHA256_HASH_ALGO;
    }

    // Make the footer (the check data section mainly), based on the image verification method chosen
    status = footerMake(&header, &body, &cipherInfo, &checkDataInfo, check_data);
    if (status != NO_ERROR)
    {
        printf("Something went wrong while making the footer.\n");
        return ERROR_FAILURE;
    }

    updateImage.header = &header;
    updateImage.body = &body;

    // Now write the whole image to a file in the disk.
    write_image_to_file(&updateImage, &cipherInfo, cli_config.output);

    // Free allocated resources
    free(cli_config.encryption_key);

    return EXIT_SUCCESS;
}
