
/* LIB */

#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/* MCAL */

#include "../include/MGPIO_Config.h"
#include "../include/MGIO_Private.h"
#include "../include/MGPIO_Interface.h"

void MGPIO_voidSetPortValue(u8 copyu8Port, u8 copyu8Value)
{
	switch(copyu8Port)
	{
	case GPIO_PORTA:
		GPIOA->ODR = copyu8Value;
		break;

	case GPIO_PORTB:
		GPIOA->ODR = copyu8Value;
		break;

	case GPIO_PORTC:
		GPIOA->ODR = copyu8Value;
		break;

	default:
		break;
	}
}

void MGPIO_voidSetPinMode(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Mode){
	if((copyu8Port == GPIO_PORTA) && ((copyu8Port == GPIO_PIN13) || (copyu8Port == GPIO_PIN14) || (copyu8Port == GPIO_PIN15))){
		/* Do Nothing */
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Port == GPIO_PIN3) || (copyu8Port == GPIO_PIN4))){
		/* Do Nothing */
	}

	else{
		switch(copyu8Port){
		case GPIO_PORTA:
			GPIOA -> MODER &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
			GPIOA -> MODER |= (copyu8Mode << (2 * copyu8Pin));
			break;
		case GPIO_PORTB:
			GPIOB -> MODER &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
			GPIOB -> MODER |= (copyu8Mode << (2 * copyu8Pin));
			break;
		case GPIO_PORTC:
			GPIOC -> MODER &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
			GPIOC -> MODER |= (copyu8Mode << (2 * copyu8Pin));
			break;
		default:
			break;
		}
	}
}

void MGPIO_voidSetPinOutputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyOutputMode, u8 copyu8Speed){
	if((copyu8Port == GPIO_PORTA) && ((copyu8Port == GPIO_PIN13) || (copyu8Port == GPIO_PIN14) || (copyu8Port == GPIO_PIN15))){
		/* Do Nothing */
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Port == GPIO_PIN3) || (copyu8Port == GPIO_PIN4))){
		/* Do Nothing */
	}

	else{
		switch(copyu8Port){
			case GPIO_PORTA:

			                     /* Set Speed */
				GPIOA -> OSPEEDR &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
				GPIOA -> OSPEEDR |= (copyu8Speed << (2 * copyu8Pin));

				GPIOA -> OTYPER &= ~(ONE_BIT_MASK << (copyu8Pin));
				GPIOA -> OTYPER |= (copyOutputMode << (copyu8Pin));
				break;
			case GPIO_PORTB:
				GPIOB -> OSPEEDR &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
				GPIOB -> OSPEEDR |= (copyu8Speed << (2 * copyu8Pin));

				GPIOB -> OTYPER &= ~(ONE_BIT_MASK << (copyu8Pin));
				GPIOB -> OTYPER |= (copyOutputMode << (copyu8Pin));
				break;
			case GPIO_PORTC:
				GPIOC -> OSPEEDR &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
				GPIOC -> OSPEEDR |= (copyu8Speed << (2 * copyu8Pin));

				GPIOC -> OTYPER &= ~(ONE_BIT_MASK << (copyu8Pin));
				GPIOC -> OTYPER |= (copyOutputMode << (copyu8Pin));
				break;
			default:
				break;
		}
	}
}

void MGPIO_voidSetPinInputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyInputMode){
	if((copyu8Port == GPIO_PORTA) && ((copyu8Port == GPIO_PIN13) || (copyu8Port == GPIO_PIN14) || (copyu8Port == GPIO_PIN15))){
		/* Do Nothing */
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Port == GPIO_PIN3) || (copyu8Port == GPIO_PIN4))){
		/* Do Nothing */
	}

	else{
		switch(copyu8Port){
			case GPIO_PORTA:
				GPIOA -> PUPDR &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
				GPIOA -> PUPDR |= (copyInputMode << (2 * copyu8Pin));
				break;

			case GPIO_PORTB:
				GPIOB -> PUPDR &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
				GPIOB -> PUPDR |= (copyInputMode << (2 * copyu8Pin));
				break;

			case GPIO_PORTC:
				GPIOC -> PUPDR &= ~(TWO_BIT_MASK << (2 * copyu8Pin));
				GPIOC -> PUPDR |= (copyInputMode << (2 * copyu8Pin));
				break;

			default:
				break;
			}
		}
}

