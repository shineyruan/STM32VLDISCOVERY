#include <stm32f1xx_hal.h>
#include "convert.h"

void SysTick_Handler(void);

uint16_t i = 0;

int main(void){
    HAL_Init();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_structure;
    GPIO_structure.Pin = GPIO_PIN_9;
    GPIO_structure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_structure.Pull = GPIO_PULLUP;
    GPIO_structure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC, &GPIO_structure);

    GPIO_structure.Pin = GPIO_PIN_8;
    GPIO_structure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_structure.Pull = GPIO_PULLUP;
    GPIO_structure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC, &GPIO_structure);

    GPIO_structure.Pin = GPIO_PIN_0;
    GPIO_structure.Mode = GPIO_MODE_INPUT;
    GPIO_structure.Pull = GPIO_PULLDOWN;
    GPIO_structure.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_structure);

    while (1){
        i++;
        if (i > 3)
            i = 0;
        WriteBinaryLED(GPIOC, i);
        HAL_Delay(100);
    }
    
}

void SysTick_Handler(void){
    HAL_IncTick();
}