/** LIB **/
#include <TFT_Arrays.h>
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/* MCAL */
#include "../include/MRCC_Interface.h"
#include "../include/MSTK_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MUSART_Interface.h"
#include "../include/HLCD_Interface.h"
#include "../include/MSPI_Interface.h"
#include "../include/HTFT_Interface.h"




u8 customChar[] = {
		0x0A,
		0x1B,
		0x15,
		0x15,
		0x11,
		0x0A,
		0x0A,
		0x04
};

u8 Global_u8RX ;


void handler_USART(void);

int main(void)
{

	MRCC_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOC);

	MRCC_voidEnablePeripheral(RCC_APB1,RCC_APB1_SPI2);


	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);

	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN9,0b0111);
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN10,0b0111);

	MNVIC_voidEnablePeripheralInterrupt(37);
	MSUART_voidSetCallBack(handler_USART);

	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);

	LCD_voidInit();

	LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN2);
	LCD_voidSendString(	(const u8*)"Welcome To");
	LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
	LCD_voidSendString((const u8*)"POWERPUFF GIRLS");
	MSTK_voidDelayms(500);

	LCD_voidClearScreen();
	LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
	LCD_voidSendString((const u8*)"Choose:");
	LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
	LCD_voidSendString((const u8*)"(1) (2) (3)");

	HTFT_voidInit();


	while(1){


	}

	return 0;
}

void handler_USART(void){

	MUSART_voidReceive(MUSART_USART1, &Global_u8RX);
	if(Global_u8RX == 'a'){
	LCD_voidInit();


	LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN1);
	LCD_voidSendString((u8*)" BLOSSOM");

	LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN1);
	LCD_voidSendString((u8*)"POWERPUFF GIRLS");

	LCD_voidSendCustomCharacter(customChar,1,1,15);
	MSTK_voidDelayms(5000);
	HTFT_voidSendPicture(BLOSSOM);
	}

	else if(Global_u8RX == 'b')
	{

		LCD_voidInit();

		LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN1);
		LCD_voidSendString((u8*)" BUTTERCUP");

		LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN1);
		LCD_voidSendString((u8*)"POWERPUFF GIRLS");

		LCD_voidSendCustomCharacter(customChar,1,1,15);
		MSTK_voidDelayms(5000);
		HTFT_voidSendPicture(BUTTERCUP);
	}
	else if(Global_u8RX == 'c')
	{
		HTFT_voidClearScreen(0xFFFF);

		LCD_voidClearScreen();
	}

	}
