/*
 * led_display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */

#include "led_display.h"

void ledBlink(void) {
	if(timer1_flag == 1) {
		setTimer1(1000);
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	}
}
