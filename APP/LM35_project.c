///*
// * LM35_project.c
// *
// *  Created on: Apr 6, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../HAL/LCD/LCD_interface.h"
//#include "../HAL/LM35/LM35_interface.h"
//#include "../MCAL/ADC/ADC_interface.h"
//#include <util/delay.h>
//
//int main(void)
//{
//	u16 Local_ReadValue;
//	LCD_voidinit();
//	LM35_init(ADC_CHANNEL_0);
//	while(1)
//	{
//		Local_ReadValue=LM35_read_temperature(ADC_CHANNEL_0);
//		LCD_voidSendString("Temp Value = ");
//		LCD_voidGotoXY(0,12);
//		LCD_voidSendNumber(Local_ReadValue);
//		_delay_ms(1000);
//	}
//}
