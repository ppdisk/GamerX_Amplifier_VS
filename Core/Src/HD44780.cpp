/*
 * HD44780.cpp
 *
 *  Created on: 24 сент. 2020 г.
 *      Author: macukov-ma
 */

#include "HD44780.h"

HD44780::HD44780(GPIO_TypeDef *RS_Port, uint16_t RS_Pin,
		GPIO_TypeDef *RW_Port, uint16_t RW_Pin,
		GPIO_TypeDef *E_Port, uint16_t E_Pin,
		GPIO_TypeDef *D4_Port, uint16_t D4_Pin,
		GPIO_TypeDef *D5_Port, uint16_t D5_Pin,
		GPIO_TypeDef *D6_Port, uint16_t D6_Pin,
		GPIO_TypeDef *D7_Port, uint16_t D7_Pin)
{

	this->D4_Port = D4_Port;
	this->D5_Port = D5_Port;
	this->D6_Port = D6_Port;
	this->D7_Port = D7_Port;

	this->D4_Pin = D4_Pin;
	this->D5_Pin = D5_Pin;
	this->D6_Pin = D6_Pin;
	this->D7_Pin = D7_Pin;

	this->RS_Port = RS_Port;
	this->RW_Port = RW_Port;
	this->E_Port = E_Port;

	this->RS_Pin = RS_Pin;
	this->RW_Pin = RW_Pin;
	this->E_Pin = E_Pin;




	/* Следующий алгоритм гарантирует, что ЖК-дисплей находится в желаемом режиме:
	 * 1.Установите D7-D4 на 0b0011 и переключите бит enable.
	 * 2.Повторите описанное выше, установив D7-D4 на 0b0011 и снова переключив бит enable.
	 * 3.ЖК-дисплей теперь находится в состоянии State1 или State 3. Повторите предыдущий шаг еще раз.*/

	SendhalfByte(3);
	SendhalfByte(3);
	SendhalfByte(3);




}


void HD44780::On(void)
{

}

void HD44780::UpdateDisplay(void)
{

}

void HD44780::Off(void)
{

}

void HD44780::Clear(void)
{
	SendCommand(0x01);
}

uint8_t HD44780::isBisy(void)
{
	return false;
}

void HD44780::WaitNotBisy(void)
{
	HAL_Delay(1);
	if(isBisy())
		WaitNotBisy();
}

void HD44780::SendCommand(uint8_t Data)
{
	HAL_GPIO_WritePin(RS_Port, RS_Pin, GPIO_PIN_SET);
	SendhalfByte(Data);
	SendhalfByte(Data<<4);
}

void HD44780::SendData(uint8_t Data)
{
	HAL_GPIO_WritePin(RS_Port, RS_Pin, GPIO_PIN_RESET);
	SendhalfByte(Data);
	SendhalfByte(Data<<4);
}

void HD44780::SendhalfByte(uint8_t Data)
{
	if (isBisy())
	{
		WaitNotBisy();
	}

	HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(D4_Port, D4_Pin, PinState((Data >> 3) & 1u));
	HAL_GPIO_WritePin(D5_Port, D5_Pin, PinState((Data >> 2) & 1u));
	HAL_GPIO_WritePin(D6_Port, D6_Pin, PinState((Data >> 1) & 1u));
	HAL_GPIO_WritePin(D7_Port, D7_Pin, PinState((Data >> 0) & 1u));

	HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_SET);
}

GPIO_PinState HD44780::PinState(uint8_t Data)
{
	if(Data == 1)
		return GPIO_PIN_SET;
	else
		return GPIO_PIN_RESET;
}



