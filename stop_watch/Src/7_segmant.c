// Include the necessary header files
#include "BitMath.h"
#include "7_segmant.h"
#include "delay.h"

// Function to initialize the 7-segment display
void Init_Segmant(void){
	// Set the mode of the pins connected to the segments of the display to output
	// number
	DIO_voidSetPinDirection(PORTB,pin0_num,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB,pin1_num,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB,pin2_num,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB,pin3_num,GPIO_OUTPUT_10MHZ_PP);
	// select
	DIO_voidSetPinDirection(PORTB,pin0_sel,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB,pin1_sel,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB,pin2_sel,GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTB,pin3_sel,GPIO_OUTPUT_10MHZ_PP);

	// Set the initial level of the pins to low
	DIO_voidSetPinValue(PORTB,pin0_sel,GPIO_LOW);
	DIO_voidSetPinValue(PORTB,pin1_sel,GPIO_LOW);
	DIO_voidSetPinValue(PORTB,pin2_sel,GPIO_LOW);
	DIO_voidSetPinValue(PORTB,pin3_sel,GPIO_LOW);
}

// Function to display a number on the 7-segment display
void Segmant_Display(u8 Number){
	// Switch statement to control which number is displayed
	switch (Number){
		case 0:
		// Set the level of the pins to display the number 0
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		case 1:
		// Set the level of the pins to display the number 1
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		// Set the level of the pins to display the number 2
		case 2:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		// Set the level of the pins to display the number 3
		case 3:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		// Set the level of the pins to display the number 4
		case 4:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		// Set the level of the pins to display the number 5
		case 5:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		// Set the level of the pins to display the number 6
		case 6:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		// Set the level of the pins to display the number 7
		case 7:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_LOW);
		break;
		// Set the level of the pins to display the number 8
		case 8:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_HIGH);
		break;
		// Set the level of the pins to display the number 9
		case 9:
		DIO_voidSetPinValue(PORTB,pin0_num,GPIO_HIGH);
		DIO_voidSetPinValue(PORTB,pin1_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin2_num,GPIO_LOW);
		DIO_voidSetPinValue(PORTB,pin3_num,GPIO_HIGH);
		break;
	}
}

void select(u8 val){
		switch(val){
		case 0:
			DIO_voidSetPinValue(PORTB,pin0_sel,GPIO_HIGH);
			_delay_ms(5);
			DIO_voidSetPinValue(PORTB,pin0_sel,GPIO_LOW);
			break;
		case 1:
			DIO_voidSetPinValue(PORTB,pin1_sel,GPIO_HIGH);
			_delay_ms(5);
			DIO_voidSetPinValue(PORTB,pin1_sel,GPIO_LOW);
			break;
		case 2:
			DIO_voidSetPinValue(PORTB,pin2_sel,GPIO_HIGH);
			_delay_ms(5);
			DIO_voidSetPinValue(PORTB,pin2_sel,GPIO_LOW);
			break;
		case 3:
			DIO_voidSetPinValue(PORTB,pin3_sel,GPIO_HIGH);
			_delay_ms(5);
			DIO_voidSetPinValue(PORTB,pin3_sel,GPIO_LOW);
			break;
		}
	}

