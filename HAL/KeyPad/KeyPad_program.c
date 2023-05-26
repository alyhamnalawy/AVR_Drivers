/*
 * KeyPad.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Ali Ehab
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO_Driver/DIO_interface.h"
#include "KeyPad_interface.h"
#include "KeyPad_private.h"
#include "KeyPad_config.h"

void KPD_voidinit(void)
{
	/*SET ROWS PINS TO BE INPUT PULLUP*/
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,INPUT);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,INPUT);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,INPUT);
	DIO_SetPinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,INPUT);

	DIO_SetPinValue(KPD_ROWS_PORT,KPD_ROW0_PIN,PULLUP);
	DIO_SetPinValue(KPD_ROWS_PORT,KPD_ROW1_PIN,PULLUP);
	DIO_SetPinValue(KPD_ROWS_PORT,KPD_ROW2_PIN,PULLUP);
	DIO_SetPinValue(KPD_ROWS_PORT,KPD_ROW3_PIN,PULLUP);

	/*SET COLUMNS PINS TO OUTPUT HIGH*/
	DIO_SetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN0_PIN,OUTPUT);
	DIO_SetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN1_PIN,OUTPUT);
	DIO_SetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN2_PIN,OUTPUT);
	DIO_SetPinDirection(KPD_COLUMNS_PORT,KPD_COLUMN3_PIN,OUTPUT);

	DIO_SetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN0_PIN,HIGH);
	DIO_SetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN1_PIN,HIGH);
	DIO_SetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN2_PIN,HIGH);
	DIO_SetPinValue(KPD_COLUMNS_PORT,KPD_COLUMN3_PIN,HIGH);

}

u8 KPD_u8GetPressedKey(void)
{
	static u8 Local_u8KPDArray[KPD_ROWS_NUM][KPD_COLUMNS_NUM]=KPD_ARR_VAL;
	static u8 local_u8KPDColumnArray[KPD_COLUMNS_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowsArray[KPD_ROWS_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	u8 Local_u8ColumnIterator;
	u8 Local_u8RowIterator;
	u8 Local_u8RowValue;
	u8 Local_u8PressedKey=KPD_NOT_PRESSED_VAL;
	for(Local_u8ColumnIterator=0;Local_u8ColumnIterator<KPD_COLUMNS_NUM;Local_u8ColumnIterator++)
	{
		/*ACTIVATE A COLUMN, GROUND*/
		DIO_SetPinValue(KPD_COLUMNS_PORT,local_u8KPDColumnArray[Local_u8ColumnIterator],LOW);
		for(Local_u8RowIterator=0;Local_u8RowIterator<KPD_ROWS_NUM;Local_u8RowIterator++)
		{
			/*GET THE ROW VALUE*/
			Local_u8RowValue=DIO_u8GetPinValue(KPD_ROWS_PORT,Local_u8KPDRowsArray[Local_u8RowIterator]);
			if(Local_u8RowValue==LOW)
			{
				/*GET THE PRESSED KEY*/
				Local_u8PressedKey=Local_u8KPDArray[Local_u8RowIterator][Local_u8ColumnIterator];
				/*POLLING (BUSY WAIT) TILL THE KEY IS RELEASED*/
				while(Local_u8RowValue==LOW)
				{
					Local_u8RowValue=DIO_u8GetPinValue(KPD_ROWS_PORT,Local_u8KPDRowsArray[Local_u8RowIterator]);;
				}
				/*RETURN THE PRESSED KEY*/
				return Local_u8PressedKey;
			}
		}
		/*DEACTIVATE A COLUMN, (HIGH)*/
		DIO_SetPinValue(KPD_COLUMNS_PORT,local_u8KPDColumnArray[Local_u8ColumnIterator],HIGH);
	}
	/*RETURN IF NOT PRESSED*/
	return Local_u8PressedKey;
}
