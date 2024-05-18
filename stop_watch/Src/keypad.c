/*
 * Keypad.c
 *
 *  Created on: Oct 23, 2016
 *      Author: ESLAM SAID
 */


#include "std_typo.h"
#include "BitMath.h"
#include "delay.h"
#include "GPIO_interface.h"
#include "Keypad.h"

// Assuming a 4x4 keypad connected to GPIO pins
#define NUM_ROWS 4
#define NUM_COLS 4

u8 keypad[NUM_ROWS][NUM_COLS] = {
	{'7', '8', '9', 'S'},
	{'4', '5', '6', 'E'},
	{'1', '2', '3', 'C'},
	{'<', '0', '>', '*'}
};
 u8 keypad_row_arr[4]={PIN9,PIN8,PIN7,PIN6};
 u8 keypad_col_arr[4]={PIN4,PIN3,PIN2,PIN1};
	 

/*Keypad initialization*/
void Keypad_init(void)
 {
	/*configure Keypad columns as outputs others as inputs*/
	//	setting COLUMS at PORT D as INPUT
	DIO_voidSetPinDirection(COL1,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(COL2,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(COL3,GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(COL4,GPIO_INPUT_PULL_UP_DOWN);

	// setting ROWS at PORT C as OUTPUT
	DIO_voidSetPinDirection(ROW1,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(ROW2,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(ROW3,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(ROW4,GPIO_OUTPUT_10MHZ_PP);
	
	// Setting ROWS to HIGH in INTIALIZATION
	DIO_voidSetPinValue(ROW1,GPIO_HIGH);
	DIO_voidSetPinValue(ROW2,GPIO_HIGH);
	DIO_voidSetPinValue(ROW3,GPIO_HIGH);
	DIO_voidSetPinValue(ROW4,GPIO_HIGH);
 }



u8 Keypad_get_pressed_key(void) {
	u8 level=GPIO_LOW;
	u8 key = NO_KEY;
	u8 flag = 0;
	for (int row = 0; row < NUM_ROWS; row++) {
		DIO_voidSetPinValue(PORTA, keypad_row_arr[row], GPIO_HIGH);
		for (int col = 0; col < NUM_COLS; col++) {
			level = DIO_u8GetPinValue(PORTA, keypad_col_arr[col]);
			_delay_ms(2); // Debounce delay
			if (level == GPIO_HIGH) {

				while (level == GPIO_HIGH){
					level = DIO_u8GetPinValue(PORTA, keypad_col_arr[col]);
					key = keypad[row][col];
				}
				flag = 1;
				break;
			}
		}
		DIO_voidSetPinValue(PORTA, keypad_row_arr[row], GPIO_LOW);
		if(flag) break;
	}
	return key; // Default value if no key is pressed
}
