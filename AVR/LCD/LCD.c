/*
 * LCD.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Dubai
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include"LCD.h"
#include <avr/io.h>
#include <util/delay.h>


void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	DIO_SetPortValue(LCD_DATA_PORT,Copy_u8Command);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);


}
void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	DIO_SetPortValue(LCD_DATA_PORT,Copy_u8Data);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_LOW);

}
void LCD_voidInit(void)
{
	_delay_ms(40);
	LCD_voidSendCommand(0b00111000);
	LCD_voidSendCommand(0b00001100);
	LCD_voidSendCommand(1);

}
void LCD_voidSendString(const char*Copy_pcString)
{

	    u8 i=0;
	    while( Copy_pcString[i] != 0)
	    {
	    	LCD_voidSendData(Copy_pcString[i]);
	        i++;
	    }

}
void LCD_voidGoToXY(u8 Copy_u8Xpos,u8 Copy_u8Ypos)
{
	u8 Local_u8Address;
	if(Copy_u8Xpos == 0)
	{
		Local_u8Address=Copy_u8Ypos;
	}
	else if(Copy_u8Xpos == 1)
	{
		Local_u8Address=Copy_u8Ypos+0x40;
	}
	LCD_voidSendCommand(Local_u8Address+128);

}
void LCD_voidLCDClear(void)
{
	LCD_voidSendCommand(1);

}
