/*
 * fsm_simple_buttons_run.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */

#include "fsm_simple_buttons_run.h"

#define RST_BUT			0
#define INC_BUT			1
#define DEC_BUT			2

#define TIME			10000 // 10s
#define CHANGE			1000  // inc/dec counter every 1s when button is hold for >= 3s

void fsm_simple_buttons_run (void)
{
	switch (state)
	{
	case INIT:
		setTimer0(CHANGE);
		setTimer1(TIME_CYCLE);
		setTimer2(TIME_CYCLE);

		resetBuffer();
		state = WAIT;
		break;

	case WAIT:
		display7SEG();

		if(is_button_pressed(RST_BUT))
		{
			state = RST;
		}

		if(is_button_pressed(INC_BUT))
		{
			state = INC;
		}

		if(is_button_pressed(DEC_BUT))
		{
			state = DEC;
		}

		if(is_button_pressed_3s(INC_BUT))
		{
			setTimer0(0);
			state = INC_3s;
		}
		if(is_button_pressed_3s(DEC_BUT))
		{
			setTimer0(0);
			state = DEC_3s;
		}
		if(timer0_flag == 1)
		{
			setTimer2(CHANGE);
			state = AUTO;
			countdownBuffer();
			display7SEG();
		}
		break;

	case RST:
		setTimer0(TIME);
		resetBuffer();
		state = WAIT;
		break;

	case INC:
		setTimer0(TIME);
		increaseBuffer();
		state = WAIT;
		break;

	case DEC:
		setTimer0(TIME);
		decreaseBuffer();
		state = WAIT;
		break;

	case INC_3s:
		if(timer2_flag == 1 && is_button_pressed_3s(INC_BUT))
		{
			setTimer2(CHANGE);
			increaseBuffer();
			display7SEG();
		}

		if(!is_button_pressed_3s(INC_BUT))
		{
			setTimer0(TIME);
			state = WAIT;
		}
		break;

	case DEC_3s:
		if(timer2_flag == 1 && is_button_pressed_3s(DEC_BUT))
		{
			setTimer2(CHANGE);
			decreaseBuffer();
			display7SEG();
		}

		if(!is_button_pressed_3s(DEC_BUT))
		{
			setTimer0(TIME);
			state = WAIT;
		}
		break;

	case AUTO:
		if(timer2_flag == 1)
		{
			setTimer2(CHANGE);
			countdownBuffer();
			display7SEG();
		}
		if(is_button_pressed(DEC_BUT))
		{
			state = DEC;
		}

		if(is_button_pressed(INC_BUT))
		{
			state = INC;
		}

		if(is_button_pressed(RST_BUT))
		{
			state = RST;
		}
	default:
		break;
	}
}
