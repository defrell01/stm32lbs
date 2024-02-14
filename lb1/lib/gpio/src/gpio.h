#ifndef GPIO_H
#define GPIO_H

#include "stm32f1xx.h"


/// @brief Инициализация PC13
void GPIO_Init_PC13(void);

/// @brief Инициализация PA5
void GPIO_Init_PA5(void);

/// @brief Переключениеи состояния PC13 
void GPIO_Toggle_PC13(void);

/// @brief Переключение состояния PA5 
void GPIO_Toggle_PA5(void);


#endif // GPIO_H
