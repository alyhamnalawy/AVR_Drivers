/*
 * WDT_interface.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_WATCHDOG_TIMER_WDT_INTERFACE_H_
#define MCAL_WATCHDOG_TIMER_WDT_INTERFACE_H_

#define WDT_SLEEP_16_3_MS 0
#define WDT_SLEEP_32_5_MS 1
#define WDT_SLEEP_65_0_MS 2

void WDT_Enable(void);
void WDT_Sleep(u8 Copy_u8TimeOut);
void WDT_Disable(void);


#endif /* MCAL_WATCHDOG_TIMER_WDT_INTERFACE_H_ */
