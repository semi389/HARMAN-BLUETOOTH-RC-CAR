/*
 * Steer.c
 *
 *  Created on: Jul 31, 2024
 *      Author: USER
 */


#include "Steer.h"

void steer_init(){

}

// 01 우회전 10  좌회전
void steer_right_left_stop(uint8_t right_0_left_1, uint8_t right_1_left_0){

	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN3, right_1_left_0);
	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN4, right_0_left_1);
	HAL_GPIO_WritePin(ST_PORT_L0, ST_PIN_L_IN1, right_1_left_0);
	HAL_GPIO_WritePin(ST_PORT_L1, ST_PIN_L_IN2, right_0_left_1);

}

void st_back_stop(uint8_t st_1_back_0,uint8_t st_0_back_1 ){

	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN3, st_1_back_0);
	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN4, st_0_back_1);
	HAL_GPIO_WritePin(ST_PORT_L0, ST_PIN_L_IN1, st_0_back_1);
	HAL_GPIO_WritePin(ST_PORT_L1, ST_PIN_L_IN2, st_1_back_0);

}
