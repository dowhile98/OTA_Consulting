################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/lwprintf/lwprintf.c 

OBJS += \
./OTA/Middlewares/lwprintf/src/lwprintf/lwprintf.o 

C_DEPS += \
./OTA/Middlewares/lwprintf/src/lwprintf/lwprintf.d 


# Each subdirectory must supply rules for building sources it contributes
OTA/Middlewares/lwprintf/src/lwprintf/lwprintf.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/lwprintf/lwprintf.c OTA/Middlewares/lwprintf/src/lwprintf/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OTA-2f-Middlewares-2f-lwprintf-2f-src-2f-lwprintf

clean-OTA-2f-Middlewares-2f-lwprintf-2f-src-2f-lwprintf:
	-$(RM) ./OTA/Middlewares/lwprintf/src/lwprintf/lwprintf.cyclo ./OTA/Middlewares/lwprintf/src/lwprintf/lwprintf.d ./OTA/Middlewares/lwprintf/src/lwprintf/lwprintf.o ./OTA/Middlewares/lwprintf/src/lwprintf/lwprintf.su

.PHONY: clean-OTA-2f-Middlewares-2f-lwprintf-2f-src-2f-lwprintf

