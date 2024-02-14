#include "gpio.h"
#include "stm32f1xx.h"

void GPIO_Init_PC13(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // Enable GPIOC clock

    // Configure PC13 as output
    GPIOC->CRH &= ~((15ul << 4 * 5));
    GPIOC->CRH |= ((1ul << 4 * 5));

    // Set PC13 as push-pull output
    GPIOC->CRH &= ~(GPIO_CRH_CNF13);
    GPIOC->CRH |= GPIO_CRH_MODE13_0;
}

void GPIO_Init_PA5(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Enable GPIOA clock

    // Configure PA5 as output
    GPIOA->CRL &= ~((15ul << 4 * 5));
    GPIOA->CRL |= ((1ul << 4 * 5));

    // Set PA5 as push-pull output
    GPIOA->CRL &= ~(GPIO_CRL_CNF5);
    GPIOA->CRL |= GPIO_CRL_MODE5_0;
}

void GPIO_Toggle_PC13(void)
{
    GPIOC->ODR ^= GPIO_ODR_ODR13; // Toggle PC13
}

void GPIO_Toggle_PA5(void)
{
    GPIOA->ODR ^= GPIO_ODR_ODR5; // Toggle PA5
}
