///*
// * SPI_Master.c
// *
// *  Created on: Apr 18, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//
//#include "../HAL/LCD/LCD_interface.h"
//
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/GIE/GIE_interface.h"
//#include "../MCAL/EXTI/EXTI_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//#include "../MCAL/SPI/SPI_interface.h"
//
//void Push_button(void);
//u8 Global_Flag=0;
//int main(void)
//{
//	u8 Local_u8TempData;
//	EXTI_voidINT0SetCallBack(&Push_button);
//	DIO_u8SetPortDirection(DIO_PORTA,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN0,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN1,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN2,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN4,INPUT);
//	DIO_SetPinValue(DIO_PORTB,PIN4,HIGH);
//	DIO_SetPinDirection(DIO_PORTB,PIN5,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN6,INPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN7,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTD,PIN2,INPUT);
//	LCD_voidinit();
//	GIE_voidEnableGlobalInterrupt();
//	EXTI_voidEnable(EXTI_INT0);
//	SPI_voidMasterInit();
//	while(1)
//	{
//		if(Global_Flag==1)
//		{
//			Local_u8TempData=SPI_u8SendReceive(255);
//			LCD_voidSendNumber(Local_u8TempData);
//			Global_Flag=0;
//		}
//	}
//	return 0;
//}
//void Push_button(void)
//{
//	Global_Flag=1;
//}
