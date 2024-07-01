#ifndef CLCD_H_
#define CLCD_H_

// Define the data and control ports for the CLCD
#define CLCD_DATA_PORT DIO_PORTB
#define CLCD_CTRL_PORT DIO_PORTD

// Define the pins for RS (Register Select), RW (Read/Write), and E (Enable)
#define CLCD_RS_PIN DIO_PIN2
#define CLCD_RW_PIN DIO_PIN3
#define CLCD_E_PIN DIO_PIN4

// Function prototypes for the CLCD driver functions
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidInitl(void);
void CLCD_voidString(const char* Copy_pcSrting);
void CLCD_voidGoTo_X_Y(u8 Copy_u8Xposition, u8 Copy_u8Yposition);
void CLCD_voidLCD_Clear(void);

#endif /* CLCD_H_ */
