/*
 * TMR2_private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_TIMER2_TMR2_PRIVATE_H_
#define MCAL_TIMER2_TMR2_PRIVATE_H_

#define     TCCR2      		*((volatile u8 *)0x45)

#define     CS20        	0
#define     CS21        	1
#define     CS22        	2
#define     WGM21       	3
#define		COM20			4
#define		COM21			5
#define     WGM20       	6

#define     TCNT2       	*((volatile u8 *)0x44)
#define     OCR2        	*((volatile u8 *)0x43)
#define     ASSR        	*((volatile u8 *)0x42)
#define     TIMSK       	*((volatile u8 *)0x59)

#define     TOIE0       	0
#define     OCIE0       	1

#define     TIFR       		 *((volatile u8 *)0x48)

#define     TOV0       		 0
#define     OCF0        	 1

#define 	NORMAL_MODE      0
#define 	CTC_MODE         1


#endif /* MCAL_TIMER2_TMR2_PRIVATE_H_ */
