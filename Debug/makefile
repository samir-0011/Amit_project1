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
TEST_IIN.lss \

FLASH_IMAGE += \
TEST_IIN.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: TEST_IIN.elf secondary-outputs

# Tool invocations
TEST_IIN.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,TEST_IIN.map -mmcu=atmega32 -o "TEST_IIN.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

TEST_IIN.lss: TEST_IIN.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S TEST_IIN.elf  >"TEST_IIN.lss"
	@echo 'Finished building: $@'
	@echo ' '

TEST_IIN.hex: TEST_IIN.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex TEST_IIN.elf  "TEST_IIN.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: TEST_IIN.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 TEST_IIN.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) TEST_IIN.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
