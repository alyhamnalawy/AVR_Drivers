///*
// * SPI_Slave.c
// *
// *  Created on: Apr 18, 2023
// *      Author: Ali Ehab
// */
//
//
//#include "../LIB/BIT_MATH.h"
//#include "../LIB/STD_TYPES.h"
//
//#include "../HAL/LM35/LM35_interface.h"
//
//#include "../MCAL/DIO_Driver/DIO_interface.h"
//#include "../MCAL/ADC/ADC_interface.h"
//#include "../MCAL/TIMER0/TMR0_interface.h"
//#include "../MCAL/SPI/SPI_interface.h"
//
//int main(void)
//{
//	u8 Local_ADCData;
//	DIO_SetPinDirection(DIO_PORTB,PIN5,INPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN6,OUTPUT);
//	DIO_SetPinDirection(DIO_PORTB,PIN7,INPUT);
//	LM35_init(DIO_PORTA);
//	SPI_voidSlaveInit();
//	while(1)
//	{
//		Local_ADCData=LM35_read_temperature(DIO_PORTA);
//		SPI_u8SendReceive(Local_ADCData);
//	}
//	return 0;
//}
