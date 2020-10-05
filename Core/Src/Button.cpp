/*
 * Button.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: macukov-ma
 */

#include <Button.h>

Button::Button(GPIO_TypeDef *Button_Port, uint16_t Button_Pin)
{
	this->Button_Port = Button_Port;
	this->Button_Pin = Button_Pin;
	this->flagButtonPress = false;
	this->timeButtonPress = HAL_GetTick();
}


bool Button::Pressed(void)
{
	GPIO_PinState ButtonState;
	ButtonState = HAL_GPIO_ReadPin(Button_Port, Button_Pin);
	if(ButtonState==GPIO_PIN_RESET && !flagButtonPress)
	{
		flagButtonPress = true;
		timeButtonPress = HAL_GetTick();
		return true;
	}

	if(flagButtonPress && (HAL_GetTick()-timeButtonPress)>300)
	{
		flagButtonPress = false;
	}
	return false;
}
