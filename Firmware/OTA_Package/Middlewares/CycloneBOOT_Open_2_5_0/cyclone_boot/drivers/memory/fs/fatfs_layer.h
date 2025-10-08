/**
 * @file fatfs_layer.h
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

#ifndef _FS_LAYER_H
#define _FS_LAYER_H

//Dependencies
#include <stdio.h>
#include "core/fs.h"

//FatFS File System name
#define FAT_FS_NAME "Custom File SystemInternal Flash"
//FatFS File System volume path name
#define FAT_FS_PATH ""
//FatFS Fime System device size
#define FAT_FS_SIZE (size_t)0x200000000 //8GB

//FatFS driver
extern const FsDriver fat_fs_driver;

#endif //!_FS_LAYER_H
