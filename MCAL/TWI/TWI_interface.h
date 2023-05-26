/*
 * TWI_interface.h
 *
 *  Created on: Apr 19, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_


typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartConditionError,
	SlaveAddressWithWriteRequestError,
	SlaveAddressWithReadRequestError,
	SendDataPacketError,
	MasterReadDataPacketError,


}ERR_t;

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
ERR_t TWI_ERRSendStartCondition(void);
ERR_t TWI_ERRSendRepeatedStartCondition(void);
ERR_t TWI_ERRSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
ERR_t TWI_ERRSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
ERR_t TWI_ERRSendDataPacket(u8 Copy_u8DataPacket);
ERR_t TWI_ERRReceiveDataPacket(u8 *Copy_pu8DataPacket);
void TWI_voidSendStopCondition(void);

#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
