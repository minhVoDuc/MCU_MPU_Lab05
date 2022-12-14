/*
 * unit_test.c
 *
 *  Created on: 13 thg 12, 2022
 *      Author: Guest_demo
 */

#include "unit_test.h"
#include "global.h"

uint32_t temp = 0;

void test_uart_send() {
	if (timer_checkFlag(TIMER_LED)) {
		HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
		temp = HAL_ADC_GetValue(&hadc1);
		uart_send(temp);
		timer_setDuration(TIMER_LED, 1000);
	}
}
