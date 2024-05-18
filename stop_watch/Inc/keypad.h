/*
 * Keypad.h
 *
 *  Created on: Oct 23, 2016
 *      Author: ESLAM SAID
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

//#include <avr/io.h>
//#include <util/delay.h>
#define NO_KEY 'x'
/*Wiring diagram*/

/* * * *c1  c2 c3 c4
 * row1  1  2  3  A
 * row2  4  5  6  B
 * row3  7  8  9  C
 * row4  *  0  #  D
 */

#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA

#define FIRST_ROW  9
#define SECOND_ROW 8
#define THIRD_ROW  7
#define FOURTH_ROW 6
#define FIRST_COL  4
#define SECOND_COL 3
#define THIRD_COL  2
#define FOURTH_COL 1

#define COL1 PORTA,PIN4
#define COL2 PORTA,PIN3
#define COL3 PORTA,PIN2
#define COL4 PORTA,PIN1

#define ROW1 PORTA,PIN9
#define ROW2 PORTA,PIN8
#define ROW3 PORTA,PIN7
#define ROW4 PORTA,PIN6

void  Keypad_init(void);
u8 Keypad_get_pressed_key(void);

#endif /* KEYPAD_H_ */
