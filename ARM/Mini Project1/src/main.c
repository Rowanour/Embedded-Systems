#include "../include/BIT_MATH.h"
#include "../include/STD_Types.h"

#include "../include/MRCC_Interface.h"
#include "../include/MGPIO_Interface.h"
#include "../include/MNVIC_Interface.h"
#include "../include/MEXTI_Interface.h"
#include "../include/MSTK_Interface.h"

void FunctionOne(void);
void FunctionTwo(void);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);

void main(void)
{
    MRCC_voidInit();
    MSTK_voidInit();

    MNVIC_voidSetInetrruptGroupMode(Groups16_NoSub);
    MNVIC_voidSetInterruptPriority(6, 0, 0);
    MNVIC_voidSetInterruptPriority(7, 1, 0);

    MRCC_voidEnablePeripheral(RCC_AHB1, RCC_AHB1_GPIOA);
    MRCC_voidEnablePeripheral(RCC_AHB1, RCC_AHB1_GPIOB);
    MRCC_voidEnablePeripheral(RCC_APB2, RCC_APB2_SYSCFG);
    MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    MGPIO_voidSetPinInputMode(GPIO_PORTB, GPIO_PIN0, GPIO_PULLUP);
    MGPIO_voidSetPinMode(GPIO_PORTB, GPIO_PIN1, GPIO_INPUT);
    MGPIO_voidSetPinInputMode(GPIO_PORTB, GPIO_PIN1, GPIO_PULLUP);

    MEXTI_voidInit();
    MEXTI_voidSetCallBack(MEXTI_LINE0, FunctionOne);
    MEXTI_voidSetCallBack(MEXTI_LINE1, FunctionTwo);
    MNVIC_voidEnablePeripheralInterrupt(6);
    MNVIC_voidEnablePeripheralInterrupt(7);
    u8 local_u8Iterator = 0;

    for (local_u8Iterator = 0; local_u8Iterator < 8; local_u8Iterator++)
    {
        MGPIO_voidSetPinMode(GPIO_PORTA, local_u8Iterator, GPIO_OUTPUT);
        MGPIO_voidSetPinOutputMode(GPIO_PORTA, local_u8Iterator, 0, GPIO_LOW_SPEED);
        MGPIO_voidSetResetPin(GPIO_PORTA, local_u8Iterator, GPIO_RESET);
    }

    MEXTI_voidEnableEXTILine(MEXTI_LINE0);
    MEXTI_voidEnableEXTILine(MEXTI_LINE1);
}

void FunctionOne(void)
{
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_LOW);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_LOW);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_PIN_LOW);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_LOW);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_PIN_LOW);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_PIN_LOW);
    MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_PIN_LOW);
    while (1)
    {

        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_PIN_LOW);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_PIN_HIGH);
        MSTK_voidDelayms(1000);
    }
}

void FunctionTwo(void)
{
    while (1)
    {
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_HIGH);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_HIGH);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_PIN_HIGH);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_PIN_HIGH);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_PIN_HIGH);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_PIN_HIGH);
        MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GPIO_PIN_HIGH);
    }
}

void EXTI0_IRQHandler(void)
{
    FunctionOne();
}

void EXTI1_IRQHandler(void)
{
    FunctionTwo();
}
