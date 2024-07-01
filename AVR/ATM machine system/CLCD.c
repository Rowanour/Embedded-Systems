
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO.h"
#include <avr/io.h>
#include <util/delay.h>
#include "CLCD.h"

void CLCD_voidSendCommand(u8 Copy_u8Command){
	// set low to send command
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN, DIO_LOW);

	// write --> 0 , read --> 1 send command---> write
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN, DIO_LOW);

	// SEND COMMAND AT PORT DATA
	DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	// set enable ---> *E pulse / high for 2ms then low pulse
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_LOW);
}
void CLCD_voidSendData(u8 Copy_u8Data){
	// set high to set command
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN, DIO_HIGH);

		// write --> 0 , read --> 1 send command---> write
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN, DIO_LOW);

		// SEND COMMAND AT PORT DATA
		DIO_SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

		// set enable ---> *E pulse / high for 2ms then low pulse
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_HIGH);
		_delay_ms(2);
		DIO_SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN, DIO_LOW);
	}

void CLCD_voidInitl(void){
// delay for more than 30ms
	_delay_ms(40);
	// font size command 5x8
	CLCD_voidSendCommand(0b00111000);// from data sheet check the function
	//  display command on , off
	CLCD_voidSendCommand(0b00001100);// from data sheet check the function
	CLCD_voidSendCommand(0b00001110);
	// display clear command
	CLCD_voidSendCommand(1);// or you can write just 1 it's the same
}

//send sting

void CLCD_voidSrting(const char*Copy_pcSrting){
	u8 row1=0;
	while(Copy_pcSrting[row1]!=0){
		CLCD_voidSendData(Copy_pcSrting[row1]);
		row1++;
	}

}
// Go To posItion X AND Y
void CLCD_voidGoTo_X_Y(u8 Copy_u8Xposition,u8 Copy_u8Yposition){
	u8 Local_u8Address;
	if(Copy_u8Xposition==0){
		Local_u8Address=Copy_u8Yposition;

	}
	else if(Copy_u8Xposition==1){
		Local_u8Address= Copy_u8Yposition + 0x40;

	}
	CLCD_voidSendCommand(Local_u8Address+128);
	//else{}

}

// LCD CLEAR FUNCTION
void CLCD_voidLCD_Clear(void){
	CLCD_voidSendCommand(1);

}
void CLCD_voidNumber(u32 number) {
    char buffer[16];
    sprintf(buffer, "%lu", number);
    CLCD_voidSrting(buffer);
}
