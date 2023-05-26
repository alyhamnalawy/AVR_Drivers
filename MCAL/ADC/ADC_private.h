/*
 * DIO_private.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define RIGHT_ADJUST	0
#define LEFT_ADJUST		1

//#define AREF			0
//#define AVCC			1
//#define INTERNAL_2v56	2

#define AREF 			 0b00000000
#define AVCC 			 0b01000000
#define INTERNAL_2V56 	 0b11000000

#define prescaler_2clk	 0b00000000
#define prescaler_4clk	 0b00000010
#define prescaler_8clk	 0b00000011
#define prescaler_16clk	 0b00000100
#define prescaler_32clk	 0b00000101
#define prescaler_64clk	 0b00000110
#define prescaler_128clk 0b00000111

#define REF_SEL_BIT_MASK 		0b00111111
#define pre_SEL_BIT_MAK	 		0b11111000
#define CHANNEL_SELCTION_MASK	0b11100000



#define ENABLE	1
#define DISABLE	0
/*************REGISTERS*****************/
#define ADMUX			*((volatile u8*)0x27)
#define ADMUX_MUX0		0
#define ADMUX_MUX1		1
#define ADMUX_MUX2		2
#define ADMUX_MUX3		3
#define ADMUX_MUX4		4
#define ADMUX_ADLAR		5
#define ADMUX_REFS0		6	//ADC REF SELECTION BIT0
#define ADMUX_REFS1		7	//ADC REF SELECTION BIT1

#define ADCSRA			*((volatile u8*)0x26)
#define ADCSRA_ADPS0	0
#define ADCSRA_ADPS1	1
#define ADCSRA_ADPS2	2
#define ADCSRA_ADIE		3
#define ADCSRA_ADIF		4
#define ADCSRA_ADATE	5
#define ADCSRA_ADSC		6
#define ADCSRA_ADEN		7

#define ADCL			*((volatile u8*)0x24) //8 BIT
#define ADCH			*((volatile u8*)0x25) //8 BIT
#define ADC				*((volatile u8*)0x24) //TO READ LOW AND HIGH AT THE SAME TIME 16 BIT

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
