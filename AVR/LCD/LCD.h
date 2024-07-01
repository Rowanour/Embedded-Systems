/*
 * LCD.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Dubai
 */

#ifndef LCD_H_
#define LCD_H_

#define LCD_DATA_PORT DIO_PORTA
#define LCD_CTRL_PORT DIO_PORTC

#define LCD_RS_PIN    DIO_PIN0
#define LCD_RW_PIN    DIO_PIN1
#define LCD_E_PIN     DIO_PIN2

void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidSendString(const char*Copy_pcString);
void LCD_voidGoToXY(u8 Copy_u8Xpos,u8 Copy_u8Ypos);

void LCD_voidLCDClear(void);

#endif /* LCD_H_ */
