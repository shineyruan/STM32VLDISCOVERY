#ifndef __CONVERT_H
#define __CONVERT_H

#include "stm32f1xx_hal.h"

/**
 * A function for fancy LED blinking. 
 * When provided with an integer i (i<3), 
 * converts i into binary number and 
 * lights up the PC8, PC9 LED correspondingly. 
 */
void WriteBinaryLED(GPIO_TypeDef *GPIOx, uint16_t i);

#endif