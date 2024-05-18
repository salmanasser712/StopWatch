/*
 * app.h
 *
 *  Created on: Nov 12, 2023
 *      Author: Owner
 */

#ifndef APP_H_
#define APP_H_

#define segled_0               PIN11
#define segled_1               PIN12
#define segled_2               PIN13
#define segled_3               PIN14

#define LED_PORT               PORTA

void stop_watch(u8 key_pressed);

void inc_watch();

void Init_leds();

#endif /* APP_H_ */
