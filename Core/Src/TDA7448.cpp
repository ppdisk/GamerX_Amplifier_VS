/*
 * TDA7448.cpp
 *
 *  Created on: 28 сент. 2020 г.
 *      Author: macukov-ma
 */

#include "TDA7448.h"

TDA7448::TDA7448(I2C_HandleTypeDef* hi2c, uint8_t address)
{
	this->hi2c = hi2c;
	this->addr = address;

}

void TDA7448::SendToAmplifier(void)
{
	HAL_I2C_Master_Transmit_DMA(hi2c, addr, reinterpret_cast<uint8_t*>(&ampData), sizeof(ampData));
}

void TDA7448::SetMasterVolume(uint8_t volume)
{
	ampData.SPEAKER_ATTENUATION_OUT_1 = volume;
	ampData.SPEAKER_ATTENUATION_OUT_2 = volume;
	ampData.SPEAKER_ATTENUATION_OUT_3 = volume;
	ampData.SPEAKER_ATTENUATION_OUT_4 = volume;
	ampData.SPEAKER_ATTENUATION_OUT_5 = volume;
	ampData.SPEAKER_ATTENUATION_OUT_6 = volume;

	SendToAmplifier();
}

uint8_t TDA7448::GetMasterVolume(void)
{
	return (volume1+volume2+volume3+volume4+volume5+volume6)/6;
}

void TDA7448::SetChannelVolume(uint8_t ch,uint8_t volume)
{
	switch (ch)
	{
		case 1:
			ampData.SPEAKER_ATTENUATION_OUT_1 = volume;
			break;
		case 2:
			ampData.SPEAKER_ATTENUATION_OUT_2 = volume;
			break;
		case 3:
			ampData.SPEAKER_ATTENUATION_OUT_3 = volume;
			break;
		case 4:
			ampData.SPEAKER_ATTENUATION_OUT_4 = volume;
			break;
		case 5:
			ampData.SPEAKER_ATTENUATION_OUT_5 = volume;
			break;
		case 6:
			ampData.SPEAKER_ATTENUATION_OUT_6 = volume;
			break;
		default:
			break;
	}
	SendToAmplifier();
}

void TDA7448::ChangeVolumeWithoutSend(uint8_t ch, int8_t direction)
{
	switch (ch)
		{
			case 1:
				if(ampData.SPEAKER_ATTENUATION_OUT_1<250&&ampData.SPEAKER_ATTENUATION_OUT_1>5)
					ampData.SPEAKER_ATTENUATION_OUT_1 +=(5*direction);
				break;
			case 2:
				if(ampData.SPEAKER_ATTENUATION_OUT_2<250&&ampData.SPEAKER_ATTENUATION_OUT_2>5)
					ampData.SPEAKER_ATTENUATION_OUT_2 +=(5*direction);
				break;
			case 3:
				if(ampData.SPEAKER_ATTENUATION_OUT_3<250&&ampData.SPEAKER_ATTENUATION_OUT_3>5)
					ampData.SPEAKER_ATTENUATION_OUT_3 +=(5*direction);
				break;
			case 4:
				if(ampData.SPEAKER_ATTENUATION_OUT_4<250&&ampData.SPEAKER_ATTENUATION_OUT_4>5)
					ampData.SPEAKER_ATTENUATION_OUT_4 +=(5*direction);
				break;
			case 5:
				if(ampData.SPEAKER_ATTENUATION_OUT_5<250&&ampData.SPEAKER_ATTENUATION_OUT_5>5)
					ampData.SPEAKER_ATTENUATION_OUT_5 +=(5*direction);
				break;
			case 6:
				if(ampData.SPEAKER_ATTENUATION_OUT_6<250&&ampData.SPEAKER_ATTENUATION_OUT_6>5)
					ampData.SPEAKER_ATTENUATION_OUT_6 +=(5*direction);
				break;
			default:
				break;
		}

}

void TDA7448::MasterVolumeInc(void)
{
	for(uint8_t i=1; i<=6; i++)
	{
		ChangeVolumeWithoutSend(i,1);
	}
	SendToAmplifier();
}

void TDA7448::MasterVolumeDec(void)
{
	for(uint8_t i=1; i<=6; i++)
		{
			ChangeVolumeWithoutSend(i,-1);
		}
	SendToAmplifier();
}

void TDA7448::Mute(bool mute)
{
	if(mute==true)
	{
		uint8_t tempData[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
		HAL_I2C_Master_Transmit_DMA(hi2c, addr, tempData, 7);
	}
	else
	{
		SendToAmplifier();
	}
}
