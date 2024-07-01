#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_

/**************CONTROL PORT PINS******************/
#define LCD_CTRL_EN_PORT        GPIO_PORTC
#define LCD_CTRL_RW_PORT        GPIO_PORTC
#define LCD_CTRL_RS_PORT        GPIO_PORTC

#define LCD_EN_PIN              GPIO_PIN13
#define LCD_RW_PIN              GPIO_PIN14
#define LCD_RS_PIN              GPIO_PIN15

/**************DATA PORT PINS******************/
#define LCD_DATA_PORT           GPIO_PORTA

#define LCD_DATA_D0_PORT        GPIO_PORTA
#define LCD_DATA_D1_PORT        GPIO_PORTA
#define LCD_DATA_D2_PORT        GPIO_PORTA
#define LCD_DATA_D3_PORT        GPIO_PORTA
#define LCD_DATA_D4_PORT        GPIO_PORTA
#define LCD_DATA_D5_PORT        GPIO_PORTA
#define LCD_DATA_D6_PORT        GPIO_PORTA
#define LCD_DATA_D7_PORT        GPIO_PORTA

#define LCD_DATA_D0             GPIO_PIN0
#define LCD_DATA_D1             GPIO_PIN1
#define LCD_DATA_D2             GPIO_PIN2
#define LCD_DATA_D3             GPIO_PIN3
#define LCD_DATA_D4             GPIO_PIN4
#define LCD_DATA_D5             GPIO_PIN5
#define LCD_DATA_D6             GPIO_PIN6
#define LCD_DATA_D7             GPIO_PIN7

/*********************LCD MODE*******************/
#define LCD_MODE                LCD_EIGHT_BIT

#endif /* HLCD_CONFIG_H_ */
