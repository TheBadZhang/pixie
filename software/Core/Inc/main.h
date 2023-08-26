/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define R5_Pin GPIO_PIN_14
#define R5_GPIO_Port GPIOC
#define R6_Pin GPIO_PIN_15
#define R6_GPIO_Port GPIOC
#define R7_Pin GPIO_PIN_3
#define R7_GPIO_Port GPIOA
#define LTP1C3_Pin GPIO_PIN_5
#define LTP1C3_GPIO_Port GPIOA
#define LTP1P_Pin GPIO_PIN_6
#define LTP1P_GPIO_Port GPIOA
#define LTP1C1_Pin GPIO_PIN_7
#define LTP1C1_GPIO_Port GPIOA
#define R4_Pin GPIO_PIN_0
#define R4_GPIO_Port GPIOB
#define R3_Pin GPIO_PIN_1
#define R3_GPIO_Port GPIOB
#define R1_Pin GPIO_PIN_8
#define R1_GPIO_Port GPIOA
#define LTP1C2_Pin GPIO_PIN_6
#define LTP1C2_GPIO_Port GPIOC
#define LTP1C4_Pin GPIO_PIN_11
#define LTP1C4_GPIO_Port GPIOA
#define LTP2C2_Pin GPIO_PIN_12
#define LTP2C2_GPIO_Port GPIOA
#define LTP2C4_Pin GPIO_PIN_15
#define LTP2C4_GPIO_Port GPIOA
#define LTP2C5_Pin GPIO_PIN_3
#define LTP2C5_GPIO_Port GPIOB
#define LTP2C3_Pin GPIO_PIN_4
#define LTP2C3_GPIO_Port GPIOB
#define LTP1C5_Pin GPIO_PIN_5
#define LTP1C5_GPIO_Port GPIOB
#define LTP2C1_Pin GPIO_PIN_6
#define LTP2C1_GPIO_Port GPIOB
#define R2_Pin GPIO_PIN_7
#define R2_GPIO_Port GPIOB
#define LTP2P_Pin GPIO_PIN_8
#define LTP2P_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
