################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.c 

S_UPPER_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/startup_stm32h753xx.S 

OBJS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/startup_stm32h753xx.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.o 

S_UPPER_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/startup_stm32h753xx.d 

C_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/startup_stm32h753xx.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/startup_stm32h753xx.S App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.c App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/App/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include/lwbtn" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/system" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/ymodem" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-demo-2f-st-2f-stm32h753i_eval2-2f-iap_dual_bank-2f-http_server_demo-2f-gcc

clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-demo-2f-st-2f-stm32h753i_eval2-2f-iap_dual_bank-2f-http_server_demo-2f-gcc:
	-$(RM) ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/startup_stm32h753xx.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/startup_stm32h753xx.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.cyclo ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32h753i_eval2/iap_dual_bank/http_server_demo/gcc/syscalls.su

.PHONY: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-demo-2f-st-2f-stm32h753i_eval2-2f-iap_dual_bank-2f-http_server_demo-2f-gcc

