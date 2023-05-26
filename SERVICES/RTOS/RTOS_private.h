/*
 * RTOS_private.h
 *
 *  Created on: Apr 20, 2023
 *      Author: Ali Ehab
 */

#ifndef SERVICES_RTOS_RTOS_PRIVATE_H_
#define SERVICES_RTOS_RTOS_PRIVATE_H_

typedef enum
{
    Deleted,
    Ready,
}States_t;


typedef struct
{
    u8 Priority;
    u16 Periodicity;
    States_t State;
    void (*TaskFunc)(void);
}Task_t;



static void voidScheduler(void);

#endif /* SERVICES_RTOS_RTOS_PRIVATE_H_ */
