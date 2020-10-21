/*
 * HD44780.cpp
 *
 *  Created on: 24 сент. 2020 г.
 *      Author: macukov-ma
 */

#include "HD44780.h"


#define d4_set() HAL_GPIO_WritePin(D4_Port, D4_Pin, GPIO_PIN_SET)
#define d5_set() HAL_GPIO_WritePin(D5_Port, D5_Pin, GPIO_PIN_SET)
#define d6_set() HAL_GPIO_WritePin(D6_Port, D6_Pin, GPIO_PIN_SET)
#define d7_set() HAL_GPIO_WritePin(D7_Port, D7_Pin, GPIO_PIN_SET)

#define d4_reset() HAL_GPIO_WritePin(D4_Port, D4_Pin, GPIO_PIN_RESET)
#define d5_reset() HAL_GPIO_WritePin(D5_Port, D5_Pin, GPIO_PIN_RESET)
#define d6_reset() HAL_GPIO_WritePin(D6_Port, D6_Pin, GPIO_PIN_RESET)
#define d7_reset() HAL_GPIO_WritePin(D7_Port, D7_Pin, GPIO_PIN_RESET)

#define e1 HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_SET)
#define e0 HAL_GPIO_WritePin(E_Port, E_Pin, GPIO_PIN_RESET)


#define rs1 HAL_GPIO_WritePin(RS_Port, RS_Pin, GPIO_PIN_SET)
#define rs0 HAL_GPIO_WritePin(RS_Port, RS_Pin, GPIO_PIN_RESET)

void HD44780::DWT_DelayUpdate(void)
{
	Delay_ms = SystemCoreClock / 1000;    // Число тактов ядра за миллисекунду.
	Delay_us = SystemCoreClock / 1000000; // Число тактов ядра за микросекунду.
}

void HD44780::DWT_Init(void)
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
	DWT_DelayUpdate();
}

void HD44780::DWT_Delay_us(uint32_t us) // В микросекундах.
{
	uint32_t Count = DWT->CYCCNT;
	us = us * Delay_us;
	while ((DWT->CYCCNT - Count) < us) ;
}

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

	DWT_Init();
	
	HAL_Delay(40);
	rs0;
	LCD_WriteData(3);
	e1;
	DWT_Delay_us(1);
	e0;
	HAL_Delay(1);
	LCD_WriteData(3);
	e1;
	DWT_Delay_us(1);
	e0;
	HAL_Delay(1);
	LCD_WriteData(3);
	e1;
	DWT_Delay_us(1);
	e0;
	HAL_Delay(1);
	LCD_Command(0x28);
	HAL_Delay(1);
	LCD_Command(0x28);
	HAL_Delay(1);
	LCD_Command(0x0C);
	HAL_Delay(1);
	LCD_Command(0x01);
	HAL_Delay(2);
	LCD_Command(0x06);
	HAL_Delay(1);
	LCD_Command(0x02);
	HAL_Delay(2);
	
}


void HD44780::LCD_String(char* ch)
{
	uint8_t i = 0;
	while (ch[i] != 0)
	{
		LCD_Data((uint8_t) ch[i]);
		HAL_Delay(1);
		i++;
	}
	
}
void HD44780::LCD_WriteData(uint8_t dt)
{
	if (((dt >> 3) & 0x01) == 1) {d7_set();}
	else {d7_reset();}
	if (((dt >> 2) & 0x01) == 1) {d6_set();}
	else {d6_reset();}
	if (((dt >> 1) & 0x01) == 1) {d5_set();}
	else {d5_reset();}
	if ((dt & 0x01) == 1) {d4_set();}
	else {d4_reset();}
}

void HD44780::delay(void)
{
	DWT_Delay_us(50);
}

void HD44780::LCD_Data(uint8_t dt)
{
	rs1;
	LCD_WriteData(dt >> 4);
	e1;
	DWT_Delay_us(1);
	//delay();
	e0;
	LCD_WriteData(dt);
	e1;
	DWT_Delay_us(1);
	//delay();
	e0;
}

void HD44780::LCD_Command(uint8_t dt)
{
	rs0;
	LCD_WriteData(dt >> 4);
	e1;
	DWT_Delay_us(1);
	e0;
	LCD_WriteData(dt);
	e1;
	DWT_Delay_us(1);
	e0;
}


void HD44780::LCD_Clear(void)
{
	LCD_Command(0x01);
	HAL_Delay(1);
}

void HD44780::LCD_SendChar(char ch)
{
	LCD_Data((uint8_t) ch);
	for (uint8_t i = 0; i < 65; i++)
	{
		DWT_Delay_us(50);
	}
	
}

void HD44780::LCD_SetPos(uint8_t x, uint8_t y)
{
	switch (y)
	{
	case 0:
		LCD_Command(x | 0x80);
		break;
	case 1:
		LCD_Command(0x80 | 0x40 | x);
		break;
	case 2:
		LCD_Command(0x80 | 0x14 | x);
		break;
	case 3:
		LCD_Command(0x80 | 0x54 | x);
		break;
	default:
		break;
	}
	
	for (uint8_t i = 0; i < 65; i++)
	{
		DWT_Delay_us(50);
	}
	
}

void HD44780::UpdateDisplay(void)
{
	LCD_SetPos(0, 0);
	LCD_String(StringData1);
	LCD_SetPos(0, 1);
	LCD_String(StringData2);
}