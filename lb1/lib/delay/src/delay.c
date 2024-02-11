#include "delay.h"

volatile uint32_t millis = 0;

void SysTick_Handler(void)
{
    millis++;
}

void SysTick_Init(void)
{
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

void Delay_ms(uint32_t ms)
{
    uint32_t start = millis;

    while ((millis - start) < ms);
}
