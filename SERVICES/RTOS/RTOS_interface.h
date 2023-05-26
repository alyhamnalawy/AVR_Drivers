/*
 * RTOS_interface.h
 *
 *  Created on: Apr 20, 2023
 *      Author: Ali Ehab
 */

#ifndef SERVICES_RTOS_RTOS_INTERFACE_H_
#define SERVICES_RTOS_RTOS_INTERFACE_H_

void RTOS_voidInit(void);
void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*TaskFunction)(void));
void RTOS_voidDeleteTask(u8 Copy_u8Priority);
static void voidScheduler(void);


#endif /* SERVICES_RTOS_RTOS_INTERFACE_H_ */
