/*
 * TMR1_interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_TIMER1_TMR1_INTERFACE_H_
#define MCAL_TIMER1_TMR1_INTERFACE_H_

#define RISING_EDGE 	1
#define FALLING_EDGE 	0
#define ICU_ENABLE		1
#define ICU_DISABLE		0

void TIMER1_voidInit(void);
void TIMER1_voidSetOCR1AValue(u16 Copy_u16OCR1A);
void TIMER1_voidSetICRValue(u16 Copy_u16ICRValye);
void ICU_voidSetCallBack(void(*Notification)(void));
u8 TIMER1_u8GetCounterValue(void);
u16 ICU_u16GetICRRegister(void);
void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal);
void ICU_voidInterruptContol(u8 Copy_u8InterruptControl);

#endif /* MCAL_TIMER1_TMR1_INTERFACE_H_ */
