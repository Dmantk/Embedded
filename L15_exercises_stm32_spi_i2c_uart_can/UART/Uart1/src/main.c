#include "stm32f1xx.h"

void CLOCK_Config(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;   // Enable clock Port A
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;   // Enable clock Port C
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // Enable clock USART1
}

void GPIO_Config(void)
{
    // Button
    GPIOA->CRL &= ~(GPIO_CRL_CNF0 | GPIO_CRL_MODE0);      // Clear MODE,CNF
    GPIOA->CRL &= ~(GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0); // Input mode (reset state)
    GPIOA->CRL |= GPIO_CRL_CNF0_1;                        // Input with pull-up / pull-down
    GPIOA->ODR |= GPIO_ODR_ODR0;                          // pull-up

    // Led
    GPIOC->CRH &= ~(GPIO_CRH_CNF13 | GPIO_CRH_MODE13); // Clear MODE,CNF
    GPIOC->CRH |= GPIO_CRH_MODE13_0;                   // Output mode, max speed 10 MHz
    GPIOC->BSRR = GPIO_BSRR_BS13;                      // set PC13 high
    // TX
    GPIOA->CRH &= ~(GPIO_CRH_CNF9 | GPIO_CRH_MODE9);   // Clear MODE,CNF
    GPIOA->CRH |= GPIO_CRH_MODE9_1 | GPIO_CRH_MODE9_0; // Output mode, max speed 50 MHz
    GPIOA->CRH |= GPIO_CRH_CNF9_1;                     // Alternate function push-pull
    // RX
    GPIOA->CRH &= ~(GPIO_CRH_CNF10 | GPIO_CRH_MODE10);      // Clear MODE,CNF
    GPIOA->CRH &= ~(GPIO_CRH_MODE10_1 | GPIO_CRH_MODE10_0); // Input mode (reset state)
    GPIOA->CRH |= GPIO_CRH_CNF10_1;                         // Input with pull-up / pull-down
    GPIOA->ODR |= GPIO_ODR_ODR10;                           // pull-up
}

void UART1_Config(void)
{
    USART1->CR1 |= USART_CR1_RE | USART_CR1_TE; // Full-duplex
    USART1->CR1 &= ~USART_CR1_M;                // 8-bit
    USART1->BRR = 0x00001D4C;                   // Baud rate 9600
    USART1->CR1 |= USART_CR1_UE;                // Enable USART1
}

void sendData(uint8_t data)
{
    while (!(USART1->SR & USART_SR_TXE)); // Wait for data is transferred to the shift register
    USART1->DR = data;                    // Write data
    while (!(USART1->SR & USART_SR_TC));  // Wait for transmission is complete
}

uint8_t receiveData()
{
    uint8_t data = 0x00;
    while (!(USART1->SR & USART_SR_RXNE)); // Wait for received data is ready to be read
    data = USART1->DR;                     // Read data
    return data;
}

uint8_t readButton(void)
{
    return GPIOA->IDR & GPIO_IDR_IDR0; // Read status of button
}

int main()
{
    CLOCK_Config();
    GPIO_Config();
    UART1_Config();

    while (1)
    {
        if (readButton() == 0x00)
        {
            sendData(0x33);
        }
        else
        {
            sendData(0x44);
        }
        uint8_t status = receiveData();
        if (status == 0x55)
        {
            GPIOC->BSRR = GPIO_BSRR_BR13;
        }
        if (status == 0x66)
        {
            GPIOC->BSRR = GPIO_BSRR_BS13;
        }
    }
}