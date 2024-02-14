#include "timer.h"

void TIM3_Init(uint32_t frequency, uint16_t prescaler, uint16_t duty_cycle)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // TIM3 clock enable
    TIM3->CR1 = TIM_CR1_CEN;            // TIM3 counter enable

    TIM3->PSC = prescaler - 1; // Set prescaler
    TIM3->ARR = (SystemCoreClock / 2) / (frequency * prescaler) - 1; // Set auto-reload value for desired frequency

    if (duty_cycle != 0) {
        TIM3->CCR1 = (duty_cycle * (TIM3->ARR + 1)) / 100 - 1; // Set capture/compare value for desired duty cycle
        TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;     // PWM mode 1
        TIM3->CCER |= TIM_CCER_CC1E;                            // Enable output compare 1
    }

    TIM3->DIER |= TIM_DIER_UIE; // Enable TIM3 interrupt
    NVIC_EnableIRQ(TIM3_IRQn);  // Enable TIM3 interrupt in interrupt controller
}

