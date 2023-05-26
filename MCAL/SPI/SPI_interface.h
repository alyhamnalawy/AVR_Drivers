/*
 * SPI_interface.h
 *
 *  Created on: Apr 17, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8SendReceive(u8 Copy_u8Data);
void SPI_send(u8 Copy_Data);
u8 SPI_u8Receive(u8 *pdata);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
