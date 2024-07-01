#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include "Keypad.h"
#include "timer.h"
#include "GIE.h"
#include <avr/io.h>
#include <util/delay.h>

void main(void)
{
    // Set up LCD and keypad
    DIO_SetPortDirection(CLCD_DATA_PORT, DIO_PORT_OUTPUT);
    DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN0, DIO_OUTPUT);
    DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN1, DIO_OUTPUT);
    DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN2, DIO_OUTPUT);

    CLCD_voidInitl();
    KPD_Init();

    // Display a prompt for the user
    CLCD_voidGoTo_X_Y(0, 0);
    CLCD_voidSrting("Enter an angle:");

    u16 angle = 0;
    u8 key;
    u8 digitCount = 0;

    while (1) {
        key = KPD_GETPressedKey();

        switch (key) {
            case '0' ... '9':
                if (digitCount < 3) {
                    angle = (angle * 10) + (key - '0');
                    CLCD_voidGoTo_X_Y(1, digitCount);
                    CLCD_voidSendData(key);
                    digitCount++;
                }
                break;
            case '=':
                goto angleEntered;
                break;
        }
    }

angleEntered:
    // Rotate the servo to the desired angle
    TIMER1_voidINIT();
    TIMER1_voidSetTopTicks(20000);

    // Calculate PW
    u16 servoAngle = map(angle, 0, 99, 1000, 2000);
    servoAngle = (servoAngle * 180) / 100;  // Set the angle between 0-180 range
    servoAngle = map(servoAngle, 0, 180, 1000, 2000);  // Map the angle to the corresponding PW

    TIMER1_voidSetChannelCompareMatch(servoAngle);
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);

    while (1) {
        // Your main loop code can go here
        // It will execute after setting the servo angle
    }
}
