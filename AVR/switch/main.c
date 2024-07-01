
#define F_CPU 8000000UL
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_INPUT);
	DIO_SetPinValue(DIO_PORTA, DIO_PIN0,DIO_LOW);

	while (1)
	{
		u8 res=DIO_GetPinValue(DIO_PORTD, DIO_PIN2);
		if (res==DIO_LOW)
		{
			DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
		}
		else
		{
			DIO_SetPinValue(DIO_PORTA, DIO_PIN0, DIO_LOW);
		}
	}
}

