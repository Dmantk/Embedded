#include "stm32f1xx.h"

void CLOCKConfig(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // enable port A clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // enable port C clock
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN; // enable SPI1 clock
}

void GPIOConfig(void)
{
    // button PA0
    GPIOA->CRL &= ~(GPIO_CRL_CNF0_Msk | GPIO_CRL_MODE0_Msk); // clear old config PA0
    GPIOA->CRL &= ~(GPIO_CRL_MODE0_1 | GPIO_CRL_MODE0_0);    // Input mode
    GPIOA->CRL |= GPIO_CRL_CNF0_1;                           // Input mode push-pull
    GPIOA->ODR |= GPIO_IDR_IDR0;                             // Pull-up PA0

    // led PC13
    GPIOC->CRH &= ~(GPIO_CRH_MODE13_Msk | GPIO_CRH_CNF13_Msk); // clear old config PC13
    GPIOC->CRH |= GPIO_CRH_MODE13_1 | GPIO_CRH_MODE13_0;       // max speed 50MHz

    // SPI
    // NSS (PA4), Output mode, 50 MHz, push-pull
    GPIOA->CRL &= ~(GPIO_CRL_CNF4_Msk | GPIO_CRL_MODE4_Msk);
    GPIOA->CRL |= GPIO_CRL_MODE4_1 | GPIO_CRL_MODE4_0; // Output mode, 50MHz
    // SCK (PA5), Output mode, 50 MHz, push-pull
    GPIOA->CRL &= ~(GPIO_CRL_CNF5_Msk | GPIO_CRL_MODE5_Msk);
    GPIOA->CRL |= GPIO_CRL_MODE5_1 | GPIO_CRL_MODE5_0; // Output mode, 50MHz
    GPIOA->CRL |= GPIO_CRL_CNF5_1;                     // Alternal function ouput push-pull
    // MISO (PA6), Input mode, push-pull
    GPIOA->CRL &= ~(GPIO_CRL_CNF6_Msk | GPIO_CRL_MODE6_Msk);
    GPIOA->CRL &= ~(GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0); // Input mode
    GPIOA->CRL |= GPIO_CRL_CNF6_1;                        // Input with push-pull
    GPIOA->ODR |= GPIO_IDR_IDR6;                          // Pull-up PA6
    // MOSI (PA7), Output mode, 50 MHz, push-pull
    GPIOA->CRL &= ~(GPIO_CRL_CNF7_Msk | GPIO_CRL_MODE7_Msk);
    GPIOA->CRL |= GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0; // Output mode, 50MHz
    GPIOA->CRL |= GPIO_CRL_CNF7_1;                     // Alternal function ouput push-pull
}

void SPI1Config(void)
{

    SPI1->CR1 = 0;                            // Reset Control Register 1
    SPI1->CR1 |= SPI_CR1_CPHA;                // CPHA 1
    SPI1->CR1 |= SPI_CR1_CPOL;                // CPOL 1
    SPI1->CR1 |= SPI_CR1_MSTR;                // master mode
    SPI1->CR1 |= SPI_CR1_BR_1 | SPI_CR1_BR_0; // Baud rate control Fpclk/16
    SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);         // Frame format: MSB transmitted first
    SPI1->CR1 |= SPI_CR1_SSM;                 // choose NSS manual
    SPI1->CR1 |= SPI_CR1_SSI;                 // NSS high
    SPI1->CR1 &= ~(SPI_CR1_RXONLY);           // Full duplex
    SPI1->CR1 &= ~(SPI_CR1_DFF);              // 8-bit data frame format

    SPI1->CR2 = 0;            // Control Register 2 off
    SPI1->CR1 |= SPI_CR1_SPE; // SPI enable
}

uint8_t dataSendReceive(uint8_t data)
{
    uint8_t dataReceive = 0;

    while (!(SPI1->SR & SPI_SR_TXE));            // wait for TXE to set, TX buffer empty
    SPI1->DR = data; // data send to DR register
    while (!(SPI1->SR & SPI_SR_RXNE));
    dataReceive = SPI1->DR;
    //while (SPI1->SR & SPI_SR_BSY);                        // wait for BSY to reset, SPI is busy in communication or Tx buffer is not empty
    return dataReceive;
}

uint8_t readButtonState(void)
{
    return GPIOA->IDR & GPIO_IDR_IDR0; // Read the state of button A0 (0 or 1)
}

int main()
{
    CLOCKConfig();
    GPIOConfig();
    SPI1Config();
    while (1)
    {
        if (readButtonState() == GPIO_IDR_IDR0)
        {
            GPIOC->BSRR |= GPIO_BSRR_BS13; // led off
        }
        else
        {
            GPIOC->BSRR |= GPIO_BSRR_BR13; // led on
        }
        GPIOA->BSRR |= GPIO_BSRR_BR4; // slave enable
        dataSendReceive(readButtonState());
        GPIOA->BSRR |= GPIO_BSRR_BS4; // slave disenable
    }
}