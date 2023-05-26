/*
 * EEPROM_interface.h
 *
 *  Created on: Apr 20, 2023
 *      Author: Ali Ehab
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8Data);
void EEPROM_voidReceiveDataByte(u16 Copy_u16LocationAddress, u8 * Copy_pu8ReceivedData);


#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
