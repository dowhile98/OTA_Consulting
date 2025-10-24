/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "rng.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "stm32_log.h"


#include "bootloader/boot.h"
#include "drivers/memory/flash/internal/stm32f4xx_flash_driver.h"
#include "drivers/memory/flash/external/w25q_flash_driver.h"
#include "core/cboot_error.h"
#include "boot_config.h"
#include "debug.h"
#include "ymodem.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static const char *TAG = "BOOT";
BootSettings bootSettings;
BootContext bootContext;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
COM_StatusTypeDef ymodem_uart_read(uint8_t *data, size_t size, uint32_t timeout_ms);

COM_StatusTypeDef ymodem_uart_write(const uint8_t *data, size_t size);

COM_StatusTypeDef ymodem_data_callback(uint8_t *data, size_t length, uint32_t offset);

static int32_t w25q_spi_init(void *user_ctx);

static int32_t w25q_spi_write_read(void *user_ctx, const uint8_t *tx, uint8_t *rx, size_t len);

static void w25q_cs_control(void *user_ctx, bool level);

static void w25q_delay_ms(uint32_t ms);

static void w25q_lock(void *user_ctx);

static void w25q_unlock(void *user_ctx);
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

	/* USER CODE BEGIN 1 */
	cboot_error_t cerror;
	uint32_t ticks = 0;

	static w25q_hw_t w25q_hw = {
			.spi_init = w25q_spi_init,
			.spi_write_read = w25q_spi_write_read,
			.cs_control = w25q_cs_control,
			.delay_ms = w25q_delay_ms,
			.lock = w25q_lock,
			.unlock = w25q_unlock
	};

	w25q_driver_config_t config = {
			.hw_callbacks = w25q_hw,
			.user_ctx = NULL,
			.timeout_ms = 5000,
			.software_cs = true
	};
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_RNG_Init();
	MX_SPI1_Init();
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	/* USER CODE BEGIN 2 */
	stm32_log_init(NULL);

	STM32_LOGI(TAG, "\r\n");
	STM32_LOGI(TAG, "**********************************************");
	STM32_LOGI(TAG, "*** CycloneBOOT IAP Single-Bank Bootloader ***");
	STM32_LOGI(TAG, "**********************************************");
	STM32_LOGI(TAG, "Compiled: %s %s\r\n", __DATE__, __TIME__);
	STM32_LOGI(TAG, "Target: STM32F407");

	//external flash driver init
	w25qFlashSetConfig(&config);

	//Get default booloader user settings
	bootGetDefaultSettings(&bootSettings);

	//User settings primary memory configuration
	bootSettings.memories[0].memoryType = MEMORY_TYPE_FLASH;
	bootSettings.memories[0].memoryRole = MEMORY_ROLE_PRIMARY;
	bootSettings.memories[0].driver = &stm32f4xxFlashDriver;
	bootSettings.memories[0].nbSlots = 1;
	//User settings primary memory slot 0 configuration
	bootSettings.memories[0].slots[0].type = SLOT_TYPE_DIRECT;
	bootSettings.memories[0].slots[0].cType = SLOT_CONTENT_BINARY;
	bootSettings.memories[0].slots[0].memParent = &bootSettings.memories[0];
	bootSettings.memories[0].slots[0].addr = 0x08020000;
	bootSettings.memories[0].slots[0].size = 0xE0000;
	//User settings primary memory slot 1 configuration
	//	bootSettings.memories[0].slots[1].type = SLOT_TYPE_DIRECT;
	//	bootSettings.memories[0].slots[1].cType = SLOT_CONTENT_UPDATE;
	//	bootSettings.memories[0].slots[1].memParent = &bootSettings.memories[0];
	//	bootSettings.memories[0].slots[1].addr = 0x08080000;
	//	bootSettings.memories[0].slots[1].size = 0x60000;

	bootSettings.memories[1].memoryRole 			   = MEMORY_ROLE_SECONDARY;
	bootSettings.memories[1].memoryType 			   = MEMORY_TYPE_FLASH;
	bootSettings.memories[1].driver 				   = &w25qFlashDriver;
	bootSettings.memories[1].nbSlots 				   = 1;

	//User update settings secondary memory slot 0 configuration
	bootSettings.memories[1].slots[0].type 		   = SLOT_TYPE_DIRECT;
	bootSettings.memories[1].slots[0].cType 		= SLOT_CONTENT_APP | SLOT_CONTENT_BACKUP;
	bootSettings.memories[1].slots[0].memParent 	= &bootSettings.memories[1];
	bootSettings.memories[1].slots[0].addr 		   = 0x00000000;
	bootSettings.memories[1].slots[0].size 		   = 0x200000;

	//Initialize bootloader
	cerror = bootInit(&bootContext, &bootSettings);
	//Is any error?
	if(cerror)
	{
		STM32_LOGE(TAG, "Bootloader configuration failed!\r\n");

		Error_Handler();
	}
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
		if((HAL_GetTick() - ticks)>= 100)
		{
			ticks = HAL_GetTick();

			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
		}

		cerror = bootTask(&bootContext);
		//Is any error?
		if(cerror)
		{
			//Enable ymodem


		}
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 168;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
			|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */
int stm32_log_out(int ch, lwprintf_t* p) {

	uint8_t c = (uint8_t)ch;

	/* Don't print zero */
	if (c == '\0') {
		return ch;
	}
	ITM_SendChar(ch);
	//add uart
	HAL_UART_Transmit(&huart1, &c, 1, 1);
	return ch;
}

// User-provided read function (w25q for UART)
COM_StatusTypeDef ymodem_uart_read(uint8_t *data, size_t size, uint32_t timeout_ms) {
	return HAL_UART_Receive(&huart2, data, size, timeout_ms);

}

// User-provided write function (w25q for UART)
COM_StatusTypeDef ymodem_uart_write(const uint8_t *data, size_t size) {

	return HAL_UART_Transmit(&huart2, data, size, 2000);

}

// User data callback to process received data
COM_StatusTypeDef ymodem_data_callback(uint8_t *data, size_t length, uint32_t offset) {

	error_t error = NO_ERROR;
	//write to flash


	return error;
}

static int32_t w25q_spi_init(void *user_ctx)
{
	MX_SPI1_Init();
	// Inicializar hardware SPI aquí
	STM32_LOGI(TAG, "SPI inicializado\r\n");
	return 0;
}

static int32_t w25q_spi_write_read(void *user_ctx, const uint8_t *tx, uint8_t *rx, size_t len)
{
	int32_t ret = HAL_OK;
	// Implementar transferencia SPI aquí
	if(tx == NULL)
	{
		ret = HAL_SPI_Receive(&hspi1, rx, len, HAL_MAX_DELAY);
	}
	else if(rx == NULL)
	{
		ret = HAL_SPI_Transmit(&hspi1, tx, len, HAL_MAX_DELAY);
	}
	else
	{
		ret = HAL_SPI_TransmitReceive(&hspi1, tx, rx, len, HAL_MAX_DELAY);
	}


	return ret;
}

static void w25q_cs_control(void *user_ctx, bool level)
{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, level ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

static void w25q_delay_ms(uint32_t ms)
{
	HAL_Delay(ms);
}

static void w25q_lock(void *user_ctx) {

}
static void w25q_unlock(void *user_ctx) {

}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	STM32_LOGE(TAG, "%s, line: %d", __FILE__,__LINE__);
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
