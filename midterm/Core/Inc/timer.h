/*
 * timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIME_CYCLE		10 //10ms delay

extern int timer0_flag;
//extern int timer0_counter;

extern int timer1_flag;
//extern int timer1_counter;

extern int timer2_flag;
//extern int timer2_counter;

void setTimer1(int duration);
void setTimer0 (int duration);
void setTimer2(int duration);

void timer_run();
//void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef * htim);


#endif /* INC_TIMER_H_ */
