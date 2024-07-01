#define F_CPU 8000000UL
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include<avr/io.h>
#include<util/delay.h>

void DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirCopy){
	if(u8PortIdCopy<=DIO_PORTA){
	switch(u8PortIdCopy)
	{
	case DIO_PORTA: DDRA=u8PortDirCopy;break;
	case DIO_PORTB: DDRB=u8PortDirCopy;break;
	case DIO_PORTC: DDRC=u8PortDirCopy;break;
	case DIO_PORTD: DDRD=u8PortDirCopy;break;
	}
	}
}

void DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	if((u8PortIdCopy<=DIO_PORTD)&&(u8PinIdCopy<=DIO_PIN7))
	{
		if(u8PinDirCopy==DIO_OUTPUT)
		{
			switch(u8PortIdCopy)
			{
			case DIO_PORTA:SET_BIT(DDRA,u8PinIdCopy);break;
			case DIO_PORTB:SET_BIT(DDRB,u8PinIdCopy);break;
			case DIO_PORTC:SET_BIT(DDRC,u8PinIdCopy);break;
			case DIO_PORTD:SET_BIT(DDRD,u8PinIdCopy);break;
			}
		}
		else if(u8PinDirCopy==DIO_INPUT)
		{
			switch(u8PortIdCopy)
			{
			case DIO_PORTA:CLR_BIT(DDRA,u8PinIdCopy);break;
			case DIO_PORTB:CLR_BIT(DDRB,u8PinIdCopy);break;
			case DIO_PORTC:CLR_BIT(DDRC,u8PinIdCopy);break;
			case DIO_PORTD:CLR_BIT(DDRD,u8PinIdCopy);break;
			}
		}
		else{}
	}
	else{}
}

void DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PortValCopy)
{
	switch(u8PortIdCopy)
		{
		case DIO_PORTA: PORTA=u8PortValCopy;break;
		case DIO_PORTB: PORTB=u8PortValCopy;break;
		case DIO_PORTC: PORTC=u8PortValCopy;break;
		case DIO_PORTD: PORTD=u8PortValCopy;break;
		}
}

void DIO_SetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy, u8 u8PinValCopy)
{
	if((u8PortIdCopy<=DIO_PORTD)&&(u8PinIdCopy<=DIO_PIN7))
		{
			if(u8PinValCopy==DIO_HIGH)
			{
				switch(u8PortIdCopy)
				{
				case DIO_PORTA:SET_BIT(PORTA,u8PinIdCopy);break;
				case DIO_PORTB:SET_BIT(PORTB,u8PinIdCopy);break;
				case DIO_PORTC:SET_BIT(PORTC,u8PinIdCopy);break;
				case DIO_PORTD:SET_BIT(PORTD,u8PinIdCopy);break;
				}
			}
			else if(u8PinValCopy==DIO_LOW)
			{
				switch(u8PortIdCopy)
				{
				case DIO_PORTA:CLR_BIT(PORTA,u8PinIdCopy);break;
				case DIO_PORTB:CLR_BIT(PORTB,u8PinIdCopy);break;
				case DIO_PORTC:CLR_BIT(PORTC,u8PinIdCopy);break;
				case DIO_PORTD:CLR_BIT(PORTD,u8PinIdCopy);break;
				}
			}
			else{}
		}
		else{}
}

u8 DIO_GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy)
{
	u8 u8ResultLocal;
	if((u8PortIdCopy<=DIO_PORTD)&&(u8PinIdCopy<=DIO_PIN7))
	{
		switch(u8PortIdCopy)
		{
		case DIO_PORTA:u8ResultLocal=GET_BIT(PINA,u8PinIdCopy);break;
		case DIO_PORTB:u8ResultLocal=GET_BIT(PINB,u8PinIdCopy);break;
		case DIO_PORTC:u8ResultLocal=GET_BIT(PINC,u8PinIdCopy);break;
		case DIO_PORTD:u8ResultLocal=GET_BIT(PIND,u8PinIdCopy);break;
		}
	}
	else{}
	return u8ResultLocal;
}

