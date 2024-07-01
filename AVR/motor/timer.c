/*
 * timer.c
 *
 *  Created on: Aug 28, 2023
 *      Author: LAPTOP
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer.h"
#include <avr/io.h>
#define NULL ((void*)0)
void (*TIMER0_pvCallBackFunc)(void)= NULL;
void TIMER0_voidINIT(void){
	// CHOOSE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	OCR0 = 250;

	SET_BIT(TIMSK,TIMSK_OCIE0);

	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}

void TIMER0_voidINIT1(void){
	// CHOOSE
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	OCR0 = 250;

	SET_BIT(TIMSK,TIMSK_OCIE0);

	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}
u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc)){

	u8 u8ErrorStatus_Local=OK;
	if(Copy_pvCallBackFunc!= NULL){
		TIMER0_pvCallBackFunc =Copy_pvCallBackFunc;
	}
	else{
		u8ErrorStatus_Local= NOT_OK;
	}
	return u8ErrorStatus_Local;
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(TIMER0_pvCallBackFunc!=0){
		TIMER0_pvCallBackFunc();
	}
}
void TIMER1_voidINIT(void)
{
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);

	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	TCCR1B&= PRESCALLER_MASK;

}
void TIMER1_voidSetChannelCompareMatch(u16 copy_u16CompareMatch)
{
	OCR1A=copy_u16CompareMatch;
}
void TIMER1_voidSetTopTicks(u16 copy_u16TopTicks)
{
	ICR1=copy_u16TopTicks;
}

u16 map(u16 x, u16 in_min, u16 in_max, u16 out_min, u16 out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
