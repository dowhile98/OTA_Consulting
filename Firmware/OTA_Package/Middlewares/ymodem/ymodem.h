/**
  ******************************************************************************
  * @file    ymodem.h
  * @author  Modified by AI Assistant
  * @brief   YMODEM protocol implementation with user-provided I/O functions
  ******************************************************************************
  */

#ifndef _YMODEM_H
#define _YMODEM_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  Comm status structures definition
 **/
typedef enum
{
  COM_OK       = 0x00,
  COM_ERROR    = 0x01,
  COM_ABORT    = 0x02,
  COM_TIMEOUT  = 0x03,
  COM_DATA     = 0x04,
  COM_LIMIT    = 0x05
} COM_StatusTypeDef;

// Packet structure defines
#define PACKET_HEADER_SIZE      ((uint32_t)3)
#define PACKET_DATA_INDEX       ((uint32_t)4)
#define PACKET_START_INDEX      ((uint32_t)1)
#define PACKET_NUMBER_INDEX     ((uint32_t)2)
#define PACKET_CNUMBER_INDEX    ((uint32_t)3)
#define PACKET_TRAILER_SIZE     ((uint32_t)2)
#define PACKET_OVERHEAD_SIZE    (PACKET_HEADER_SIZE + PACKET_TRAILER_SIZE - 1)
#define PACKET_SIZE             ((uint32_t)128)
#define PACKET_1K_SIZE          ((uint32_t)1024)

#define FILE_NAME_LENGTH        ((uint32_t)64)
#define FILE_SIZE_LENGTH        ((uint32_t)16)

#define SOH                     ((uint8_t)0x01)  /* start of 128-byte data packet */
#define STX                     ((uint8_t)0x02)  /* start of 1024-byte data packet */
#define EOT                     ((uint8_t)0x04)  /* end of transmission */
#define ACK                     ((uint8_t)0x06)  /* acknowledge */
#define NAK                     ((uint8_t)0x15)  /* negative acknowledge */
#define CA                      ((uint32_t)0x18) /* two of these in succession aborts transfer */
#define CRC16                   ((uint8_t)0x43)  /* 'C' == 0x43, request 16-bit CRC */
#define NEGATIVE_BYTE           ((uint8_t)0xFF)

#define ABORT1                  ((uint8_t)0x41)  /* 'A' == 0x41, abort by user */
#define ABORT2                  ((uint8_t)0x61)  /* 'a' == 0x61, abort by user */

#define NAK_TIMEOUT             ((uint32_t)0x100000)
#define DOWNLOAD_TIMEOUT        ((uint32_t)10000) /* 10 second retry delay */
#define MAX_ERRORS              ((uint32_t)5)

/* User-provided I/O function types */
typedef COM_StatusTypeDef (*ymodem_read_fn_t)(uint8_t *data, size_t size, uint32_t timeout_ms);
typedef COM_StatusTypeDef (*ymodem_write_fn_t)(const uint8_t *data, size_t size);

/* YMODEM handle structure */
typedef struct {
    ymodem_read_fn_t read_fn;
    ymodem_write_fn_t write_fn;
    uint8_t filename[FILE_NAME_LENGTH];
    uint8_t packet_data[PACKET_1K_SIZE + PACKET_DATA_INDEX + PACKET_TRAILER_SIZE];
    uint32_t file_size;
    uint32_t bytes_transferred;
} ymodem_handle_t;

/* User data callback */
typedef COM_StatusTypeDef (*ymodem_data_callback_t)(uint8_t *data, size_t length, uint32_t offset);

// Public functions
COM_StatusTypeDef ymodem_receive(ymodem_handle_t *handle, ymodem_data_callback_t data_callback);
void ymodem_init(ymodem_handle_t *handle, ymodem_read_fn_t read_fn, ymodem_write_fn_t write_fn);

#ifdef __cplusplus
}
#endif

#endif  //!_YMODEM_H
