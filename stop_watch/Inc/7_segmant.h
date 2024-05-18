/*
 * 7_segmant.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Muhamed Ashraf
 */

#ifndef INC_7_segmant_H_
#define INC_7_segmant_H_

#define Commom_Anode    0
#define Common_Cathode  1

#define pin0_num        PIN7
#define pin1_num        PIN8
#define pin2_num        PIN9
#define pin3_num        PIN10

#define pin0_sel        PIN3
#define pin1_sel        PIN2
#define pin2_sel        PIN1
#define pin3_sel        PIN0


#include "std_typo.h"
#include "GPIO_interface.h"

// Function Prototypes


void Init_Segmant(void);

void Segmant_Display(u8 Number);

void select(u8 val);


#endif /* INC_7_segmant_H_ */
