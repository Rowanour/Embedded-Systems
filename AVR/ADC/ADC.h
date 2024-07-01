/*
 * ADC.h
 *
 *  Created on: Sept, 2023
 *      Author: r0wan
 */

#ifndef ADC_H_
#define ADC_H_


#define ADMUX_REFS1     7
#define ADMUX_REFS0     6
#define ADMUX_ADLAR1    5
#define ADMUX_MUX4      4
#define ADMUX_MUX3      3
#define ADMUX_MUX2      2
#define ADMUX_MUX1      1
#define ADMUX_MUX0      0

#define ADCSRA_ADEN     7
#define ADCSRA_ADSC     6
#define ADCSRA_ADATE    5
#define ADCSRA_ADIF     4
#define ADCSRA_ADIE     3
#define ADCSRA_ADPS2    2
#define ADCSRA_ADPS1    1
#define ADCSRA_ADPS0    0

#define ADC0_PIN    DIO_PIN0
#define ADC1_PIN    DIO_PIN1
#define ADC2_PIN    DIO_PIN2
#define ADC3_PIN    DIO_PIN3
#define ADC4_PIN    DIO_PIN4
#define ADC5_PIN    DIO_PIN5
#define ADC6_PIN    DIO_PIN6
#define ADC7_PIN    DIO_PIN7



void ADC_voidInit(void);
u8 ADC_u8GetChannelReading(u8 Copy_u8Channel);

#endif /* ADC_H_ */
