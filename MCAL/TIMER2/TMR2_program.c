/*
 * TMR2_program.c
 *
 *  Created on: Apr 10, 2023
 *      Author: Ali Ehab
 */
#include  "../../LIB/BIT_MATH.h"
#include  "../../LIB/STD_TYPES.h"

#include "TMR2_interface.h"
#include "TMR2_private.h"
#include "TMR2_config.h"

void TIMER2_voidInit(void)
{
   /*Set Normal Mode*/
   CLR_BIT(TCCR2,WGM20);
   CLR_BIT(TCCR2,WGM21);

   /*Set CTC Mode*/
   SET_BIT(TCCR2, WGM21);
   CLR_BIT(TCCR2, WGM20);

   /*Set Prescalar Value*/
   CLR_BIT(TCCR2, CS20);
   SET_BIT(TCCR2, CS21);
   CLR_BIT(TCCR2, CS22);
}

void TIMER2_voidSetBusyWaitMS_OVFMode(u32 Copy_u32Time)
{
    CLR_BIT(TCCR2, CS20);
    SET_BIT(TCCR2, CS21);
    CLR_BIT(TCCR2, CS22);
    u32 Number_of_OVF;
    u32 Counter = 0;
    TCNT2 = 0x00;
    Number_of_OVF = ((u32)1000UL*Copy_u32Time) / 256UL;
    while (Counter < Number_of_OVF)
    {
        while(!GET_BIT(TIFR,TOV0));
        SET_BIT(TIFR,TOV0);
        Counter++;
    }

}

void TIMER2_voidSetBusyWaitMS_CTCMode(u32 Copy_u32Time)
{
    CLR_BIT(TCCR2, CS20);
    SET_BIT(TCCR2, CS21);
    CLR_BIT(TCCR2, CS22);
    TIMER2_voidSetCTCCompareMatchValue(250);
    u32 Number_of_OCF;
    u32 Counter = 0;
    TCNT2= 0x00;
    Number_of_OCF = ((u32)1000UL*Copy_u32Time) / 250UL;
    while (Counter < Number_of_OCF)
    {
        while(!GET_BIT(TIFR,OCF0));
        SET_BIT(TIFR,OCF0);
        Counter++;
    }
}

void TIMER2_voidDisableInterrupt(u8 Copy_u8Mode)
{

    if (Copy_u8Mode == NORMAL_MODE)
    {
        CLR_BIT(TIMSK, TOIE0);
    }
    else if (Copy_u8Mode == CTC_MODE)
    {
        CLR_BIT(TIMSK, OCIE0);
    }

}

void TIMER2_voidEnableInterrupt(u8 Copy_u8Mode)
{
    if (Copy_u8Mode == NORMAL_MODE)
    {
        SET_BIT(TIMSK, TOIE0);
    }
    else if (Copy_u8Mode == CTC_MODE)
    {
        SET_BIT(TIMSK, OCIE0);
    }
}
void TIMER2_voidSetCTCCompareMatchValue(u8 Copy_u8Value)
{
    OCR2 = Copy_u8Value;
}

void TIMER2_voidSetPreLoadValue(u8 Copy_u8Value)
{
    TCNT2 = Copy_u8Value;
}

