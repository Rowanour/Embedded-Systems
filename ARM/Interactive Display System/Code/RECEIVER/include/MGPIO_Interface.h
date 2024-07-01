
#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

/*GPIO Ports*/
#define GPIO_PORTA       0
#define GPIO_PORTB       1
#define GPIO_PORTC       2

/*GPIO Pins*/
#define GPIO_PIN0         0
#define GPIO_PIN1         1
#define GPIO_PIN2         2
#define GPIO_PIN3         3
#define GPIO_PIN4         4
#define GPIO_PIN5         5
#define GPIO_PIN6         6
#define GPIO_PIN7         7
#define GPIO_PIN8         8
#define GPIO_PIN9         9
#define GPIO_PIN10        10
#define GPIO_PIN11        11
#define GPIO_PIN12        12
#define GPIO_PIN13        13
#define GPIO_PIN14        14
#define GPIO_PIN15        15

#define GPIO_INPUT            0b00
#define GPIO_OUTPUT   		  0b01
#define GPIO_ALT_FUNC 		  0b10
#define GPIO_ANALOG 		  0b11

/*Output Speed Modes*/
#define GPIO_LOW_SPEED        0b00
#define GPIO_MEDIUM_SPEED     0b01
#define GPIO_HIGH_SPEED       0b10
#define GPIO_VERYHIGH_SPEED   0b11

/*Input Modes*/
#define GPIO_NOPUPD           0b00
#define GPIO_PULLUP           0b01
#define GPIO_PULLDOWN  		  0b10
#define GPIO_PUSH_PULL	      0b00

/*Pin Values*/
#define GPIO_PIN_HIGH         1
#define GPIO_PIN_LOW          0

/*Pin Set Reset*/
#define GPIO_SET              1
#define GPIO_RESET            0

/*Functions Prototypes*/
void MGPIO_voidSetPinMode(u8 copyu8Port, u8 copyu8Pin, u8 Mode);
void MGPIO_voidSetPortValue(u8 copyu8Port, u8 copyu8Value);
void MGPIO_voidSetPinOutputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyOutputMode, u8 copyu8Speed);
void MGPIO_voidSetPinInputMode(u8 copyu8Port, u8 copyu8Pin, u8 copyInputMode);
void MGPIO_voidSetAltFunction(u8 copyu8Port, u8 copyu8Pin, u8 copyu8AltFunc);
void MGPIO_voidSetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 copyu8Output);
void MGPIO_voidGetPinValue(u8 copyu8Port, u8 copyu8Pin, u8 *pu8Return);

void MGPIO_voidSetResetPin(u8 copyu8Port, u8 copyu8Pin, u8 copyu8SetResetValue);


#endif /* MGPIO_INTERFACE_H_ */
