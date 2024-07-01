/*
 * EXTI_Program.c
 *
 *  Created on: Feb 1, 2024
 *      Author: r0wan
 */


#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

#include "../include/MEXTI_Interface.h"
#include "../include/MEXTI_private.h"
#include "../include/MEXTI_Config.h"

/************** MCAL ****************/
extern MEXTI_Configuration MEXTI_Config[MEXTI_NUMBER];
static PtrToFunc_void MEXTI_CallBack[MEXIT_TOTAL_LINE_NUMBER];

/********* Function Definitions *********/
void MEXTI_voidInit(void){
	u8 local_u8Iterator = 0;
	for(local_u8Iterator = 0 ; local_u8Iterator < MEXTI_NUMBER ; local_u8Iterator++){
		MEXTI_voidSelectPort(MEXTI_Config[local_u8Iterator].Line , MEXTI_Config[local_u8Iterator].Port);
		MEXTI_voidSetMode(MEXTI_Config[local_u8Iterator].Line ,MEXTI_Config[local_u8Iterator].Mode);
		switch (MEXTI_Config[local_u8Iterator].State) {
			case MEXTI_ENABLED:
				MEXTI_voidEnableEXTILine(MEXTI_Config[local_u8Iterator].Line);
				break;
			case MEXTI_DISABLED:
				MEXTI_voidDisableEXTILine(MEXTI_Config[local_u8Iterator].Line);
				break;
			default:
				break;
		}
	}
}

void MEXTI_voidEnableEXTILine(MEXTI_LINE_t copy_MEXTI_LINE){
	SET_BIT(EXTI->IMR , copy_MEXTI_LINE);
}
void MEXTI_voidDisableEXTILine(MEXTI_LINE_t copy_MEXTI_Line){
	CLR_BIT(EXTI->IMR , copy_MEXTI_Line);
}

void MEXTI_voidSetCallBack(MEXTI_LINE_t copy_MEXTI_Line , PtrToFunc_void P_CallBackFunction){
	MEXTI_CallBack[copy_MEXTI_Line] = P_CallBackFunction;
}

void MEXTI_voidSoftwareInterruptRequest(MEXTI_LINE_t copy_MEXTI_Line){
	SET_BIT(EXTI->SWIER , copy_MEXTI_Line);
}

void MEXTI_voidClearPendingFlag(MEXTI_LINE_t copy_MEXTI_Line){
	SET_BIT(EXTI->PR , copy_MEXTI_Line);
}

void MEXTI_voidSelectPort(MEXTI_LINE_t copy_MEXTI_Line , MEXTI_PORT_t copy_EXTI_Port ){
	(SYSCFG->EXTICR)[copy_MEXTI_Line / 4] &= ~(FOUR_BIT_MASK   << ( 4 * (copy_MEXTI_Line % 4)));
	(SYSCFG->EXTICR)[copy_MEXTI_Line / 4] |=  (copy_EXTI_Port  << ( 4 * (copy_MEXTI_Line % 4)));
}

void MEXTI_voidSetMode(MEXTI_LINE_t copy_MEXTI_Line , MEXTI_MODE_t copy_EXTI_Mode){
	switch(copy_EXTI_Mode){
	case MEXTI_FALLING_EDGE:
		SET_BIT(EXTI->FTSR , copy_MEXTI_Line);
		break;
	case MEXTI_RISING_EDGE:
		SET_BIT(EXTI->RTSR , copy_MEXTI_Line);
		break;
	default:
		SET_BIT(EXTI->FTSR , copy_MEXTI_Line);
		SET_BIT(EXTI->RTSR , copy_MEXTI_Line);
		break;
	}
}
