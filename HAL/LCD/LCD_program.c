/******************************
 * Author:    Aly Ehab
 * Data:      26 Mar, 2023
 * Version:   v1
 * Compiler:  IMT STK
 ******************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../../MCAL/DIO_Driver/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"



void LCD_voidinit(void)
{
    #if LCD_INIT_MODE == EIGHT_BIT_MODE
    /*Initialize Data Port*/
    DIO_u8SetPortDirection(LCD_DATA_PORT,OUTPUT);
    //R/W->PB0
    //RS->PB1
    //EN->PB2
    DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_EN_PIN,OUTPUT);
    DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,OUTPUT);
    DIO_SetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,OUTPUT);
    //wait for more than 30 ms
    _delay_ms(40);
    //send function send command
    LCD_voidSendCommand(FUNCTION_SET_COMMAND);
    //send on off display command
    LCD_voidSendCommand(DISPLAY_ON_OFF_COMMAND);
    //send display clear command
    LCD_voidSendCommand(DISPLAY_CLEAR_MODE);

    #elif LCD_INIT_MODE == FOUR_BIT_MODE



    #else
	#error("warning")
    #endif
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    //SET RS TO BE IN SEND DATA MODE
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,HIGH);
    //SET RW TO WRITE THE DATA
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);

    DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Data);
     /*SEND ENABLE PULSE*/
    DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
    DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
    _delay_ms(2);
    DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);

}
static void LCD_voidSendCommand(u8 Copy_u8Command)
{
    //CLEAR RS TO BE IN COMMAND MODE
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,LOW);
    //CLEAR RW TO WRITE THE COMMAND
	DIO_SetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,LOW);

    DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Command);

    /*SEND ENABLE PULSE*/
    DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
    DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,HIGH);
    _delay_ms(2);
    DIO_SetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,LOW);
}
void LCD_voidClearDisplay(void)
{
    LCD_voidSendCommand(DISPLAY_CLEAR_MODE);
}
void LCD_voidGotoXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CharacterAddress;
	/*Calculate the address of the character on LCD*/
	if(Copy_u8XPos==0)
	{
		Local_u8CharacterAddress=Copy_u8YPos;
	}
	else if(Copy_u8XPos==1)
	{
		Local_u8CharacterAddress=0x40+Copy_u8YPos;
	}
	else
	{
		//Raise an error
	}
	//to set the most significant bit which is fixed
	SET_BIT(Local_u8CharacterAddress,7);
	/*SEND THE ADDRESS VARIABLE AS A COMMAND*/
	LCD_voidSendCommand(Local_u8CharacterAddress);
}
void LCD_voidSendString(u8 *Copy_pu8StringArray)
{
	u8 Local_u8LoopCounter=0;
	/*Lopp on the string till the null terminator*/
	while(Copy_pu8StringArray[Local_u8LoopCounter]!='\0')
	{
		LCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}
void LCD_voidSendNumber(u32 Copy_u32UserInput)
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
		LCD_voidSendData(Local_u8ArrayNumber[Local_s8LoopCounter]+'0');
		Local_s8LoopCounter--;
	}
}
void LCD_voidCustomCharacter(u8 *Copy_pu8CharacterArray,u8 Copy_u8PatternNumber,
		u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
	u8 Local_u8LoopCounter;
	u8 Local_u8CGRAMAddress=0;
	/*CALCULATE THE CGRAM ADDRESS*/
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;
	/*SET THE CGRAM THE 6TH BIT TO COMPLETE THE COMMAND FRAME FORMAT*/
	SET_BIT(Local_u8CGRAMAddress,6);
	LCD_voidSendCommand(Local_u8CGRAMAddress);
	for(Local_u8LoopCounter=0;Local_u8LoopCounter<8;Local_u8LoopCounter++)
	{
		/*SEND BYT FROM THE CHARACTER ARRAY TO THE CGRAM*/
		LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
	}
	/*SEND THE COMMAND TO SET THE DDRAM ADDRESS*/
	LCD_voidGotoXY(Copy_u8XPosition,Copy_u8YPosition);
	/*DISPLAY THE PATTER FROM CGRAM*/
	LCD_voidSendData(Copy_u8PatternNumber);
}


