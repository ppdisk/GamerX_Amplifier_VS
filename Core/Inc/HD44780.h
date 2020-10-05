/*
 * HD44780.h
 *
 *  Created on: 24 сент. 2020 г.
 *      Author: macukov-ma
 */

#include "stm32f1xx_hal.h"

#ifndef HD44780_H_
#define HD44780_H_

class HD44780 {
public:
	HD44780(GPIO_TypeDef *RS_Port, uint16_t RS_Pin,
			GPIO_TypeDef *RW_Port, uint16_t RW_Pin,
			GPIO_TypeDef *E_Port, uint16_t E_Pin,
			GPIO_TypeDef *D4_Port, uint16_t D4_Pin,
			GPIO_TypeDef *D5_Port, uint16_t D5_Pin,
			GPIO_TypeDef *D6_Port, uint16_t D6_Pin,
			GPIO_TypeDef *D7_Port, uint16_t D7_Pin);

	void Clear(void);
	void On(void);
	void Off(void);
	void UpdateDisplay(void);

	char* StringData1;
	char* StringData2;

private:
	GPIO_TypeDef *RS_Port, *RW_Port, *E_Port, *D4_Port, *D5_Port, *D6_Port, *D7_Port;
	uint16_t RS_Pin, RW_Pin, E_Pin, D4_Pin, D5_Pin, D6_Pin, D7_Pin;
	void SendhalfByte(uint8_t);
	void SendCommand(uint8_t);
	void SendData(uint8_t);
	uint8_t isBisy(void);
	void WaitNotBisy(void);
	GPIO_PinState PinState(uint8_t);

};

#endif /* HD44780_H_ */
