/*
 * TMR0_interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_TIMER0_TMR0_INTERFACE_H_
#define MCAL_TIMER0_TMR0_INTERFACE_H_


#define NORMAL_MODE 0
#define CTC_MODE	1

void TMR0_voidinit(void);
void TMR0_voidSetPreloadValue(u8 Copy_u8Value);
void TMR0_voidSetCTCCompareValue(u8 Copy_u8Value);
void TMR0_voidEnableInterrupt(u8 Copy_u8Mode);
void TMR0_voidDisableInterrupt(u8 Copy_u8Mode);
void TMR0_voidNormalSetBusyWaitMS(u32 Copy_u32Time);
void TMR0_voidCTCSetBusyWaitMS(u32 Copy_u32Time);
u8 TMR0_u8GetCounterValue(void);
void TMR0_voidOVFCallBack(void(*pvNotificationFunction)(void));
void TMR0_voidCTCCallBack(void(*pvNotificationFunction)(void));
#endif /* MCAL_TIMER0_TMR0_INTERFACE_H_ */
