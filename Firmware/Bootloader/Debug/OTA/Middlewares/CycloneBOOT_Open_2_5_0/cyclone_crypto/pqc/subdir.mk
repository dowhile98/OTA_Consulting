################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.c \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.c 

OBJS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.o \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.o 

C_DEPS += \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.d \
./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.d 


# Each subdirectory must supply rules for building sources it contributes
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.c OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F4xxxG -DGPL_LICENSE_TERMS_ACCEPTED -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA/OTA/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_crypto-2f-pqc

clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_crypto-2f-pqc:
	-$(RM) ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/kem.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem1024.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem512.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/mlkem768.su ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.cyclo ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.d ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.o ./OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/sntrup761.su

.PHONY: clean-OTA-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-cyclone_crypto-2f-pqc

