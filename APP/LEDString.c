///*
// * LEDString.c
// *
// *  Created on: Apr 1, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/BIT_MATH.h"
//#include <util/delay.h>
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//
//void main(void)
//{
//	DIO_SetPinDirection(DIO_PORTA, OUTPUT);
//
//	DIO_SetPinDirection(DIO_PORTD, PIN0, INPUT);
//	DIO_SetPinDirection(DIO_PORTD, PIN1, INPUT);
//	DIO_SetPinDirection(DIO_PORTD, PIN2, INPUT);
//	u8 Local_u8SwitchValue;
//	u8 Local_u8LEDStringValue;
//	u8 Local_u8LEDStringRightNibble;
//	u8 Local_u8LEDStringLeftNibble;
//
//	u8 Local_u8Snake = 0;
//	u8 Local_u8Counter = 0;
//
//	u8 Local_u8Flag = 'L';
//	u8 Local_u8CD = 'C';
//
//
//
//	while(1)
//	{
//		DIO_u8GetPinValue(DIO_PORTD, &Local_u8SwitchValue);
//
//		switch (Local_u8SwitchValue & 0x07)
//		{
//		case 0:
//			DIO_voidTogglePinValue(DIO_PORTA);
//			_delay_ms(500);
//			break;
//
//		case 1:
//			if(Local_u8LEDStringValue == 0)
//			{
//				Local_u8LEDStringValue = 1;
//			}
//			DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//			Local_u8LEDStringValue = Local_u8LEDStringValue << 1;
//
//			_delay_ms(250);
//			break;
//
//		case 2:
//			if(Local_u8LEDStringValue == 0)
//			{
//				Local_u8LEDStringValue = 128;
//			}
//			DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//			Local_u8LEDStringValue = Local_u8LEDStringValue >> 1;
//
//			_delay_ms(250);
//			break;
//
//		case 3:
//			if(Local_u8LEDStringRightNibble > 15 || Local_u8LEDStringRightNibble == 0)
//			{
//				Local_u8LEDStringRightNibble = 1;
//			}
//			if(Local_u8LEDStringLeftNibble < 16 || Local_u8LEDStringLeftNibble == 0)
//			{
//				Local_u8LEDStringLeftNibble = 128;
//			}
//			Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
//			DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//			Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble << 1);
//			Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble >> 1);
//			_delay_ms(300);
//			break;
//
//		case 4:
//			if(Local_u8LEDStringRightNibble == 0)
//			{
//				Local_u8LEDStringRightNibble = 8;
//			}
//			if(Local_u8LEDStringLeftNibble == 0)
//			{
//				Local_u8LEDStringLeftNibble = 16;
//			}
//			Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
//			DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//			Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble >> 1);
//			Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble << 1);
//			_delay_ms(300);
//			break;
//
//		case 5:
//			switch (Local_u8Flag)
//			{
//			case 'L':
//				if(Local_u8LEDStringValue == 0)
//				{
//					Local_u8LEDStringValue = 1;
//				}
//				DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//				Local_u8LEDStringValue = Local_u8LEDStringValue << 1;
//				if(Local_u8LEDStringValue == 128)
//				{
//					Local_u8Flag = 'R'; /* Shift Right */
//				}
//				break;
//			case 'R':
//				if(Local_u8LEDStringValue == 0)
//				{
//					Local_u8LEDStringValue = 128;
//				}
//				DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//				Local_u8LEDStringValue = Local_u8LEDStringValue >> 1;
//				if(Local_u8LEDStringValue == 1)
//				{
//					Local_u8Flag = 'L';
//				}
//				break;
//
//			default:
//				break;
//			}
//			_delay_ms(250);
//			break;
//
//			case 6:
//				if(Local_u8LEDStringValue == 0)
//				{
//					Local_u8Snake |= (1<<Local_u8Counter);
//					Local_u8LEDStringValue = Local_u8Snake;
//					Local_u8Counter++;
//				}
//				DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//				Local_u8LEDStringValue = Local_u8LEDStringValue << 1;
//
//				_delay_ms(250);
//				break;
//
//			case 7:
//				switch (Local_u8CD)
//				{
//				case 'C':
//					if(Local_u8LEDStringRightNibble > 15 || Local_u8LEDStringRightNibble == 0)
//					{
//						Local_u8LEDStringRightNibble = 1;
//					}
//					if(Local_u8LEDStringLeftNibble < 16 || Local_u8LEDStringLeftNibble == 0)
//					{
//						Local_u8LEDStringLeftNibble = 128;
//					}
//					Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
//					DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//					Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble << 1);
//					Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble >> 1);
//					if(Local_u8LEDStringRightNibble == 8)
//					{
//						Local_u8CD = 'D';
//					}
//					break;
//
//				case 'D':
//					if(Local_u8LEDStringRightNibble == 0)
//					{
//						Local_u8LEDStringRightNibble = 8;
//					}
//					if(Local_u8LEDStringLeftNibble == 0)
//					{
//						Local_u8LEDStringLeftNibble = 16;
//					}
//					Local_u8LEDStringValue = (Local_u8LEDStringRightNibble & 0x0F) | (Local_u8LEDStringLeftNibble & 0xF0);
//					DIO_u8SetPortValue(DIO_PORTA, ~Local_u8LEDStringValue);
//					Local_u8LEDStringRightNibble = (Local_u8LEDStringRightNibble >> 1);
//					Local_u8LEDStringLeftNibble = (Local_u8LEDStringLeftNibble << 1);
//					if(Local_u8LEDStringRightNibble == 1)
//					{
//						Local_u8CD = 'C'; /* Converging */
//					}
//					break;
//
//				default:
//					break;
//				}
//
//				_delay_ms(300);
//				break;
//
//				default:
//					break;
//		}
//
//	}
//}
