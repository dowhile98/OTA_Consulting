################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.c 

OBJS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.o 

C_DEPS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.d 


# Each subdirectory must supply rules for building sources it contributes
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-memory

clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-memory:
	-$(RM) ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/memory_ex.su

.PHONY: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_boot-2f-memory

