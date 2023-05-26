/******************************
 * Author:    Aly Ehab
 * Data:      26 Mar, 2023
 * Version:   v1
 * Compiler:  GNU GCC
 ******************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/*options:
*DIO_PORTA
*DIO_PORTB
*DIO_PORTC
*DIO_PORTD
*/
#define LCD_DATA_PORT   DIO_PORTA

/*options:
*EIGHT_BIT_MODE
*FOUR_BIT_MODE
*/
#define LCD_INIT_MODE  EIGHT_BIT_MODE

#define LCD_CONTROL_PORT    DIO_PORTB
#define LCD_RW_PIN          PIN0
#define LCD_RS_PIN          PIN1
#define LCD_EN_PIN          PIN2

#endif
