################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICES/portable/GCC/ATMega323/port.c 

OBJS += \
./SERVICES/portable/GCC/ATMega323/port.o 

C_DEPS += \
./SERVICES/portable/GCC/ATMega323/port.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICES/portable/GCC/ATMega323/%.o: ../SERVICES/portable/GCC/ATMega323/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


