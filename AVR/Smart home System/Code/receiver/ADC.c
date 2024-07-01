#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include <avr/io.h>
#include"ADC.h"

// Function to initialize the ADC module
void ADC_vinit(void)
{
    // Set the reference voltage to AVCC with external capacitor at AREF pin
    SET_BIT(ADMUX, ADMUX_REFS0);
    CLR_BIT(ADMUX, ADMUX_REFS1);

    // Left adjust the result (8-bit resolution)
    SET_BIT(ADMUX, ADMUX_ADLAR);

    // Set the ADC prescaler to 128 for slower conversion speed but higher accuracy
    SET_BIT(ADCSRA, ADCSRA_ADPS2);
    SET_BIT(ADCSRA, ADCSRA_ADPS1);
    SET_BIT(ADCSRA, ADCSRA_ADPS0);

    // Enable the ADC module
    SET_BIT(ADCSRA, ADCSRA_ADEN);
}

// Function to read the ADC value from a specified channel
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel)
{
    // Clear the MUX bits in ADMUX to select the channel
    ADMUX &= 0b11100000;
    ADMUX |= Copy_u8Channel; // Set the specified channel

    // Start the ADC conversion by setting the ADSC bit
    SET_BIT(ADCSRA, ADCSRA_ADSC);

    // Wait for the conversion to complete (ADIF flag to be set)
    while ((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0);

    // Clear the ADC interrupt flag (ADIF)
    SET_BIT(ADCSRA, ADCSRA_ADIF);

    // Return the 8-bit ADC result from the high register (ADCH)
    return ADCH;
}
