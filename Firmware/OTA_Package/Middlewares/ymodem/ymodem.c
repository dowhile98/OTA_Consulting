/**
  ******************************************************************************
  * @file    ymodem.c
  * @author  Modified by AI Assistant
  * @brief   YMODEM protocol implementation with user-provided I/O functions
  ******************************************************************************
  */

#include "ymodem.h"
#include <string.h>

// Private function prototypes
static COM_StatusTypeDef receive_packet(ymodem_handle_t *handle, uint8_t *p_data, uint32_t *p_length, uint32_t timeout);
static uint16_t update_crc16(uint16_t crc_in, uint8_t byte);
static uint16_t calculate_crc16(const uint8_t* p_data, uint32_t size);
static uint8_t calculate_checksum(const uint8_t *p_data, uint32_t size);
static COM_StatusTypeDef serial_put_byte(ymodem_handle_t *handle, uint8_t data);

// String to integer conversion (replacement for Str2Int)
static COM_StatusTypeDef string_to_uint32(const uint8_t *str, uint32_t *value) {
    uint32_t result = 0;
    uint32_t i = 0;

    if (str == NULL || value == NULL) {
        return COM_ERROR;
    }

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
            i++;
        } else {
            break;
        }
    }

    *value = result;
    return COM_OK;
}

/**
 * @brief Initialize YMODEM handle with user I/O functions
 * @param handle Pointer to YMODEM handle
 * @param read_fn User-provided read function
 * @param write_fn User-provided write function
 */
void ymodem_init(ymodem_handle_t *handle, ymodem_read_fn_t read_fn, ymodem_write_fn_t write_fn) {
    if (handle == NULL) return;

    handle->read_fn = read_fn;
    handle->write_fn = write_fn;
    handle->file_size = 0;
    handle->bytes_transferred = 0;
    memset(handle->filename, 0, FILE_NAME_LENGTH);
    memset(handle->packet_data, 0, sizeof(handle->packet_data));
}

/**
 * @brief Send a single byte using user write function
 * @param handle Pointer to YMODEM handle
 * @param data Byte to send
 * @return COM_StatusTypeDef
 */
static COM_StatusTypeDef serial_put_byte(ymodem_handle_t *handle, uint8_t data) {
    if (handle == NULL || handle->write_fn == NULL) {
        return COM_ERROR;
    }
    return handle->write_fn(&data, 1);
}

/**
 * @brief Receive a packet from sender
 * @param handle Pointer to YMODEM handle
 * @param p_data Data buffer
 * @param p_length Packet length
 * @param timeout Timeout in milliseconds
 * @return COM_StatusTypeDef
 */
static COM_StatusTypeDef receive_packet(ymodem_handle_t *handle, uint8_t *p_data, uint32_t *p_length, uint32_t timeout) {
    uint32_t crc;
    uint32_t packet_size = 0;
    COM_StatusTypeDef status;
    uint8_t char1;

    *p_length = 0;

    if (handle == NULL || handle->read_fn == NULL) {
        return COM_ERROR;
    }

    status = handle->read_fn(&char1, 1, timeout);

    if (status == COM_OK) {
        switch (char1) {
            case SOH:
                packet_size = PACKET_SIZE;
                break;
            case STX:
                packet_size = PACKET_1K_SIZE;
                break;
            case EOT:
                break;
            case CA:
                if ((handle->read_fn(&char1, 1, timeout) == COM_OK) && (char1 == CA)) {
                    packet_size = 2;
                } else {
                    status = COM_ERROR;
                }
                break;
            case ABORT1:
            case ABORT2:
                status = COM_ABORT;
                break;
            default:
                status = COM_ERROR;
                break;
        }
        *p_data = char1;

        if (packet_size >= PACKET_SIZE) {
            status = handle->read_fn(&p_data[PACKET_NUMBER_INDEX], packet_size + PACKET_OVERHEAD_SIZE, timeout);

            /* Simple packet sanity check */
            if (status == COM_OK) {
                if (p_data[PACKET_NUMBER_INDEX] != ((p_data[PACKET_CNUMBER_INDEX]) ^ NEGATIVE_BYTE)) {
                    packet_size = 0;
                    status = COM_ERROR;
                } else {
                    /* Check packet CRC */
                    crc = p_data[packet_size + PACKET_DATA_INDEX] << 8;
                    crc += p_data[packet_size + PACKET_DATA_INDEX + 1];
                    if (calculate_crc16(&p_data[PACKET_DATA_INDEX], packet_size) != crc) {
                        packet_size = 0;
                        status = COM_ERROR;
                    }
                }
            } else {
                packet_size = 0;
            }
        }
    }
    *p_length = packet_size;
    return status;
}

/**
 * @brief Update CRC16 for input byte
 * @param crc_in Input CRC value
 * @param byte Input byte
 * @return Updated CRC16 value
 */
static uint16_t update_crc16(uint16_t crc_in, uint8_t byte) {
    uint32_t crc = crc_in;
    uint32_t in = byte | 0x100;

    do {
        crc <<= 1;
        in <<= 1;
        if (in & 0x100)
            ++crc;
        if (crc & 0x10000)
            crc ^= 0x1021;
    } while (!(in & 0x10000));

    return crc & 0xffffu;
}

/**
 * @brief Calculate CRC16 for YModem Packet
 * @param p_data Data buffer
 * @param size Data size
 * @return CRC16 value
 */
