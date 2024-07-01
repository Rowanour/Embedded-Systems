#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include <avr/io.h>
#include <util/delay.h>

void DIO_SetPinDirection(u8 u8PortIDcopy,u8 u8PinIDcopy,u8 u8PinDircopy){
	if((u8PortIDcopy<=DIO_PORTD)&& (u8PinIDcopy<=DIO_PIN7)){
		if(u8PinDircopy==DIO_OUTPUT){
					switch(u8PortIDcopy)
					{
					case DIO_PORTA:SET_BIT(DDRA,u8PinIDcopy);break;
					case DIO_PORTB:SET_BIT(DDRB,u8PinIDcopy);break;
					case DIO_PORTC:SET_BIT(DDRC,u8PinIDcopy);break;
					case DIO_PORTD:SET_BIT(DDRD,u8PinIDcopy);break;
					}
				}
				else if (u8PinDircopy==DIO_INPUT){
					switch(u8PortIDcopy)
					{
					case DIO_PORTA:CLR_BIT(DDRA,u8PinIDcopy);break;
					case DIO_PORTB:CLR_BIT(DDRB,u8PinIDcopy);break;
					case DIO_PORTC:CLR_BIT(DDRC,u8PinIDcopy);break;
					case DIO_PORTD:CLR_BIT(DDRD,u8PinIDcopy);break;
				}
			}
				else{}}}


void DIO_SetPortDirection(u8 u8PortIDcopy,u8 u8PortDircopy){

			switch(u8PortIDcopy)
						{
					case DIO_PORTA:DDRA=u8PortDircopy;break;
					case DIO_PORTB:DDRB=u8PortDircopy;break;
					case DIO_PORTC:DDRC=u8PortDircopy;break;
					case DIO_PORTD:DDRD=u8PortDircopy;break;
						}
					}

void DIO_SetPinValue(u8 u8PortIDcopy,u8 u8PinIDcopy,u8 u8PinValuecopy){
	if((u8PortIDcopy<=DIO_PORTD)&& (u8PinIDcopy<=DIO_PIN7)){
			if(u8PinValuecopy==DIO_HIGH){
				switch(u8PortIDcopy)
									{
						case DIO_PORTA:SET_BIT(PORTA,u8PinIDcopy);break;
						case DIO_PORTB:SET_BIT(PORTB,u8PinIDcopy);break;
						case DIO_PORTC:SET_BIT(PORTC,u8PinIDcopy);break;
						case DIO_PORTD:SET_BIT(PORTD,u8PinIDcopy);break;
									}
							}
	else if (u8PinValuecopy==DIO_LOW){
						switch(u8PortIDcopy)
						{
						case DIO_PORTA:CLR_BIT(PORTA,u8PinIDcopy);break;
						case DIO_PORTB:CLR_BIT(PORTB,u8PinIDcopy);break;
						case DIO_PORTC:CLR_BIT(PORTC,u8PinIDcopy);break;
						case DIO_PORTD:CLR_BIT(PORTD,u8PinIDcopy);break;
					}
				}}
					else{}
	}
void DIO_SetPortValue(u8 u8PortIDcopy,u8 u8PortValuecopy){

			switch(u8PortIDcopy)
							{
							case DIO_PORTA:PORTA=u8PortValuecopy;break;
							case DIO_PORTB:PORTB=u8PortValuecopy;break;
							case DIO_PORTC:PORTC=u8PortValuecopy;break;
							case DIO_PORTD:PORTD=u8PortValuecopy;break;
							}
						}

u8 DIO_GetPinValue(u8 u8PortIDcopy,u8 u8PinIDcopy){
	u8 u8ResultLocal;
	if((u8PortIDcopy<=DIO_PORTD)&& (u8PinIDcopy<=DIO_PIN7)){
					switch(u8PortIDcopy)
					{
					case DIO_PORTA:u8ResultLocal=GET_BIT(PINA,u8PinIDcopy);break;
					case DIO_PORTB:u8ResultLocal=GET_BIT(PINB,u8PinIDcopy);break;
					case DIO_PORTC:u8ResultLocal=GET_BIT(PINC,u8PinIDcopy);break;
					case DIO_PORTD:u8ResultLocal=GET_BIT(PIND,u8PinIDcopy);break;
					}
	}
					else{}
	return u8ResultLocal;
}

