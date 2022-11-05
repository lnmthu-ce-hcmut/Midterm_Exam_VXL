/*
 * 7SEF_display.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */
#include "7SEG_display.h"

#define NO_OF_SEGMENTS	7
#define NO_OF_VALUES 	10
#define MAX_VALUE		10

#define SECOND 			1000 // 1s = 1000ms

GPIO_TypeDef * SEGPort[NO_OF_SEGMENTS] = {
	LED7_0_GPIO_Port,
	LED7_1_GPIO_Port,
	LED7_2_GPIO_Port,
	LED7_3_GPIO_Port,
	LED7_4_GPIO_Port,
	LED7_5_GPIO_Port,
	LED7_6_GPIO_Port
};

uint16_t SEGPin[NO_OF_SEGMENTS] = {
	LED7_0_Pin,
	LED7_1_Pin,
	LED7_2_Pin,
	LED7_3_Pin,
	LED7_4_Pin,
	LED7_5_Pin,
	LED7_6_Pin
};

//seven segment display
const uint8_t valSEG[NO_OF_VALUES] = {0x40, 0x79, 0x24, 0x30, 0x19,
		0x12, 0x02, 0x78, 0x00, 0x10};

//seven segment buffer
int seven_seg_buffer;

//seven segment functions
void drive7SEG(int num) {
	if(num < 0 || num > 9) return;
	for(int i = 0; i < NO_OF_SEGMENTS; i++) {
		HAL_GPIO_WritePin(SEGPort[i], SEGPin[i], (valSEG[num] >> i) & 0x01);
	}
}

void resetBuffer(void) {
	seven_seg_buffer = 0;
}

void increaseBuffer(void) {
	seven_seg_buffer++;
	seven_seg_buffer %= MAX_VALUE;
}

void decreaseBuffer(void) {
	seven_seg_buffer--;
	if(seven_seg_buffer < 0)
	{
		seven_seg_buffer = MAX_VALUE - 1;
	}
}

void countdownBuffer(void) {
	if(seven_seg_buffer > 0)
	{
		seven_seg_buffer -= 1;
	}
}

void display7SEG(void) {
	drive7SEG(seven_seg_buffer);
}
