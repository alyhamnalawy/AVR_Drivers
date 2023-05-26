///*
// * RTOSMain.c
// *
// *  Created on: Apr 20, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../SERVICES/RTOS/RTOS_interface.h"
//
//
//void LED1_Task(void);
//void LED2_Task(void);
//void LED3_Task(void);
//
//void main(void)
//{
//    DIO_SetPinDirection(DIO_PORTA,PIN0,OUTPUT);
//    DIO_SetPinDirection(DIO_PORTA,PIN1,OUTPUT);
//    DIO_SetPinDirection(DIO_PORTA,PIN2,OUTPUT);
//    /* create task (0, 1000, &led1task)*/
//    /* create task (1, 2000, &led1task)*/
//    /* create task (2, 3000, &led1task)*/
//    RTOS_voidCreateTask(0, 1000, &LED1_Task);
//    RTOS_voidCreateTask(1, 2000, &LED1_Task);
//    RTOS_voidCreateTask(2, 3000, &LED1_Task);
//
//    /* RTOS init */
//    RTOS_voidInit();
//
//    while (1);
//}
//
//void LED1_Task(void)
//{
//    /* toggle */
//	DIO_voidTogglePinValue(DIO_PORTA,PIN0);
//}
//void LED2_Task(void)
//{
//	DIO_voidTogglePinValue(DIO_PORTA,PIN1);
//}
//void LED3_Task(void)
//{
//	DIO_voidTogglePinValue(DIO_PORTA,PIN2);
//}
