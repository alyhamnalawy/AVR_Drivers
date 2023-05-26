/*
 * UART_interface.h
 *
 *  Created on: Apr 16, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_voidInit(void);
void UART_voidTransmitDataSynchronous(u8 Copy_u8Data);
void UART_u8ReceiveDataSynchronous(u8 *Copy_pu8ReceiveData);
void UART_voidSendString(u8 *Copy_pu8StringArray);
void UART_voidSendNumber(u32 Copy_u32UserInput);
void UART_RXInterruptEnable(void);
void UART_TXInterruptEnable(void);

#endif /* MCAL_UART_UART_INTERFACE_H_ */
