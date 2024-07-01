


/****************************LIB***************************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

/****************************MCAL**************************/
#include "../include/MGPIO_Interface.h"
#include "../include/MSTK_Interface.h"

/****************************HAL***************************/
#include "../include/HLCD_Config.h"
#include "../include/HLCD_Interface.h"
#include "../include/HLCD_Private.h"




/********************Functions Definitions*****************/
void LCD_voidInit(void)
{
	/************Set the control pins to be output**********/
	MGPIO_voidSetPinMode(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_CTRL_RW_PORT,LCD_RW_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_CTRL_RS_PORT,LCD_RS_PIN,GPIO_OUTPUT);

	/*Set output type*/
	MGPIO_voidSetPinOutputMode(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_CTRL_RW_PORT,LCD_RW_PIN,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_CTRL_RS_PORT,LCD_RS_PIN,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);

	/*Waiting for more than 30ms*/
	MSTK_voidDelayms(40);

#if LCD_MODE == LCD_EIGHT_BIT
	/*Set the mode of pins as output*/
	MGPIO_voidSetPinMode(LCD_DATA_D0_PORT,LCD_DATA_D0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D1_PORT,LCD_DATA_D1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D2_PORT,LCD_DATA_D2,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D3_PORT,LCD_DATA_D3,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D4_PORT,LCD_DATA_D4,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D5_PORT,LCD_DATA_D5,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D6_PORT,LCD_DATA_D6,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D7_PORT,LCD_DATA_D7,GPIO_OUTPUT);


	/*Set output type*/
	MGPIO_voidSetPinOutputMode(LCD_DATA_D0_PORT,LCD_DATA_D0,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D1_PORT,LCD_DATA_D1,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D2_PORT,LCD_DATA_D2,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D3_PORT,LCD_DATA_D3,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D4_PORT,LCD_DATA_D4,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D5_PORT,LCD_DATA_D5,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D6_PORT,LCD_DATA_D6,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D7_PORT,LCD_DATA_D7,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);

	/*Send the function set command: N->1 (2 lines) ,F-> 0 (5*7 char font)*/
	LCD_voidSendCommand(0x38);

	/*Display ON/OFF control*/
	LCD_voidSendCommand(0x0C);

	/*Display clear control*/
	LCD_voidSendCommand(0x01);


#elif LCD_MODE == LCD_FOUR_BIT
	/*Set pins mode as output*/
	MGPIO_voidSetPinMode(LCD_DATA_D0_PORT,LCD_DATA_D0,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D1_PORT,LCD_DATA_D1,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D2_PORT,LCD_DATA_D2,GPIO_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_D3_PORT,LCD_DATA_D3,GPIO_OUTPUT);

	/*Set output type*/
	MGPIO_voidSetPinOutputMode(LCD_DATA_D0_PORT,LCD_DATA_D0,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D1_PORT,LCD_DATA_D1,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D2_PORT,LCD_DATA_D2,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);
	MGPIO_voidSetPinOutputMode(LCD_DATA_D3_PORT,LCD_DATA_D3,GPIO_PUSH_PULL,GPIO_HIGH_SPEED);

	/*Cursor off*/
	LCD_voidSendCommand(0x28);

	/*Display ON/OFF control*/
	LCD_voidSendCommand(0x0C);

	/*Display clear control*/
	LCD_voidSendCommand(0x01);

#else
#error "Wrong LCD_MODE Configuration parameter"
#endif
}

void LCD_voidSendCommand(u8 copy_u8Command)
{
	/*Set the RS pin to be low*/
	MGPIO_voidSetPinValue(LCD_CTRL_RS_PORT,LCD_RS_PIN,GPIO_PIN_LOW);

	/*Set the RW pin to be low*/
	MGPIO_voidSetPinValue(LCD_CTRL_RS_PORT,LCD_RS_PIN,GPIO_PIN_LOW);


#if LCD_MODE == LCD_EIGHT_BIT

	/*Set port with the command*/
	MGPIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Command);

#elif LCD_MODE == LCD_FOUR_BIT
	/*Set port with the command*/
	MGPIO_voidSetPortValue(LCD_DATA_PORT,(copy_u8Command&0xFFFFFFF0));

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);

	/*Wait 2 msec*/
	MSTK_voidDelayms(2);

	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);

	MGPIO_voidSetPortValue(LCD_DATA_PORT,((copy_u8Command<<4)&0xFFFFFFF0));


