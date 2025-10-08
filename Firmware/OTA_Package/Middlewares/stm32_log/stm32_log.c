/*
 * stm32_log.c
 *
 *  Created on: Nov 11, 2023
 *      Author: eplim
 */

#include "stm32_log.h"
#include "main.h"

static lwprintf_t debug;

uint8_t stm32_log_init(lwprintf_output_fn out_fn)
{

	if(out_fn == NULL)
	{
		lwprintf_init_ex(&debug, stm32_log_out);
	}
	else
	{
		lwprintf_init_ex(&debug, out_fn);
	}
	return 0;

}
// Función para obtener la marca de tiempo (adapta según sea necesario)
__attribute__((weak)) uint32_t stm32_log_timestamp(void) {
    // Implementa la obtención de la marca de tiempo aquí (puede ser un contador o un reloj en tiempo real)
    return HAL_GetTick() ;
}

// Función para escribir un mensaje de registro (adapta según sea necesario)
void stm32_log_write(int level, const char* tag, const char* format, ...) {
    if (level <= STM32_LOG_LEVEL) {
        va_list args;
        va_start(args, format);
        lwprintf_vprintf_ex(&debug, format, args);
        va_end(args);
    }
    return;
}


__weak int stm32_log_out(int ch, lwprintf_t* p) {

    uint8_t c = (uint8_t)ch;

    /* Don't print zero */
    if (c == '\0') {
        return ch;
    }
    ITM_SendChar(ch);
    return ch;
}
