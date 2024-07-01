/*
 * MEXTI_Config.c
 *
 *  Created on: Feb 7, 2024
 *      Author: r0wan
 */

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"
#include "../include/MEXTI_Interface.h"
#include "../include/MEXTI_private.h"
#include "../include/MEXTI_Config.h"


/*
 * MEXTI_Configuartions {
	 * Line
	 * Port
	 * Mode
	 * Initial Value
 * }
 */


MEXTI_Configuration MEXTI_Config [MEXTI_NUMBER] =
{
		{
				MEXTI_LINE0,
				MEXTI_PortB,
				MEXTI_RISING_EDGE,
				MEXTI_ENABLED
		}
		,
		{
				MEXTI_LINE1,
				MEXTI_PortB,
				MEXTI_RISING_EDGE,
				MEXTI_ENABLED
		}
};


