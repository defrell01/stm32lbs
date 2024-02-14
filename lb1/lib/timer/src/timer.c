#include "timer.h"

void TIM3_Init(uint32_t frequency)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // TIM3 clock enable
    TIM3->CR1 = TIM_CR1_CEN;            // TIM3 counter enable

    TIM3->PSC = (SystemCoreClock / 2) / frequency - 1; // Set prescaler for desired frequency
    TIM3->ARR = frequency / 2 - 1;                     // Set auto-reload value for 50% duty cycle

    TIM3->DIER |= TIM_DIER_UIE; // Enable TIM3 interrupt
    NVIC_EnableIRQ(TIM3_IRQn);  // Enable TIM3 interrupt in interrupt controller
}
