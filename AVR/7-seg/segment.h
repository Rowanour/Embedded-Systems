#ifndef SEGMENT_H_
#define SEGMENT_H_

#define SEG_PORT             DIO_PORTB
#define SEG_PIN_A            DIO_PIN0
#define SEG_PIN_B            DIO_PIN1
#define SEG_PIN_C            DIO_PIN2
#define SEG_PIN_D            DIO_PIN3
#define SEG_PIN_E            DIO_PIN4
#define SEG_PIN_F            DIO_PIN5
#define SEG_PIN_G            DIO_PIN6

#define DG_PORT         DIO_PORTC
#define DG_PIN_ONES     DIO_PIN0
#define DG_PIN_TENS     DIO_PIN1

void displaynumber(u8 digit);



#endif /* SEGMENT_H_ */
