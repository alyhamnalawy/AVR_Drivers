///*
// * PotentiometerAndTimer.c
// *
// *  Created on: Apr 10, 2023
// *      Author: Ali Ehab
// */
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/ADC/ADC_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//
//int main(void)
//{
//	u8 Local_u8ADCvalue;
//	TMR0_voidinit();
//	ADC_voidInit();
//	DIO_SetPinDirection(DIO_PORTB,PIN3,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN0,INPUT);
//	while(1)
//	{
//		Local_u8ADCvalue=ADC_u8StartConversion(ADC_CHANNEL_0);
//		TMR0_voidSetCTCCompareValue(Local_u8ADCvalue);
//	}
//	return 0;
//}
