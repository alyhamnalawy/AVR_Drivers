///*
// * UART_TTL.c
// *
// *  Created on: Apr 16, 2023
// *      Author: Ali Ehab
// */
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/UART/UART_interface.h"
//
//
//int main(void)
//{
//	u8 Local_u8ReceivedData;
//	/*LED TO BE OUTPUT*/
//	DIO_SetPinDirection(DIO_PORTA,PIN0,OUTPUT);
//	/*SET TX PIN TO BE OUTPUT*/
//	DIO_SetPinDirection(DIO_PORTD,PIN0,OUTPUT);
//	/*RX PIN TO BE INPUT*/
//	DIO_SetPinDirection(DIO_PORTD,PIN1,INPUT);
//	UART_voidInit();
//	while(1)
//	{
//		UART_u8ReceiveDataSynchronous(&Local_u8ReceivedData);
//		UART_voidTransmitDataSynchronous(Local_u8ReceivedData);
//		if(Local_u8ReceivedData=='A')
//		{
//			DIO_SetPinValue(DIO_PORTA,PIN0,HIGH);
//		}
//		else if(Local_u8ReceivedData=='B')
//		{
//			DIO_SetPinValue(DIO_PORTA,PIN0,LOW);
//		}
//		else
//		{
//			//do nothing
//		}
//	}
//
//	return 0;
//}
//
