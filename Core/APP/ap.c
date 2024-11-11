/*
 * ap.c
 *
 *  Created on: Aug 12, 2024
 *      Author: USER
 */
#include "ap.h"

extern uint8_t rxData;
extern uint16_t PWM_duty;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        switch (rxData)
        {
            case 'F':
            	PWM_Speed(PWM_duty);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);

                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
                break;

            case 'B':
            	PWM_Speed(PWM_duty);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);

                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
                break;

            case 'R':
            	PWM_Speed(PWM_duty);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);

                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
                break;

            case 'L':
            	PWM_Speed(PWM_duty);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);

                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
                break;

            case 'S':
            	PWM_Speed(PWM_duty);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);

                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, GPIO_PIN_SET);
                break;

            case 'T':
            	PWM_Speed_up(50);
            	PWM_Speed(PWM_duty);
                break;

            case 'X':
            	PWM_Speed_down(50);
            	PWM_Speed(PWM_duty);
                break;

            default:
                break;
        }
        Uart_rxData();
    }
}

void apInit(void)
{

}

void apMain(void)
{

    PWM_Init();
    Uart_rxData();

	while (1)
	{

		uint32_t distance = US_Distance();

			 if (distance < 25)
			 {
				 PWM_Speed(0);
			 }
			 else
			 {
			     PWM_Speed(PWM_duty);
			 }
			     HAL_Delay(100);
	}
}
