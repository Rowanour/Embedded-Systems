/*
 * main.
 *
 *  Created on: sept, 2023
 *      Author: r0wan
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include"LCD.h"
#include <avr/io.h>
#include <util/delay.h>
void main(void)
{
	DIO_SetPortDirection(DIO_PORTD,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	LCD_voidInit();
	LCD_voidSendString("Rowan Nour");
	LCD_voidGoToXY(1, 0);
	LCD_voidSendString("21");
    _delay_ms(1000);
    LCD_voidLCDClear();

}
