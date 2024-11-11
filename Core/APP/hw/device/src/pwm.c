/*
 * pwm.c
 *
 *  Created on: Aug 12, 2024
 *      Author: USER
 */
#include "pwm.h"

uint16_t PWM_duty = 600;

void PWM_Init(void)
{
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void PWM_Speed(uint16_t CCR)
{
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, CCR);
}

void PWM_Speed_up(uint16_t UP)
{
	if(PWM_duty >= 650)
	{
		PWM_duty = 600;
	}
	else
	{
		PWM_duty = PWM_duty + UP;
	}
}

void PWM_Speed_down(uint16_t DOWN)
{
	if(PWM_duty <= 250)
	{
		PWM_duty = 300;
	}
	else
	{
		PWM_duty = PWM_duty - DOWN;
	}
}
