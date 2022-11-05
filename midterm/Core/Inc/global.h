/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH THU
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "7SEG_display.h"

typedef enum  {
	INIT,
	WAIT,
	RST,
	INC,
	DEC,
	INC_3s,
	DEC_3s,
	AUTO,
} State;

extern State state;

#endif /* INC_GLOBAL_H_ */
