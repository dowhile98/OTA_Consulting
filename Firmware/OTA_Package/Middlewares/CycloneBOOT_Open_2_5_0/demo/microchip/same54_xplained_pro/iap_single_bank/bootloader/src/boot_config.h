/**
 * @file boot_config.h
 * @brief CycloneBOOT configuration file
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

#ifndef _BOOT_CONFIG_H
#define _BOOT_CONFIG_H

//Bootloader trace level
#define BOOT_TRACE_LEVEL 4

//Number of memory to be used
#define NB_MEMORIES 1

//Numbe of slots within the memory
#define NB_MAX_MEMORY_SLOTS 3

//External memory support
#define EXTERNAL_MEMORY_SUPPORT DISABLED

//Bootloader Anti-Rollback support
#define BOOT_ANTI_ROLLBACK_SUPPORT DISABLED

#endif //!_BOOT_CONFIG_H
