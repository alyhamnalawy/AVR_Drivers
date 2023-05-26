/*
 * TMR1_private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_TIMER1_TMR1_PRIVATE_H_
#define MCAL_TIMER1_TMR1_PRIVATE_H_

#define     TCCR1A  *((volatile u8 *)0x4F)
#define     WGM10   0
#define     WGM11   1
#define     FOC1B   2
#define     FOC1A   3
#define     COM1B0  4
#define     COM1B1  5
#define     COM1A0  6
#define     COM1A1  7

#define     TCCR1B  *((volatile u8 *)0x4E)
#define     CS10    0
#define     CS11    1
#define     CS12    2
#define     WGM12   3
#define     WGM13   4
#define     ICES1   6
#define     ICNC1   7

#define     TCNT1   *((volatile u16 *)0x4C)
#define     OCR1A   *((volatile u16 *)0x4A)
#define     OCR1B   *((volatile u16 *)0x48)
#define     ICR1    *((volatile u16 *)0x46)

#define     TIMSK   *((volatile u8 *)0x59)
#define     TOIE1   2
#define     OCIE1B  3
#define     OCIE1A  4
#define     TICIE1  5

#define     TIFR    *((volatile u8 *)0x58)
#define     TOV1    2
#define     OCF1B   3
#define     OCF1A   4
#define     ICF1    5



#endif /* MCAL_TIMER1_TMR1_PRIVATE_H_ */
