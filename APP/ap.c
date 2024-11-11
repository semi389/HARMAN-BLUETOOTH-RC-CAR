
#include "ap.h"

//uint8_t txData[10];
//uint8_t rxData[10];
extern uint8_t Data;
extern uint16_t pwm_duty;
void apInit(void){
	hwInit();

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	if(huart->Instance == USART6 ){

		if(Data == 'F'){
			pwm_con(1000, pwm_duty);
			st_back_stop(1, 0);
		}
		if(Data == 'R'){
			pwm_con(1000, pwm_duty);
			steer_right_left_stop(1, 0);
		}
		if(Data == 'L'){
			pwm_con(1000, pwm_duty);
			steer_right_left_stop(0, 1);
		}
		if(Data == 'S'){
			pwm_con(1000, pwm_duty);
			st_back_stop(1, 1);
		}
		if(Data == 'B'){
			pwm_con(1000, pwm_duty);
			st_back_stop(0, 1);
		}
		if(Data == 'T'){
			pwm_up(50);
			pwm_con(1000, pwm_duty);
		}
		if(Data == 'X'){
			pwm_down(50);
			pwm_con(1000, pwm_duty);
		}

	}

	uart_re();
}

void apMain(void){


	uart_re();
	while (1)
	{




	}

}

