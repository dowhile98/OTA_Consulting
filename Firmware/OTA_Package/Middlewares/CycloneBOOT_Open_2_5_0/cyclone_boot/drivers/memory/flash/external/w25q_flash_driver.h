/*
 * w25q_flash_driver.h
 *
 *  Created on: Oct 22, 2025
 *      Author: tecna-smart-lab
 */

/**
 * @file w25q_flash_driver.h
 * @brief Flash driver for W25Qxxx series using generic W25Q library - CycloneBOOT compatible
 */

#ifndef COMPONENTS_ORYX_EMBEDDED_CYCLONE_BOOT_DRIVERS_MEMORY_FLASH_EXTERNAL_W25Q_FLASH_DRIVER_H_
#define COMPONENTS_ORYX_EMBEDDED_CYCLONE_BOOT_DRIVERS_MEMORY_FLASH_EXTERNAL_W25Q_FLASH_DRIVER_H_

// Dependencies
#include <stdlib.h>
#include <stdint.h>
#include "core/flash.h"
#include "error.h"
#include "w25q.h"

// W25Q Flash driver name
#define W25Q_FLASH_NAME "W25Qxxx External SPI Flash"

// W25Q start address (memory mapped)
#define W25Q_FLASH_ADDR 0x00000000

// W25Q write size (page program)
#define W25Q_WRITE_SIZE 256  // Max page size
// W25Q read size
#define W25Q_READ_SIZE  1    // Can read single bytes

// W25Q Internal Memory Flash driver
extern const FlashDriver w25qFlashDriver;

// Hardware configuration structure
typedef struct {
    w25q_hw_t hw_callbacks;
    void *user_ctx;
    uint32_t timeout_ms;
    bool software_cs;
} w25q_driver_config_t;

/**
 * @brief Set hardware configuration for W25Q driver
 * @param config Hardware configuration structure
 */
void w25qFlashSetConfig(const w25q_driver_config_t *config);

#endif /* COMPONENTS_ORYX_EMBEDDED_CYCLONE_BOOT_DRIVERS_MEMORY_FLASH_EXTERNAL_W25Q_FLASH_DRIVER_H_ */
