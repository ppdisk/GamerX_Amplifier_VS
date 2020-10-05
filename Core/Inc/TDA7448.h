/*
 * TDA7448.h
 *
 *  Created on: 28 сент. 2020 г.
 *      Author: macukov-ma
 */

#include "stm32f1xx_hal.h"
#include "main.h"


#ifndef TDA7448_H_
#define TDA7448_H_

//extern struct srtAmpData;


class TDA7448 {
public:
	TDA7448(I2C_HandleTypeDef*, uint8_t);
	void SetMasterVolume(uint8_t volume);
	void SetChannelVolume(uint8_t ch,uint8_t volume);
	void MasterVolumeInc(void);
	void MasterVolumeDec(void);
	void Mute(bool);
	uint8_t GetMasterVolume();

private:
	I2C_HandleTypeDef* hi2c;
	uint8_t addr;
	uint8_t volume1,volume2,volume3,volume4,volume5,volume6;
	srtAmpData ampData;
	void ChangeVolumeWithoutSend(uint8_t ch, int8_t direction);

	void SendToAmplifier(void);
};

#endif /* TDA7448_H_ */
