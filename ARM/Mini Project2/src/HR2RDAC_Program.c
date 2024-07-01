/*
 * HR2RDAC_Program.c
 *
 *  Created on: Feb 11, 2024
 *      Author: r0wan
 */
/*LIB*/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/*MCAL*/
#include "../include/MGPIO_Interface.h"
#include "../include/MSTK_Interface.h"

/* HAL */

#include "../include/HR2RDAC_Config.h"
#include "../include/HR2RDAC_Private.h"
#include "../include/HR2RDAC_Interface.h"

void HR2RDAC_voidInit(void)
{
	    /**SET DAC PINS MODE TO OUTPUT***/
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN0 , GPIO_OUTPUT );
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN1 , GPIO_OUTPUT );
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN2 , GPIO_OUTPUT );
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN3 , GPIO_OUTPUT );
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN4 , GPIO_OUTPUT );
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN5 , GPIO_OUTPUT );
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN6 , GPIO_OUTPUT );
		MGPIO_voidSetPinMode(DAC_PORT, GPIO_PIN7 , GPIO_OUTPUT );

		/***SET DAC PINS OUTPUT MODE TO PUSH_PULL AND SPEED MEDUIM ***/

		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN0 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN1 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN2 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN3 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN4 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN5 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN6 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinOutputMode( DAC_PORT , GPIO_PIN7 , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
}
void HR2RDAC_voidSendData(u8 *p_u8Arr , u32 copy_u32ArraySize)
{
	/*INTIALIZE AN ITERATOR ON THE GIVEN ARRAY*/
	u32 local_u8Iterator =0;
	for(local_u8Iterator ; local_u8Iterator<copy_u32ArraySize ; local_u8Iterator++)
	{
		/*SET THOSE BITS BASED ON THE GIVEN VALUE*/
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN0 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN0));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN1 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN1));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN2 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN2));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN3 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN3));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN4 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN4));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN5 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN5));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN6 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN6));
		MGPIO_voidSetPinValue(DAC_PORT , GPIO_PIN7 , GET_BIT(p_u8Arr[local_u8Iterator] , GPIO_PIN7));

		/*MAKE A DELAY USING SYSTICK TO ACHIEVE 8KHZ*/
		MSTK_voidDelayus(DELAY_US);

	}

}

