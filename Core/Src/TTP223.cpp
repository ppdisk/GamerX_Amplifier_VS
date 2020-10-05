/*
 * TTP223.cpp
 *
 *  Created on: 25 сент. 2020 г.
 *      Author: macukov-ma
 */

#include "TTP223.h"

TTP223::TTP223(GPIO_TypeDef *TTP223_Port, uint16_t TTP223_Pin)
{
	this->TTP223_Port = TTP223_Port;
	this->TTP223_Pin = TTP223_Pin;

}


bool TTP223::StateChanged(void)
{
	return StateChnd;
}

void TTP223::SetState(bool state)
{
	StateChnd = true;
	this->State = state;
}

bool TTP223::GetState(void)
{
	StateChnd = false;
	return State;
}
