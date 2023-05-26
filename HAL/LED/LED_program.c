/*
 * LED_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Ali Ehab
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO_Driver/DIO_interface.h"
#include "LED_interface.h"
void LED_voidInit(LED_t *LEDobj)
{
	DIO_SetPinDirection(LEDobj->LED_PORT,LEDobj->LED_PIN,OUTPUT);
}
void LED_voidLEDTurnON(LED_t *LEDobj)
{
	DIO_SetPinValue(LEDobj->LED_PORT,LEDobj->LED_PIN,HIGH);
}

void LED_voidLEDTurnOFF(LED_t *LEDobj)
{
	DIO_SetPinValue(LEDobj->LED_PORT,LEDobj->LED_PIN,LOW);
}

/*void LED_voidLEDToggle(LED_t *LEDobj)
{
	// reverse the state of pin
}*/
