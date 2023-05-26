/*
 * DIO_Program.c
 *
 *  Created on: Mar 22, 2023
 *      Author: Ali Ehab
 */
/******************************
 * Author:    Aly Ehab
 * Data:      25 Mar, 2023
 * Version:   v1
 * Compiler:  IMT STK
 ******************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_Private.h"
#include "DIO_config.h"



void DIO_SetPinDirection(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8Direction)
{
	switch(Copy_u8PortName)
	{
	case DIO_PORTA:
		if(Copy_u8Direction==OUTPUT)
		{
			SET_BIT(DDRA,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction==INPUT)
		{
			CLR_BIT(DDRA,Copy_u8PinNumber);
		}
		else
		{

		}
		break;
	case DIO_PORTB:
		if(Copy_u8Direction==OUTPUT)
		{
			SET_BIT(DDRB,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction==INPUT)
		{
			CLR_BIT(DDRB,Copy_u8PinNumber);
		}
		else
		{

		}
		break;
	case DIO_PORTC:
		if(Copy_u8Direction==OUTPUT)
		{
			SET_BIT(DDRC,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction==INPUT)
		{
			CLR_BIT(DDRC,Copy_u8PinNumber);
		}
		else
		{

		}
		break;
	case DIO_PORTD:
		if(Copy_u8Direction==OUTPUT)
		{
			SET_BIT(DDRD,Copy_u8PinNumber);
		}
		else if(Copy_u8Direction==INPUT)
		{
			CLR_BIT(DDRD,Copy_u8PinNumber);
		}
		else
		{
			//DO NOTHING
		}
		break;
	default:
		//DO NOTHING
		break;

	}
}
void DIO_SetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8Value)
{
	switch(Copy_u8PortName)
	{
	case DIO_PORTA:
		switch(Copy_u8Value)
		{
		case LOW:
			CLR_BIT(PORTA,Copy_u8PinNumber);
			break;
		case HIGH:
			SET_BIT(PORTA,Copy_u8PinNumber);
			break;
		}
		break;
		case DIO_PORTB:
			switch(Copy_u8Value)
			{
			case LOW:
				CLR_BIT(PORTB,Copy_u8PinNumber);
				break;
			case HIGH:
				SET_BIT(PORTB,Copy_u8PinNumber);
				break;
			}
			break;
			case DIO_PORTC:
				switch(Copy_u8Value)
				{
				case LOW:
					CLR_BIT(PORTC,Copy_u8PinNumber);
					break;
				case HIGH:
					SET_BIT(PORTC,Copy_u8PinNumber);
					break;
				}
				break;
				case DIO_PORTD:
					switch(Copy_u8Value)
					{
					case LOW:
						CLR_BIT(PORTD,Copy_u8PinNumber);
						break;
					case HIGH:
						SET_BIT(PORTD,Copy_u8PinNumber);
						break;
					}
					break;
					default:
						//do nothing
						break;
	}
}
void DIO_voidTogglePinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{

	switch (Copy_u8PortName)
	{
	case DIO_PORTA : TOGGLE_BIT( PORTA ,Copy_u8PinNumber ); break ;
	case DIO_PORTB : TOGGLE_BIT( PORTB ,Copy_u8PinNumber ); break ;
	case DIO_PORTC : TOGGLE_BIT( PORTC ,Copy_u8PinNumber ); break ;
	case DIO_PORTD : TOGGLE_BIT( PORTD ,Copy_u8PinNumber ); break ;
	}

}
void DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	//u8 Local_u8ErrorState=TRUE;
	switch(Copy_u8Port)
	{
	case DIO_PORTA: PORTA= Copy_u8Value; break;
	case DIO_PORTB: PORTB= Copy_u8Value; break;
	case DIO_PORTC: PORTC= Copy_u8Value; break;
	case DIO_PORTD: PORTD= Copy_u8Value; break;
	default: /*Local_u8ErrorState=FALSE;*/ break;
	}
	//return Local_u8ErrorState;
}
void DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	//u8 Local_u8ErrorState=TRUE;
	switch(Copy_u8Port)
	{
	case DIO_PORTA: DDRA= Copy_u8Direction; break;
	case DIO_PORTB: DDRB= Copy_u8Direction; break;
	case DIO_PORTC: DDRC= Copy_u8Direction; break;
	case DIO_PORTD: DDRD= Copy_u8Direction; break;
	default: /*Local_u8ErrorState=FALSE;*/  break;
	}
	//return Local_u8ErrorState;
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue;
	switch(Copy_u8PortName)
	{
	case DIO_PORTA:
		Local_u8PinValue=GET_BIT(PINA,Copy_u8PinNumber);
		break;
	case DIO_PORTB:
		Local_u8PinValue=GET_BIT(PINB,Copy_u8PinNumber);
		break;
	case DIO_PORTC:
		Local_u8PinValue=GET_BIT(PINC,Copy_u8PinNumber);
		break;
	case DIO_PORTD:
		Local_u8PinValue=GET_BIT(PIND,Copy_u8PinNumber);
		break;
	default:
		break;
	}
	return Local_u8PinValue;
}