static uint16_t calculate_crc16(const uint8_t* p_data, uint32_t size) {
    uint32_t crc = 0;
    const uint8_t* dataEnd = p_data + size;

    while (p_data < dataEnd)
        crc = update_crc16(crc, *p_data++);

    crc = update_crc16(crc, 0);
    crc = update_crc16(crc, 0);

    return crc & 0xffffu;
}

/**
 * @brief Calculate Check sum for YModem Packet
 * @param p_data Pointer to input data
 * @param size Length of input data
 * @return Checksum value
 */
static uint8_t calculate_checksum(const uint8_t *p_data, uint32_t size) {
    uint32_t sum = 0;
    const uint8_t *p_data_end = p_data + size;

    while (p_data < p_data_end) {
        sum += *p_data++;
    }

    return (sum & 0xffu);
}

/**
 * @brief Receive a file using the ymodem protocol with CRC16
 * @param handle Pointer to YMODEM handle
 * @param data_callback Callback function to process received data
 * @return COM_StatusTypeDef result of reception
 */
COM_StatusTypeDef ymodem_receive(ymodem_handle_t *handle, ymodem_data_callback_t data_callback) {
    uint32_t i, packet_length, session_done = 0, file_done, errors = 0, session_begin = 0, packets_received = 0, bytes_received = 0;
    uint32_t filesize;
    uint8_t *file_ptr, *data_ptr;
    uint8_t file_size[FILE_SIZE_LENGTH];
    COM_StatusTypeDef result = COM_OK;

    if (handle == NULL || data_callback == NULL) {
        return COM_ERROR;
    }

    // Reset transfer state
    handle->file_size = 0;
    handle->bytes_transferred = 0;
    memset(handle->filename, 0, FILE_NAME_LENGTH);

    while ((session_done == 0) && (result == COM_OK)) {
        packets_received = 0;
        file_done = 0;
        while ((file_done == 0) && (result == COM_OK)) {
            switch (receive_packet(handle, handle->packet_data, &packet_length, DOWNLOAD_TIMEOUT)) {
                case COM_OK:
                    errors = 0;
                    switch (packet_length) {
                        case 2:
                            /* Abort by sender */
                            serial_put_byte(handle, ACK);
                            result = COM_ABORT;
                            break;
                        case 0:
                            /* End of transmission */
                            serial_put_byte(handle, ACK);
                            file_done = 1;
                            break;
                        default:
                            /* Normal packet */
                            if (handle->packet_data[PACKET_NUMBER_INDEX] != (0xFFU & packets_received)) {
                                serial_put_byte(handle, NAK);
                            } else {
                                if (packets_received == 0) {
                                    /* File name packet */
                                    if (handle->packet_data[PACKET_DATA_INDEX] != 0) {
                                        /* File name extraction */
                                        i = 0;
                                        file_ptr = handle->packet_data + PACKET_DATA_INDEX;
                                        while ((*file_ptr != 0) && (i < FILE_NAME_LENGTH)) {
                                            handle->filename[i++] = *file_ptr++;
                                        }
                                        handle->filename[i] = '\0';

                                        /* File size extraction */
                                        i = 0;
                                        file_ptr++;
                                        while ((*file_ptr != ' ') && (i < FILE_SIZE_LENGTH)) {
                                            file_size[i++] = *file_ptr++;
                                        }
                                        file_size[i] = '\0';

                                        // Convert string to integer
                                        if (string_to_uint32(file_size, &filesize) != COM_OK) {
                                            result = COM_ERROR;
                                            break;
                                        }

                                        handle->file_size = filesize;
                                        handle->bytes_transferred = 0;

                                        // Send ACK and request CRC mode for next packet
                                        serial_put_byte(handle, ACK);
                                        serial_put_byte(handle, CRC16);
                                    }
                                    /* File header packet is empty, end session */
                                    else {
                                        serial_put_byte(handle, ACK);
                                        file_done = 1;
                                        session_done = 1;
                                        break;
                                    }
                                } else {
                                    /* Data packet */
                                    data_ptr = (uint8_t*)&handle->packet_data[PACKET_DATA_INDEX];

                                    // Check if remaining bytes is less than 1024
                                    if ((handle->file_size - bytes_received) < 1024) {
                                        // Discard '1A' fill data block
                                        while (data_ptr[packet_length - 1] == '\x1A') {
                                            packet_length--;
                                        }
                                    }

                                    // Update received data bytes
                                    bytes_received += packet_length;
                                    handle->bytes_transferred = bytes_received;

                                    /* Process received file data through user callback */
                                    if (data_callback(data_ptr, packet_length, bytes_received - packet_length) == COM_OK) {
                                        serial_put_byte(handle, ACK);
                                    } else {
                                        /* An error occurred while processing data */
                                        serial_put_byte(handle, CA);
                                        serial_put_byte(handle, CA);
                                        result = COM_DATA;
                                    }
                                }
                                packets_received++;
                                session_begin = 1;
                            }
                            break;
                    }
                    break;
                case COM_ABORT: /* Abort actually */
                    serial_put_byte(handle, CA);
                    serial_put_byte(handle, CA);
                    result = COM_ABORT;
                    break;
                default:
                    if (session_begin > 0) {
                        errors++;
                    }
                    if (errors > MAX_ERRORS) {
                        /* Abort communication */
                        serial_put_byte(handle, CA);
                        serial_put_byte(handle, CA);
                        result = COM_ERROR;
                    } else {
                        serial_put_byte(handle, CRC16); /* Ask for a packet */
                    }
                    break;
            }
        }
    }
    return result;
}
