/*
 * MSTK_Interface.h
 *
 *  Created on: Feb 6, 2024
 *      Author: r0wan
 */

#ifndef MSTK_INTERFACE_H_
#define MSTK_INTERFACE_H_

/*FUNCTION PROTYPESS*/
void MSTK_voidInit(void);
void MSTK_voidClearCurrentValue(void);
void MSTK_voidSetPreloadValue(u32 copy_u32PreloadValue);
void MSTK_voidGetFlagValue(u8 *p_Read);
void MSTK_voidEnableSTK(void);
void MSTK_voidDisableSTK(void);
void MSTK_voidGetElapsedTime(u32 *p_Read);
void MSTK_voidGetRemainingTime(u32 *p_Read);
void MSTK_voidEnableInterrup(void);
void MSTK_voidDisableInterrup(void);
void MSTK_voidDelayms(u32 copy_u32Delay32);
void MSTK_voidDelayus(u32 copy_u32Delay32);

#endif /* MSTK_INTERFACE_H_ */
