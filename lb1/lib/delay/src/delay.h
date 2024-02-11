#ifndef DELAY_H
#define DELAY_H

#include "stm32f1xx.h"

/// @brief Функция инициалзации 
void SysTick_Init(void);

/// @brief Функция формирования задержки в миллисекундах
/// @param ms Количество миллисекунд
void Delay_ms(uint32_t ms);

void SysTick_Handler(void);

#endif // DELAY_H
