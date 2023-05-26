/*
 * Transistor_program.c
 *
 *  Created on: Apr 29, 2023
 *      Author: Ali Ehab
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO_Driver/DIO_interface.h"

#include "Transistor_interface.h"
#include "Transistor_private.h"
#include "Transistor_config.h"

void Transistor_voidConfigure(Transistor_t * Copy_TransistorName)
{
	DIO_SetPinDirection(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber,OUTPUT);
	switch(Copy_TransistorName -> Trans_Type)
	{
	case NPN:
		switch(Copy_TransistorName -> Trans_InitialState)
		{
		case Saturation:
			DIO_SetPinValue(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber,HIGH);
			break;
		case Cutoff:
			DIO_SetPinValue(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber,LOW);
			break;
		}
		break;
		case PNP:
			switch(Copy_TransistorName -> Trans_InitialState)
			{
			case Saturation:
				DIO_SetPinValue(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber,LOW);
				break;
			case Cutoff:
				DIO_SetPinValue()(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber,HIGH);
				break;
			}
			break;

	}
}

void Transistor_voidChangeTransistorState(Transistor_t * Copy_TransistorName, Transistor_State_t Copy_TransistorState)
{
	switch(Copy_TransistorName -> Trans_Type)
	{
	case NPN:
		switch(Copy_TransistorState)
		{
		case TRANSISTOR_SATURATION:
			DIO_SetPinValue(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber,HIGH);
			break;

		case TRANSISTOR_CUTOFF:
			DIO_SetPinValue(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber, LOW);
			break;
		}
		break;

		case PNP:
			switch(Copy_TransistorState)
			{
			case TRANSISTOR_SATURATION:
				DIO_SetPinValue(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber, LOW);
				break;

			case TRANSISTOR_CUTOFF:
				DIO_SetPinValue()(Copy_TransistorName->Trans_PortName,Copy_TransistorName->Trans_PinNumber,HIGH);
				break;
			}
			break;

	}
}

