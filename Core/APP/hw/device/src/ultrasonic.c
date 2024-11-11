/*
 * ultrasonic.c
 *
 *  Created on: Aug 12, 2024
 *      Author: USER
 */
#include "ultrasonic.h"

void US_Trigger(void)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
    HAL_Delay(2);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
}

uint32_t US_Distance(void)
{
    uint32_t pulse_length;

    uint32_t distance;

    US_Trigger();

    while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) == GPIO_PIN_RESET);

    uint32_t start = HAL_GetTick();

    while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) == GPIO_PIN_SET);

    uint32_t end = HAL_GetTick();

    pulse_length = end - start;

    distance = (pulse_length * 34300) / 2000;

    return distance;
}
