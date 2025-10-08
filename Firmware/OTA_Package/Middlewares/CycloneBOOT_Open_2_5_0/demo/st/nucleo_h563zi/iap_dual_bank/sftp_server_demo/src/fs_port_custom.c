/**
 * @file fs_port_custom.c
 * @brief File system abstraction layer
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


#define TRACE_LEVEL TRACE_LEVEL_DEBUG

//Dependencies
#include <string.h>
#include "fs_port.h"
#include "fs_port_custom.h"
#include "path.h"
#include "version.h"
#include "update/update.h"
#include "security/verify.h"
#include "drivers/memory/flash/internal/stm32h5xx_flash_driver.h"
#include "debug.h"


//File system objects
static FileDesc fileTable[FS_MAX_FILES];
static DirDesc dirTable[FS_MAX_DIRS];

//Mutex that protects critical sections
static OsMutex fsMutex;

//Global variables
extern bool_t rebootRequested;
extern systime_t rebootTimestamp;

//Extern update signature public key declaration
extern const uint8_t* pemUpdtSignPublicKey;
extern size_t pemUpdtSignPublicKeyLen;

UpdateSettings updateSettings;
UpdateContext updateContext;

/**
 * @brief File system initialization
 * @return Error code
 **/

error_t fsInit(void)
{
   cboot_error_t cerror;

   //Clear file system objects
   memset(fileTable, 0, sizeof(fileTable));
   memset(dirTable, 0, sizeof(dirTable));

   //Create a mutex to protect critical sections
   if(!osCreateMutex(&fsMutex))
   {
      //Failed to create mutex
      return ERROR_OUT_OF_RESOURCES;
   }

   //User update settings security configuration
   updateSettings.imageInCrypto.verifySettings.verifyMethod    = VERIFY_METHOD_SIGNATURE;
   updateSettings.imageInCrypto.verifySettings.signAlgo        = VERIFY_SIGN_RSA;
   updateSettings.imageInCrypto.verifySettings.signHashAlgo    = SHA256_HASH_ALGO;
   updateSettings.imageInCrypto.verifySettings.signKey         = (const char_t*) pemUpdtSignPublicKey;
   updateSettings.imageInCrypto.verifySettings.signKeyLen      = pemUpdtSignPublicKeyLen;
   updateSettings.imageInCrypto.cipherAlgo                     = AES_CIPHER_ALGO;
   updateSettings.imageInCrypto.cipherMode                     = CIPHER_MODE_CBC;
   updateSettings.imageInCrypto.cipherKey                      = (const uint8_t *)"aa3ff7d43cc015682c7dfd00de9379e7";
   updateSettings.imageInCrypto.cipherKeyLen                   = 32;

   //User update settings primary memory configuration
   updateSettings.memories[0].memoryRole           = MEMORY_ROLE_PRIMARY;
   updateSettings.memories[0].memoryType           = MEMORY_TYPE_FLASH;
   updateSettings.memories[0].driver               = &stm32h5xxFlashDriver;
   updateSettings.memories[0].nbSlots              = 2;
   //User update settings primary memory slot 0 configuration
   updateSettings.memories[0].slots[0].type        = SLOT_TYPE_DIRECT;
   updateSettings.memories[0].slots[0].cType       = SLOT_CONTENT_APP | SLOT_CONTENT_BACKUP;
   updateSettings.memories[0].slots[0].memParent   = &updateSettings.memories[0];
   updateSettings.memories[0].slots[0].addr        = 0x08000000;
   updateSettings.memories[0].slots[0].size        = 0x100000;
   //User update settings primary memory slot 1 configuration
   updateSettings.memories[0].slots[1].type        = SLOT_TYPE_DIRECT;
   updateSettings.memories[0].slots[1].cType       = SLOT_CONTENT_APP | SLOT_CONTENT_BACKUP;
   updateSettings.memories[0].slots[1].memParent   = &updateSettings.memories[0];
   updateSettings.memories[0].slots[1].addr        = 0x08100000;
   updateSettings.memories[0].slots[1].size        = 0x100000;

   //Initialize IAP update context
   cerror = updateInit(&updateContext, &updateSettings);
   //Is any error?
   if (cerror) {
	   //Debug message
	   TRACE_ERROR("Failed to initialize IAP!\r\n");
	   return ERROR_FAILURE;
   }

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Check whether a file exists
 * @param[in] path NULL-terminated string specifying the filename
 * @return The function returns TRUE if the file exists. Otherwise FALSE is returned
 **/

bool_t fsFileExists(const char_t *path)
{
   //Check file name
   if(!strcasecmp(path, "/test_1k.txt") ||
      !strcasecmp(path, "/test_1m.txt") ||
      !strcasecmp(path, "/test_10m.txt") ||
	  !strcasecmp(path, "/version.txt") ||
	  !strcasecmp(path, "/reboot.txt"))

   {
      return TRUE;
   }
   else
   {
      return FALSE;
   }
}


/**
 * @brief Retrieve the size of the specified file
 * @param[in] path NULL-terminated string specifying the filename
 * @param[out] size Size of the file in bytes
 * @return Error code
 **/

error_t fsGetFileSize(const char_t *path, uint32_t *size)
{
   error_t error;

   //Initialize status code
   error = NO_ERROR;

   //Check file name
   if(!strcasecmp(path, "/test_1k.txt"))
   {
      *size = 1000;
   }
   else if(!strcasecmp(path, "/test_1m.txt"))
   {
      *size = 10000000;
   }
   else if(!strcasecmp(path, "/test_10m.txt"))
   {
      *size = 10000000;
   }
   else if(!strcasecmp(path, "/test_100m.txt"))
   {
      *size = 100000000;
   }
   else if(!strcasecmp(path, "/version.txt"))
   {
         *size = strlen(APP_VERSION_STRING);
   }
   else if(!strcasecmp(path, "/reboot.txt"))
   {
         *size = 0;
   }
   else if(!strcasecmp(path, UPDATE_IMAGE_PATH))
   {
         *size = 0; //TODO: get the current application size?
   }
   else
   {
      //File not found
      error = ERROR_NOT_FOUND;
   }

   //Return status code
   return error;
}


/**
 * @brief Retrieve the attributes of the specified file
 * @param[in] path NULL-terminated string specifying the filename
 * @param[out] fileStat File attributes
 * @return Error code
 **/

error_t fsGetFileStat(const char_t *path, FsFileStat *fileStat)
{
   //Check parameters
   if(path == NULL || fileStat == NULL)
      return ERROR_INVALID_PARAMETER;

   //Clear file attributes
   osMemset(fileStat, 0, sizeof(FsFileStat));

   //Check file name
   if(!strcasecmp(path, "/test_1k.txt"))
   {
      fileStat->size = 1000;
   }
   else if(!strcasecmp(path, "/test_1m.txt"))
   {
      fileStat->size = 1000000;
   }
   else if(!strcasecmp(path, "/test_10m.txt"))
   {
      fileStat->size = 10000000;
   }
   else if(!strcasecmp(path, "/test_100m.txt"))
   {
      fileStat->size = 100000000;
   }
   else if(!strcasecmp(path, "/version.txt"))
   {
	   fileStat->size = strlen(APP_VERSION_STRING);
   }
   else if(!strcasecmp(path, UPDATE_IMAGE_PATH))
   {
	   fileStat->size = 0;
   }
   else if(!strcasecmp(path, "/reboot.txt"))
   {
	   fileStat->size = 0;
   }
   else
   {
      //File not found
      return ERROR_NOT_FOUND;
   }

   //File attributes
   fileStat->attributes = 0;

   //Time of last modification
   fileStat->modified.year = 2000;
   fileStat->modified.month = 1;
   fileStat->modified.day = 1;
   fileStat->modified.dayOfWeek = 0;
   fileStat->modified.hours = 12;
   fileStat->modified.minutes = 0;
   fileStat->modified.seconds = 0;
   fileStat->modified.milliseconds = 0;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Rename the specified file
 * @param[in] oldPath NULL-terminated string specifying the pathname of the file to be renamed
 * @param[in] newPath NULL-terminated string specifying the new filename
 * @return Error code
 **/

error_t fsRenameFile(const char_t *oldPath, const char_t *newPath)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Delete a file
 * @param[in] path NULL-terminated string specifying the filename
 * @return Error code
 **/

error_t fsDeleteFile(const char_t *path)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Open the specified file for reading or writing
 * @param[in] path NULL-terminated string specifying the filename
 * @param[in] mode Type of access permitted (FS_FILE_MODE_READ,
 *   FS_FILE_MODE_WRITE or FS_FILE_MODE_CREATE)
 * @return File handle
 **/

FsFile *fsOpenFile(const char_t *path, uint_t mode)
{
   uint_t i;

   //File pointer
   FsFile *file = NULL;

   //Make sure the pathname is valid
   if(path == NULL)
      return NULL;

   //Enter critical section
   osAcquireMutex(&fsMutex);

   //Loop through the file objects
   for(i = 0; i < FS_MAX_FILES; i++)
   {
      //Unused file object?
      if(fileTable[i].mode == 0)
      {
         if(mode & FS_FILE_MODE_READ)
         {
            //Check file name
            if(!strcasecmp(path, "/test_1k.txt"))
            {
               //Initialize file object
               fileTable[i].mode = FS_FILE_MODE_READ;
               fileTable[i].length = 1000;
               fileTable[i].pos = 0;

               //Save file handle
               file = &fileTable[i];
            }
            else if(!strcasecmp(path, "/test_1m.txt"))
            {
               //Initialize file object
               fileTable[i].mode = FS_FILE_MODE_READ;
               fileTable[i].length = 1000000;
               fileTable[i].pos = 0;

               //Save file handle
               file = &fileTable[i];

            }
            else if(!strcasecmp(path, "/test_10m.txt"))
            {
               //Initialize file object
               fileTable[i].mode = FS_FILE_MODE_READ;
               fileTable[i].length = 10000000;
               fileTable[i].pos = 0;

               //Save file handle
               file = &fileTable[i];
            }
            else if(!strcasecmp(path, "/test_100m.txt"))
            {
               //Initialize file object
               fileTable[i].mode = FS_FILE_MODE_READ;
               fileTable[i].length = 100000000;
               fileTable[i].pos = 0;

               //Save file handle
               file = &fileTable[i];
            }
            else if(!strcasecmp(path, "/version.txt"))
            {
            	//Initialize file object
            	fileTable[i].mode = FS_FILE_MODE_READ;
            	fileTable[i].length = 0;
            	fileTable[i].pos = 0;
            	fileTable[i].type = FILE_TYPE_VERSION;
            	fileTable[i].length = strlen(APP_VERSION_STRING);

            	//Save file handle
				file = &fileTable[i];
            }
            else if(!strcasecmp(path, "/reboot.txt"))
            {
            	//Initialize file object
            	fileTable[i].mode = FS_FILE_MODE_READ;
            	fileTable[i].length = 0;
            	fileTable[i].pos = 0;
            	fileTable[i].type = FILE_TYPE_REBOOT;
            	fileTable[i].length = 0;

            	//Save file handle
				file = &fileTable[i];
            }
            else
            {
               //The file does not exist
            }
         }
         else if(mode & FS_FILE_MODE_WRITE)
         {
        	 if (!strcasecmp(path, UPDATE_IMAGE_PATH)) {
        		 //Initialize file object
        		 fileTable[i].mode = FS_FILE_MODE_WRITE;
        		 fileTable[i].length = 0;
        		 fileTable[i].pos = 0;
        		 fileTable[i].type = FILE_TYPE_FIRMWARE;
        		 fileTable[i].length = 0; //TODO: get the current application size?

        		 //Save file handle
        		 file = &fileTable[i];

        	 } else {
        		 //Initialize file object
        		 fileTable[i].mode = FS_FILE_MODE_WRITE;
        		 fileTable[i].length = 0;
        		 fileTable[i].pos = 0;

        		 //Save file handle
        		 file = &fileTable[i];
        	 }
         }

         //Stop immediately
         break;
      }
   }

   //Leave critical section
   osReleaseMutex(&fsMutex);

   //Return a handle to the file
   return file;
}


/**
 * @brief Move to specified position in file
 * @param[in] file Handle that identifies the file
 * @param[in] offset Number of bytes to move from origin
 * @param[in] origin Position used as reference for the offset (FS_SEEK_SET,
 *   FS_SEEK_CUR or FS_SEEK_END)
 * @return Error code
 **/

error_t fsSeekFile(FsFile *file, int_t offset, uint_t origin)
{
   error_t error;
   FileDesc *fileDesc;

   //Make sure the file pointer is valid
   if(file == NULL)
      return ERROR_INVALID_PARAMETER;

   fileDesc = (FileDesc *) file;

   //Enter critical section
   osAcquireMutex(&fsMutex);

   //Offset is relative to the current file pointer position?
   if(origin == FS_SEEK_CUR)
      offset += fileDesc->pos;
   //Offset is relative to the end of the file?
   else if(origin == FS_SEEK_END)
      offset += fileDesc->length;

   //Move read/write pointer
   if(offset < fileDesc->length)
   {
      fileDesc->pos = offset;
      error = NO_ERROR;
   }
   else
   {
      error = ERROR_FAILURE;
   }

   //Leave critical section
   osReleaseMutex(&fsMutex);

   //Return status code
   return error;
}


/**
 * @brief Write data to the specified file
 * @param[in] file Handle that identifies the file to be written
 * @param[in] data Pointer to a buffer containing the data to be written
 * @param[in] length Number of data bytes to write
 * @return Error code
 **/

error_t fsWriteFile(FsFile *file, void *data, size_t length)
{
   cboot_error_t cerror;
   error_t error;
   uint8_t *p;
   FileDesc *fileDesc;

   //Initialize error code
   error = NO_ERROR;

   //Point to the file descriptor
   fileDesc = (FileDesc *) file;

   //Point to the buffer containing the data to be written
   p = (uint8_t *) data;

   //Enter critical section
   osAcquireMutex(&fsMutex);

   //Make sure the file is writable
   if((fileDesc->mode & FS_FILE_MODE_WRITE) && (fileDesc->type = FILE_TYPE_FIRMWARE)) {
	   //Write received bytes in flash
	   cerror = updateProcess(&updateContext, (uint8_t*) p, length);
	   //Is any error?
	   if (cerror != CBOOT_NO_ERROR) {
		   //Debug message
		   TRACE_ERROR("Failed to update firmware!\r\n");
		   error = ERROR_WRITE_FAILED;
	   } else {
		   error = NO_ERROR;
	   }
   }
   else
   {
      //Report an error
      error = ERROR_WRITE_FAILED;
   }

   //Leave critical section
   osReleaseMutex(&fsMutex);

   //Return status code
   return error;
}


/**
 * @brief Read data from the specified file
 * @param[in] file Handle that identifies the file to be read
 * @param[in] data Pointer to the buffer where to copy the data
 * @param[in] size Size of the buffer, in bytes
 * @param[in] length Number of data bytes to read
 * @return Error code
 **/

error_t fsReadFile(FsFile *file, void *data, size_t size, size_t *length)
{
   error_t error;
   size_t n;
   FileDesc *fileDesc;

   //No data has been read yet
   *length = 0;

   //File pointer
   fileDesc = (FileDesc *) file;

   //Enter critical section
   osAcquireMutex(&fsMutex);

   //Make sure the file is readable
   if(fileDesc->mode & FS_FILE_MODE_READ)
   {
	   if(fileDesc->pos < fileDesc->length)
	   {
		   //Limit the number of bytes to read at a time
		   n = MIN(size, fileDesc->length - fileDesc->pos);

		   if(fileDesc->type == FILE_TYPE_VERSION) {
			   //TODO: this is the best case where all 5 bytes are read
			   // at once. Sometimes, a socket might need several attempts
			   // to read this.
			   //Write dummy data
			   memcpy(data, APP_VERSION_STRING, n);
			   //Advance data pointer
			   fileDesc->pos += n;

		   } else {

			   //Write dummy data
			   memset(data, 'A', n);
			   //Advance data pointer
			   fileDesc->pos += n;
		   }

		   //Total number of data that have been read
		   *length = n;

		   //Successful read operation
		   error = NO_ERROR;
	   }
      else
      {
         //End of file
         error = ERROR_END_OF_STREAM;
      }
   }
   else
   {
      //Report an error
      error = ERROR_READ_FAILED;
   }

   //Leave critical section
   osReleaseMutex(&fsMutex);

   //Return status code
   return error;
}


/**
 * @brief Close a file
 * @param[in] file Handle that identifies the file to be closed
 **/

void fsCloseFile(FsFile *file)
{
   cboot_error_t cerror;
   FileDesc *fileDesc;

   //File pointer
   fileDesc = (FileDesc *) file;

   //Enter critical section
   osAcquireMutex(&fsMutex);

   //Close file
   fileDesc->mode = 0;
   fileDesc->length = 0;
   fileDesc->pos = 0;

   //Signal that MCU reboot is due
   if(fileDesc->type == FILE_TYPE_REBOOT) {
	   osDelayTask(2000);
	   TRACE_INFO("Resetting MCU...\r\n");
	   //Perform flash swap bank then reboot
	   cerror = updateReboot(&updateContext);
	   //Is any error?
	   if (cerror != CBOOT_NO_ERROR) {
		   //Debug message
		   TRACE_ERROR("Failed to reboot!\r\n");
	   }
   }
   if(fileDesc->type == FILE_TYPE_FIRMWARE) {
		//Check application firmware validity
		cerror = updateFinalize(&updateContext);
		//Is application is invalid?
		if (cerror != CBOOT_NO_ERROR) {
			//Debug message
			TRACE_ERROR("Failed to finalize firmware update!\r\n");
		} else {
			TRACE_INFO("Firmware update complete.\r\n");
		}
   }

   //Leave critical section
   osReleaseMutex(&fsMutex);
}


/**
 * @brief Check whether a directory exists
 * @param[in] path NULL-terminated string specifying the directory path
 * @return The function returns TRUE if the directory exists. Otherwise FALSE is returned
 **/

bool_t fsDirExists(const char_t *path)
{
   //Check directory name
   if(!strcmp(path, "/"))
      return TRUE;
   else
      return FALSE;
}


/**
 * @brief Create a directory
 * @param[in] path NULL-terminated string specifying the directory path
 * @return Error code
 **/

error_t fsCreateDir(const char_t *path)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Remove a directory
 * @param[in] path NULL-terminated string specifying the directory path
 * @return Error code
 **/

error_t fsRemoveDir(const char_t *path)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Open a directory stream
 * @param[in] path NULL-terminated string specifying the directory path
 * @return Directory handle
 **/

FsDir *fsOpenDir(const char_t *path)
{
   uint_t i;

   //Directory pointer
   FsDir *dir = NULL;

   //Make sure the pathname is valid
   if(path == NULL)
      return NULL;

   //Enter critical section
   osAcquireMutex(&fsMutex);

   //Loop through the directory objects
   for(i = 0; i < FS_MAX_DIRS; i++)
   {
      //Unused directory object?
      if(dirTable[i].index == 0)
      {
         //Point to the first entry
         dirTable[i].index = 1;
         //Save directory handle
         dir = &dirTable[i];

         //Stop immediately
         break;
      }
   }

   //Leave critical section
   osReleaseMutex(&fsMutex);

   //Return a handle to the directory
   return dir;
}


/**
 * @brief Read an entry from the specified directory stream
 * @param[in] dir Handle that identifies the directory
 * @param[out] dirEntry Pointer to a directory entry
 * @return Error code
 **/

error_t fsReadDir(FsDir *dir, FsDirEntry *dirEntry)
{
   error_t error;
   DirDesc *dirDesc;

   //Directory pointer
   dirDesc = (DirDesc *) dir;

   //Read current entry
   if(dirDesc->index == 1)
   {
      //File name
      strcpy(dirEntry->name, "test_1k.txt");

      //Get the length of the application image
      dirEntry->size = 1000;

      //File attributes
      dirEntry->attributes = 0;

      //Last modified date
      dirEntry->modified.year = 2000;
      dirEntry->modified.month = 1;
      dirEntry->modified.day = 1;
      dirEntry->modified.dayOfWeek = 0;

      //Last modified time
      dirEntry->modified.hours = 12;
      dirEntry->modified.minutes = 0;
      dirEntry->modified.seconds = 0;
      dirEntry->modified.milliseconds = 0;

      //Next entry
      dirDesc->index++;

      //Successful processing
      error = NO_ERROR;
   }
   else if(dirDesc->index == 2)
   {
      //File name
      strcpy(dirEntry->name, "test_1m.txt");

      //Get the length of the application image
      dirEntry->size = 1000000;

      //File attributes
      dirEntry->attributes = 0;

      //Last modified date
      dirEntry->modified.year = 2000;
      dirEntry->modified.month = 1;
      dirEntry->modified.day = 1;
      dirEntry->modified.dayOfWeek = 0;

      //Last modified time
      dirEntry->modified.hours = 12;
      dirEntry->modified.minutes = 0;
      dirEntry->modified.seconds = 0;
      dirEntry->modified.milliseconds = 0;

      //Next entry
      dirDesc->index++;

      //Successful processing
      error = NO_ERROR;
   }
   else if(dirDesc->index == 3)
   {
      //File name
      strcpy(dirEntry->name, "test_10m.txt");

      //Get the length of the application image
      dirEntry->size = 10000000;

      //File attributes
      dirEntry->attributes = 0;

      //Last modified date
      dirEntry->modified.year = 2000;
      dirEntry->modified.month = 1;
      dirEntry->modified.day = 1;
      dirEntry->modified.dayOfWeek = 0;

      //Last modified time
      dirEntry->modified.hours = 12;
      dirEntry->modified.minutes = 0;
      dirEntry->modified.seconds = 0;
      dirEntry->modified.milliseconds = 0;

      //Next entry
      dirDesc->index++;

      //Successful processing
      error = NO_ERROR;
   }
   else if(dirDesc->index == 4)
   {
      //File name
      strcpy(dirEntry->name, "test_100m.txt");

      //Get the length of the application image
      dirEntry->size = 100000000;

      //File attributes
      dirEntry->attributes = 0;

      //Last modified date
      dirEntry->modified.year = 2000;
      dirEntry->modified.month = 1;
      dirEntry->modified.day = 1;
      dirEntry->modified.dayOfWeek = 0;

      //Last modified time
      dirEntry->modified.hours = 12;
      dirEntry->modified.minutes = 0;
      dirEntry->modified.seconds = 0;
      dirEntry->modified.milliseconds = 0;

      //Next entry
      dirDesc->index++;

      //Successful processing
      error = NO_ERROR;
   }
   else if(dirDesc->index == 5)
   {
	   //File name
	   strcpy(dirEntry->name, "version.txt");

	   //Get the length of the application image
	   dirEntry->size = 5;

	   //File attributes
	   dirEntry->attributes = 0;

	   //Last modified date
	   dirEntry->modified.year = 2000;
	   dirEntry->modified.month = 1;
	   dirEntry->modified.day = 1;
	   dirEntry->modified.dayOfWeek = 0;

	   //Last modified time
	   dirEntry->modified.hours = 12;
	   dirEntry->modified.minutes = 0;
	   dirEntry->modified.seconds = 0;
	   dirEntry->modified.milliseconds = 0;

	   //Next entry
	   dirDesc->index++;

	   //Successful processing
	   error = NO_ERROR;
   }
   else if(dirDesc->index == 6)
   {
	   //File name
	   strcpy(dirEntry->name, "reboot.txt");

	   //Get the length of the application image
	   dirEntry->size = 0;

	   //File attributes
	   dirEntry->attributes = 0;

	   //Last modified date
	   dirEntry->modified.year = 2000;
	   dirEntry->modified.month = 1;
	   dirEntry->modified.day = 1;
	   dirEntry->modified.dayOfWeek = 0;

	   //Last modified time
	   dirEntry->modified.hours = 12;
	   dirEntry->modified.minutes = 0;
	   dirEntry->modified.seconds = 0;
	   dirEntry->modified.milliseconds = 0;

	   //Next entry
	   dirDesc->index++;

	   //Successful processing
	   error = NO_ERROR;
   }
   else
   {
      //End of directory
      error = ERROR_END_OF_STREAM;
   }

   //Return status code
   return error;
}


/**
 * @brief Close a directory stream
 * @param[in] dir Handle that identifies the directory to be closed
 **/

void fsCloseDir(FsDir *dir)
{
   //Directory pointer
   DirDesc *dirDesc = (DirDesc *) dir;

   //Enter critical section
   osAcquireMutex(&fsMutex);
   //Close directory
   dirDesc->index = 0;
   //Leave critical section
   osReleaseMutex(&fsMutex);
}
