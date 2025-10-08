/**
 * @file body.h
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

#ifndef __BODY_H
#define __BODY_H

#include <stdint.h>
#include "header.h"
#include "main.h"

typedef struct
{
    uint8_t* binary;        // pointer to the buffer containing the firmware binary (and any associated padding)
    size_t binarySize;      // size of the firmware binary
    uint8_t* checkData;     // pointer to the buffer containing image verification data
    size_t checkDataSize;   // image verification data buffer length
} ImageBody;

// Function to generate the update image body containing the firmware binary
int bodyMake(ImageHeader *header, ImageBody *body, CipherInfo cipherInfo);

#endif // __BODY_H
