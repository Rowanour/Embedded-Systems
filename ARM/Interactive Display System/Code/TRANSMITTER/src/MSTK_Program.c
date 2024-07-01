
/*LIB*/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/* MCAL */

#include "../include/MSTK_Config.h"
#include "../include/MSTK_Private.h"
#include "../include/MSTK_Interface.h"

void(*Globe_voidPointerToFunc)(void) = NULL;
u8 GlobeSingleFlag = 0;
/*FUNCTION DEFINITIONS**/
void MSTK_voidInit(void)
{

	/****SELECT CLK Source*******/
	#if MST_CLK_SOURCE == MSTK_AHB_BY_8
		CLR_BIT(STK->CTRL,CLKSOURCE);

	#elif MST_CLK_SOURCE == MSTK_AHB
		SET_BIT(STK->CTRL,CLKSOURCE);
	#else
	#error "Wrong MSTK CLK SOURCE Configuration Parameter"
	#endif
	}
	void MSTK_voidClearCurrentValue(void)
	{
		STK->VAL =0;
	}
	void MSTK_voidSetPreLoadValue(u32 copy_u32PreLoadValue)
	{
		STK->LOAD =copy_u32PreLoadValue & STK_RES;
	}
	void MSTK_voidGetFlagValue(u8 *p_Read)
	{
		*p_Read = GET_BIT(STK-> CTRL,COUNTFLAG);
	}
	void MSTK_voidEnableSTK(void)
	{
		SET_BIT(STK->CTRL,ENABLE);
	}
	void MSTK_voidDisableSTK(void)
	{
		CLR_BIT(STK->CTRL,ENABLE);
	}
	void MSTK_voidGetElapsedTime(u32 *p_Read)
	{
		*p_Read= (STK->LOAD)-(STK->VAL);
	}
	void MSTK_voidGetRemainingTime(u32 *p_Read)
	{
		*p_Read= STK->VAL;
	}
	void MSTK_voidEnableInterrupt(void)
	{
		SET_BIT(STK->CTRL ,TICKINT);
	}
	void MSTK_voidDisableInterrupt(void)
	{
		CLR_BIT(STK->CTRL ,TICKINT);
	}
	void MSTK_voidDelayms(u32 copy_u32Delayms)
	{
		/* Calculate The needed Preload Value***/
		u32 local_u32PreloadValue = copy_u32Delayms * (STK_FREQ/1000);
		STK->LOAD = local_u32PreloadValue;
		/*** RESET THE CURRENT VALUE ****/
		STK->VAL = 0;
		/*** SET SYSTICLK ****/
		SET_BIT(STK->CTRL,ENABLE);

		while(GET_BIT(STK->CTRL,COUNTFLAG)==0);

		/*** CLR SYSTICLK ****/
			CLR_BIT(STK->CTRL,ENABLE);
	}
	void MSTK_voidDelayus(u32 copy_u32Delayus)
	{
		/* Calculate The needed Preload Value***/
			u32 local_u32PreloadValue = copy_u32Delayus * (STK_FREQ/1000000);
			STK->LOAD = local_u32PreloadValue;
			/*** RESET THE CURRENT VALUE ****/
			STK->VAL = 0;
			/*** SET SYSTICLK ****/
			SET_BIT(STK->CTRL,ENABLE);

			while(GET_BIT(STK->CTRL,COUNTFLAG)==0);

			/*** CLR SYSTICLK ****/
				CLR_BIT(STK->CTRL,ENABLE);
	}
