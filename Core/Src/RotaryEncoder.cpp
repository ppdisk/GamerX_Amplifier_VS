/*
 * RotaryEncoder.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: macukov-ma
 */

#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(TIM_HandleTypeDef htim)
{


}

bool RotaryEncoder::StateChanged(void)
{
	return false;
}

uint16_t RotaryEncoder::GetDiff(void)
{
	return 0;
}
