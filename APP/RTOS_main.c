/*
 * RTOS_main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: Ali Ehab
 */

#include "../SERVICES/include/FreeRTOS.h"
#include "../SERVICES/include/task.h"

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO_Driver/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"


void Led1_Task(void *pvParam);
void Led2_Task(void *pvParam);

void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTA, PIN0, OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, PIN1, OUTPUT);
	UART_voidInit();
	xTaskCreate(&Led1_Task,"Led1",300,NULL,0,NULL);
	xTaskCreate(&Led2_Task,"Led2",300,NULL,1,NULL);
	vTaskStartScheduler();
	while(1)
	{

	}
}

void Led1_Task(void *pvParam)
{
	while(1)
	{
		DIO_voidTogglePinValue(DIO_PORTA,PIN0);
		UART_voidSendString("Task 1\r\n");
		vTaskDelay(1000);
	}
}

void Led2_Task(void *pvParam)
{
	while(1)
	{
		DIO_voidTogglePinValue(DIO_PORTA,PIN1);
		UART_voidSendString("Task 2\r\n");
		vTaskDelay(2000);
	}
}
