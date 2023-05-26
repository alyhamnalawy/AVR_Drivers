///*
// * ControlLEDPWM.c
// *
// *  Created on: Apr 10, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//#include <util/delay.h>
//int main(void)
//{
//	u16 Local_u8Iterator;
//	TMR0_voidinit();
//	DIO_SetPinDirection(DIO_PORTB,PIN3,OUTPUT);
//
//	while(1)
//	{
//		/*SET OCR VALUE*/
//		for(Local_u8Iterator=0;Local_u8Iterator<=255;Local_u8Iterator++)
//		{
//			TMR0_voidSetCTCCompareValue(Local_u8Iterator);
//			_delay_ms(10);
//		}
//		for(Local_u8Iterator=0;Local_u8Iterator<=255;Local_u8Iterator++)
//		{
//			TMR0_voidSetCTCCompareValue(255-Local_u8Iterator);
//			_delay_ms(10);
//		}
//	}
//	return 0;
//}
