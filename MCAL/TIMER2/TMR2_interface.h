/*
 * TMR2_interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_TIMER2_TMR2_INTERFACE_H_
#define MCAL_TIMER2_TMR2_INTERFACE_H_

void TMR2_voidSetBusyWaitMS_CTCMode(u32 Copy_u32Time);
void TMR2_voidSetBusyWaitMS_OVfMode(u32 Copy_u32Time);
void TMR2_voidInit(void);
void TMR2_voidEnableInterrupt(u8 Copy_u8Mode);
void TMR2_voiDisbaleInterrupt(u8 Copy_u8Mode);
void TMR2_voidSetPreLoadValue(u8 Copy_u8Value);
void TMR2_voidSetCTCCompareMatchValue(u8 Copy_u8Value);

#endif /* MCAL_TIMER2_TMR2_INTERFACE_H_ */
