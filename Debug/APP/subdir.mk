################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Calculator.c \
../APP/ControlLEDPWM.c \
../APP/ICU.c \
../APP/ICU_SW.c \
../APP/KPD.c \
../APP/LCD.c \
../APP/LEDString.c \
../APP/LM35_project.c \
../APP/PotentiometerAndLCD.c \
../APP/PotentiometerAndLED.c \
../APP/PotentiometerAndTimer.c \
../APP/RTOSMain.c \
../APP/RTOS_main.c \
../APP/SPI.c \
../APP/SPI_Master.c \
../APP/SPI_Slave.c \
../APP/TMR0.c \
../APP/Toggle_LED_ISR.c \
../APP/Traffic7Seg.c \
../APP/UART_TTL.c \
../APP/WDT_Disable.c \
../APP/WDT_Sleep.c \
../APP/main.c 

OBJS += \
./APP/Calculator.o \
./APP/ControlLEDPWM.o \
./APP/ICU.o \
./APP/ICU_SW.o \
./APP/KPD.o \
./APP/LCD.o \
./APP/LEDString.o \
./APP/LM35_project.o \
./APP/PotentiometerAndLCD.o \
./APP/PotentiometerAndLED.o \
./APP/PotentiometerAndTimer.o \
./APP/RTOSMain.o \
./APP/RTOS_main.o \
./APP/SPI.o \
./APP/SPI_Master.o \
./APP/SPI_Slave.o \
./APP/TMR0.o \
./APP/Toggle_LED_ISR.o \
./APP/Traffic7Seg.o \
./APP/UART_TTL.o \
./APP/WDT_Disable.o \
./APP/WDT_Sleep.o \
./APP/main.o 

C_DEPS += \
./APP/Calculator.d \
./APP/ControlLEDPWM.d \
./APP/ICU.d \
./APP/ICU_SW.d \
./APP/KPD.d \
./APP/LCD.d \
./APP/LEDString.d \
./APP/LM35_project.d \
./APP/PotentiometerAndLCD.d \
./APP/PotentiometerAndLED.d \
./APP/PotentiometerAndTimer.d \
./APP/RTOSMain.d \
./APP/RTOS_main.d \
./APP/SPI.d \
./APP/SPI_Master.d \
./APP/SPI_Slave.d \
./APP/TMR0.d \
./APP/Toggle_LED_ISR.d \
./APP/Traffic7Seg.d \
./APP/UART_TTL.d \
./APP/WDT_Disable.d \
./APP/WDT_Sleep.d \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


