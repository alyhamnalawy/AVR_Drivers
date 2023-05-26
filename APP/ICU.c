///*
// * ICU.c
// *
// *  Created on: Apr 12, 2023
// *      Author: Ali Ehab
// */
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../HAL/LCD/LCD_interface.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/GIE/GIE_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//#include "../MCAL/TIMER1/TMR1_interface.h"
//
//void ICU_HW(void);
//
//volatile u16 APP_u16Reading1;
//volatile u16 APP_u16Reading2;
//volatile u16 APP_u16Reading3;
//
//volatile u16 APP_u16OnTicks=0;
//volatile u16 APP_u16PeriodTicks=0;
//
//
//int main(void)
//{
//	DIO_SetPinDirection(DIO_PORTB,PIN3,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTD,PIN6,INPUT);
//	LCD_voidinit();
//	/*PERIOD TIME = 256US */
//	/*ON TIME = 50US*/
//	TMR0_voidSetCTCCompareValue(50);
//	/*TIMER 0 INITIALIZE*/
//	TMR0_voidinit();
//	/*SET THE SENSE SIGNAL TO BE RISING EDGE*/
//	ICU_voidSetTriggerSignal(RISING_EDGE);
//	/*SET THE ICU CALLBACK */
//	ICU_voidSetCallBack(&ICU_HW);
//	/*ENABLE ICU INTERRUPT*/
//	ICU_voidInterruptContol(ICU_ENABLE);
//	/*enable global interrupt*/
//	GIE_voidEnableGlobalInterrupt();
//	/*INITIALIZE TIMER 1*/
//	TIMER1_voidInit();
//
//	while(1)
//	{
//		/*POLLING ON ON TICKS AND PERIOD TICKS*/
//		while(APP_u16OnTicks==0||APP_u16PeriodTicks==0);
//		LCD_voidGotoXY(0,0);
//		LCD_voidSendString("P.T = ");
//		LCD_voidSendNumber(APP_u16PeriodTicks);
//		LCD_voidGotoXY(1,0);
//		LCD_voidSendString("O.T = ");
//		LCD_voidSendNumber(APP_u16OnTicks);
//	}
//
//	return 0;
//}
//void ICU_HW(void)
//{
//	static u8 Local_u8Counter=0;
//	Local_u8Counter++;
//	if(Local_u8Counter==1) //state 1
//	{
//		/*READ ICR1 REGISTER IN A VARIABLES*/
//		APP_u16Reading1=ICU_u16GetICRRegister();
//		ICU_voidSetTriggerSignal(FALLING_EDGE);
//	}
//	else if(Local_u8Counter==2)//state 2
//	{
//		/*READING 2*/
//		APP_u16Reading2=ICU_u16GetICRRegister();
//		APP_u16OnTicks=APP_u16Reading2-APP_u16Reading1-1;
//	}
//	else if(Local_u8Counter==3)//state 3
//	{
//		/*READING 3*/
//		APP_u16Reading3=ICU_u16GetICRRegister();
//		/*PERIOD TICKS*/
//		APP_u16PeriodTicks=APP_u16Reading3-APP_u16Reading2-1;
//
//		/*DISABLE ICU INTERRUPT*/
//		ICU_voidInterruptContol(ICU_DISABLE);
//		/*RESET THE COUNTER*/
//		Local_u8Counter=0;
//	}
//}
