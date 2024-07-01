/*
 * EXTI_private.h
 *
 *  Created on: Feb 6, 2024
 *      Author: r0wan
 */

#ifndef MEXTI_PRIVATE_H
#define MEXTI_PRIVATE_H

/***** SYSCFG *****/
#define SYSCFG_BASE_ADDRESS		(0x40013800)

typedef struct
{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;
} SYSCFG_t ;

#define SYSCFG ((volatile SYSCFG_t*) SYSCFG_BASE_ADDRESS)

/***** EXTI *****/
#define MEXTI_BASE_ADDRESS		(0x40013C00)

typedef struct{
	u32	IMR;
	u32	EMR;
	u32	RTSR;
	u32	FTSR;
	u32	SWIER;
	u32	PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t*) MEXTI_BASE_ADDRESS)

/********* MEXTI Macros *********/
#define MEXIT_TOTAL_LINE_NUMBER		16
#define FOUR_BIT_MASK				0b1111

/********* MEXTI Configuration Struct *********/
typedef struct
{
	MEXTI_LINE_t 	Line;
	MEXTI_PORT_t 	Port;
	MEXTI_MODE_t	Mode;
	MEXTI_STATE_t	State;

} MEXTI_Configuration;

#endif /* MEXTI_PRIVATE_H */
