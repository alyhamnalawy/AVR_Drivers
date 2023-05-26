///*
// * ICU_SW.c
// *
// *  Created on: Apr 12, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../HAL/LCD/LCD_interface.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/GIE/GIE_interface.h"
//#include "../MCAL/EXTI/EXTI_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//#include "../MCAL/TIMER1/TMR1_interface.h"
//
//void ICU_SW(void);
//
//volatile u16 APP_u16Reading1;
//volatile u16 APP_u16Reading2;
//volatile u16 APP_u16Reading3;
//
//volatile u16 APP_u16OnTicks=0;
//volatile u16 APP_u16PeriodTicks=0;
//
//int main(void)
//{
//	DIO_SetPinDirection(DIO_PORTD,PIN2,INPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN3,OUTPUT);
//	LCD_voidinit();
//	TMR0_voidinit();
//	/*PERIOD TIME = 256US */
//	/*ON TIME = 50US*/
//	TMR0_voidSetCTCCompareValue(50);
//	EXTI_voidTriggerEdge(EXTI_INT0,RISING_EDGE);
//	EXTI_voidINT0SetCallBack(&ICU_SW);
//	EXTI_voidEnable(EXTI_INT0);
//	GIE_voidEnableGlobalInterrupt();
//	TIMER1_voidInit();
//	while(1)
//	{
//				/*POLLING ON ON TICKS AND PERIOD TICKS*/
//				while(APP_u16OnTicks==0||APP_u16PeriodTicks==0);
//				LCD_voidGotoXY(0,0);
//				LCD_voidSendString("P.T = ");
//				LCD_voidSendNumber(APP_u16PeriodTicks);
//				LCD_voidGotoXY(1,0);
//				LCD_voidSendString("O.T = ");
//				LCD_voidSendNumber(APP_u16OnTicks);
//	}
//	return 0;
//}
//
//void ICU_SW(void)
//{
//	static u8 Local_u8Counter=0;
//	Local_u8Counter++;
//	if(Local_u8Counter==1) //state 1
//	{
//		/*START TIMER 0*/
//		APP_u16Reading1=TIMER1_u8GetCounterValue();
//		EXTI_voidTriggerEdge(EXTI_INT0,FALLING_EDGE);
//	}
//	else if(Local_u8Counter==2)//state 2
//	{
//		/*READING 2 FOR ON TIME*/
//		APP_u16Reading2=TIMER1_u8GetCounterValue();
//		APP_u16OnTicks=APP_u16Reading2-APP_u16Reading1-1;
//	}
//	else if(Local_u8Counter==3)//state 3
//	{
//		/*READING 3*/
//		APP_u16Reading3=TIMER1_u8GetCounterValue();
//		/*PERIOD TICKS PERIOD TIME*/
//		APP_u16PeriodTicks=APP_u16Reading3-APP_u16Reading2-1;
//		EXTI_voidDisable(EXTI_INT0);
//		/*RESET THE COUNTER*/
//		Local_u8Counter=0;
//	}
//}
//
//
//
//
