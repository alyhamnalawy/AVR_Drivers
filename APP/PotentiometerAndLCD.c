///*
// * PotentiometerAndLED.c
// *
// *  Created on: Apr 6, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../HAL/LCD/LCD_interface.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/ADC/ADC_interface.h"
//#include <util/delay.h>
//
//int main(void)
//{
//	u8 Local_ADCReturnValue=0;
//	LCD_voidinit();
//	ADC_voidInit();
//	while(1)
//	{
//		Local_ADCReturnValue=ADC_u8StartConversion(ADC_CHANNEL_0);
//		LCD_voidSendString("ADC value = ");
//		LCD_voidGotoXY(0,12);
//		LCD_voidSendNumber(Local_ADCReturnValue);
//		_delay_ms(1000);
//		LCD_voidClearDisplay();
//	}
//}
