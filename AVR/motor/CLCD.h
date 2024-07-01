#ifndef CLCD_H_
#define CLCD_H_


#define CLCD_DATA_PORT DIO_PORTA
#define CLCD_CTRL_PORT DIO_PORTC

#define CLCD_RS_PIN DIO_PIN0
#define CLCD_RW_PIN DIO_PIN1
#define CLCD_E_PIN DIO_PIN2



void CLCD_voidInitl(void);
void CLCD_voidSrting(const char*Copy_pcSrting);

void CLCD_voidLCD_Clear(void);
#endif /* CLCD_H_ */
