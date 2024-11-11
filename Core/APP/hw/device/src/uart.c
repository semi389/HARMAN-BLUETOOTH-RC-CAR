/*
 * uart.c
 *
 *  Created on: Aug 12, 2024
 *      Author: USER
 */
#include "uart.h"

uint8_t rxData;

void Uart_rxData()
{
	HAL_UART_Receive_IT(&huart1, &rxData, 1);
}
