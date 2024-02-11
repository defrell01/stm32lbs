#include "sysclock.h"

void SysClock_Init(void) 
{
    RCC->CR |= RCC_CR_HSEON; // Включение внешнего источника HSE
    while (!(RCC->CR & RCC_CR_HSERDY)) {} // Ожидание готовности HSE

    // Конфигурация PLL
    RCC->CFGR &= ~RCC_CFGR_PLLSRC; // Использование HSE как источника PLL
    RCC->CFGR &= ~RCC_CFGR_PLLXTPRE; // Отключение HSE/2 для PLL
    RCC->CFGR &= ~RCC_CFGR_PLLMULL; // Очистка битов умножителя PLL
    RCC->CFGR |= RCC_CFGR_PLLMULL6; // Умножение HSE на 6 (48 МГц)

    // Включение PLL
    RCC->CR |= RCC_CR_PLLON;
    // Ожидание готовности PLL
    while (!(RCC->CR & RCC_CR_PLLRDY)) {}

    // Использование PLL в качестве источника системной частоты
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    // Ожидание установки бита переключения
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {}
}
