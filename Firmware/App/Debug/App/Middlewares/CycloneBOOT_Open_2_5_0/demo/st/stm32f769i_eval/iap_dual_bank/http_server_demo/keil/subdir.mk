################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/startup_stm32f769xx.s 

C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.c 

OBJS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/startup_stm32f769xx.o 

S_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/startup_stm32f769xx.d 

C_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.d 


# Each subdirectory must supply rules for building sources it contributes
App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.c App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/App/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include/lwbtn" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/system" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/ymodem" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/startup_stm32f769xx.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/startup_stm32f769xx.s App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-demo-2f-st-2f-stm32f769i_eval-2f-iap_dual_bank-2f-http_server_demo-2f-keil

clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-demo-2f-st-2f-stm32f769i_eval-2f-iap_dual_bank-2f-http_server_demo-2f-keil:
	-$(RM) ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.cyclo ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/retarget.su ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/startup_stm32f769xx.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/demo/st/stm32f769i_eval/iap_dual_bank/http_server_demo/keil/startup_stm32f769xx.o

.PHONY: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-demo-2f-st-2f-stm32f769i_eval-2f-iap_dual_bank-2f-http_server_demo-2f-keil

