
/****************** LIB **********************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/****************** MCAL **********************/
#include "../include/MGPIO_Interface.h"
#include "../include/MSTK_Interface.h"

/****************** HAL **********************/
#include "../include/HLEDMATRIX_Config.h"
#include "../include/HLEDMATRIX_Interface.h"
#include "../include/HLEDMATRIX_Private.h"


/*********************** Functions Definitions ******************************/
void HLEDMATRIX_voidInit(void){
	/********* Port A ************/
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN0, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN1, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN2, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN3, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN4, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN5, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN6, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN6, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN7, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	/********* Port B ************/
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN0, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN1, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN2, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN2, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN5, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN5, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN6, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN6, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN7, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN7, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN8, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN8, GPIO_PUSH_PULL, GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN9, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(GPIO_PORTB, GPIO_PIN9, GPIO_PUSH_PULL, GPIO_LOW_SPEED);
}

void HLEDMATRIX_voidDisableColumns(void){
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_PIN_LOW);
}
void HLEDMATRIX_voidSetRowValue(u8 copy_u8RowValue){
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN0, !(GET_BIT(copy_u8RowValue, 0)));
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN1, !(GET_BIT(copy_u8RowValue, 1)));
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN2, !(GET_BIT(copy_u8RowValue, 2)));
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN5, !(GET_BIT(copy_u8RowValue, 3)));
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN6, !(GET_BIT(copy_u8RowValue, 4)));
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN7, !(GET_BIT(copy_u8RowValue, 5)));
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN8, !(GET_BIT(copy_u8RowValue, 6)));
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN9, !(GET_BIT(copy_u8RowValue, 7)));
}
void HLEDMATRIX_voidDisplay(u8 *copy_u8Array){
	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[0]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);

	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[1]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);

	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[2]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);

	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[3]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);

	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[4]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);

	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[5]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);

	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[6]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);

	HLEDMATRIX_voidDisableColumns();
	HLEDMATRIX_voidSetRowValue(copy_u8Array[7]);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_PIN_HIGH);
	MSTK_voidDelayus(2500);
}
