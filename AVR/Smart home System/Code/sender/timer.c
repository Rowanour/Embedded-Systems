#define F_CPU 8000000UL
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"timer.h"
#include<avr/io.h>
#include<util/delay.h>
#define NULL ((void*)0)

void (*TIMER0_PvCallBackFun)(void) = NULL;

void TIMER0_voidINIT(void)
{
	//choose CTC mode
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);

	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);

	//set compare value
	OCR0=250;

	TCNT0=192;
	//outPut compare enable
	SET_BIT(TIMSK,TIMSK_OCIE0);

	SET_BIT(TIMSK,TIMSK_TOIE0);
	//prescaller : division by 8
	CLR_BIT(TCCR0,TCCR0_CS00 );
	SET_BIT(TCCR0,TCCR0_CS01 );
	CLR_BIT(TCCR0,TCCR0_CS02 );
}
u8 TIMER0_u8SetCallBack(void(*Copy_PvCallBackFun))
{
   u8 u8ErrorStatus_Local = OK;
   if(Copy_PvCallBackFun != NULL)
   {
	   TIMER0_PvCallBackFun = Copy_PvCallBackFun;
   }
   else
   {
	   u8ErrorStatus_Local= NOT_OK;
   }
   return u8ErrorStatus_Local;
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if( TIMER0_PvCallBackFun != 0)
	{
		TIMER0_PvCallBackFun();
	}
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if( TIMER0_PvCallBackFun != 0)
	{
		TIMER0_PvCallBackFun();
	}
}
void TIMER1_voidINIT(void)
{
   SET_BIT(TCCR1A,TCCR1A_COM1A1);
   CLR_BIT(TCCR1A,TCCR1A_COM1A0);
   CLR_BIT(TCCR1A,TCCR1A_WGM10);
   SET_BIT(TCCR1A,TCCR1A_WGM11);
   SET_BIT(TCCR1B,TCCR1B_WGM12);
   SET_BIT(TCCR1B,TCCR1B_WGM13);
   ICR1=19999;
   TCCR1B&=PRESCALLER_MASK;
   TCCR1B|=DIVIDE_BY_8;
}
void TIMER1_voidSetChannelCompareMatch(u16 Copy_u16CompareMatch)
{
	OCR1A =  Copy_u16CompareMatch;
}
/*void TIMER1_voidSetTopTicks(u16 Copy_u16TopTicks)
{
	ICR1 = Copy_u16TopTicks;
}*/




