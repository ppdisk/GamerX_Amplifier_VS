/*
 * RotaryEncoder.h
 *
 *  Created on: Sep 30, 2020
 *      Author: macukov-ma
 */

#include "stm32f1xx_hal.h"

#ifndef ROTARYENCODER_H_
#define ROTARYENCODER_H_

class RotaryEncoder {
public:
	RotaryEncoder(TIM_HandleTypeDef htim);
	bool StateChanged(void);
	uint16_t GetDiff(void);
private:
	uint16_t current_value;
	uint16_t previous_value;
	int16_t diff;
};

#endif /* ROTARYENCODER_H_ */
