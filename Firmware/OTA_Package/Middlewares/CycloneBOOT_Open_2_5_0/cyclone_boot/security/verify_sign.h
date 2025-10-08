/**
 * @file verify_sign.h
 * @brief CycloneBOOT Encryption & Decryption handling
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

#ifndef _VERIFY_SIGN_H
#define _VERIFY_SIGN_H

// Dependencies
#include "security/verify.h"

//CycloneBOOT signature verification related functions
cboot_error_t signInit(VerifyContext *context);
cboot_error_t signVerify(VerifyContext *context, uint8_t *verifyData, size_t verifyDataLength);

#endif // !_VERIFY_AUTH_H
