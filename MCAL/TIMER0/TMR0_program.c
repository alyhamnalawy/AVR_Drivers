/*
 * TMR0_program.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Ali Ehab
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO_Driver/DIO_interface.h"
#include "../GIE/GIE_interface.h"

#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_config.h"

static void(*Global_pvOVFNotificationFunction)(void)=NULL;
static void(*Global_pvOCRNotificationFunction)(void)=NULL;

void TMR0_voidinit(void)
{
#if T0_MODE == Normal_Mode
	{
		CLR_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	}

#elif T0_MODE == PWM_Mode
	{
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	}

#elif T0_MODE == CTC_Mode
	{
		CLR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		OCR0  = T0_OCR_Value;
	}

#elif T0_MODE == FastPWM_Mode
	{
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	}

#endif

#if(T0_MODE == Normal_Mode && CompareOUTPUTMode == NO_OC0)
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == NO_OC0)
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}
#elif(T0_MODE == Normal_Mode && CompareOUTPUTMode == ToggleOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == ToggleOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}
#elif(T0_MODE == Normal_Mode && CompareOUTPUTMode == ClearOC0_OnComp)
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == ClearOC0_OnComp)
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == Normal_Mode && CompareOUTPUTMode == SetOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif(T0_MODE == CTC_Mode && CompareOUTPUTMode == SetOC0_OnComp)
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}




#elif  T0_MODE == PWM_Mode && CompOutputModePWM == No_OC0
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}
#elif  T0_MODE == FastPWM_Mode && CompOutputModePWM == No_OC0
	{
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);
	}

#elif  T0_MODE == PWM_Mode && CompOutputModePWM == Non_InvertedPWM
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif  T0_MODE == FastPWM_Mode && CompOutputModePWM == Non_InvertedPWM
	{
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#elif T0_MODE == PWM_Mode && CompOutputModePWM == InvertedPWM
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}
#elif T0_MODE == FastPWM_Mode && CompOutputModePWM == InvertedPWM
	{
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
	}

#endif

#if CLK_Pre == NoCLK
	{
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == NoPre
	{
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre8
	{
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre64
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre256
	{
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == Pre1024
	{
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#elif CLK_Pre == ExtSourceT0_FallingE
	{
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#elif CLK_Pre ExtSourceT0_RaisingE
	{
		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		SET_BIT(TCCR0,CS02);
	}

#endif
}
void TMR0_voidSetPreloadValue(u8 Copy_u8Value)
{
	TCNT0=Copy_u8Value;
}
void TMR0_voidSetCTCCompareValue(u8 Copy_u8Value)
{
	OCR0=Copy_u8Value;
}

void TMR0_voidEnableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode==NORMAL_MODE)
	{
		SET_BIT(TIMSK,TOIE0);
	}
	else if(Copy_u8Mode==CTC_MODE)
	{
		SET_BIT(TIMSK,OCIE0);
	}
}
void TMR0_voidDisableInterrupt(u8 Copy_u8Mode)
{
	if(Copy_u8Mode==NORMAL_MODE)
	{
		CLR_BIT(TIMSK,TOIE0);
	}
	else if(Copy_u8Mode==CTC_MODE)
	{
		CLR_BIT(TIMSK,OCIE0);
	}

}
void TMR0_voidNormalSetBusyWaitMS(u32 Copy_u32Time)
{
	u32 Local_u32NumberOVF;
	u32 Local_u32Counter=0;
	Local_u32NumberOVF=((u32)1000*Copy_u32Time)/256;
	while(Local_u32Counter<Local_u32NumberOVF)
	{
		while(!GET_BIT(TIFR,TOV0));
		Local_u32Counter++;
		SET_BIT(TIFR,TOV0);
	}

}
void TMR0_voidCTCSetBusyWaitMS(u32 Copy_u32Time)
{
	TMR0_voidSetCTCCompareValue(250);
	u32 Local_u32NumberOCF;
	u32 Local_u32Counter=0;
	//Local_u32NumberOCF=((1000 UL)*Copy_u32Time)/(250 UL);
	while(Local_u32Counter<4000)
	{
		while((GET_BIT(TIFR,OCF0))==0);
		Local_u32Counter++;
		SET_BIT(TIFR,OCF0);
	}
}
u8 TMR0_u8GetCounterValue(void)
{
	return TCNT0;
}
void TMR0_voidOVFCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOVFNotificationFunction=pvNotificationFunction;
}
void TMR0_voidCTCCallBack(void(*pvNotificationFunction)(void))
{
	Global_pvOCRNotificationFunction=pvNotificationFunction;
}
void __vector_10(void)  __attribute__((signal));
void __vector_10(void)
{
	if(Global_pvOCRNotificationFunction!=NULL)
	{
		Global_pvOCRNotificationFunction();
	}
}

void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{
	if(Global_pvOVFNotificationFunction!=NULL)
	{
		Global_pvOVFNotificationFunction();
	}
}


