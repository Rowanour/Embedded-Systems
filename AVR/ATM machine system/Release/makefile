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
ATM\ machine\ system.lss \

FLASH_IMAGE += \
ATM\ machine\ system.hex \

EEPROM_IMAGE += \
ATM\ machine\ system.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ATM\ machine\ system.elf secondary-outputs

# Tool invocations
ATM\ machine\ system.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ATM machine system.map -mmcu=atmega32 -o "ATM machine system.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ATM\ machine\ system.lss: ATM\ machine\ system.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ATM machine system.elf  >"ATM machine system.lss"
	@echo 'Finished building: $@'
	@echo ' '

ATM\ machine\ system.hex: ATM\ machine\ system.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ATM machine system.elf  "ATM machine system.hex"
	@echo 'Finished building: $@'
	@echo ' '

ATM\ machine\ system.eep: ATM\ machine\ system.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ATM machine system.elf  "ATM machine system.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ATM\ machine\ system.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ATM machine system.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "ATM machine system.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
