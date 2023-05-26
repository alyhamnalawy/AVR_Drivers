///*
// * TMR0.c
// *
// *  Created on: Apr 9, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//
//#define F_CPU 	8000000UL
//
//int main(void)
//{
//	TMR0_voidinit();
//	DIO_SetPinDirection(DIO_PORTB,PIN7,OUTPUT);
//	while(1)
//	{
//		DIO_voidTogglePinValue(DIO_PORTB,PIN7);
//		TMR0_voidCTCSetBusyWaitMS(1000);
//	}
//	return 0;
//}
