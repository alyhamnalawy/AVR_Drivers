################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SERVICES/portable/MemMang/subdir.mk
-include SERVICES/portable/GCC/ATMega323/subdir.mk
-include SERVICES/subdir.mk
-include MCAL/WatchDog\ Timer/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/TWI/subdir.mk
-include MCAL/TIMER2/subdir.mk
-include MCAL/TIMER1/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO_Driver/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Transistor/subdir.mk
-include HAL/SEVEN_SEGMENT/subdir.mk
-include HAL/LM35/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KeyPad/subdir.mk
-include HAL/EEPROM/subdir.mk
-include APP/subdir.mk
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
DIO_DRIVER2.lss \

FLASH_IMAGE += \
DIO_DRIVER2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: DIO_DRIVER2.elf secondary-outputs

# Tool invocations
DIO_DRIVER2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,DIO_DRIVER2.map -mmcu=atmega32 -o "DIO_DRIVER2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

DIO_DRIVER2.lss: DIO_DRIVER2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S DIO_DRIVER2.elf  >"DIO_DRIVER2.lss"
	@echo 'Finished building: $@'
	@echo ' '

DIO_DRIVER2.hex: DIO_DRIVER2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex DIO_DRIVER2.elf  "DIO_DRIVER2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: DIO_DRIVER2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 DIO_DRIVER2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) DIO_DRIVER2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
