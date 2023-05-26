################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/WatchDog\ Timer/WDT_program.c 

OBJS += \
./MCAL/WatchDog\ Timer/WDT_program.o 

C_DEPS += \
./MCAL/WatchDog\ Timer/WDT_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/WatchDog\ Timer/WDT_program.o: ../MCAL/WatchDog\ Timer/WDT_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"MCAL/WatchDog Timer/WDT_program.d" -MT"MCAL/WatchDog\ Timer/WDT_program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


