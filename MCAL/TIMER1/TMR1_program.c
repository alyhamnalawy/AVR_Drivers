/*
 * TMR1_program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Ali Ehab
 */


#include  "../../LIB/BIT_MATH.h"
#include  "../../LIB/STD_TYPES.h"

#include "TMR1_interface.h"
#include "TMR1_private.h"
#include "TMR1_config.h"

static void (*ICU_NotifictionFunction)(void)=NULL;

void TIMER1_voidInit(void)
{
	/*NOTMAL MODE*/
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	//	/*Set Timer 1 in Mode 14 "Fast PWM with top value = ICR1" */
	//	CLR_BIT(TCCR1A,WGM10);
	//	SET_BIT(TCCR1A,WGM11);
	//	SET_BIT(TCCR1B,WGM12);
	//	SET_BIT(TCCR1B,WGM13);
	//
	//	/*Set non inverted Mode */
	//	SET_BIT(TCCR1A,COM1A1);
	//	CLR_BIT(TCCR1A,COM1A0);

	/*Set Prescalar To Be 8*/
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

}

void TIMER1_voidSetICRValue(u16 Copy_u16ICRValye)
{
	ICR1 = Copy_u16ICRValye;
}

void TIMER1_voidSetOCR1AValue(u16 Copy_u16OCR1A)
{
	OCR1A = Copy_u16OCR1A;
}
u8 TIMER1_u8GetCounterValue(void)
{
	return TCNT1;
}
u16 ICU_u16GetICRRegister(void)
{
	return ICR1;
}
void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal)
{
	switch(Copy_u8TriggerSignal)
	{
	case RISING_EDGE:
		SET_BIT(TCCR1B,ICES1);
		break;
	case FALLING_EDGE:
		CLR_BIT(TCCR1B,ICES1);
		break;
	}
}
void ICU_voidInterruptContol(u8 Copy_u8InterruptControl)
{
	switch(Copy_u8InterruptControl)
	{
	case ICU_ENABLE:
	SET_BIT(TIMSK,TICIE1);
	break;
	case ICU_DISABLE:
		CLR_BIT(TIMSK,TICIE1);
	break;
	}
}
void ICU_voidSetCallBack(void(*Notification)(void))
{
	ICU_NotifictionFunction=Notification;
}
void __vector_6(void)  __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_NotifictionFunction!=NULL)
	{
		ICU_NotifictionFunction();
	}
	else
	{
		//DO NOTHING
	}
}



