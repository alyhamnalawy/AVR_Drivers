/******************************
 * Author:    Aly Ehab
 * Data:      26 Mar, 2023
 * Version:   v1
 * Compiler:  IMT STK
 ******************************/
#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define LED_ALL_OUT             0xff
#define FUNCTION_SET_COMMAND    0b00111000
#define DISPLAY_ON_OFF_COMMAND  0x0F
#define DISPLAY_CLEAR_MODE      0X01

#define FOUR_BIT_MODE   0
#define EIGHT_BIT_MODE  1

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif