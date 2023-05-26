/*
 * LM35_interface.h
 *
 *  Created on: Apr 6, 2023
 *      Author: Ali Ehab
 */

#ifndef HAL_LM35_LM35_INTERFACE_H_
#define HAL_LM35_LM35_INTERFACE_H_

typedef struct {
	u8 Port_name;
	u8 ADC_Channel;
}lm35_sensor_t;

void LM35_init(lm35_sensor_t *Sensor);
u8 LM35_read_temperature(lm35_sensor_t *Sensor);

#endif /* HAL_LM35_LM35_INTERFACE_H_ */
