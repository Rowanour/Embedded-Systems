

#ifndef CLCD_H_
#define CLCD_H_
// CONFIGURATION PINS
#define CLCD_DATA_PORT DIO_PORTA //PORTA CAN BE CHANGED
#define CLCD_CTRL_PORT DIO_PORTC //PORTC CAN BE CHANGED

#define CLCD_RS_PIN DIO_PIN0
#define CLCD_RW_PIN DIO_PIN1
#define CLCD_E_PIN DIO_PIN2

//PROTOTYPES FUCTIONS
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidInitl(void);

//send sting

void CLCD_voidSrting(const char*Copy_pcSrting);// pc---> pointer to character , to send a full string not just a character

// Go To posItion X AND Y
void CLCD_voidGoTo_X_Y(u8 Copy_u8Xposition,u8 Copy_u8Yposition); // represents ROWS AND COLS

// LCD CLEAR FUNCTION
void CLCD_voidLCD_Clear(void);
void CLCD_voidNumber(u32 number);
#endif /* CLCD_H_ */
