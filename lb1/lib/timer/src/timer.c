#include "timer.h"

void Timer_Init(TIM_TypeDef *timer, uint16_t prescaler, uint16_t period)
{
    timer->PSC = prescaler - 1; // Установка значения предделителя
    timer->ARR = period - 1;    // Установка значения периода
    timer->CR1 |= TIM_CR1_CEN;  // Включение таймера
}