void MGPIO_voidSetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Output){
	if((copyu8Port == GPIO_PORTA) && ((copyu8Port == GPIO_PIN13) || (copyu8Port == GPIO_PIN14) || (copyu8Port == GPIO_PIN15))){
			/* Do Nothing */
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Port == GPIO_PIN3) || (copyu8Port == GPIO_PIN4))){
		/* Do Nothing */
	}

	else{
		switch(copyu8Port){
			case GPIO_PORTA:
				switch(copyu8Output){
					case GPIO_PIN_HIGH:
						SET_BIT(GPIOA -> ODR, copyu8Pin);
						break;

					case GPIO_PIN_LOW:
						CLR_BIT(GPIOA -> ODR, copyu8Pin);
						break;
					}
				break;

			case GPIO_PORTB:
				switch(copyu8Output){
					case GPIO_PIN_HIGH:
						SET_BIT(GPIOB -> ODR, copyu8Pin);
						break;

					case GPIO_PIN_LOW:
						CLR_BIT(GPIOB -> ODR, copyu8Pin);
						break;
					}
				break;

			case GPIO_PORTC:
				switch(copyu8Output){
					case GPIO_PIN_HIGH:
						SET_BIT(GPIOC -> ODR, copyu8Pin);
						break;

					case GPIO_PIN_LOW:
						CLR_BIT(GPIOC -> ODR, copyu8Pin);
						break;
					}
				break;

		default:
			break;
		}
	}
}

void MGPIO_voidGetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 *pu8Return){
	if((copyu8Port == GPIO_PORTA) && ((copyu8Port == GPIO_PIN13) || (copyu8Port == GPIO_PIN14) || (copyu8Port == GPIO_PIN15))){
		/* Do Nothing */
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Port == GPIO_PIN3) || (copyu8Port == GPIO_PIN4))){
		/* Do Nothing */
	}

	else{
		switch(copyu8Port){
			case GPIO_PORTA:
				*pu8Return = GET_BIT(GPIOA -> IDR, copyu8Pin);
				break;

			case GPIO_PORTB:
				*pu8Return = GET_BIT(GPIOB -> IDR, copyu8Pin);
				break;

			case GPIO_PORTC:
				*pu8Return = GET_BIT(GPIOC -> IDR, copyu8Pin);
				break;

		default:
			break;
		}
	}
}

void MGPIO_voidSetResetPin(u8 copyu8Port, u8 copyu8Pin, u8 copyu8SetResetValue){
	if((copyu8Port == GPIO_PORTA) && ((copyu8Port == GPIO_PIN13) || (copyu8Port == GPIO_PIN14) || (copyu8Port == GPIO_PIN15))){
		/* Do Nothing */
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Port == GPIO_PIN3) || (copyu8Port == GPIO_PIN4))){
		/* Do Nothing */
	}

	else{
		switch(copyu8Port){
			case GPIO_PORTA:
				switch(copyu8SetResetValue){
					case GPIO_SET:
						GPIOA -> BSRR = (1 << copyu8Pin);
						break;
					case GPIO_RESET:
						GPIOA -> BSRR = (1 << (copyu8Pin + 16));
						break;
					default:
						break;
				}
				break;

			case GPIO_PORTB:
				switch(copyu8SetResetValue){
					case GPIO_SET:
						GPIOB -> BSRR = (1 << copyu8Pin);
						break;
					case GPIO_RESET:
						GPIOB -> BSRR = (1 << (copyu8Pin + 16));
						break;
					default:
						break;
					}
				break;

			case GPIO_PORTC:
				switch(copyu8SetResetValue){
					case GPIO_SET:
						GPIOC -> BSRR = (1 << copyu8Pin);
						break;
					case GPIO_RESET:
						GPIOC -> BSRR = (1 << (copyu8Pin + 16));
						break;
					default:
						break;
				}
				break;

		default:
			break;
		}
	}
}


void MGPIO_voidSetAltFunction(u8 copyu8Port, u8 copyu8Pin, u8 copyu8AltFunc)
{
	if((copyu8Port == GPIO_PORTA) && ((copyu8Pin == GPIO_PIN13) ||(copyu8Pin == GPIO_PIN14)||(copyu8Pin == GPIO_PIN15)))
	{
		/*Do Nothing*/
	}

	else if((copyu8Port == GPIO_PORTB) && ((copyu8Pin == GPIO_PIN3) ||(copyu8Pin == GPIO_PIN4)))
	{
		/*Do Nothing*/
	}

	else
	{
		if(copyu8Pin <= 7)
		{
			switch(copyu8Port)
			{
			case GPIO_PORTA:
				GPIOA->AFRL |= (u32)(copyu8AltFunc << (4U*copyu8Pin));
				break;

			case GPIO_PORTB:
				GPIOB->AFRL |= (u32)(copyu8AltFunc << (4U*copyu8Pin));
				break;

			case GPIO_PORTC:
				GPIOC->AFRL |= (u32)(copyu8AltFunc << (4U*copyu8Pin));
				break;

			default:
				break;
			}
		}
		else
		{
			switch(copyu8Port)
			{
			case GPIO_PORTA:
				GPIOA->AFRH |= (u32)(copyu8AltFunc << (4U*(copyu8Pin%8)));
				break;

			case GPIO_PORTB:
				GPIOB->AFRH |= (u32)(copyu8AltFunc << (4U*(copyu8Pin%8)));
				break;

			case GPIO_PORTC:
				GPIOC->AFRH |= (u32)(copyu8AltFunc << (4U*(copyu8Pin%8)));
				break;

			default:
				break;
			}
		}
	}
}


