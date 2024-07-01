/*
 * MRCC_Progarm.c
 *
 *  Created on: Feb 1, 2024
 *      Author: r0wan
 */

/*LIB*/

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/*MCAL*/

#include "../include/MRCC_Config.h"
#include "../include/MRCC_Private.h"
#include "../include/MRCC_Interface.h"

/*Functions Definitions*/

void MRCC_voidInit(void)
{
# if SYS_CLK == RCC_HSI

/*ENABLE HSI*/
SET_BIT(RCC->CR , RCC_CR_HSI_ON);
/*TILL IT TO BE READY*/
while(GET_BIT(RCC->CR , RCC_CR_HSI_RDY) == RCC_NOT_READY);
RCC->CFGR &=(TWO_BIT_MASK << SW_BIT0);
/*SELECT HSI AS SYS CLK*/
RCC->CFGR |= (SW_HSI <<SW_BIT0);
#elif SYS_CLK == RCC_HSE

/*ENABLE HSE*/
SET_BIT(RCC->CR , RCC_CR_HSE_ON);
/*TILL IT TO BE READY*/
while(GET_BIT(RCC->CR , RCC_CR_HSE_RDY) == RCC_NOT_READY);
RCC->CFGR &=(TWO_BIT_MASK << SW_BIT0);
/*SELECT HSE AS SYS CLK*/
RCC->CFGR |= (SW_HSE <<SW_BIT0);

#elif SYS_CLK == RCC_PLL

/*ENABLE PLL*/
SET_BIT(RCC->CR , RCC_CR_PLL_ON);
/*TILL IT TO BE READY*/
while(GET_BIT(RCC->CR , RCC_CR_PLL_RDY) == RCC_NOT_READY);
RCC->CFGR &=(TWO_BIT_MASK << SW_BIT0);
/*SELECT HSI AS SYS CLK*/
RCC->CFGR |= (SW_PLL <<SW_BIT0);

#else
#error "Wrong SYS_CLK configuration parameter"

#endif

}
void MRCC_voidEnablePeripheral(u32 copyu32_BusSddress , u32 copyu32_Peripheral)
{
	switch(copyu32_BusSddress)
	{
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,copyu32_Peripheral);
		  break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR,copyu32_Peripheral);
		  break;
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,copyu32_Peripheral);
		  break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,copyu32_Peripheral);
		   break;
	default:
		   break;
	}

}
void MRCC_voidDisablePeripheral(u32 copyu32_BusSddress , u32 copyu32_Peripheral)
{
	switch(copyu32_BusSddress)
	{
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,copyu32_Peripheral);
		  break;
	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR,copyu32_Peripheral);
		  break;
	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR,copyu32_Peripheral);
		  break;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR,copyu32_Peripheral);
		   break;
	default:
		   break;
	}

}

void MRCC_voidSetAPB1Prescaler(u8 copyu8APB1Prescaler)
{
	RCC-> CFGR &= ~(THREE_BIT_MASK <<CFGR_PREF1);
	RCC-> CFGR |= (copyu8APB1Prescaler <<CFGR_PREF1);

}
void MRCC_voidSetAPB2Prescaler(u8 copyu8APB2Prescaler)
{
	RCC-> CFGR &= ~(THREE_BIT_MASK <<CFGR_PREF1);
	RCC-> CFGR |= (copyu8APB2Prescaler <<CFGR_PREF1);
}
void MRCC_voidSetAHBPrescaler(u8 copyu8AHBPrescaler)
{
	RCC-> CFGR &= ~(THREE_BIT_MASK <<CFGR_PREF1);
	RCC-> CFGR |= (copyu8AHBPrescaler <<CFGR_PREF1);
}

