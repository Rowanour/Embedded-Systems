
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"


#include "../include/MRCC_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MUSART_Interface.h"
#include "../include/MSTK_Interface.h"
#include "../include/HLEDMATRIX_Interface.h"


u8 arr1[58][8]=
{
		{0, 0, 255, 137, 137, 137, 118, 0},
		{0, 255, 137, 137, 137, 118, 0, 0},
		{255, 137, 137, 137, 118, 0, 0, 0},
		{137, 137, 137, 118, 0, 0, 0, 0},
		{137, 137, 118, 0, 0, 0, 0, 0},
		{137, 118, 0, 0, 0, 0, 0, 0},
		{118, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{255, 255, 192, 192, 192, 192, 0, 0},
		{255, 192, 192, 192, 192, 0, 0, 0},
		{192, 192, 192, 192, 0, 0, 0, 0},
		{192, 192, 192, 0, 0, 0, 0, 0},
		{192, 192, 0, 0, 0, 0, 0, 0},
		{192, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},

		{60, 66, 129, 129, 129, 129, 66, 60},
		{66, 129, 129, 129, 129, 66, 60 ,0},
		{129, 129, 129, 129, 66, 60, 0, 0},
		{129, 129, 129, 66, 60, 0, 0, 0},
		{129, 129, 66, 60, 0, 0, 0, 0},
		{129, 66, 60, 0, 0, 0, 0, 0},
		{66, 60, 0, 0, 0, 0, 0, 0},
		{60, 0, 0, 0, 0, 0, 0, 0},
		{0,0,0,0,0,0,0,0},


		{0, 206, 145, 145, 145, 145, 114, 0},
		{206, 145, 145, 145, 145, 114, 0, 0},
		{145, 145, 145, 145, 114, 0, 0, 0},
		{145, 145, 145, 114, 0, 0, 0, 0},
		{145, 145, 114, 0, 0, 0, 0, 0},
		{145, 114, 0, 0, 0, 0, 0, 0},
		{114, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},



		{0, 206, 145, 145, 145, 145, 114, 0},
		{206, 145, 145, 145, 145, 114, 0, 0},
		{145, 145, 145, 145, 114, 0, 0, 0},
		{145, 145, 145, 114, 0, 0, 0, 0},
		{145, 145, 114, 0, 0, 0, 0, 0},
		{145, 114, 0, 0, 0, 0, 0, 0},
		{114, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{60, 66, 129, 129, 129, 129, 66, 60},
		{66, 129, 129, 129, 129, 66, 60 ,0},
		{129, 129, 129, 129, 66, 60, 0, 0},
		{129, 129, 129, 66, 60, 0, 0, 0},
		{129, 129, 66, 60, 0, 0, 0, 0},
		{129, 66, 60, 0, 0, 0, 0, 0},
		{66, 60, 0, 0, 0, 0, 0, 0},
		{60, 0, 0, 0, 0, 0, 0, 0},
		{0,0,0,0,0,0,0,0},



		{255, 1, 2, 4, 4, 2, 1, 255},
		{1, 2, 4, 4, 2, 1, 255, 0},
		{2, 4, 4, 2, 1, 255, 0, 0},
		{4, 4, 2, 1, 255, 0, 0, 0},
		{4, 2, 1, 255, 0, 0, 0, 0},
		{2, 1, 255, 0, 0, 0, 0, 0},
		{1, 255, 0, 0, 0, 0, 0, 0},
		{255, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
};



u8 arr2[69][8]=
{
		{0, 0, 255, 137, 137, 137, 118, 0},
		{0, 255, 137, 137, 137, 118, 0, 0},
		{255, 137, 137, 137, 118, 0, 0, 0},
		{137, 137, 137, 118, 0, 0, 0, 0},
		{137, 137, 118, 0, 0, 0, 0, 0},
		{137, 118, 0, 0, 0, 0, 0, 0},
		{118, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{0, 252, 128, 128, 128, 128, 252, 0},
		{252, 128, 128, 128, 128, 252, 0, 0},
		{128, 128, 128, 128, 252, 0, 0, 0},
		{128, 128, 128, 252, 0, 0, 0, 0},
		{128, 128, 252, 0, 0, 0, 0, 0},
		{128, 252, 0, 0, 0, 0, 0, 0},
		{252, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{3, 3, 3, 255, 255, 3, 3, 3},
		{3, 3, 255, 255, 3, 3, 3, 0},
		{3, 255, 255, 3, 3, 3, 0, 0},
		{255, 255, 3, 3, 3, 0, 0, 0},
		{255, 3, 3, 3, 0, 0, 0, 0},
		{3, 3, 3, 0, 0, 0, 0, 0},
		{3, 3, 0, 0, 0, 0, 0, 0},
		{3, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{3, 3, 3, 255, 255, 3, 3, 3},
		{3, 3, 255, 255, 3, 3, 3, 0},
		{3, 255, 255, 3, 3, 3, 0, 0},
		{255, 255, 3, 3, 3, 0, 0, 0},
		{255, 3, 3, 3, 0, 0, 0, 0},
		{3, 3, 3, 0, 0, 0, 0, 0},
		{3, 3, 0, 0, 0, 0, 0, 0},
		{3, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{255, 137, 137, 137, 137, 129, 0, 0},
		{137, 137, 137, 137, 129, 0, 0, 0},
		{137, 137, 137, 129, 0, 0, 0, 0},
		{137, 137, 129, 0, 0, 0, 0, 0},
		{137, 129, 0, 0, 0, 0, 0, 0},
		{129, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{255, 9, 25, 41, 73, 134, 0, 0},
		{9, 25, 41, 73, 134, 0, 0, 0},
		{25, 41, 73, 134, 0, 0, 0, 0},
		{41, 73, 134, 0, 0, 0, 0, 0},
		{73, 134, 0, 0, 0, 0, 0, 0},
		{134, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{126, 129, 129, 129, 129, 66, 0, 0},
		{129, 129, 129, 129, 66, 0, 0, 0},
		{129, 129, 129, 66, 0, 0, 0, 0},
		{129, 129, 66, 0, 0, 0, 0, 0},
		{129, 66, 0, 0, 0, 0, 0, 0},
		{66, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{0, 252, 128, 128, 128, 128, 252, 0},
		{252, 128, 128, 128, 128, 252, 0, 0},
		{128, 128, 128, 128, 252, 0, 0, 0},
		{128, 128, 128, 252, 0, 0, 0, 0},
		{128, 128, 252, 0, 0, 0, 0, 0},
		{128, 252, 0, 0, 0, 0, 0, 0},
		{252, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},


		{255, 17, 17, 17, 14, 0, 0, 0},
		{17, 17, 17, 14, 0, 0, 0, 0},
		{17, 17, 14, 0, 0, 0, 0, 0},
		{17, 14, 0, 0, 0, 0, 0, 0},
		{14, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},

};

void main (void){


	MRCC_voidInit();
	MSTK_voidInit();

	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1 , RCC_AHB1_GPIOB);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN12, GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB, GPIO_PIN12,GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN13, GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB, GPIO_PIN13,GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN14, GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB, GPIO_PIN14,GPIO_PULLUP);

	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN3, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN4, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN10, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN15, GPIO_OUTPUT);


	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);

	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN9,0b0111);
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN10,0b0111);

	MNVIC_voidEnablePeripheralInterrupt(37);


	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);



	u8 b1;
	u8 b2;
	u8 b3;

	while(1){
	MGPIO_voidGetPinValue(GPIO_PORTB, GPIO_PIN12, &b1);
	MGPIO_voidGetPinValue(GPIO_PORTB, GPIO_PIN13, &b2);
	MGPIO_voidGetPinValue(GPIO_PORTB, GPIO_PIN14, &b3);

	if (b1 == GPIO_PIN_LOW)
	{
	MUSART_voidTransmit(MUSART_USART1, (u8*)"a" , 1);
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN4, GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN10, GPIO_PIN_HIGH);
	MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN15, GPIO_PIN_LOW);

	HLEDMATRIX_voidInit();
		for(int i = 0; i<58; i++){
			HLEDMATRIX_voidDisplay(arr1[i]);
			MSTK_voidDelayms(50);
		}

	}

	else if(b2 == GPIO_PIN_LOW)
	{
		MUSART_voidTransmit(MUSART_USART1, (u8*)"b" , 1);

		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN4, GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN10, GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN15, GPIO_PIN_HIGH);

		HLEDMATRIX_voidInit();


			for(int i = 0; i<69; i++){
				HLEDMATRIX_voidDisplay(arr2[i]);
				MSTK_voidDelayms(50);
			}
	}

	else if(b3 == GPIO_PIN_LOW)
	{
		MUSART_voidTransmit(MUSART_USART1, (u8*)"c" , 1);
		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN3, GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN4, GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN10, GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTB, GPIO_PIN15, GPIO_PIN_LOW);
	}

	}
}
