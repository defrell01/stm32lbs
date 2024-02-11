#ifndef GPIO_H
#define GPIO_H

#include "stm32f1xx.h"

/// @brief Инициализация GPIO
void GPIO_Init(void);

/// @brief Настройка порта вывода
/// @param port Порт
/// @param pin Пин
void GPIO_SetOutput(GPIO_TypeDef *port, uint32_t pin);

/// @brief Функция переключения состояния пина
/// @param port Порт
/// @param pin Пин
void GPIO_TogglePin(GPIO_TypeDef *port, uint32_t pin);

#endif // GPIO_H
