/*
 * TMR0_private.h
 *
 *  Created on: Apr 9, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_TIMER0_TMR0_PRIVATE_H_
#define MCAL_TIMER0_TMR0_PRIVATE_H_

#define TIMSK 	*((volatile u8*)0x59)
#define TOIE0	0
#define OCIE0	1


#define TIFR 	*((volatile u8*)0x58)
#define TOV0	0
#define OCF0	1

#define TCCR0 	*((volatile u8*)0x53)
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

#define TCNT0 	*((volatile u8*)0x52)

#define OCR0 	*((volatile u8*)0x5C)

#define Normal_Mode   0
#define PWM_Mode      1
#define CTC_Mode      2
#define FastPWM_Mode  3

#define No_OC0           0
#define ToggleOC0_OnComp 1
#define ClearOC0_OnComp  2
#define SetOC0_OnComp    3

#define No_OC0_PWM         0
#define NotUsed            1
#define Non_InvertedPWM    2
#define InvertedPWM        3

#define NoCLK                 0
#define NoPre                 1
#define Pre8                  2
#define Pre64                 3
#define Pre256                4
#define Pre1024               5
#define ExtSourceT0_FallingE  6
#define ExtSourceT0_RaisingE  7


#endif /* MCAL_TIMER0_TMR0_PRIVATE_H_ */
