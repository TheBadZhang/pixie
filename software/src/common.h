#ifndef __TBZ_COMMON_H__
#define __TBZ_COMMON_H__
#include "main.h"
// #include "oled.h"
#include "sys.h"
#include "trick.h"
// #include "mpu6050.h"
#ifdef __cplusplus
#include <cstdint>
#include <cstdio>
#else
#include <stdint.h>
#include <stdio.h>
#endif

extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;

#endif