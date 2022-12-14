/*
 * fsm_command.h
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#ifndef INC_FSM_CMD_H_
#define INC_FSM_CMD_H_

#include <stdint.h>

#define CMD_INIT	20
#define CMD_START	21
#define	CMD_ASK_0	22
#define CMD_ASK_1	23
#define CMD_ASK_2	24
#define CMD_OK_0	25
#define	CMD_OK_1	26
#define CMD_END		27

void cmd_init();
void cmd_parser_fsm();
uint8_t cmd_get();

#endif /* INC_FSM_CMD_H_ */
