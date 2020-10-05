/*
 * eeprom.h
 *
 *  Created on: Oct 1, 2020
 *      Author: macukov-ma
 */

#include "stm32f1xx_hal.h"
#include "main.h"

#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

class eeprom {
public:
	eeprom(I2C_HandleTypeDef hi2c, uint8_t address);
	void ReadSettings(void);
	void WriteSettings(void);
private:
	uint8_t address;
	I2C_HandleTypeDef hi2c;
	uint8_t RandomRead(uint8_t byteNumber);
	uint8_t* SequentialRead(uint8_t startByteNumber, uint8_t byteCount);
	srtAmpData ampData;
};

#endif /* INC_EEPROM_H_ */
