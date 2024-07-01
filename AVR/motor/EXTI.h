/*
 * EXTI.h
 *
 *  Created on: Aug 23, 2023
 *      Author: yousi
 */

#ifndef EXTI_H_
#define EXTI_H_

// Configurations
//EXTI PINS ,PORTS , INT0, INT1, INT2,
#define EXTI0_PORT   DIO_PORTD
#define EXTI0_PIN    DIO_PIN2

#define EXTI1_PORT   DIO_PORTD
#define EXTI1_PIN    DIO_PIN3

#define EXTI2_PORT   DIO_PORTB
#define EXTI2_PIN    DIO_PIN2

//MCUCR REGISTER ---> STATUS
#define MCUCR_ISC00  0
#define MCUCR_ISC01  1
#define MCUCR_ISC10  2
#define MCUCR_ISC11  3

//MCUCSR REGISTER ---> STATUS
#define MCUCSR_ISC2  6

//GICR REGISTER ---> SIE
#define GICR_INT2    5
#define GICR_INT0    6
#define GICR_INT1    7

//GIFR REGISTER ---> FLAG
#define GIFR_INTF2    5
#define GIFR_INTF0    6
#define GIFR_INTF1    7

//SENSE CONTROL OPTIONS
#define EXTI_RISING_EDGE    0
#define EXTI_FALLING_EDGE   1
#define EXTI_LOW_LEVEL      2
#define EXTI_ANY_CHANGE     3


//PROTOTYPES
void EXTI_void_INT0(void);
void EXTI_void_INT1(void);
void EXTI_void_INT2(void);

#endif /* EXTI_H_ */
