/*
 * u_uart.c
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#include "u_uart.h"
#include "u_adc.h"

char buffer[MAX_BUFFER_SIZE];
uint8_t temp;
uint8_t index_rcv, index_get;
uint8_t buffer_flag;

void uart_init() {
	temp = 0;
	index_rcv = index_get = 0;
	buffer_flag = 0;
    HAL_UART_Receive_IT(&huart2, &temp, 1);
}

void uart_receive_char() {
//	HAL_UART_Transmit(&huart2, &temp, 1, 50);
	buffer[index_rcv++] = temp;
	if (index_rcv == MAX_BUFFER_SIZE) {
		index_rcv = 0;
	}
	buffer_flag = 1;
	HAL_UART_Receive_IT(&huart2, &temp, 1);
}

void uart_send(uint32_t data) {
	char str[50];
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "#ADC=%ld!\r\n", data), 1000);
}

void uart_send_char(uint32_t data) {
	char str[50];
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "\r\n%c - ",buffer[index_rcv-1]), 1000);
	HAL_UART_Transmit(&huart2, (uint8_t *)&data, sizeof(data), 1000);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "\r\n"), 1000);
}

uint8_t uart_check_flag() {
	if (buffer_flag == 1) {
		buffer_flag = 0;
		return 1;
	}
	return 0;
}

uint8_t uart_get_currBuffer() {
	if (index_rcv == MAX_BUFFER_SIZE) {
		index_rcv = 0;
	}
	return buffer[index_get++];
}
