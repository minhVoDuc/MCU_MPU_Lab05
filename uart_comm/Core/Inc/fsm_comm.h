/*
 * fsm_comm.h
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#ifndef INC_FSM_COMM_H_
#define INC_FSM_COMM_H_

#include <stdint.h>

#define COMM_INIT	30
#define COMM_IDLE	31
#define COMM_SEND	32
#define COMM_RESEND	33
#define COMM_OK		34

#define PKT_NOTOK	0
#define PKT_OK		1

void comm_init();
void comm_uart_fsm();

#endif /* INC_FSM_COMM_H_ */
