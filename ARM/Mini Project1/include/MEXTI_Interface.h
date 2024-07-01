/*
 * EXTI_Interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: r0wan
 */

#ifndef MEXTI_INTERFACE_H
#define MEXTI_INTERFACE_H


/****enums ****/
/*** EXTI Lines ***/
typedef enum
{
	MEXTI_LINE0      = 0,
	MEXTI_LINE1			,
	MEXTI_LINE2			,
	MEXTI_LINE3			,
	MEXTI_LINE4			,
	MEXTI_LINE5			,
	MEXTI_LINE6			,
	MEXTI_LINE7			,
	MEXTI_LINE8			,
	MEXTI_LINE9			,
	MEXTI_LINE10		,
	MEXTI_LINE11		,
	MEXTI_LINE12		,
	MEXTI_LINE13		,
	MEXTI_LINE14		,
	MEXTI_LINE15		,

} MEXTI_LINE_t;

/*** EXTI Ports ***/
typedef enum
{
	MEXTI_PortA 	 = 0,
	MEXTI_PortB			,
	MEXTI_PortC			,
	MEXTI_PortD			,
	MEXTI_PortE			,
	MEXTI_PortH		 = 7,
} MEXTI_PORT_t;

/*** EXTI Modes ***/
typedef enum
{
	MEXTI_RISING_EDGE = 0,
	MEXTI_FALLING_EDGE	 ,
	MEXTI_ON_CHANGE		 ,
} MEXTI_MODE_t;

/*** EXTI States ***/
typedef enum
{
	MEXTI_DISABLED 		 = 0,
	MEXTI_ENABLED			,
} MEXTI_STATE_t;

/********* Function Prototypes *********/
void MEXTI_voidInit(void);

void MEXTI_voidEnableEXTILine(MEXTI_LINE_t copy_MEXTI_Line);
void MEXTI_voidDisableEXTILine(MEXTI_LINE_t copy_MEXTI_Line);

void MEXTI_voidSetCallBack(MEXTI_LINE_t copy_MEXTI_Line , PtrToFunc_void P_CallBackFunction);
void MEXTI_voidSoftwareInterruptRequest(MEXTI_LINE_t copy_MEXTI_Line);
void MEXTI_voidClearPendingFlag(MEXTI_LINE_t copy_MEXTI_Line);
void MEXTI_voidSelectPort(MEXTI_LINE_t copy_MEXTI_Line , MEXTI_PORT_t copy_EXTI_Port );
void MEXTI_voidSetMode(MEXTI_LINE_t copy_MEXTI_Line , MEXTI_MODE_t copy_EXTI_Mode);
#endif /* MEXTI_INTERFACE_H */
