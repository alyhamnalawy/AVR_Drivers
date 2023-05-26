/*
 * KeyPad_config.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Ali Ehab
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_


#define KPD_ROWS_PORT		DIO_PORTD
#define KPD_COLUMNS_PORT	DIO_PORTD

#define KPD_ROW0_PIN	PIN0
#define KPD_ROW1_PIN	PIN1
#define KPD_ROW2_PIN	PIN2
#define KPD_ROW3_PIN	PIN3

#define KPD_COLUMN0_PIN	PIN4
#define KPD_COLUMN1_PIN	PIN5
#define KPD_COLUMN2_PIN	PIN6
#define KPD_COLUMN3_PIN	PIN7

#define KPD_ROWS_NUM 	4
#define KPD_COLUMNS_NUM 4

#define KPD_NOT_PRESSED_VAL 255

#define KPD_ARR_VAL {{'7','8','9','/'},\
{'4','5','6','*'},\
{'1','2','3','-'},\
{'*','0','=','+'}}

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
