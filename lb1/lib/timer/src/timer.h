#ifndef TIMER_H
#define TIMER_H

#include "stm32f1xx.h"

/// @brief Функция инициализации таймера TIM3
/// @param frequency Частота
/// @param prescaler Предделитель
/// @param duty_cycle Коэффицент заполнения
void TIM3_Init(uint32_t frequency, uint16_t prescaler, uint16_t duty_cycle);

#endif // TIMER_H
