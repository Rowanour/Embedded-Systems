/*
 * MSTK_Private.h
 *
 *  Created on: Feb 6, 2024
 *      Author: r0wan
 */

#ifndef MSTK_PRIVATE_H_
#define MSTK_PRIVATE_H_

#define STK_BASE_ADDRESS (0xE000E010)

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_t;

#define STK   ((volatile STK_t*)STK_BASE_ADDRESS)

#define MSTK_AHB         1
#define MSTK_AHB_BY_8    0

#define STK_RES          (0x00FFFFFF)

#define ENABLE           0
#define TICKINT          1
#define CLKSOURCE        2
#define COUNTFLAG        16

#define STK_FREQ          16000000

#endif /* MSTK_PRIVATE_H_ */
