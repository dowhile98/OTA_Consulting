################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.c 

OBJS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.o 

C_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.d 


# Each subdirectory must supply rules for building sources it contributes
App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.c App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/App/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/system" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/ymodem" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-drivers-2f-mcu-2f-arm

clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-drivers-2f-mcu-2f-arm:
	-$(RM) ./App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.cyclo ./App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/stm32f4xx_mcu_driver.su

.PHONY: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-drivers-2f-mcu-2f-arm

