#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC.h"
#include "CLCD.h"
#include "UART.h"
#include <avr/io.h>

int main(void)
{

	unsigned short temperatue;
	u8 received_data;
	u16 Analogue_Value=0;
	// Set the direction for pins that connected master w slave with each other
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN0, DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);

	// Set the direction for the LDR as input
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN1, DIO_INPUT);

	//LCD DATA DIRECTION
	DIO_SetPortDirection(CLCD_DATA_PORT, DIO_PORT_OUTPUT);

	//LCD CTRL DIRECTION
	DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN2, DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN3, DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN4, DIO_OUTPUT);

	// Set the direction for the LM35 as input
	DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_INPUT);

	// Set the directions of the AC and heater
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN3, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN4, DIO_OUTPUT);
	CLCD_voidInitl();

	// Set the directions of the LEDs
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	// Initialize UART for receiving data
	UART_voidINIT_RX();

	ADC_vinit();
	while(1)
	{

		received_data=UART_u8RecieveData_RX();
		//received_data=UART_u8RecieveData_RX();
		if(received_data==1)
		{
			//converting digital reading to analog
			Analogue_Value=((ADC_u8GetChannelReading(ADC_u8_ADC_CHANNEL_1)*(5000UL))/256);

			//when light is low leds turn on automatically
			if(2500<Analogue_Value && Analogue_Value<=5000)
			{
				DIO_SetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
				DIO_SetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
				DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_HIGH);

			}
			//when light is high leds turn off automatically
			else if(0<=Analogue_Value && Analogue_Value<=2500)
			{
				DIO_SetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
				DIO_SetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);
				DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_LOW);
			}

			else
			{
				//			DIO_SetPinValue(DIO_PORTC,DIO_PIN0,LOW);
				//			DIO_SetPinValue(DIO_PORTC,DIO_PIN1,LOW);
				//			DIO_SetPinValue(DIO_PORTC,DIO_PIN2,LOW);
			}

			//display temprature on the lcd
			CLCD_voidString("temperature=");

			//converting digital reading to analog (temperature degrees)
			temperatue=(ADC_u8GetChannelReading(ADC_u8_ADC_CHANNEL_0)*2);
			//if statement that checks if the temperature variable is less than 10
			if(temperatue<10)
			{
				// sets the cursor position on the LCD to the second row (row 1) and the first column (column 0)
				CLCD_voidGoTo_X_Y(1,0);
				//converts the digit to its ASCII equivalent
				CLCD_voidSendData((temperatue%10)+48);
				//sends the degree symbol (°) to the LCD
				CLCD_voidSendData(0xDF);
				CLCD_voidSendData('c');
			}
			else if( temperatue<100)
			{
				CLCD_voidGoTo_X_Y(1,0);

				//temperature % 10 calculates the remainder of the temperature when divided by 10.
				//+ 48 converts the digit to its ASCII equivalent, as characters in C are represented using ASCII values.
				CLCD_voidSendData((temperatue/10)+48);
				CLCD_voidSendData((temperatue%10)+48);
				CLCD_voidSendData(0XDF);
				CLCD_voidSendData('c');

				if(temperatue<20)
				{
					//heater turn on
					DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_HIGH);
				}
				else if (temperatue>30)
				{
					//AC turn on
					DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_HIGH);
				}
				else
				{
					//both turn off
					DIO_SetPinValue(DIO_PORTC,DIO_PIN3,DIO_LOW);
					DIO_SetPinValue(DIO_PORTC,DIO_PIN4,DIO_LOW);
				}
			}
			else
			{

			}



		}

		if(received_data==2)
		{
			//room 1 light turn on
			DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		}
		if(received_data==3)
		{
			//room 1 light turn off
			DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);
		}
		if(received_data==4)
		{
			//room 2 light turn on
			DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		}
		if(received_data==5)
		{
			//room 1 light turn off
			DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);
		}
		if(received_data==6)
		{
			//room 3 light turn on
			DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		}
		if(received_data==7)
		{
			//room 1 light turn off
			DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_LOW);
		}
		if(received_data==8)
		{
			//heater turn on
			DIO_SetPinValue(DIO_PORTC, DIO_PIN4, DIO_HIGH);
		}
		if(received_data==9)
		{
			//heater turn off
			DIO_SetPinValue(DIO_PORTC, DIO_PIN4, DIO_LOW);
		}
		if(received_data==10)
		{
			//AC turn on
			DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_HIGH);
		}
		if(received_data==11)
		{
			//AC turn off
			DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_LOW);
		}

	}
}
