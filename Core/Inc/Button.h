/*
 * Button.h
 *
 *  Created on: Oct 1, 2020
 *      Author: macukov-ma
 */

#include "stm32f1xx_hal.h"

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

class Button {
public:
	Button(GPIO_TypeDef *Button_Port, uint16_t Button_Pin);
	bool Pressed(void);
private:
	GPIO_TypeDef *Button_Port;
	uint16_t Button_Pin;
	bool flagButtonPress;
	uint32_t timeButtonPress;
};

#endif /* INC_BUTTON_H_ */
