#include "stm32f1xx.h"
#include <gpio.h>
#include <timer.h>
#include <delay.h>

int main(void) {
    // Инициализация порта A
    GPIO_Init(); 
    // Настройка пина PA5 на вывод
    GPIO_SetOutput(GPIOA, GPIO_PIN_13); 

   
    while (1) {
        // Переключение состояния пина PA5
        GPIOA->BSRR = GPIO_BSRR_BS13; // Переключение состояния пина PA5

        // Задержка для демонстрации
        Delay_ms(1000); // Задержка в 83 микросекунды
        GPIOA->BRR = GPIO_BRR_BR13;
    }

    Delay_ms(1000);
}
