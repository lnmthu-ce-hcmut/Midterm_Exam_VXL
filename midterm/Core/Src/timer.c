/*
 * timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */

#include "main.h"
#include "timer.h"
#include "input_reading.h"


int timer0_counter = 0;
int timer0_flag = 0;

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;


void setTimer0(int duration) {
	if(TIME_CYCLE > 0)
	{
		timer0_counter = duration / TIME_CYCLE;
	}
	else timer0_counter = duration;
	timer0_flag = 0;
}

void setTimer1(int duration){
	if(TIME_CYCLE > 0)
	{
		timer1_counter = duration / TIME_CYCLE;
	}
	else timer1_counter = duration;
	timer1_flag = 0;
}

void setTimer2(int duration){
	if(TIME_CYCLE > 0)
	{
		timer2_counter = duration / TIME_CYCLE;
	}
	else timer2_counter = duration;
	timer2_flag = 0;
}

void timer_run(){
	if(timer0_counter > 0) {
		timer0_counter--;
		if(timer0_counter == 0) timer0_flag = 1;
	}
	if(timer1_counter > 0) {
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
	if(timer2_counter > 0) {
		timer2_counter--;
		if(timer2_counter == 0) timer2_flag = 1;
	}
}


