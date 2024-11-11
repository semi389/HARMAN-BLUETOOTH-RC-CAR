/*
 * pwm.h
 *
 *  Created on: Aug 12, 2024
 *      Author: USER
 */

#ifndef APP_HW_INC_PWM_H_
#define APP_HW_INC_PWM_H_

#include "hw.h"

extern TIM_HandleTypeDef htim3;

void PWM_Init(void);
void PWM_Speed(uint16_t CCR);
void PWM_Speed_up(uint16_t UP);
void PWM_Speed_down(uint16_t DOWN);

#endif /* APP_HW_INC_PWM_H_ */
