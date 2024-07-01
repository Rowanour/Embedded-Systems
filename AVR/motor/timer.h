/*
 * timer.h
 *
 *  Created on: Aug 28, 2023
 *      Author: LAPTOP
 */

#ifndef TIMER_H_
#define TIMER_H_


#define TCCR0_WGM00    6
#define TCCR0_WGM01    3
#define TCCR0_CS02    2
#define TCCR0_CS01    1
#define TCCR0_CS00    0

#define TCCR1A_COM1A0   6
#define TCCR1A_COM1A1   7
#define TCCR1A_WGM10    0
#define TCCR1A_WGM11    1

#define TCCR1B_WGM12    3
#define TCCR1B_WGM13    4

#define PRESCALLER_MASK  0b11111000
#define DIVIDE_BY_1     1
#define DIVIDE_BY_8     2
#define DIVIDE_BY_64    3
#define DIVIDE_BY_256   8

#define OK     1
#define NOT_OK 0
#define TIMSK_OCIE0    1
#define TIMSK_TOIE0    1

void TIMER0_voidINIT(void);
u8 TIMER0_u8SetCallBack(void(*Copy_pvCallBackFunc));

void TIMER1_voidINIT(void);
void TIMER1_voidSetChannelCompareMatch(u16 copy_u16CompareMatch);
void TIMER1_voidSetTopTicks(u16 copy_u16TopTicks);
u16 map(u16 x, u16 in_min, u16 in_max, u16 out_min, u16 out_max);



#endif /* TIMER_H_ */
