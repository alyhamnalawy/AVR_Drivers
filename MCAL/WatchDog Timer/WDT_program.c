/*
 * WatchDogTimer_program.c
 *
 *  Created on: Apr 12, 2023
 *      Author: Ali Ehab
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO_Driver/DIO_interface.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"

void WDT_Enable(void)
{
	SET_BIT(WDTCR,WDTCR_WDE);
}


void WDT_Sleep(u8 Copy_u8TimeOut)
{
	/* MASK (CLEAR) FIRST 3 BITS */
	WDTCR&=0b11111000;
	WDTCR|=Copy_u8TimeOut;
}
void WDT_Disable(void)
{
	/*DISABLE SEQUENCE*/
	WDTCR = (1<<WDTCR_WDTOE)|(1<<WDTCR_WDE);
	WDTCR=0;
}





