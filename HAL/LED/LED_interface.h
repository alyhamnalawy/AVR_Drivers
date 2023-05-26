/*
 * LED_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: Ali Ehab
 */

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef struct {
			u8 LED_PORT;
			u8 LED_PIN;
		}LED_t;

void LED_voidInit(LED_t *LEDobj);
void LED_voidLEDTurnON(LED_t *LEDobj);
void LED_voidLEDTurnOFF(LED_t *LEDobj);
//void LED_voidLEDToggle(LED_t *LEDobj);

#endif
