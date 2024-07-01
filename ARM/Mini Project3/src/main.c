
/************ LIB **************/
#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

			/* MCAL */
#include "../include/MRCC_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MUSART_Interface.h"


/*******************HAL*****************************/

/*************CallBack functions********************/
void handler_USART(void);

/*****************Variable**************************/
u8 Global_u8RX ;
u8 R= GPIO_PIN_LOW;
u8 G= GPIO_PIN_LOW;
u8 B= GPIO_PIN_LOW;

void main(void)
{
	/****************************************************************/
	/*             		  1- CLOCK GATING							*/
	/****************************************************************/
	/*Initialize RCC module*/
	MRCC_voidInit();
	/*Enable clock to GPIOA*/
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	/*Enable clock to USART1*/
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);


	/****************************************************************/
	/*             		  2- PINS SETUP 							*/
	/****************************************************************/
	/*Configure Pins 9 & 10 as alternative function -> USART1*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);
	/*Setup the pins of the alternative functions*/
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN9,0b0111);
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN10,0b0111);

	/*Configure pin0 as output*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);
	/*Setup pin0 with the suitable setting*/
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN0,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	/*Configure pin1 as output*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT);
	/*Setup pin1 with the suitable setting*/
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN1,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	/*Configure pin2 as output*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT);
	/*Setup pin2 with the suitable setting*/
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN2,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);


	/****************************************************************/
	/*         	   3- ENABLE USART INTERRUPT						*/
	/****************************************************************/
	/*Enable Peripheral number of USART1*/
	MNVIC_voidEnablePeripheralInterrupt(37);
	/*callBack function when the interrupt fires goes to*/
	MSUART_voidSetCallBack(handler_USART);

	/****************************************************************/
	/*             	 4- USART INITIALIZATION						*/
	/****************************************************************/
	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);


	/****************************************************************/
	/*               5- DATA TRANSMISSION   						*/
	/****************************************************************/
	MUSART_voidTransmit(MUSART_USART1,(u8*)"choose color: red/ green/ blue", 30);

	while(1);
}


void handler_USART(void)
{
    static const char* colors[] = {"Red", "Green", "Blue"};
    static const u8 pins[] = {GPIO_PIN0, GPIO_PIN1, GPIO_PIN2};
    static u8 states[] = {GPIO_PIN_LOW, GPIO_PIN_LOW, GPIO_PIN_LOW};

    MUSART_voidReceive(MUSART_USART1, &Global_u8RX);

    for (u8 i = 0; i < 3; i++) {
        if (Global_u8RX == colors[i][0]) {
            if (states[i] == GPIO_PIN_LOW) {
                MUSART_voidTransmit(MUSART_USART1, (u8*) (colors[i]), strlen(colors[i]));
                MUSART_voidTransmit(MUSART_USART1, (u8*) "_LED_ON\r", 8);
                states[i] = GPIO_PIN_HIGH;
                MGPIO_voidSetPinValue(GPIO_PORTA, pins[i], GPIO_PIN_HIGH);
            } else {
                MUSART_voidTransmit(MUSART_USART1, (u8*) (colors[i]), strlen(colors[i]));
                MUSART_voidTransmit(MUSART_USART1, (u8*) "_LED_OFF\r", 9);
                states[i] = GPIO_PIN_LOW;
                MGPIO_voidSetPinValue(GPIO_PORTA, pins[i], GPIO_PIN_LOW);
            }
            break;
        }
    }
}