#else
#error "Wrong LCD_MODE Configuration parameter"
#endif

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);


	/*Wait 2 msec*/
	MSTK_voidDelayms(2);

	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);

}

void LCD_voidSendData(u8 copy_u8Data)
{
	/*Set the RS pin to be low*/
	MGPIO_voidSetPinValue(LCD_CTRL_RS_PORT,LCD_RS_PIN,GPIO_PIN_HIGH);

	/*Set the RW pin to be low*/
	MGPIO_voidSetPinValue(LCD_CTRL_RW_PORT,LCD_RW_PIN,GPIO_PIN_LOW);


#if LCD_MODE == LCD_EIGHT_BIT

	MGPIO_voidSetPortValue(LCD_DATA_PORT,copy_u8Data);


#elif LCD_MODE == LCD_FOUR_BIT
	/*Set port with data*/
	MGPIO_voidSetPortValue(LCD_DATA_PORT,(copy_u8Data&0xFFFFFFF0));

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);

	/*Wait 2 msec*/
	MSTK_voidDelayms(2);

	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);

	MGPIO_voidSetPortValue(LCD_DATA_PORT,((copy_u8Data<<4)&0xFFFFFFF0));


#else
#error "Wrong LCD_MODE Configuration parameter"
#endif

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);


	/*Wait 2 msec*/
	MSTK_voidDelayms(2);

	MGPIO_voidSetPinValue(LCD_CTRL_EN_PORT,LCD_EN_PIN,GPIO_PIN_LOW);

}

void LCD_voidSendString(const u8* copy_pu8String)
{
	for(u8 local_u8Iterator = 0; copy_pu8String[local_u8Iterator] != '\0';local_u8Iterator++)
	{
		LCD_voidSendData(copy_pu8String[local_u8Iterator]);
	}
}


void LCD_voidSetPosition(u8 copy_u8XPosition,u8 copy_u8YPosition)
{
	u8 Local_u8Address = 0;
	if(copy_u8XPosition == LCD_ROW0)
	{
		Local_u8Address = copy_u8YPosition;
	}
	else if(copy_u8XPosition == LCD_ROW1)
	{
		Local_u8Address = copy_u8YPosition + DDRAM_OFFSET;
	}
	else
	{

	}

	SET_BIT(Local_u8Address,7);
	LCD_voidSendCommand(Local_u8Address);
}

void LCD_voidSendNumber(s64 copy_s32Number)
{
	u64 reversed = 1;
	if (copy_s32Number == 0)
	{
		LCD_voidSendData('0');
	}
	else
	{
		if(copy_s32Number <0)
		{
			LCD_voidSendData('-');
			copy_s32Number *=-1;
		}
		else
		{
			while(copy_s32Number!= 0)
			{
				reversed = (reversed*10) + (copy_s32Number%10);
				copy_s32Number/=10;
			}
			while(reversed != 1)
			{
				LCD_voidSendData(reversed%10 +'0');
				reversed/=10;
			}
		}
	}
}

void LCD_voidSendCustomCharacter(u8* copy_pu8CharacterArray,u8 copy_u8PatternNumber,u8 copy_u8XPosition,u8 copy_u8YPosition)
{
	u8 Local_u8CGRAMAddress = 0 ,Local_u8LoopCounter;

	/*Calculating CGRAM Address*/
	Local_u8CGRAMAddress = copy_u8PatternNumber*8;

	/*Make the 6th bit from address to be high and sending cmd to LCD*/
	SET_BIT(Local_u8CGRAMAddress,6);

	LCD_voidSendCommand(Local_u8CGRAMAddress);

	for(Local_u8LoopCounter = 0; Local_u8LoopCounter<8 ; Local_u8LoopCounter++)
	{
		LCD_voidSendData(copy_pu8CharacterArray[Local_u8LoopCounter]);
	}
	LCD_voidSetPosition( copy_u8XPosition,copy_u8YPosition);

	/*Displaying the pattern from CGRAM*/
	LCD_voidSendData(copy_u8PatternNumber);
}

void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(0x01);
}



