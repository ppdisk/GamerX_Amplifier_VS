/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
	struct srtAmpData
	{
		uint8_t SUBADDRESS;
		uint8_t  SPEAKER_ATTENUATION_OUT_1;
		uint8_t  SPEAKER_ATTENUATION_OUT_2;
		uint8_t  SPEAKER_ATTENUATION_OUT_3;
		uint8_t  SPEAKER_ATTENUATION_OUT_4;
		uint8_t  SPEAKER_ATTENUATION_OUT_5;
		uint8_t  SPEAKER_ATTENUATION_OUT_6;
	};
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DEBUG_LED_Pin GPIO_PIN_13
#define DEBUG_LED_GPIO_Port GPIOC
#define HD44780_RS_Pin GPIO_PIN_1
#define HD44780_RS_GPIO_Port GPIOA
#define HD44780_RW_Pin GPIO_PIN_2
#define HD44780_RW_GPIO_Port GPIOA
#define HD44780_E_Pin GPIO_PIN_3
#define HD44780_E_GPIO_Port GPIOA
#define HD44780_D4_Pin GPIO_PIN_4
#define HD44780_D4_GPIO_Port GPIOA
#define HD44780_D5_Pin GPIO_PIN_5
#define HD44780_D5_GPIO_Port GPIOA
#define HD44780_D6_Pin GPIO_PIN_6
#define HD44780_D6_GPIO_Port GPIOA
#define HD44780_D7_Pin GPIO_PIN_7
#define HD44780_D7_GPIO_Port GPIOA
#define sensor_Button_Pin GPIO_PIN_11
#define sensor_Button_GPIO_Port GPIOB
#define encoder_Button_Pin GPIO_PIN_14
#define encoder_Button_GPIO_Port GPIOB
#define Button1_Pin GPIO_PIN_15
#define Button1_GPIO_Port GPIOB
#define MOC3041_Pin GPIO_PIN_8
#define MOC3041_GPIO_Port GPIOA
#define Led2_Pin GPIO_PIN_15
#define Led2_GPIO_Port GPIOA
#define Led1_Pin GPIO_PIN_3
#define Led1_GPIO_Port GPIOB
#define encoder_A_Pin_Pin GPIO_PIN_4
#define encoder_A_Pin_GPIO_Port GPIOB
#define encoder_B_Pin_Pin GPIO_PIN_5
#define encoder_B_Pin_GPIO_Port GPIOB
#define HX1838_Pin GPIO_PIN_9
#define HX1838_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
