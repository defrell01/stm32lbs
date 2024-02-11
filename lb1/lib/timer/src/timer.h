#ifndef TIMER_H
#define TIMER_H

#include "stm32f1xx.h"

/// @brief
/// @param timer Таймер для инициализации
/// @param prescaler Предделитель
/// @param period Значение периода
void Timer_Init(TIM_TypeDef *timer, uint16_t prescaler, uint16_t period);

#endif // TIMER_H
