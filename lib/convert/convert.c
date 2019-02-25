#include "convert.h"

void WriteBinaryLED(GPIO_TypeDef *GPIOx, uint16_t i)
{
    if (i > 3)
        return;
    else
    {
        if (i % 2 == 1)
            HAL_GPIO_WritePin(GPIOx, GPIO_PIN_9, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(GPIOx, GPIO_PIN_9, GPIO_PIN_RESET);

        i /= 2;

        if (i % 2 == 1)
            HAL_GPIO_WritePin(GPIOx, GPIO_PIN_8, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(GPIOx, GPIO_PIN_8, GPIO_PIN_RESET);
    }
}