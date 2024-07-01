/*
 * main.
 *
 *  Created on: sept, 2023
 *      Author: r0wan
 */
#define F_CPU 8000000UL
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include <avr/io.h>
#include <util/delay.h>
void main (void)
{
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	while(1)
	{
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_HIGH);
		_delay_ms(100);
		DIO_SetPinValue(DIO_PORTA,DIO_PIN0,DIO_LOW);
		_delay_ms(100);
	}
}
