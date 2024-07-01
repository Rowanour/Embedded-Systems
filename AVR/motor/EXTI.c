/*
 * EXTI.c
 *
 *  Created on: Aug 23, 2023
 *      Author: yousi
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI.h"
#include <util/delay.h>
#include <avr/io.h>
#include "DIO.h"

void EXTI_void_INT0(void){
	// set falling edge
	// set sense control for INT0
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	// PREPHIRAL INTERRUPT ENABLE FOR INT0
	SET_BIT(GICR,GICR_INT0);
}
void EXTI_void_INT1(void){
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC00);


}
void EXTI_void_INT2(void){
	// FALLING EDGE



}

