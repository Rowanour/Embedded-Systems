/*
 * GIE.c
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

void GIE_ENABLED(void){
	SET_BIT(SREG,SREG_I);

}
void GIE_DISABLED(void){
	CLR_BIT(SREG,SREG_I);

}
