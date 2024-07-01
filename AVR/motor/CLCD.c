#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include <avr/io.h>
#include <util/delay.h>
#include "CLCD.h"

void CLCD_voidSendCommand(u8 Copy_u8Command){
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN, DIO_LOW);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN, DIO_LOW);
	DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data){
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN, DIO_HIGH);
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN, DIO_LOW);
		DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_LOW);
}

void CLCD_voidInitl(void){
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001100);
	CLCD_voidSendCommand(1);
}

void CLCD_voidSrting(const char*Copy_pcSrting){
	u8 x=0;
		while(Copy_pcSrting[x]!=0){
			CLCD_voidSendData(Copy_pcSrting[x]);
			x++;
}}

void CLCD_voidGoTo_X_Y(u8 Copy_u8Xpos,u8 Copy_u8Ypos){
	u8 Local_u8Address;
	if(Copy_u8Xpos==0){
		Local_u8Address=Copy_u8Ypos;
	}
	else if(Copy_u8Xpos==1){
		Local_u8Address= Copy_u8Ypos + 0x40;
	}
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidLCD_Clear(void){
	CLCD_voidSendCommand(1);

}
