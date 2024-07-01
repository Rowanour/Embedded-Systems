#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"
#include "../include/MRCC_Interface.h"
#include "../include/MSTK_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MSPI_Interface.h"

#include "../include/HTFT_Interface.h"
#include "../include/HTFT_private.h"
#include "../include/HTFT_Config.h"



void HTFT_voidReset (void)
{
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayms(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MSTK_voidDelayms(1);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayms(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MSTK_voidDelayms(100);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_SET);
	MSTK_voidDelayms(120);


	/*Send command sleep out*/
	HTFT_voidSendCommand(SLEEP_OUT);

	/*wait 150 msec*/
	MSTK_voidDelayms(150);

	/*color mode command*/
	HTFT_voidSendCommand(MODE_SET_COLOR);
	/*RGB565*/
	HTFT_voidSendData(TFT_RGB565);

	/*Display command*/
	HTFT_voidSendCommand(DISPLAY_ON);

}

void HTFT_voidInit (void)
{
	MSTK_voidInit();

	MSPI_voidInit();

	MGPIO_voidSetPinMode(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
	MGPIO_voidSetResetPin(TFT_RESET_PORT , TFT_RESET_PIN , GPIO_RESET);
	MGPIO_voidSetPinMode(TFT_CS_PORT , TFT_CS_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_CS_PORT , TFT_CS_PIN , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);
	MGPIO_voidSetResetPin(TFT_CS_PORT , TFT_CS_PIN , GPIO_RESET);
	MGPIO_voidSetPinMode(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_PUSH_PULL , GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN13 , GPIO_ALT_FUNC);
	MGPIO_voidSetAltFunction(GPIO_PORTB , GPIO_PIN13 , 0b0101);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN14 , GPIO_ALT_FUNC);
	MGPIO_voidSetAltFunction(GPIO_PORTB , GPIO_PIN14 , 0b0101);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN15 , GPIO_ALT_FUNC);
	MGPIO_voidSetAltFunction(GPIO_PORTB , GPIO_PIN15 , 0b0101);

	HTFT_voidReset();

	HTFT_voidSendCommand(SLEEP_OUT);
	MSTK_voidDelayms(150);
	HTFT_voidSendCommand(MODE_SET_COLOR);
	HTFT_voidSendData(TFT_COLOR_MODE);
	HTFT_voidSendCommand(DISPLAY_ON);
	MSTK_voidDelayms(1);


}

void HTFT_voidSendPicture (const u16 *p_Picture)
{
	/*******************Send TFT Size******************/

	HTFT_voidSendCommand(SET_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_PIXELS_X-1);
	HTFT_voidSendCommand(SET_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_START_PIXEL_Y);
	HTFT_voidSendData(TFT_START_PIXEL_X);
	HTFT_voidSendData(TFT_PIXELS_Y-1);

	/****************Send Pixels***********************/
	u16 local_u16Iterator = 0;
	HTFT_voidSendCommand(MEMORY_WRITE);
	for (local_u16Iterator = 0 ; local_u16Iterator < (TFT_PIXELS_X*TFT_PIXELS_Y) ; local_u16Iterator++)
	{
		HTFT_voidSendData((u8)(p_Picture[local_u16Iterator]>>HIGH_BITS));
		HTFT_voidSendData((u8)p_Picture[local_u16Iterator]);
	}
}

static void HTFT_voidSendCommand (u8 A_u8Command)
{
	MGPIO_voidSetResetPin(TFT_CS_PORT , TFT_CS_PIN , GPIO_RESET);
	MGPIO_voidSetResetPin(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_RESET);
	MSPI_voidSendReceiveData(A_u8Command);
	MGPIO_voidSetResetPin(TFT_CS_PORT , TFT_CS_PIN , GPIO_SET);
}
static void HTFT_voidSendData (u8 A_u8Data)
{
	MGPIO_voidSetResetPin(TFT_CS_PORT , TFT_CS_PIN , GPIO_RESET);
	MGPIO_voidSetResetPin(TFT_CONTROL_PORT , TFT_CONTROL_PIN , GPIO_SET);
	MSPI_voidSendReceiveData(A_u8Data);
	MGPIO_voidSetResetPin(TFT_CS_PORT , TFT_CS_PIN , GPIO_SET);
}

void HTFT_voidClearScreen(u16 color)
{
    u32 total_pixels = TFT_PIXELS_X * TFT_PIXELS_Y;

    HTFT_voidSendCommand(SET_X);
    HTFT_voidSendData(TFT_START_PIXEL_Y);
    HTFT_voidSendData(TFT_START_PIXEL_X);
    HTFT_voidSendData(TFT_START_PIXEL_Y);
    HTFT_voidSendData(TFT_PIXELS_X - 1);

    HTFT_voidSendCommand(SET_Y);
    HTFT_voidSendData(TFT_START_PIXEL_X);
    HTFT_voidSendData(TFT_START_PIXEL_Y);
    HTFT_voidSendData(TFT_START_PIXEL_X);
    HTFT_voidSendData(TFT_PIXELS_Y - 1);

    HTFT_voidSendCommand(MEMORY_WRITE);
    for (u32 i = 0; i < total_pixels; i++)
    {
        HTFT_voidSendData((u8)(color >> HIGH_BITS));
        HTFT_voidSendData((u8)color);
    }
}

