################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICES/croutine.c \
../SERVICES/event_groups.c \
../SERVICES/list.c \
../SERVICES/queue.c \
../SERVICES/stream_buffer.c \
../SERVICES/tasks.c \
../SERVICES/timers.c 

OBJS += \
./SERVICES/croutine.o \
./SERVICES/event_groups.o \
./SERVICES/list.o \
./SERVICES/queue.o \
./SERVICES/stream_buffer.o \
./SERVICES/tasks.o \
./SERVICES/timers.o 

C_DEPS += \
./SERVICES/croutine.d \
./SERVICES/event_groups.d \
./SERVICES/list.d \
./SERVICES/queue.d \
./SERVICES/stream_buffer.d \
./SERVICES/tasks.d \
./SERVICES/timers.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICES/%.o: ../SERVICES/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


