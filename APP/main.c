#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO_Driver/DIO_interface.h"
/*int main()
{
	//set direction for push button as input
	DIO_SetPinDirection(DIO_PORTA,PIN3,INPUT);
	//PULLUP RESISTOR
	DIO_SetPinValue(DIO_PORTA,PIN3,HIGH);
	//set direction for LED as output
	DIO_SetPinDirection(DIO_PORTB,PIN4,OUTPUT);
	while(1)
	{
		if(DIO_u8GetPinValue(DIO_PORTA,PIN3)==0)
		{
			DIO_SetPinValue(DIO_PORTB,PIN4,HIGH);
		}
		else
		{
			DIO_SetPinValue(DIO_PORTB,PIN4,LOW);
		}
	}
	return 0;
}
*/
