///*
// * SPI.c
// *
// *  Created on: Apr 18, 2023
// *      Author: Ali Ehab
// */
//
//
///*
// * SPI.c
// *
// *  Created on: Apr 17, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//#include "../MCAL/SPI/SPI_interface.h"
//
//#define MASTER	0
//#define SLAVE	1
//
//void main(void)
//{
//#if MASTER
//	u8 Local_u8transmitData,Local_u8receiveData;
//	/*MOSI*/
//	DIO_SetPinDirection(DIO_PORTB,PIN5,OUTPUT);
//	/*MISO*/
//	DIO_SetPinDirection(DIO_PORTB,PIN6,INPUT);
//	/*CLOCK PIN*/
//	DIO_SetPinDirection(DIO_PORTB,PIN7,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN4,INPUT);
//	DIO_SetPinValue(DIO_PORTB,PIN4,HIGH);
//
//	SPI_voidMasterInit();
//	TMR0_voidinit();
//	//TMR0_voidCTCSetBusyWaitMS(100);
//	Local_u8transmitData=10;
//	SPI_u8SendReceive(Local_u8transmitData);
//	TMR0_voidCTCSetBusyWaitMS(500);
//	Local_u8transmitData=20;
//	SPI_u8SendReceive(Local_u8transmitData);
//	while(1)
//	{
//
//	}
//#elif SLAVE
//
//	/*MOSI*/
//	DIO_SetPinDirection(DIO_PORTA,PIN0,OUTPUT);
//	/*MISO*/
//	DIO_SetPinDirection(DIO_PORTB,PIN5,INPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN6,OUTPUT);
//	/*CLOCK PIN*/
//	DIO_SetPinDirection(DIO_PORTB,PIN7,INPUT);
//
//	SPI_voidSlaveInit();
//
//
//	u8 Local_u8Data;
//	while(1)
//		{
//		Local_u8Data=SPI_u8SendReceive(255);
//			if(Local_u8Data==10)
//			{
//				DIO_SetPinValue(DIO_PORTA,PIN0,HIGH);
//			}
//			else if(Local_u8Data==20)
//			{
//				DIO_SetPinValue(DIO_PORTA,PIN0,LOW);
//			}
//
//		}
//
//#endif
//
//}
