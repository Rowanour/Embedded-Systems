#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "buzzer.h"

void buzzer_init() {
    // Set buzzer pin as output
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN7, DIO_OUTPUT);
}

void buzzer_on() {
    // Set buzzer pin high
	DIO_SetPinValue(DIO_PORTD, DIO_PIN7, DIO_HIGH);
}

void buzzer_off() {
    // Set buzzer pin low
	DIO_SetPinValue(DIO_PORTD, DIO_PIN7, DIO_LOW);
}

