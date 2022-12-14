/*
 * u_adc.h
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#ifndef INC_U_ADC_H_
#define INC_U_ADC_H_

#include <stdio.h>
#include <stdint.h>
#include "main.h"

extern ADC_HandleTypeDef hadc1;

void adc_init();
void adc_read_data();
uint32_t adc_get_value();

#endif /* INC_U_ADC_H_ */
