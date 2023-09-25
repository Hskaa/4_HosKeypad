################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
4_HosKeypad.lss \

FLASH_IMAGE += \
4_HosKeypad.hex \

EEPROM_IMAGE += \
4_HosKeypad.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: 4_HosKeypad.elf secondary-outputs

# Tool invocations
4_HosKeypad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,4_HosKeypad.map -mmcu=atmega32 -o "4_HosKeypad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

4_HosKeypad.lss: 4_HosKeypad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S 4_HosKeypad.elf  >"4_HosKeypad.lss"
	@echo 'Finished building: $@'
	@echo ' '

4_HosKeypad.hex: 4_HosKeypad.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex 4_HosKeypad.elf  "4_HosKeypad.hex"
	@echo 'Finished building: $@'
	@echo ' '

4_HosKeypad.eep: 4_HosKeypad.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex 4_HosKeypad.elf  "4_HosKeypad.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: 4_HosKeypad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 4_HosKeypad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) 4_HosKeypad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
