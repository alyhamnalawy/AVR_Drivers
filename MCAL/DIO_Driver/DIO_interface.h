/*
 * DIO_init.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Ali Ehab
 */

#ifndef DIO_INIT_H_
#define DIO_INIT_H_

#define INPUT  	        0
#define OUTPUT 	        1

#define LOW		        0
#define HIGH 	        1

#define DIO_PORTA	    0
#define DIO_PORTB	    1
#define DIO_PORTC	    2
#define DIO_PORTD	    3

#define PIN0	        0
#define PIN1	        1
#define PIN2	        2
#define PIN3	        3
#define PIN4	        4
#define PIN5	        5
#define PIN6	        6
#define PIN7	        7

#define PULLUP          0
#define NO_PULLUP        1

void DIO_SetPinDirection(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8Direction);
void DIO_SetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8Value);
void DIO_voidTogglePinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber);
void DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
u8 DIO_u8GetPinValue(u8 Copy_u8PortName,u8 Copy_u8PinNumber);

#endif /* DIO_INIT_H_ */
