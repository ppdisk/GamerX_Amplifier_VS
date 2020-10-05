/*
 * eeprom.cpp
 *
 *  Created on: Oct 1, 2020
 *      Author: macukov-ma
 */

#include <eeprom.h>

eeprom::eeprom(I2C_HandleTypeDef hi2c, uint8_t address)
{
	this->hi2c = hi2c;
	this->address = address;
	ReadSettings();
}

void eeprom::ReadSettings(void)
{
	HAL_I2C_Master_Receive_DMA(&hi2c, address, reinterpret_cast<uint8_t*>(&ampData), sizeof(ampData));
}

void eeprom::WriteSettings(void)
{
	HAL_I2C_Master_Transmit_DMA(&hi2c, address, reinterpret_cast<uint8_t*>(&ampData), sizeof(ampData));
}
