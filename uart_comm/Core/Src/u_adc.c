/*
 * u_adc.c
 *
 *  Created on: 12 thg 12, 2022
 *      Author: Guest_demo
 */

#include "u_adc.h"

uint32_t adc_value;

void adc_init() { //initialize
	adc_value = 0;
}

void adc_read_data() { //reading new value periodically
	adc_value = HAL_ADC_GetValue(&hadc1);
}

uint32_t adc_get_value() {
	return adc_value;
}
