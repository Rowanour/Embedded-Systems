#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "segment.h"
#include <avr/io.h>
#include <util/delay.h>

u8 s[] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66,
      0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void displaynumber(u8 digit) {
    DIO_SetPinValue(SEG_PORT, SEG_PIN_A, (s[digit] & 0x01));
    DIO_SetPinValue(SEG_PORT, SEG_PIN_B, (s[digit] & 0x02) >> 1);
    DIO_SetPinValue(SEG_PORT, SEG_PIN_C, (s[digit] & 0x04) >> 2);
    DIO_SetPinValue(SEG_PORT, SEG_PIN_D, (s[digit] & 0x08) >> 3);
    DIO_SetPinValue(SEG_PORT, SEG_PIN_E, (s[digit] & 0x10) >> 4);
    DIO_SetPinValue(SEG_PORT, SEG_PIN_F, (s[digit] & 0x20) >> 5);
    DIO_SetPinValue(SEG_PORT, SEG_PIN_G, (s[digit] & 0x40) >> 6);
}

int main(void) {
    DIO_SetPinDirection(SEG_PORT, SEG_PIN_A, DIO_OUTPUT);
    DIO_SetPinDirection(SEG_PORT, SEG_PIN_B, DIO_OUTPUT);
    DIO_SetPinDirection(SEG_PORT, SEG_PIN_C, DIO_OUTPUT);
    DIO_SetPinDirection(SEG_PORT, SEG_PIN_D, DIO_OUTPUT);
    DIO_SetPinDirection(SEG_PORT, SEG_PIN_E, DIO_OUTPUT);
    DIO_SetPinDirection(SEG_PORT, SEG_PIN_F, DIO_OUTPUT);
    DIO_SetPinDirection(SEG_PORT, SEG_PIN_G, DIO_OUTPUT);

    DIO_SetPinDirection(DG_PORT,DG_PIN_ONES , DIO_OUTPUT);
    DIO_SetPinDirection(DG_PORT, DG_PIN_TENS , DIO_OUTPUT);

    for (u8 i = 0; i < 100; i++) {
        u8 x = i % 10;
        u8 y = i/10;

        DIO_SetPinValue(DG_PORT,DG_PIN_ONES , DIO_HIGH);
        DIO_SetPinValue(DG_PORT,DG_PIN_TENS , DIO_LOW);
        displaynumber(x);
        _delay_ms(25);

        DIO_SetPinValue(DG_PORT, DG_PIN_ONES , DIO_LOW);
        DIO_SetPinValue(DG_PORT, DG_PIN_TENS, DIO_HIGH);
        displaynumber(y);
        _delay_ms(25);
    }
}
