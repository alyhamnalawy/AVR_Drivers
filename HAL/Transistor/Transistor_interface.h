/*
 * Transistor_interface.h
 *
 *  Created on: Apr 29, 2023
 *      Author: Ali Ehab
 */

#ifndef HAL_TRANSISTOR_TRANSISTOR_INTERFACE_H_
#define HAL_TRANSISTOR_TRANSISTOR_INTERFACE_H_

typedef enum
{
	NPN,
	PNP
}Transistor_Type_t;

typedef enum
{
	Saturation,
	Cutoff
}Transistor_InitialState_t;

typedef enum
{
	TRANSISTOR_CUTOFF,
	TRANSISTOR_SATURATION
}Transistor_State_t;

typedef struct
{
	u8                          Trans_PortName;
	u8                          Trans_PinNumber;
	Transistor_Type_t           Trans_Type;
	Transistor_InitialState_t   Trans_InitialState;
}Transistor_t;



void Transistor_voidConfigure(Transistor_t * Copy_TransistorName);
void Transistor_voidChangeTransistorState(Transistor_t * Copy_TransistorName, u8 Copy_u8TransistorState);

#endif /* HAL_TRANSISTOR_TRANSISTOR_INTERFACE_H_ */
