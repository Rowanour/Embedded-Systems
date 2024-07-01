/*
 * ADC.c
 *
 *  Created on: Sept, 2023
 *      Author: r0wan
 */
#define F_CPU 8000000UL
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include"ADC.h"
#include<avr/io.h>
#include<util/delay.h>

void ADC_voidInit(void)
{
	SET_BIT(ADCSRA,ADCSRA_ADEN);

	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
}
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
	//clear MUX bits
	ADMUX &=0b11100000;
	ADMUX |=Copy_u8Channel;
	SET_BIT(ADCSRA,ADCSRA_ADSC);
	while(GET_BIT(ADCSRA,ADCSRA_ADIF)==0);
	SET_BIT(ADCSRA,ADCSRA_ADIF);
	return ADCH;

}


