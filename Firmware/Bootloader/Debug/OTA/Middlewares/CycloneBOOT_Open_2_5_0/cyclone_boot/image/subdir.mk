################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.c 

OBJS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.o 

C_DEPS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.d 


# Each subdirectory must supply rules for building sources it contributes
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-image

clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-image:
	-$(RM) ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_process.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/image_utils.su

.PHONY: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-image

