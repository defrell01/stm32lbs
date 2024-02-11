#include "gpio.h"

void GPIO_Init(void)
{
    // Включение тактирования порта A
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
}

void GPIO_SetOutput(GPIO_TypeDef *port, uint32_t pin)
{
    port->CRL &= ~(GPIO_CRL_CNF | GPIO_CRL_MODE);     // Сброс битов CNF и MODE
    port->CRL |= GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0; // Установка режима General Purpose Output push-pull
}

void GPIO_TogglePin(GPIO_TypeDef *port, uint32_t pin)
{
    port->ODR ^= pin;
}
