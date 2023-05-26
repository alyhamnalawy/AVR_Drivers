/*
 * UART_private.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define PARITY_MODE_DISABLED 	0
#define PARITY_MODE_EVEN 		1
#define PARITY_MODE_ODD 		2

#define STOP_BIT_ONE 			0
#define STOP_BIT_TWO 			1

#define BIT_SIZE_FIVE 			0
#define BIT_SIZE_SIX 			1
#define BIT_SIZE_SEVEN 			2
#define BIT_SIZE_EIGHT 			3
#define BIT_SIZE_NINE 			4

#define RX_INT_MODE 			DISABLE
#define TX_INT_MODE 			DISABLE

#define BAUD_RATE 				9600UL
#define F_CPU 					8000000UL
#define BAUD_RATE_NORMAL 		((F_CPU/(16UL*(BAUD_RATE)))-1)
#define BAUD_RATE_SPEED 		(F_CPU/(16UL*(BAUD_RATE)))-1)

/****************REGISTERS***************/

#define UBRRH 		*((volatile u8 *)0x40)
#define UBRRH_URSEL	7

#define UBRRL 		*((volatile u8 *)0x29)

#define UCSRC 		*((volatile u8 *)0x40)
#define UCSRC_UCPOL	0
#define UCSRC_UCSZ0	1
#define UCSRC_UCSZ1	2
#define UCSRC_USBS	3
#define UCSRC_UPM0	4
#define UCSRC_UPM1	5
#define UCSRC_UMSEL	6
#define UCSRC_URSEL	7


#define UCSRB 		*((volatile u8 *)0x2A)
#define UCSRB_TXB8	0
#define UCSRB_RXB8	1
#define UCSRB_UCSZ2	2
#define UCSRB_TEXEN	3
#define UCSRB_REXEN	4
#define UCSRB_USRIE	5
#define UCSRB_TXCIE	6
#define UCSRB_RXCIE	7


#define UCSRA 		*((volatile u8 *)0x2B)
#define UCSRA_MPCM	0
#define UCSRA_U2X	1
#define UCSRA_PE	2
#define UCSRA_DOR	3
#define UCSRA_FE	4
#define UCSRA_UDRE	5
#define UCSRA_TXC	6
#define UCSRA_RXC	7


#define UDR   		*((volatile u8 *)0x2C)

#endif /* MCAL_UART_UART_PRIVATE_H_ */
