################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include OTA/Middlewares/ymodem/subdir.mk
-include OTA/Middlewares/stm32_log/subdir.mk
-include OTA/Middlewares/lwprintf/src/system/subdir.mk
-include OTA/Middlewares/lwprintf/src/lwprintf/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pkc/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/mpi/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/mac/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/lwc/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/kdf/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/hash/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/hardware/stm32f4xx/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/encoding/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/ecc/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/cipher_modes/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/cipher/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/aead/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/update/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/security/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/memory/flash/internal/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/core/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/bootloader/subdir.mk
-include OTA/Middlewares/CycloneBOOT_Open_2_5_0/common/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Bootloader
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Bootloader.elf \

MAP_FILES += \
Bootloader.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Bootloader.list \


# All Target
all: main-build

# Main-build Target
main-build: Bootloader.elf secondary-outputs

# Tool invocations
Bootloader.elf Bootloader.map: $(OBJS) $(USER_OBJS) /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Bootloader.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/Bootloader/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Bootloader.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Bootloader.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Bootloader.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Bootloader.elf Bootloader.list Bootloader.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
