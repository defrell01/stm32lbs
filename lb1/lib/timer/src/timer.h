#ifndef TIMER_H
#define TIMER_H

#include "stm32f1xx.h"

/// @brief Инициализация TIM3
/// @param frequency Частота
void TIM3_Init(uint32_t frequency);

#endif // TIMER_H
