/*
 * input_reading.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
#include "main.h"
#include "timer.h"
#define N0_OF_BUTTONS 						3
#define DURATION_FOR_AUTO_INCREASING 		300
#define BUTTON_IS_PRESSED 					GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 					GPIO_PIN_SET

void button_reading(void);
unsigned char is_button_pressed (uint8_t index );
unsigned char is_button_pressed_3s (uint8_t index);


#endif /* INC_INPUT_READING_H_ */
