################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.c 

OBJS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.o 

C_DEPS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.d 


# Each subdirectory must supply rules for building sources it contributes
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_crypto-2f-xof

clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_crypto-2f-xof:
	-$(RM) ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/cshake.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/keccak.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/shake.su

.PHONY: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_crypto-2f-xof

