/*
 * uart.h
 *
 *  Created on: Aug 12, 2024
 *      Author: USER
 */

#ifndef APP_HW_DEVICE_INC_UART_H_
#define APP_HW_DEVICE_INC_UART_H_

#include "hw.h"

extern UART_HandleTypeDef huart1;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void Uart_rxData(void);

#endif /* APP_HW_DEVICE_INC_UART_H_ */
