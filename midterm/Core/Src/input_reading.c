/*
 * input_reading.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */


#ifndef SRC_INPUT_READING_C_
#define SRC_INPUT_READING_C_

#include "main.h"
#include "input_reading.h"

int FlagForButtonPress[N0_OF_BUTTONS]= {1, 1, 1};


static GPIO_PinState Key_0 [N0_OF_BUTTONS];
static GPIO_PinState Key_1 [N0_OF_BUTTONS];
static GPIO_PinState Key_2 [N0_OF_BUTTONS];
static GPIO_PinState Key_3 [N0_OF_BUTTONS];

static uint8_t buttonBuffer [N0_OF_BUTTONS];
static uint8_t flagForButtonPress3s [N0_OF_BUTTONS];
static uint16_t counterForButtonPress3s [N0_OF_BUTTONS ];
// mode  time  select button
// RESET INC DEC
void button_reading ( void ) {
	for( char i = 0; i < N0_OF_BUTTONS ; i++) {
			Key_2[i] = Key_1[i];
			Key_1[i]=Key_0[i];
			if (i == 0) Key_0[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13 << i);

			if(Key_2[i] == Key_1[i] && Key_1[i] == Key_0[i]){
				if(Key_3[i]!=Key_2[i]){
					Key_3[i]=Key_2[i];
					if(Key_3[i] == BUTTON_IS_PRESSED){
						buttonBuffer[i] = BUTTON_IS_PRESSED;
						counterForButtonPress3s[i]= DURATION_FOR_AUTO_INCREASING;
					}
					else
					{
						buttonBuffer[i] = BUTTON_IS_RELEASED;
						flagForButtonPress3s[i] = 0;
						FlagForButtonPress[i]=1;
					}
				}else{
					if(Key_3[i] == BUTTON_IS_PRESSED){
						counterForButtonPress3s[i]--;
						if(counterForButtonPress3s[i]==0){
							flagForButtonPress3s[i]=1;
						}
					}
			}
		}
	}
}
unsigned char is_button_pressed ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	if(buttonBuffer[index]==BUTTON_IS_PRESSED && FlagForButtonPress[index]==1 ){
		FlagForButtonPress[index]=0;
		return 1;
	}
	return 0;
}
unsigned char is_button_pressed_3s ( uint8_t index ) {
	if( index >= N0_OF_BUTTONS ) return 0;
	return (flagForButtonPress3s[index]==1);
}



#endif /* SRC_INPUT_READING_C_ */
