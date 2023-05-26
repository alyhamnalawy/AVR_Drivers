/*
 * UART_program.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Ali Ehab
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO_Driver/DIO_interface.h"
#include "../GIE/GIE_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

static void(*Global_pRXDataCompleteNotificationFunction)(void)=NULL;
static void(*Global_pTXDataCompleteNotificationFunction)(void)=NULL;

void UART_voidInit(void)
{
	u8 Local_u8UCSRCTemp=0;

	/*ASYNCHRONOUS MODE*/
	CLR_BIT(Local_u8UCSRCTemp, UCSRC_UMSEL);

	/*ENABLE TX CIRCUIT AND RX CIRCUIT*/
#if TX_MODE == ENABLE
	SET_BIT(UCSRB,UCSRB_TEXEN);
#elif TX_MODE == DISABLE
	CLR_BIT(UCSRB,UCSRB_TEXEN);
#endif
#if RX_MODE == ENABLE
	SET_BIT(UCSRB,UCSRB_REXEN);
#elif RX_MODE == DISABLE
	CLR_BIT(UCSRB,UCSRB_REXEN);
#endif

	/*SET THE DATA SIZE TO BE 8*/
#if BIT_DATA_SIZE == BIT_SIZE_EIGHT
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCTemp,UCSRB_UCSZ2);
#elif BIT_DATA_SIZE==BIT_SIZE_FIVE
	CLR_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCTemp,UCSRB_UCSZ2);
#elif BIT_DATA_SIZE==BIT_SIZE_SIX
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCTemp,UCSRB_UCSZ2);
#elif BIT_DATA_SIZE==BIT_SIZE_SEVEN
	CLR_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UCSZ1);
	CLR_BIT(Local_u8UCSRCTemp,UCSRB_UCSZ2);

#endif

	/*DSIABLE PARITY*/
#if PARITY_MODE == PARITY_MODE_DISABLED
	CLR_BIT(Local_u8UCSRCTemp,UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRCTemp,UCSRC_UPM1);

#elif PARITY_MODE == PARITY_MODE_EVEN
	CLR_BIT(UCSRC,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UPM1);
#elif PARITY_MODE == PARITY_MODE_ODD
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UPM0);
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UPM1);
#endif

	/*STOP BIT TO BE ONE BIT*/
#if STOP_BIT_MODE == STOP_BIT_ONE
	CLR_BIT(Local_u8UCSRCTemp,UCSRC_USBS);

#elif STOP_BIT_MODE == STOP_BIT_TWO
	SET_BIT(Local_u8UCSRCTemp,UCSRC_USBS);
#endif


	/*SET THE UART REGISTER SELECT BIT TO WRITE ON UCSRC*/
	SET_BIT(Local_u8UCSRCTemp,UCSRC_UMSEL);
	UCSRC=Local_u8UCSRCTemp;

	/*DISABLE DOUBLE SPEED MODE*/
	CLR_BIT(UCSRA,UCSRA_U2X);


	/*CLEAR THE UART REGISTER SELECT BIT TO WRITE ON UBRRH*/
	CLR_BIT(UBRRH,UBRRH_URSEL);
	UBRRH=0;

	/*BAUD RATE TO BE 9600BPS*/
	UBRRL = BAUD_RATE_NORMAL;
	UBRRH = (BAUD_RATE_NORMAL >> 8);


}
void UART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
	/*MAKE SURE UDR REGISTER IS EMPTY*/
	while(GET_BIT(UCSRA,UCSRA_UDRE)==0);

	UDR=Copy_u8Data;

	/*CHECK IF THE TRANMISSION IS COMPLETE*/
	while(GET_BIT(UCSRA,UCSRA_TXC)==0);
	/*CLEAR THE FLAG*/
	SET_BIT(UCSRA,UCSRA_TXC);
}

void UART_u8ReceiveDataSynchronous(u8 *Copy_pu8ReceiveData)
{
	/*POLLING UNTIL THE RECEIVE IS COMPLETE*/
	while(GET_BIT(UCSRA,UCSRA_RXC)==0);

	/*GET THE RECEIVED DATA*/
	*Copy_pu8ReceiveData=UDR;
}

void UART_voidSendString(u8 *Copy_pu8StringArray)
{
	u8 Local_u8LoopCounter=0;
	while(Copy_pu8StringArray[Local_u8LoopCounter]!='\0')
	{
		UART_voidTransmitDataSynchronous(Copy_pu8StringArray[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}

void UART_voidSendNumber(u32 Copy_u32UserInput)
{
	u8 Local_u8ArrayNumber[10];
	s8 Local_s8LoopCounter=0;
	while(Copy_u32UserInput!=0)
	{
		Local_u8ArrayNumber[Local_s8LoopCounter]=Copy_u32UserInput%10;
		Copy_u32UserInput/=10;
		Local_s8LoopCounter++;
	}
	Local_s8LoopCounter--;
	while(Local_s8LoopCounter>=0)
	{
		UART_voidTransmitDataSynchronous(Local_u8ArrayNumber[Local_s8LoopCounter]+'0');
		Local_s8LoopCounter--;
	}
}
void UART_RXInterruptEnable(void)
{
	SET_BIT(UCSRB,UCSRB_RXCIE);
}
void UART_TXInterruptEnable(void)
{
	SET_BIT(UCSRB,UCSRB_TXCIE);
}
void UART_voidRXCompleteCallBack(void(*pvNotificationFunction)(void))
{
	Global_pRXDataCompleteNotificationFunction=pvNotificationFunction;
}
void UART_voidTXCompleteCallBack(void(*pvNotificationFunction)(void))
{
	Global_pTXDataCompleteNotificationFunction=pvNotificationFunction;
}

void __vector_13(void)  __attribute__((signal));
void __vector_13(void)
{
	if(Global_pRXDataCompleteNotificationFunction!=NULL)
	{
		Global_pRXDataCompleteNotificationFunction();
	}
}

void __vector_15(void)  __attribute__((signal));
void __vector_15(void)
{
	if(Global_pTXDataCompleteNotificationFunction!=NULL)
	{
		Global_pTXDataCompleteNotificationFunction();
	}
}

