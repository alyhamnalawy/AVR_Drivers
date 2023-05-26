///*
// * Seven_Segment.c
// *
// *  Created on: Mar 25, 2023
// *      Author: Ali Ehab
// *      Common Cathode
// */
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MATH.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/DIO_Driver/DIO_Private.h"
//#include "util/delay.h"
//int main()
//{
//	DIO_SetPinDirection(DIO_PORTA,PIN0,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN1,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN2,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN3,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN4,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN5,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN6,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTA,PIN7,OUTPUT);
//	u8 i;
//	u8 arr[10]={0b00111111, /*0*/
//				0b00000110,	/*1*/
//				0b01011011,	/*2*/
//				0b01001111,	/*3*/
//				0b01100110,	/*4*/
//				0b01101101,	/*5*/
//				0b01111101,	/*6*/
//				0b00000111,	/*7*/
//				0b01111111,	/*8*/
//				0b01101111	/*9*/
//				};
//	while(1)
//	{
//		for(i=0;i<=9;i++)
//		{
//			SET_REG(PORTA,arr[i]);
//			_delay_ms(1000);
//		}
//	}
//
//	return 0;
//}
