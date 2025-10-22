################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v4_keil.s \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_iar.s \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_keil.s 

C_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.c 

S_UPPER_SRCS += \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_gcc.S \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_iar.S \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_gcc.S \
/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_mips_gcc.S 

OBJS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v4_keil.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_gcc.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_iar.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_gcc.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_iar.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_keil.o \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_mips_gcc.o 

S_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v4_keil.d \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_iar.d \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_keil.d 

S_UPPER_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_gcc.d \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_iar.d \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_gcc.d \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_mips_gcc.d 

C_DEPS += \
./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.d 


# Each subdirectory must supply rules for building sources it contributes
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.c App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/App/config" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/common" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwbtn/src/include/lwbtn" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/lwprintf" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/lwprintf/src/include/system" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/stm32_log" -I"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/ymodem" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v4_keil.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v4_keil.s App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_gcc.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_gcc.S App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_iar.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_iar.S App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_gcc.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_gcc.S App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_iar.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_iar.s App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_keil.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_keil.s App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_mips_gcc.o: /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/OTA_Package/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_mips_gcc.S App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-utils-2f-ImageBuilder-2f-lib-2f-CycloneCRYPTO-2f-mpi

clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-utils-2f-ImageBuilder-2f-lib-2f-CycloneCRYPTO-2f-mpi:
	-$(RM) ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.cyclo ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi.su ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v4_keil.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v4_keil.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_gcc.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_gcc.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_iar.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7a_iar.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_gcc.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_gcc.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_iar.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_iar.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_keil.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_arm_v7m_keil.o ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_mips_gcc.d ./App/Middlewares/CycloneBOOT_Open_2_5_0/utils/ImageBuilder/lib/CycloneCRYPTO/mpi/mpi_mips_gcc.o

.PHONY: clean-App-2f-Middlewares-2f-CycloneBOOT_Open_2_5_0-2f-utils-2f-ImageBuilder-2f-lib-2f-CycloneCRYPTO-2f-mpi

