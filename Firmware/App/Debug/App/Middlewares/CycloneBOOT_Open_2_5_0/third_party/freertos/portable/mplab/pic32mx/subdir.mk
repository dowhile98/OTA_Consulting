################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.c 

S_UPPER_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port_asm.S 

OBJS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port_asm.o 

S_UPPER_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port_asm.d 

C_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.d 


# Each subdirectory must supply rules for building sources it contributes
App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.c App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/App/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include/lwbtn" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/system" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/ymodem" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port_asm.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port_asm.S App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-third_party-2f-freertos-2f-portable-2f-mplab-2f-pic32mx

clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-third_party-2f-freertos-2f-portable-2f-mplab-2f-pic32mx:
	-$(RM) ./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.cyclo ./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port.su ./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port_asm.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/third_party/freertos/portable/mplab/pic32mx/port_asm.o

.PHONY: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-third_party-2f-freertos-2f-portable-2f-mplab-2f-pic32mx

