/*
 * WDT_private.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_WATCHDOG_TIMER_WDT_PRIVATE_H_
#define MCAL_WATCHDOG_TIMER_WDT_PRIVATE_H_

#define WDTCR 		*((volatile u8 *)0x41)
#define WDTCR_WDP0	0 //PRESCALER
#define WDTCR_WDP1	1
#define WDTCR_WDP2	2
#define WDTCR_WDE	3
#define WDTCR_WDTOE	4

#endif /* MCAL_WATCHDOG_TIMER_WDT_PRIVATE_H_ */
