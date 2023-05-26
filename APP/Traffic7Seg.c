///*
// * Traffic7Seg.c
// *
// *  Created on: Apr 2, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MATH.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../HAL/SEVEN_SEGMENT/Seven_Segment.c"
//#include <util/delay.h>
//
//void main(void)
//{
//    SEG7_voidInit(DIO_PORTA);
//    DIO_voidSetPinDirection(DIO_PORTA,PIN0,OUTPUT);
//    DIO_voidSetPinDirection(DIO_PORTA,PIN1,OUTPUT);
//    DIO_voidSetPinDirection(DIO_PORTA,PIN2,OUTPUT);
//
//    while(1)
//    {
//        DIO_voidSetPinValue(DIO_PORTA,PIN0,HIGH);
//		_delay_ms(10000);
//        DIO_voidSetPinValue(DIO_PORTA,PIN0,LOW);
//        DIO_voidSetPinValue(DIO_PORTA,PIN1,HIGH);
//		_delay_ms(3000);
//        DIO_voidSetPinValue(DIO_PORTA,PIN1,LOW);
//        DIO_voidSetPinValue(DIO_PORTA,PIN2,HIGH);
//		_delay_ms(10000);
//        DIO_voidSetPinValue(DIO_PORTA,PIN2,LOW);
//    }
//}
