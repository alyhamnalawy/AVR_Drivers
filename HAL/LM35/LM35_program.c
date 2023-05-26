/*
 * LM35_program.c
 *
 *  Created on: Apr 6, 2023
 *      Author: Ali Ehab
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_Driver/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"
#include "LM35_interface.h"


void LM35_init(lm35_sensor_t *Sensor)
{
	DIO_SetPinDirection(Sensor->Port_name,Sensor->ADC_Channel,INPUT);
	ADC_voidInit();
}

u8 LM35_read_temperature(lm35_sensor_t *Sensor)
{
	u8 Local_ReturnConversion=0,Local_u8ReturnValue;
	u16 Local_u16milliVoltValue=0;
	Local_ReturnConversion=ADC_u8StartConversion(Sensor->ADC_Channel);
	Local_u16milliVoltValue=((u32)Local_ReturnConversion*5000UL)/256UL;
	Local_u8ReturnValue= (Local_u16milliVoltValue/10);
	return Local_u8ReturnValue;

}
