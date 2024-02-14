#include "stm32f1xx.h"
#include <sysclock.h>
#include <gpio.h>
#include <timer.h>

unsigned long TIM3_interrupts = 0;

void TIM3_IRQHandler()
{
    TIM3->SR &= ~TIM_SR_UIF;
    TIM3_interrupts++;  // TIM3 interrupts counter
    GPIO_Toggle_PC13(); // Toggle PC13
    GPIO_Toggle_PA5();
}

int main(void)
{
    SystemClock_Config();
    SystemCoreClockUpdate();

    GPIO_Init_PC13();
    GPIO_Init_PA5();
    TIM3_Init(12000, 3, 0); // Initialize TIM3 with 12 kHz frequency

    while (1)
    {
    }
}