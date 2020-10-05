/*
 * TTP223.h
 *
 *  Created on: 25 сент. 2020 г.
 *      Author: macukov-ma
 */

#include "stm32f1xx_hal.h"

#ifndef TTP223_H_
#define TTP223_H_

class TTP223 {
public:
	TTP223(GPIO_TypeDef *TTP223_Port, uint16_t TTP223_Pin);
	bool GetState(void);
	void SetState(bool);
	bool StateChanged();

private:
	bool State, StateChnd;
	GPIO_TypeDef *TTP223_Port;
	uint8_t TTP223_Pin;
};

#endif /* TTP223_H_ */
