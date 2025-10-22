################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include App/Middlewares/ymodem/subdir.mk
-include App/Middlewares/stm32_log/subdir.mk
-include App/Middlewares/lwprintf/src/system/subdir.mk
-include App/Middlewares/lwprintf/src/lwprintf/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/xof/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/rng/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pqc/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pkix/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/pkc/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/mpi/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/mac/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/lwc/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/kdf/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/hash/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/hardware/stm32f4xx/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/encoding/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/ecc/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/cipher_modes/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/cipher/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_crypto/aead/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/update/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/security/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/memory/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/image/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/memory/flash/internal/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/drivers/mcu/arm/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/core/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/cyclone_boot/bootloader/subdir.mk
-include App/Middlewares/CycloneBOOT_Open_2_5_0/common/subdir.mk
-include App/App/Src/subdir.mk
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


BUILD_ARTIFACT_NAME := App
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
App.elf \

MAP_FILES += \
App.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
App.list \

OBJCOPY_BIN += \
App.bin \


# All Target
all:
	+@$(MAKE) --no-print-directory pre-build && $(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: App.elf secondary-outputs

# Tool invocations
App.elf App.map: $(OBJS) $(USER_OBJS) /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "App.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="App.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

App.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "App.list"
	@echo 'Finished building: $@'
	@echo ' '

App.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "App.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) App.bin App.elf App.list App.map default.size.stdout
	-@echo ' '

pre-build:
	python3 /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/../utils/rc/rc.py /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/resources /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/App/App/Src/res.c
	-@echo ' '

post-build:
	python3 /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/scripts/misc/copy_file.py /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/Debug/App.bin /home/tecna-smart-lab/GitHub/OTA_Consulting/Firmware/App/
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified pre-build post-build

-include ../makefile.targets
