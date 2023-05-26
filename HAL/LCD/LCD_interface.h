/******************************
 * Author:    Aly Ehab
 * Data:      26 Mar, 2023
 * Version:   v1
 * Compiler:  IMT STK
 ******************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidinit(void);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidClearDisplay(void);
void LCD_voidGotoXY(u8 Copy_u8XPos,u8 Copy_u8YPos);
void LCD_voidSendString(u8 *Copy_pu8StringArray);
void LCD_voidSendNumber(u32 Copy_u32UserInput);
void LCD_voidCustomCharacter(u8 *Copy_pu8CharacterArray,u8 Copy_u8PatternNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition);

#endif
