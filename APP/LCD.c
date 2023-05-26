///*
// * LCD.c
// *
// *  Created on: Mar 26, 2023
// *      Author: Ali Ehab
// */
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../HAL/LCD/LCD_interface.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include <util/delay.h>
//
//int main(void)
//{
//	LCD_voidinit();
//	while(1)
//	{
////		LCD_voidGotoXY(0,0);
////		LCD_voidSendData('A');
////		_delay_ms(1000);
////		LCD_voidClearDisplay();
////
////		LCD_voidGotoXY(0,1);
////		LCD_voidSendData('A');
////		_delay_ms(1000);
////		LCD_voidClearDisplay();
////
////		LCD_voidGotoXY(1,1);
////		LCD_voidSendData('A');
////		_delay_ms(1000);
////		LCD_voidClearDisplay();
////
////		LCD_voidGotoXY(1,0);
////		LCD_voidSendData('A');
////		_delay_ms(1000);
////		LCD_voidClearDisplay();
//		u8 arr1[8]={ 0x0E,
//				  0x0E,
//				  0x04,
//				  0x0E,
//				  0x15,
//				  0x04,
//				  0x0A,
//				  0x11};
//		u8 arr2[8]={ 0x0E,
//				  0x0E,
//				  0x05,
//				  0x0E,
//				  0x14,
//				  0x04,
//				  0x0A,
//				  0x11};
//		u8 arr3[8]={ 0x0E,
//				  0x0E,
//				  0x04,
//				  0x1E,
//				  0x1D,
//				  0x04,
//				  0x0A,
//				  0x11};
//		u8 arr4[8]={ 0x0E,
//				  0x0E,
//				  0x04,
//				  0x06,
//				  0x1D,
//				  0x1C,
//				  0x0A,
//				  0x11};
//		/* the elements inside the array from https://maxpromer.github.io/LCD-Character-Creator/ */
//		LCD_voidSendString("my name is aly");
//		LCD_voidCustomCharacter(arr1,0,0,15);
//		_delay_ms(1000);
//		LCD_voidCustomCharacter(arr2,0,0,15);
//		_delay_ms(1000);
//		LCD_voidClearDisplay();
//		LCD_voidSendString("i can play football");
//		LCD_voidCustomCharacter(arr3,0,1,15);
//		_delay_ms(1000);
//		LCD_voidCustomCharacter(arr4,0,1,15);
//		_delay_ms(3000);
//	}
//	return 0;
//
//}
