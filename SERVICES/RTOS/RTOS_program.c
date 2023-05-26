///*
// * RTOS_program.c
// *
// *  Created on: Apr 20, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../../LIB/BIT_MATH.h"
//#include "../../LIB/STD_TYPES.h"
//
//#include "../../MCAL/TIMER0/TMR0_interface.h"
//#include "../../MCAL/GIE/GIE_interface.h"
//
//#include "RTOS_interface.h"
//#include "RTOS_private.h"
//#include "RTOS_config.h"
//
//static Task_t SystemTasks[NUMBER_OF_TASKS] = {{0}};
//
//void RTOS_voidInit(void)
//{
//    /* Set The Compare Match Value To 125 To Make CTC Event Every 1 msec */
//    TMR0_voidSetCTCCompareValue(125);
//    /* Set The Callback For Timer0 To Call Scheduler Function For Each Interrupt */
//    TMR0_voidCTCCallBack(&voidScheduler);
//    /* Enable The CTC Mode Interrupt */
//    TMR0_voidEnableInterrupt(CTC_MODE);
//    /* Enable Global Interrupt */
//    GIE_voidEnableGlobalInterrupt();
//    /* Set The CTC Mode, Prescaler = 64 */
//    TMR0_voidinit();
//}
//
//void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, void(*TaskFunction)(void))
//{
//    SystemTasks[Copy_u8Priority].Priority = Copy_u8Priority;
//    SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
//    SystemTasks[Copy_u8Priority].TaskFunc = TaskFunction;
//    // SystemTasks[Copy_u8Priority].State = READY;
//}
//
//void RTOS_voidDeleteTask(u8 Copy_u8Priority)
//{
//    SystemTasks[Copy_u8Priority].TaskFunc = NULL;
//    // SystemTasks[Copy_u8Priority].State = DELETED;
//}
//
//static void voidScheduler(void)
//{
//    /* Algorithm = Priority Based */
//    static u32 Local_u32TickCounter = 0;
//    Local_u32TickCounter++;
//    u8 Local_u8LoopCounter;
//    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUMBER_OF_TASKS; Local_u8LoopCounter++)
//    {
//        // if(SystemTasks[Local_u8LoopCounter].State == READY)
//        // {
//        if(Local_u32TickCounter % SystemTasks[Local_u8LoopCounter].Periodicity == 0)
//        {
//            /* Execute The Task Function */
//            SystemTasks[Local_u8LoopCounter].TaskFunc();
//        }
//        // }
//    }
//}
