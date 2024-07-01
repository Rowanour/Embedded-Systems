#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Keypad.h"

int main(void) {

    DIO_SetPortDirection(DIO_PORTA, DIO_OUTPUT);
    DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
    DIO_SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
    DIO_SetPinDirection(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);

    DIO_SetPortDirection(CLCD_DATA_PORT, DIO_PORT_OUTPUT);
    DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN0, DIO_OUTPUT);
    DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN1, DIO_OUTPUT);
    DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN2, DIO_OUTPUT);

    CLCD_voidInitl();
    CLCD_voidSrting("Hello! :)");
    CLCD_voidGoTo_X_Y(1, 0);

    int correctPassword = 123;
    u8 trialsCount = 0;
    u8 maxTrials = 3;
    u8 x;
    KPD_Init();
    CLCD_voidInitl();
    u16 balance = 5000;

    while (trialsCount < maxTrials) {

        CLCD_voidGoTo_X_Y(0, 0);
        CLCD_voidSrting("please enter your password:");
        CLCD_voidGoTo_X_Y(1, 0);
        char enteredPassword[5];
        for (u8 i = 0; i < 4; i++) {
            while (1) {
                u8 keyPressed = KPD_GETPressedKey();
                if (keyPressed != KPD_NOT_PRESSED_KEY) {
                    enteredPassword[i] = keyPressed;
                    CLCD_voidSendData('*');
                    break;
                }
            }
        }
        enteredPassword[4] = '\0';

        if (stringToInteger(enteredPassword) == correctPassword) {

            while (1) {
                CLCD_voidGoTo_X_Y(0, 0);
                CLCD_voidSrting("1-Show balance");
                CLCD_voidGoTo_X_Y(1, 0);
                CLCD_voidSrting("2-Insert money");
                _delay_ms(1000);
                CLCD_voidLCD_Clear();
                CLCD_voidGoTo_X_Y(2, 0);
                CLCD_voidSrting("3-Withdraw");
                _delay_ms(1000);
                while (1) {
                	do {
                		x = KPD_GETPressedKey();
                	} while (x == KPD_NOT_PRESSED_KEY);

                	CLCD_voidLCD_Clear();
                	CLCD_voidSendData(x);
                u8 choice = x;
                if (choice == '1') {

                    CLCD_voidLCD_Clear();
                    CLCD_voidGoTo_X_Y(0, 0);
                    CLCD_voidSrting("Current balance=");
                    CLCD_voidGoTo_X_Y(1, 0);
                    CLCD_voidNumber(balance);
                    _delay_ms(200);
                    CLCD_voidLCD_Clear();
                } else if (choice == '2') {

                    CLCD_voidLCD_Clear();
                    CLCD_voidGoTo_X_Y(0, 0);
                    CLCD_voidSrting("Enter amount:");
                    CLCD_voidGoTo_X_Y(1, 0);
                    CLCD_voidSrting("Insert amount, then press =");
                    _delay_ms(120);
                    CLCD_voidLCD_Clear();

                    u16 amount = 0;
                    u8 key;
                    while (1) {
                        do {
                            key = KPD_GETPressedKey();
                        } while (key == KPD_NOT_PRESSED_KEY);
                        if (key == '=') {
                            break;
                        }
                        amount = amount * 10 + (key - '0');
                        CLCD_voidGoTo_X_Y(0, 0);
                        CLCD_voidNumber(amount);
                    }

                    balance += amount;
                    CLCD_voidGoTo_X_Y(0, 0);
                    CLCD_voidSrting("money inserted");
                    _delay_ms(1000);
                    CLCD_voidLCD_Clear();
                    CLCD_voidGoTo_X_Y(0, 0);
                    CLCD_voidSrting("new balance=");
                    CLCD_voidGoTo_X_Y(1, 0);
                    CLCD_voidNumber(balance);
                    _delay_ms(2000);
                } else if (choice == '3') {

                    CLCD_voidLCD_Clear();
                    CLCD_voidGoTo_X_Y(0, 0);
                    CLCD_voidSrting("Enter amount:");
                    _delay_ms(80);
                    CLCD_voidLCD_Clear();

                    u16 amount = 0;
                    u8 key;
                    while (1) {
                        do {
                            key = KPD_GETPressedKey();
                        } while (key == KPD_NOT_PRESSED_KEY);
                        if (key == '=') {
                            break;
                        }
                        amount = amount * 10 + (key - '0');
                        CLCD_voidGoTo_X_Y(0, 0);
                        CLCD_voidNumber(amount);
                    }

                    if (amount <= balance) {
                        balance -= amount;

                        CLCD_voidGoTo_X_Y(0, 0);
                        CLCD_voidSrting("money withdrawn");
                        _delay_ms(1000);
                        CLCD_voidLCD_Clear();
                        CLCD_voidGoTo_X_Y(0, 0);
                        CLCD_voidSrting("new balance=");
                        CLCD_voidGoTo_X_Y(1, 0);
                        CLCD_voidNumber(balance);
                        _delay_ms(200);
                        CLCD_voidLCD_Clear();
                    } else {
                        CLCD_voidGoTo_X_Y(0, 0);
                        CLCD_voidSrting("no balance");
                        _delay_ms(200);
                        CLCD_voidLCD_Clear();
                    }
                } else {

                    CLCD_voidLCD_Clear();
                    CLCD_voidGoTo_X_Y(0, 0);
                    CLCD_voidSrting("Invalid choice");
                    _delay_ms(1000);
                    CLCD_voidLCD_Clear();
                }
            }
            }} else {

            trialsCount++;
            CLCD_voidLCD_Clear();
            CLCD_voidGoTo_X_Y(0, 0);
            CLCD_voidSrting("Invalid password");
            _delay_ms(1000);
            CLCD_voidLCD_Clear();
        }
    }


    CLCD_voidGoTo_X_Y(0, 0);
    CLCD_voidSrting("Max trials reached");
    _delay_ms(1000);
    CLCD_voidLCD_Clear();
}
