//EXTI_program.c
/*
 * EXTI_program.c
 *
 *  Created on: Mar 29, 2023
 *      Author:  Aly Ehab
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../DIO_Driver/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/*GLOBAL POINTER TPO FUNCTION FOR INT0 EXTERNAL INTERRUPT*/
static void (*EXTI_pvoidNotificationFunction[3])(void)={NULL};

void EXTI_voidInitPinConnection(u8 Copy_u8InterruptNum)
{
	switch(Copy_u8InterruptNum)
	{
	case EXTI_INT0:
#if INT0_PIN_CONNECTION == INTERNAL_PULLUP
		DIO_SetPinDirection(EXTI0_PORT , EXTI0_PIN , INPUT);
		DIO_SetPinValue(EXTI0_PORT , EXTI0_PIN , HIGH);

#elif INT0_PIN_CONNECTION == EXTERNAL_PULLUP
		DIO_SetPinDirection(EXTI0_PORT , EXTI0_PIN , INPUT);

#elif INT0_PIN_CONNECTION == EXTERNAL_PULLDOWN
		DIO_SetPinDirection(EXTI0_PORT , EXTI0_PIN , INPUT);
#endif
		break;
	case EXTI_INT1:
#if INT1_PIN_CONNECTION == INTERNAL_PULLUP
		DIO_SetPinDirection(EXTI1_PORT , EXTI1_PIN , INPUT);
		DIO_SetPinValue(EXTI1_PORT , EXTI1_PIN , HIGH);

#elif INT1_PIN_CONNECTION == EXTERNAL_PULLUP
		DIO_SetPinDirection(EXTI1_PORT , EXTI1_PIN , INPUT);

#elif INT1_PIN_CONNECTION == EXTERNAL_PULLDOWN
		DIO_SetPinDirection(EXTI1_PORT , EXTI1_PIN , INPUT);
#endif
		break;

	case EXTI_INT2 :
#if INT2_PIN_CONNECTION == INTERNAL_PULLUP
		DIO_SetPinDirection(EXTI2_PORT , EXTI2_PIN , INPUT);
		DIO_SetPinValue(EXTI2_PORT , EXTI2_PIN , HIGH);

#elif INT2_PIN_CONNECTION == EXTERNAL_PULLUP
		DIO_SetPinDirection(EXTI2_PORT , EXTI2_PIN , INPUT);

#elif INT2_PIN_CONNECTION == EXTERNAL_PULLDOWN
		DIO_SetPinDirection(EXTI2_PORT , EXTI2_PIN , INPUT);
#endif
		break;
	}

}

void EXTI_voidTriggerEdge(u8 Copy_u8InterruptNum,u8 Copy_u8Edge)
{
	switch(Copy_u8InterruptNum)
	{
	case EXTI_INT0 :
		switch(Copy_u8Edge)
		{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		}
		break;

		case EXTI_INT1:
			switch(Copy_u8Edge){
			case LOW_LEVEL:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case ANY_LOGIC_CHANGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				CLR_BIT(MCUCR,MCUCR_ISC11);
				break;
			case FALLING_EDGE:
				CLR_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			case RISING_EDGE:
				SET_BIT(MCUCR,MCUCR_ISC10);
				SET_BIT(MCUCR,MCUCR_ISC11);
				break;
			}
			break;

			case EXTI_INT2 :
				switch(Copy_u8Edge){
				case FALLING_EDGE:
					CLR_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				case RISING_EDGE:
					SET_BIT(MCUCSR,MCUCSR_ISC2);
					break;
				}
				break;
	}
}
/************************************Enable/Disable functions***********************************/
void EXTI_voidEnable(u8 Copy_u8InterruptNum)
{
	switch(Copy_u8InterruptNum)
	{
	case EXTI_INT0:
		SET_BIT(GICR,GICR_INT0);
		break;
	case EXTI_INT1:
		SET_BIT(GICR,GICR_INT1);
		break;
	case EXTI_INT2:
		SET_BIT(GICR,GICR_INT2);
		break;
	}

}

void EXTI_voidDisable(u8 Copy_u8InterruptNum)
{
	switch(Copy_u8InterruptNum)
	{
	case EXTI_INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;
	case EXTI_INT1:
		CLR_BIT(GICR,GICR_INT1);
		break;
	case EXTI_INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;
	}
}


/*ISR FOR INT0*/
/*ISR DOESNT HAVE PROTOTYPE BECAUSE NO ONE WILL CALL IT*/

void EXTI_voidINT0SetCallBack(void(*Notificationfunction)(void))
{
	EXTI_pvoidNotificationFunction[0]=Notificationfunction;
}
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvoidNotificationFunction[0]!=NULL)
	{
		EXTI_pvoidNotificationFunction[0]();
	}
	else
	{
		/*DO NOTHING IF THE USER DIDNT CALL THE FUNCTION*/
	}

}
/*INT1*/
void EXTI_voidINT1SetCallBack(void(*Notificationfunction)(void))
{
	EXTI_pvoidNotificationFunction[1]=Notificationfunction;
}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvoidNotificationFunction[1]!=NULL)
	{
		EXTI_pvoidNotificationFunction[1]();
	}
	else
	{
		/*DO NOTHING IF THE USER DIDNT CALL THE FUNCTION*/
	}

}
/*INT2*/
void EXTI_voidINT2SetCallBack(void(*Notificationfunction)(void))
{
	EXTI_pvoidNotificationFunction[2]=Notificationfunction;
}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvoidNotificationFunction[2]!=NULL)
	{
		EXTI_pvoidNotificationFunction[2]();
	}
	else
	{
		/*DO NOTHING IF THE USER DIDNT CALL THE FUNCTION*/
	}

}
