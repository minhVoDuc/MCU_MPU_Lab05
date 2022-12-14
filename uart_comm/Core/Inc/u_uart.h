/*
 * u_uart.h
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#ifndef INC_U_UART_H_
#define INC_U_UART_H_

#include <stdio.h>
#include <stdint.h>
#include "main.h"

#define MAX_BUFFER_SIZE 30

extern char buffer[MAX_BUFFER_SIZE];

extern UART_HandleTypeDef huart2;

void uart_init();
void uart_receive_char();
void uart_send(uint32_t data);
void uart_send_char(uint32_t data);
uint8_t uart_check_flag();
uint8_t uart_get_currBuffer();

#endif /* INC_U_UART_H_ */
