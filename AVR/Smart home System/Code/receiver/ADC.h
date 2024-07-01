#ifndef ADC_H_
#define ADC_H_

/* ADC Channel Configuration */
#define ADC_u8_ADC_CHANNEL_0    0
#define ADC_u8_ADC_CHANNEL_1    1
#define ADC_u8_ADC_CHANNEL_2    2
#define ADC_u8_ADC_CHANNEL_3    3
#define ADC_u8_ADC_CHANNEL_4    4
#define ADC_u8_ADC_CHANNEL_5    5
#define ADC_u8_ADC_CHANNEL_6    6
#define ADC_u8_ADC_CHANNEL_7    7

/* ADC Configuration Bits */
#define ADMUX_REFS1     7 // Reference Voltage Bit 1
#define ADMUX_REFS0     6 // Reference Voltage Bit 0
#define ADMUX_ADLAR     5 // ADC Left Adjust Result Bit

#define ADCSRA_ADEN     7 // ADC Enable Bit
#define ADCSRA_ADSC     6 // ADC Start Conversion Bit
#define ADCSRA_ADATE    5 // ADC Auto-Trigger Enable Bit
#define ADCSRA_ADIF     4 // ADC Interrupt Flag Bit
#define ADCSRA_ADIE     3 // ADC Interrupt Enable Bit
#define ADCSRA_ADPS2    2 // ADC Prescaler Bit 2
#define ADCSRA_ADPS1    1 // ADC Prescaler Bit 1
#define ADCSRA_ADPS0    0 // ADC Prescaler Bit 0

/* Function Prototypes */
void ADC_vinit(void); // Function to initialize the ADC module
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel); // Function to read ADC value from a specified channel

#endif /* ADC_H_ */
