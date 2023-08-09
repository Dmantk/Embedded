#include "stm32f1xx.h"

void CLOCKConfig(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // enable port B clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // enable port C clock
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN; // enable SPI clock
}

void GPIOConfig(void)
{
    // led PC13
    GPIOC->CRH &= ~(GPIO_CRH_MODE13_Msk | GPIO_CRH_CNF13_Msk); // clear old config PC13
    GPIOC->CRH |= GPIO_CRH_MODE13_1 | GPIO_CRH_MODE13_0;       // max speed 50MHz
    GPIOC->BSRR |= GPIO_BSRR_BS13;
    // SPI
    // NSS (PB12), Input mode, push-pull mode, pull-up
    GPIOB->CRH &= ~(GPIO_CRH_CNF12_Msk | GPIO_CRH_MODE12_Msk); // clear old config PA4
    GPIOB->CRH &= ~(GPIO_CRH_MODE12_1 | GPIO_CRH_MODE12_0);    // Input mode
    GPIOB->CRH |= GPIO_CRH_CNF12_1;                           // Input mode push-pull
    GPIOB->ODR |= GPIO_IDR_IDR12;                             // Pull-up PA4
    // SCK (PB13), Input mode, floating input
    GPIOB->CRH &= ~(GPIO_CRH_CNF13_Msk | GPIO_CRH_MODE13_Msk);
    GPIOB->CRH &= ~(GPIO_CRH_MODE13_1 | GPIO_CRH_MODE13_0); // Input mode
    GPIOB->CRH |= GPIO_CRH_CNF13_0;                        // Floating input
    // MISO (PB14), Output mode, 50 MHz, push-pull
    GPIOB->CRH &= ~(GPIO_CRH_CNF14_Msk | GPIO_CRH_MODE14_Msk);
    GPIOB->CRH |= GPIO_CRH_MODE14_1 | GPIO_CRH_MODE14_0; // Output mode, 50MHz
    GPIOB->CRH |= GPIO_CRH_CNF14_1;                     // Alternal function ouput push-pull
    // MOSI (PB15), Input mode, push-pull, Pull-up
    GPIOB->CRH &= ~(GPIO_CRH_CNF15_Msk | GPIO_CRH_MODE15_Msk);
    GPIOB->CRH &= ~(GPIO_CRH_MODE15_1 | GPIO_CRH_MODE15_0); // Input mode
    GPIOB->CRH |= GPIO_CRH_CNF15_1;                        // Input mode push-pull
    GPIOB->ODR |= GPIO_IDR_IDR15;                          // Pull-up PA7
}

void SPI2Config(void)
{
    SPI2->CR1 = 0;                            // clear Control Register 1 config
    SPI2->CR1 |= SPI_CR1_CPHA;                // CPHA 1
    SPI2->CR1 |= SPI_CR1_CPOL;                // CPOL 1
    SPI2->CR1 &= ~(SPI_CR1_MSTR);             // slave mode
    SPI2->CR1 |= SPI_CR1_BR_1 | SPI_CR1_BR_0; // Baud rate control Fpclk/16
    SPI2->CR1 &= ~(SPI_CR1_LSBFIRST);         // Frame format: MSB transmitted first
    SPI2->CR1 |= SPI_CR1_SSM;                 // NSS manual
    SPI2->CR1 |= SPI_CR1_SSI;                 // NSS high
    SPI2->CR1 &= ~(SPI_CR1_RXONLY);           // Full duplex
    SPI2->CR1 &= ~(SPI_CR1_DFF);              // 8-bit data frame format

    SPI2->CR2 = 0; // Control Register 2 off
    SPI2->CR1 |= SPI_CR1_SPE; // SPI enable
}

uint8_t dataSendReceive(uint8_t data)
{
    uint8_t dataReceive = 0;
    
    while (!(SPI2->SR & SPI_SR_TXE));            // wait for TXE to set, TX buffer empty
    SPI2->DR = data; // data send to DR register
    while (!(SPI2->SR & SPI_SR_RXNE));
    dataReceive = SPI2->DR;
    //while (SPI2->SR & SPI_SR_BSY); // wait for BSY to reset, SPI is busy in communication or Tx buffer is not empty
    return dataReceive;
}

uint8_t readNSS(void)
{
    return GPIOB->IDR & GPIO_IDR_IDR12; // Read the state of button A4 (0 or 1)
}

int main()
{
    CLOCKConfig();
    GPIOConfig();
    SPI2Config();
    uint8_t datatemp = 0x01;
    while (1)
    {
        if (readNSS() != GPIO_IDR_IDR12)
        {
            datatemp = dataSendReceive(0x55);
        }
        if (datatemp == 0x00)
        {
            GPIOC->BSRR |= GPIO_BSRR_BR13;
        }
        else
        {
            GPIOC->BSRR |= GPIO_BSRR_BS13;
        }
    }
}