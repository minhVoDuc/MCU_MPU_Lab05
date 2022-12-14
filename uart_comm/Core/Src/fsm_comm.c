/*
 * fsm_comm.c
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#include "fsm_comm.h"
#include "fsm_cmd.h"
#include "global.h"

uint8_t cmd_flag,
		comm_state,
		packet_state;
uint32_t saved_packet;

void comm_init() {
	comm_state = COMM_INIT;
	packet_state = PKT_OK;
	cmd_flag = NO_CMD;
}

void comm_uart_fsm() {
	switch(comm_state) {
	case COMM_INIT:
		//TODO
		//switch state
		comm_state = COMM_IDLE;
		break;
	/*------------------------------------*/
	case COMM_IDLE:
		//TODO
		cmd_flag = cmd_get();
		//switch state
		if (cmd_flag == CMD_ASK) {
//			uart_send(cmd_flag);
			if (packet_state == PKT_OK) comm_state = COMM_SEND;
			else comm_state = COMM_RESEND;
			cmd_flag = NO_CMD;
		}
		else if (cmd_flag == CMD_OK) {
			comm_state = COMM_OK;
//			uart_send(comm_state);
			cmd_flag = NO_CMD;
		}
		else if (timer_checkFlag(TIMER_COMM)) {
			comm_state = COMM_RESEND;
		}
		else comm_state = COMM_IDLE;
		break;
	/*------------------------------------*/
	case COMM_SEND:
		//TODO
		timer_setDuration(TIMER_COMM, 3000);
		saved_packet = adc_get_value();
		packet_state = PKT_NOTOK;
		uart_send(saved_packet);
		//switch state
		comm_state = COMM_IDLE;
//		uart_send_char('A');
		break;
	/*------------------------------------*/
	case COMM_OK:
		//TODO
		timer_clear(TIMER_COMM);
		saved_packet = -1;
		packet_state = PKT_OK;
		//switch state
		comm_state = COMM_IDLE;
//		uart_send_char('B');
		break;
	/*------------------------------------*/
	case COMM_RESEND:
		//TODO
		timer_setDuration(TIMER_COMM, 3000);
		uart_send(saved_packet);
		//switch state
		comm_state = COMM_IDLE;
//		uart_send_char('C');
		break;
	/*------------------------------------*/
	default:
		break;
	}
}
