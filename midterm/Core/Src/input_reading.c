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

#define N0_OF_BUTTONS 						3
#define DURATION_FOR_LONG_PRESS		 		3000
#define BUTTON_IS_PRESSED 					GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 					GPIO_PIN_SET

static GPIO_PinState buttonBuffer[ N0_OF_BUTTONS ] = {1, 1, 1};
static GPIO_PinState debounceButtonBuffer1[ N0_OF_BUTTONS ] = {1, 1, 1};
static GPIO_PinState debounceButtonBuffer2[ N0_OF_BUTTONS ] = {1, 1, 1};
static GPIO_PinState debounceButtonBuffer3[ N0_OF_BUTTONS ] = {1, 1, 1};
static uint8_t flagForButtonPress[ N0_OF_BUTTONS ];
static uint8_t flagForButtonPress3s[ N0_OF_BUTTONS ];
static uint16_t counterForButtonPress3s[ N0_OF_BUTTONS ] = {0, 0, 0};


void button_reading ( void ) {
	for ( int i = 0; i < N0_OF_BUTTONS ; i++) {
			debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
			debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13 << i);

			if( (debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) && (debounceButtonBuffer3[i] == debounceButtonBuffer2[i]))
			{
				if(buttonBuffer[i] != debounceButtonBuffer1[i])
				{
					buttonBuffer[i] = debounceButtonBuffer1[i];
					if( buttonBuffer[i] == BUTTON_IS_PRESSED )
					{
						counterForButtonPress3s[i] = DURATION_FOR_LONG_PRESS;
						counterForButtonPress3s[i] /= TIME_CYCLE;
						flagForButtonPress[i] = 1;
					}
					else flagForButtonPress3s[i] = 0;
				}
			}

			else {
				if( buttonBuffer[i] == BUTTON_IS_PRESSED )
				{
					counterForButtonPress3s[i]--;
					if(counterForButtonPress3s[i] == 0)
					{
						flagForButtonPress3s[i] = 1;
					}
				}
			}
	}
}

int is_button_pressed (int index)
{
	if(index < 0 || index > N0_OF_BUTTONS ) return 0;
	if(flagForButtonPress3s[index] == 1)
	{
		flagForButtonPress3s[index] = 0;
		return 1;
	}
	else return 0;
}

int is_button_pressed_3s (int index )
{
	if( index < 0 || index > N0_OF_BUTTONS ) return 0 ;
	return ( flagForButtonPress3s[index] == 1) ;
}


#endif /* SRC_INPUT_READING_C_ */
