/*
 * DIO_config.h
 *
 *  Created on: Mar 30, 2023
 *      Author: Ali Ehab
 */

#ifndef MCAL_DIO_DIO_CONFIG_H_
#define MCAL_DIO_DIO_CONFIG_H_

/*
 * RIGHT ADJUST
 * LEFT ADJUST
 */
#define ADC_ADJUST_RESULT	LEFT_ADJUST

/*
 * AREF
 * AVCC
 * INTERNAL 2.65V
 */

#define ADC_PRESCALER_SELCTION	prescaler_128clk

#define ADC_REFERENCE_SELECTION 	AREF

#define ADC_INTERRUPT_STATUS	ENABLE

#define ADC_ENABLE	ENABLE


#endif /* MCAL_ADC_ADC_CONFIG_H_ */
