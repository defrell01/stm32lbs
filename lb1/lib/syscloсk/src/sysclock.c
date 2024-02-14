#include "gpio.h"
#include "stm32f1xx.h"

void SystemClock_Config(void)
{
    RCC->CR |= RCC_CR_HSEON; // Enable HSE
    while ((RCC->CR & RCC_CR_HSERDY) == 0)
        ; // Wait for HSE Ready

    RCC->CFGR = RCC_CFGR_SW_HSE; // HSE is system clock
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSE)
        ; // Wait for HSE used as system clock

    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;  // HCLK = SYSCLK
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV1; // APB1 = HCLK/1
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; // APB2 = HCLK

    RCC->CR &= ~RCC_CR_PLLON; // Disable PLL

    RCC->CFGR &= ~RCC_CFGR_PLLSRC;   // Use HSE as PLL source
    RCC->CFGR &= ~RCC_CFGR_PLLXTPRE; // Disable HSE/2 for PLL
    RCC->CFGR &= ~RCC_CFGR_PLLMULL;  // Clear PLL multiplication bits
    RCC->CFGR |= RCC_CFGR_PLLMULL6;  // PLL multiplication factor 6 (48 MHz)

    RCC->CR |= RCC_CR_PLLON; // Enable PLL
    while ((RCC->CR & RCC_CR_PLLRDY) == 0)
        ; // Wait till PLL is ready

    RCC->CFGR &= ~RCC_CFGR_SW; // Select PLL as system clock source
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL)
        ; // Wait till PLL is system clock source
}
