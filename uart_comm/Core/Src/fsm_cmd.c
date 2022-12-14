/*
 * fsm_command.c
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#include <fsm_cmd.h>
#include "u_uart.h"
#include "global.h"

uint8_t cmd_state;
uint8_t cmd_type; //3 type: NO_CMD, ASK or OK
uint8_t cmd_flag; //save cmd type until system fetch it
uint8_t currChar;

void cmd_init() {
	cmd_state = CMD_INIT;
	cmd_type = NO_CMD;
	cmd_flag = NO_CMD;
}

void cmd_parser_fsm() {
	currChar = uart_get_currBuffer(); //getting latest character from uart buffer
	switch (cmd_state) {
	case CMD_INIT:
		//TODO
		cmd_type = NO_CMD;
//		uart_send(cmd_type);
		//switch state
		if (currChar == '!') cmd_state = CMD_START;
		break;
	/*---------------------------------------------*/
	case CMD_START:
//		uart_send(cmd_type);
		//switch state
		if (currChar == 'R' || currChar == 'r') cmd_state = CMD_ASK_0;
		else if (currChar == 'O' || currChar == 'o') cmd_state = CMD_OK_0;
		else cmd_state = CMD_INIT;
		break;
	/*---------------------------------------------*/
	case CMD_ASK_0:
//		uart_send(cmd_type);
		//switch state
		if (currChar == 'S' || currChar == 's') cmd_state = CMD_ASK_1;
		else cmd_state = CMD_INIT;
		break;
	/*---------------------------------------------*/
	case CMD_ASK_1:
//		uart_send(cmd_type);
		//switch state
		if (currChar == 'T' || currChar == 't') cmd_state = CMD_ASK_2;
		else cmd_state = CMD_INIT;
		break;
	/*---------------------------------------------*/
	case CMD_ASK_2:
//		uart_send(cmd_type);
		//switch state
		if (currChar == '#') {
			cmd_state = CMD_END;
			cmd_type = CMD_ASK;
		}
		else cmd_state = CMD_INIT;
		break;
	/*---------------------------------------------*/
	case CMD_OK_0:
//		uart_send(cmd_type);
		//switch state
		if (currChar == 'K' || currChar == 'k') cmd_state = CMD_OK_1;
		else cmd_state = CMD_INIT;
		break;
	/*---------------------------------------------*/
	case CMD_OK_1:
//		uart_send(cmd_type);
		//switch state
		if (currChar == '#') {
			cmd_state = CMD_END;
			cmd_type = CMD_OK;
		}
		else cmd_state = CMD_INIT;
		break;
	/*---------------------------------------------*/
	case CMD_END:
//		uart_send(cmd_type);
		//TODO
		if (currChar == 13) {
			if (cmd_flag == NO_CMD) cmd_flag = cmd_type;
			//			if (cmd_flag == CMD_ASK) uart_send_char('A');
			//			else uart_send_char('O');
			//			uart_send(cmd_flag);
			cmd_state = CMD_INIT;
		}
		break;
	/*---------------------------------------------*/
	default:
		break;
	}
}

uint8_t cmd_get() {
	uint8_t temp = cmd_flag;
	cmd_flag = NO_CMD;
//	uart_send_char(cmd_flag);
	return temp;
}
