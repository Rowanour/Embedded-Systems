#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "ADC.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
    ADC_voidInit();

    // Set PORTC as output for 8 LEDs
    DIO_SetPortDirection(DIO_PORTC, DIO_OUTPUT);

    while (1) {
        // Read analog value from the potentiometer connected to channel 0
        u16 analogValue = ADC_u8GetChannelReading(0);

        // Convert analog value to an 8-bit value (0-255)
        u8 ledDisplay = (u8)(analogValue >> 2); // Right-shift to get an 8-bit value

        // Display the LED pattern
        DIO_SetPortValue(DIO_PORTC, ledDisplay);

        // Delay for some time
        _delay_ms(500);
    }

    return 0;
}
