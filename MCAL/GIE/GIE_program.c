/*
 * interrupt_program.c
 *
 *  Created on: Mar 29, 2023
 *      Author: Ali Ehab
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_voidEnableGlobalInterrupt(void)
{
	SET_BIT(SREG,SREG_BIT7);
}
void GIE_voidDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG,SREG_BIT7);
}
