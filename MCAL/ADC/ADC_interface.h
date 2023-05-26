/*
 * DIO_interface.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ADC_CHANNEL_0 0b00000
#define ADC_CHANNEL_1 0b00001
#define ADC_CHANNEL_2 0b00010
#define ADC_CHANNEL_3 0b00011
#define ADC_CHANNEL_4 0b00100
#define ADC_CHANNEL_5 0b00101
#define ADC_CHANNEL_6 0b00110
#define ADC_CHANNEL_7 0b00111

#define ADC_INTERRUPT_ENABLE	1
#define ADC_INTERRUPT_DISABLE	0

void ADC_voidInit(void);
void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus);
u8 ADC_u8StartConversion(u8 Copy_u8ChannelName);
void ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelName,void (*NotifiFunction)(void));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
