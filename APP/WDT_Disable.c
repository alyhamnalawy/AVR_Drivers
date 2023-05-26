///*
// * WDT_Disable.c
// *
// *  Created on: Apr 12, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/WatchDog Timer/WDT_interface.h"
//#include <util/delay.h>
//
//int main(void)
//{
//	WDT_Enable();
//	DIO_SetPinDirection(DIO_PORTD,PIN0,OUTPUT);
//	DIO_SetPinValue(DIO_PORTD,PIN0,HIGH);
//	_delay_ms(1000);
//	DIO_SetPinValue(DIO_PORTD,PIN0,LOW);
//	WDT_Sleep(WDT_SLEEP_16_3_MS);
//	WDT_Disable();
//	while(1);
//	return 0;
//}
