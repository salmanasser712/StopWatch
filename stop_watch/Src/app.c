#include "std_typo.h"
#include "BitMath.h"
#include "GPIO_interface.h"
#include "keypad.h"
#include "7_segmant.h"
#include "SYSTICK.h"
#include "app.h"

extern u8 digits[4];
u8 edit = 0;
u8 seg_edit = 0;

void S_pressed();
void E_pressed();
void left_pressed();
void right_pressed();
void num_pressed(u8 num);
void C_pressed();
void leds();
void led_val(u8 led0, u8 led1, u8 led2, u8 led3);

void stop_watch(u8 key_pressed){
	if(key_pressed == 'x') return;
	switch(key_pressed){
	case 'E':
		E_pressed();
		break;
	case 'S':
		S_pressed();
		break;
	case 'C':
		C_pressed();
		break;
	case '0':
		num_pressed(0);
		break;
	case '1':
		num_pressed(1);
		break;
	case '2':
		num_pressed(2);
		break;
	case '3':
		num_pressed(3);
		break;
	case '4':
		num_pressed(4);
		break;
	case '5':
		num_pressed(5);
		break;
	case '6':
		num_pressed(6);
		break;
	case '7':
		num_pressed(7);
		break;
	case '8':
		num_pressed(8);
		break;
	case '9':
		num_pressed(9);
		break;
	case '<':
		left_pressed();
		break;
	case '>':
		right_pressed();
		break;
	default:
		return;
	}

}

void C_pressed(){
	digits[0] = digits[1] = digits[2] = digits[3] = 0;
	edit = 0;
	leds();
}

void S_pressed(){
	SYSTICK_Start();
	edit = 0;
	leds();
}

void E_pressed(){
	if(edit){
		edit = 0;
	}
	else{
		SYSTICK_Stop();
		edit = 1;
	}
	leds();
}
void left_pressed(){
	if(!edit) return;
	if(seg_edit == 0){
		seg_edit = 3;
	}
	else{
		seg_edit--;
	}
	leds();
}
void right_pressed(){
	if(!edit) return;
	if(seg_edit == 3){
		seg_edit = 0;
	}
	else{
		seg_edit++;
	}
	leds();
}

void Init_leds(){
	DIO_voidSetPinDirection(LED_PORT, segled_0, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(LED_PORT, segled_1, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(LED_PORT, segled_2, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(LED_PORT, segled_3, GPIO_OUTPUT_10MHZ_PP);
}

void led_val(u8 led0, u8 led1, u8 led2, u8 led3){
	DIO_voidSetPinValue(LED_PORT, segled_0, led0);
	DIO_voidSetPinValue(LED_PORT, segled_1, led1);
	DIO_voidSetPinValue(LED_PORT, segled_2, led2);
	DIO_voidSetPinValue(LED_PORT, segled_3, led3);
}

void leds(){
	u8 led0 = GPIO_LOW, led1 = GPIO_LOW,  led2 = GPIO_LOW, led3 = GPIO_LOW;

	if(seg_edit == 0 && edit){
		led0 = GPIO_HIGH;
	}
	else if(seg_edit == 1 && edit){
		led1 = GPIO_HIGH;
	}
	else if(seg_edit == 2 && edit){
		led2 = GPIO_HIGH;
	}
	else if(seg_edit == 3 && edit){
		led3 = GPIO_HIGH;
	}
	led_val(led0, led1, led2, led3);
}
void num_pressed(u8 num){
	if(edit == 0) return;

	if((seg_edit == 0 || seg_edit == 2) && num > 5){
		digits[seg_edit] = 0;
	}
	else{
		digits[seg_edit] = num;
	}
}

void inc_watch(){
	if(digits[2] == 5 && digits[3] == 9){
		if(digits[0] == 5 && digits[1] == 9){
			digits[0] = digits[1] = digits[2] = digits[3] = 0;
		}
		else if(digits[0] == 5){
			digits[1]++;
			digits[2] = digits[3] = 0;
		}
		else if(digits[1] == 9){
			digits[0]++;
			digits[2] = digits[1] = digits[3] = 0;
		}
		else{
			digits[1]++;
			digits[2] = digits[3] = 0;
		}
	}
	else if(digits[3] == 9){
		digits[2]++;
		digits[3] = 0;
	}
	else{
		digits[3]++;
	}
}
