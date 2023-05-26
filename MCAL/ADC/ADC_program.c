/*
 * ADC_program.c
 *
 *  Created on: Mar 30, 2023
 *      Author: Ali Ehab
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO_Driver/DIO_interface.h"
#include "../GIE/GIE_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void (*ADC_pvoidNotificatioFunction)(void)=NULL;
volatile u16 ADC_u16DigitalResult=0;

void ADC_voidInit(void)
{
	/*ADJUST RESULT*/
#if ADC_ADJUST_RESULT==RIGHT_ADJUST
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#elif	ADC_ADJUST_RESULT==LEFT_ADJUST
	SET_BIT(ADMUX,ADMUX_ADLAR);
#else
#error("error, ADC_ADJUST_RESULT Configuration error")
#endif


	/*VOLTAGE REF ADJUSTMENT*/
	ADMUX = ADMUX& REF_SEL_BIT_MASK;
	ADMUX = ADMUX|AREF;
	//#if ADC_REFERENCE_SELECTION==AREF
	//	CLR_BIT(ADMUX,ADMUX_REFS0);
	//	CLR_BIT(ADMUX,ADMUX_REFS1);
	//#elif	ADC_REFERENCE_SELECTION==AVCC
	//	SET_BIT(ADMUX,ADMUX_REFS0);
	//	CLR_BIT(ADMUX,ADMUX_REFS1);
	//#elif ADC_REFERENCE_SELECTION==INTERNAL_2
	//	SET_BIT(ADMUX,ADMUX_REFS0);
	//	SET_BIT(ADMUX,ADMUX_REFS1);
	//#else
	//#error("ADC_REFERENCE_SELECTION Error")
	//#endif

	/*ADC INTERRUPT*/
#if ADC_INTERRUPT_STATUS==ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADIE);
#elif ADC_INTERRUPT_STATUS==DISABLE
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
#else
#error("ADC_INTERRUPT_STATUS Error")
#endif
	/*ADC ENABLE*/
#if ADC_ENABLE==ENABLE
	SET_BIT(ADCSRA, ADCSRA_ADEN);
#elif ADC_ENABLE==DISABLE
	CLR_BIT(ADCSRA, ADCSRA_ADEN);
#else
#error("ADC_ENABLE Error")
#endif


	/*PRESCALER SELCTION*/
	ADCSRA&=pre_SEL_BIT_MAK;
	ADCSRA|=ADC_PRESCALER_SELCTION;
}

void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus)
{
	switch(Copy_u8InterruptStatus)
	{
	case DISABLE:
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
		break;
	case ENABLE:
		SET_BIT(ADCSRA,ADCSRA_ADIE);
		break;
	default:
		/*Do Nothing*/
		break;
	}
}

u8 ADC_u8StartConversion(u8 Copy_u8ChannelName) //POLLING MECHANISM
{
	/*SET CHANNEL OF ADC*/
	ADMUX&=CHANNEL_SELCTION_MASK;
	ADMUX|=Copy_u8ChannelName;

	/*START ADC CONVERT THE INPUT ANALOG SIGNAL*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*POLLING TILL THE FLAG IS RAISED*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))!=FALSE);

	/*CLEAR THE FLAG BY SETTING IT TO ONE*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADCH;
}


void ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelName,void (*NotifiFunction)(void))
{
	/*SET CHANNEL OF ADC*/
	ADMUX&=CHANNEL_SELCTION_MASK;
	ADMUX|=Copy_u8ChannelName;

	/*SET CALL BACK FUUCNTION*/


	/*START ADC CONVERT THE INPUT ANALOG SIGNAL*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

}
void __vector__16(void) __attribute__((signal));
void __vector__16(void)
{
	ADC_voidInterruptControl(DISABLE);
	ADC_u16DigitalResult=ADCH;
	if(ADC_pvoidNotificatioFunction!=NULL)
	{
		ADC_pvoidNotificatioFunction();
	}
	else
	{
		//DO NOTHING
	}
	ADC_voidInterruptControl(ENABLE);
}









