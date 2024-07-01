// Include necessary libraries
#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include "keypad.h"
#include "Timer.h"
#include "buzzer.h"
#include "UART.h"
#include <util/delay.h>
void servo_angle(u16 angle);

void main(void) {
	// Initialize various hardware pins and modules
	// Set the direction for pins that connected master w slave with each other
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN0, DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN1, DIO_OUTPUT);

	//LCD DATA DIRECTION
	DIO_SetPortDirection(CLCD_DATA_PORT, DIO_OUTPUT);

	//LCD CTRL DIRECTION
	DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN0, DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN1, DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT, DIO_PIN2, DIO_OUTPUT);

	// Set direction for pin of motor
	DIO_SetPinDirection(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);

	//Timer,buzzer,KPD and UART initialization
	TIMER1_voidINIT();
	buzzer_init();
	CLCD_voidInitl();
	KPD_Init();
	UART_voidINIT_TX();

	//Password checker
	CLCD_voidString("Welcome,Enter");
	CLCD_voidGoTo_X_Y(1, 0);
	CLCD_voidString("your password");
	_delay_ms(1000);
	CLCD_voidLCD_Clear();

	char enteredPassword[6];
	// correct password
	char correctPassword[6] = "12345";
	u8 y;
	// numbers of trials
	int h = 3;

	while (1) {
		// Check if the maximum number of password trials has been reached
		if (h == 0) {
			CLCD_voidGoTo_X_Y(0, 0);
			CLCD_voidString("Max trials reached");
			CLCD_voidGoTo_X_Y(1, 0);
			CLCD_voidString("Access blocked");
			buzzer_on();
			_delay_ms(1000);
			buzzer_off();
			_delay_ms(1000);
			break;
		}

		// Wait for a key press
		do {
			y = KPD_GETPressedKey();
		} while (y == KPD_NOT_PRESSED_KEY);

		// Check if the entered password matches
		if (y == '=') {
			CLCD_voidLCD_Clear();
			int isPasswordCorrect = 1;
			for (int i = 0; i < 5; i++) {
				if (enteredPassword[i] != correctPassword[i]) {
					isPasswordCorrect = 0;
					break;
				}
			}
			CLCD_voidGoTo_X_Y(1, 0);

			if (isPasswordCorrect) {
				// If the password is correct, open the door and send a signal
				TIMER1_voidSetChannelCompareMatch(1000);
				servo_angle(90);
				CLCD_voidGoTo_X_Y(1, 0);
				CLCD_voidString("Door open");
				_delay_ms(1000);
				UART_voidSendData_TX(1);
				break; // Exit the password input loop
			} else {
				h--;
				CLCD_voidString("Wrong");
				CLCD_voidGoTo_X_Y(2, 0);
				CLCD_voidString("Trials left:");
				CLCD_voidSendData(h + '0');
				_delay_ms(1000);
				CLCD_voidLCD_Clear();
				memset(enteredPassword, 0, sizeof (enteredPassword)); // Reset entered password
			}
		} else {
			// Accumulate the entered digits as a string
			if (y >= '0' && y <= '9') {
				for (int i = 0; i < 5; i++) {
					if (enteredPassword[i] == '\0') {
						enteredPassword[i] = y;
						break;
					}
				}
			}
			// Display the entered digits on the LCD
			CLCD_voidGoTo_X_Y(0, 0);
			CLCD_voidString(enteredPassword);
		}
	}

	u8 x;
	u8 pressed;
	u8 r;

	// Function for manual control section
	void cm(void) {
		while (1) {
			// Wait for a key press
			do {
				x = KPD_GETPressedKey();
			} while (x == KPD_NOT_PRESSED_KEY);

			if (x == 'C') {
				CLCD_voidGoTo_X_Y(0, 0);
				CLCD_voidString("Need to control?");
				CLCD_voidGoTo_X_Y(1, 0);
				CLCD_voidString("(1)yes (2)no");
				_delay_ms(1000);
				CLCD_voidLCD_Clear();
				// Wait for a response (yes or no)
				do {
					r = KPD_GETPressedKey();
				} while (r == KPD_NOT_PRESSED_KEY);

				if (r == '1') {
					CLCD_voidGoTo_X_Y(0, 0);
					CLCD_voidString("1.Room1 2.Room2");
					CLCD_voidGoTo_X_Y(1, 0);
					CLCD_voidString("3.Room3 4.HU 5.AC");
					_delay_ms(1000);
					CLCD_voidLCD_Clear();
					while (1) {
						// Wait for a room selection
						do {
							pressed = KPD_GETPressedKey();
						} while (pressed == KPD_NOT_PRESSED_KEY);

						// Control options for different rooms and devices
						if (pressed == '1') {
							CLCD_voidGoTo_X_Y(0, 0);
							CLCD_voidString("Room 1:");
							CLCD_voidGoTo_X_Y(1, 0);
							CLCD_voidString("1.on  2.off 3.c");
							_delay_ms(500);
							CLCD_voidLCD_Clear();
							while (1) {
								// Wait for an action (on, off, cancel)
								do {
									pressed = KPD_GETPressedKey();
								} while (pressed == KPD_NOT_PRESSED_KEY);
								if (pressed == '1') {
									UART_voidSendData_TX(2);
								} else if (pressed == '2') {
									UART_voidSendData_TX(3);
								} else if (pressed == '3') {
									// Return to the previous menu
									cm();
								}
							}
						}
						// Similar control options for other rooms and devices
						if (pressed == '2') {
							CLCD_voidGoTo_X_Y(0, 0);
							CLCD_voidString("Room 2:");
							CLCD_voidGoTo_X_Y(1, 0);
							CLCD_voidString("1.on  2.off 3.c");
							_delay_ms(500);
							CLCD_voidLCD_Clear();
							while (1) {
								do {
									pressed = KPD_GETPressedKey();
								} while (pressed == KPD_NOT_PRESSED_KEY);
								if (pressed == '1') {
									UART_voidSendData_TX(4);
								} else if (pressed == '2') {
									UART_voidSendData_TX(5);
								} else if (pressed == '3') {
									// Return to the previous menu
									cm();
								}
							}
						}
						if (pressed == '3') {
							CLCD_voidGoTo_X_Y(0, 0);
							CLCD_voidString("Room 3:");
							CLCD_voidGoTo_X_Y(1, 0);
							CLCD_voidString("1.on  2.off 3.c");
							_delay_ms(500);
							CLCD_voidLCD_Clear();
							while (1) {
								do {
									pressed = KPD_GETPressedKey();
								} while (pressed == KPD_NOT_PRESSED_KEY);
								if (pressed == '1') {
									UART_voidSendData_TX(6);
								} else if (pressed == '2') {
									UART_voidSendData_TX(7);
								} else if (pressed == '3') {
									// Return to the previous menu
									cm();
								}
							}
						}
						if (pressed == '4') {
							CLCD_voidGoTo_X_Y(0, 0);
							CLCD_voidString("Heater:");
							CLCD_voidGoTo_X_Y(1, 0);
							CLCD_voidString("1.on  2.off 3.c");
							_delay_ms(500);
							CLCD_voidLCD_Clear();
							while (1) {
								do {
									pressed = KPD_GETPressedKey();
								} while (pressed == KPD_NOT_PRESSED_KEY);
								if (pressed == '1') {
									UART_voidSendData_TX(8);
								} else if (pressed == '2') {
									UART_voidSendData_TX(9);
								} else if (pressed == '3') {
									// Return to the previous menu
									cm();
								}
							}
						}
						if (pressed == '5') {
							CLCD_voidGoTo_X_Y(0, 0);
							CLCD_voidString("Cooler:");
							CLCD_voidGoTo_X_Y(1, 0);
							CLCD_voidString("1.on  2.off 3.c");
							_delay_ms(500);
							CLCD_voidLCD_Clear();
							while (1) {
								do {
									pressed = KPD_GETPressedKey();
								} while (pressed == KPD_NOT_PRESSED_KEY);
								if (pressed == '1') {
									UART_voidSendData_TX(10);
								} else if (pressed == '2') {
									UART_voidSendData_TX(11);
								} else if (pressed == '3') {
									// Return to the previous menu
									cm();
								}
							}
						}
					}
				} else {
					CLCD_voidString("Have a nice day!");
					_delay_ms(1000);
				}
			}
		}
	}

	// Check if there are more password trials remaining
	if (h > 0) {
		cm(); // Enter the manual control section
	}
}
void servo_angle(u16 angle) {
	// Set the initial position of the servo motor
	TIMER1_voidSetChannelCompareMatch(1000); // Assuming 1000 is the neutral position

	// Calculate the new angle value within the servo's range
	u16 new_angle = 1000 + (u16)angle * 9.72222222222; // Adjust this calculation as needed

	// Set the servo motor to the   new angle
	TIMER1_voidSetChannelCompareMatch(new_angle);
}

