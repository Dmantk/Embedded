#include "stm32f1xx.h"

void CLOCKConfig(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // Enable clock Port B
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN; // Enable clock I2C1
}

void GPIOConfig(void)
{
    // SCL
    GPIOB->CRL &= ~(GPIO_CRL_CNF6 | GPIO_CRL_MODE6);   // Clear old config of PB6
    GPIOB->CRL |= GPIO_CRL_MODE6_1 | GPIO_CRL_MODE6_0; // Output mode, max speed 50 MHz
    GPIOB->CRL |= GPIO_CRL_CNF6_1 | GPIO_CRL_CNF6_0;   // Alternate function output Open-drain
    GPIOB->ODR |= GPIO_ODR_ODR6;                       // Pull up
    // SDA
    GPIOB->CRL &= ~(GPIO_CRL_CNF7 | GPIO_CRL_MODE7);   // Clear old config of PB7
    GPIOB->CRL |= GPIO_CRL_MODE7_1 | GPIO_CRL_MODE7_0; // Output mode, max speed 50 MHz
    GPIOB->CRL |= GPIO_CRL_CNF7_1 | GPIO_CRL_CNF7_0;   // Alternate function output Open-drain
    GPIOB->ODR |= GPIO_ODR_ODR7;                       // Pull up
}

void I2C1Config(void)
{
    I2C1->CR1 |= I2C_CR1_SWRST;                 // I2C Peripheral under reset state
    I2C1->CR1 &= ~I2C_CR1_SWRST;                // start again
    I2C1->CR2 |= (36 << I2C_CR2_FREQ_Pos);      // PCLK1 FREQ 36 MHz
    I2C1->CCR |= (180 << I2C_CCR_CCR_Pos);      // Baud rate 100 kHz, RCC = PCLK1_FREQ/(2*Baudrate)
    I2C1->TRISE |= (37 << I2C_TRISE_TRISE_Pos); // Max speed 1000 ns. TRISE = Max_speed/(1/PCLK1_FREQ) + 1
    I2C1->CR1 |= I2C_CR1_PE;                    // I2C1 peripheral enable
}

void start(void)
{
    I2C1->CR1 |= I2C_CR1_ACK;   // Enable the ACK
    I2C1->CR1 |= I2C_CR1_START; // Start I2C
    while (!(I2C1->SR1 & I2C_SR1_SB)); // Wait fror SB bit to set
}

void sendAddress(uint8_t address)
{
    I2C1->DR = address;                   // Send the address
    while (!(I2C1->SR1 & I2C_SR1_ADDR));  // Wait for ADDR bit to set
    uint8_t temp = I2C1->SR1 | I2C1->SR2; // Read SR1 and SR2 to clear the ADDR bit
}

void stop(void)
{
    I2C1->CR1 &= ~I2C_CR1_ACK;  // clear the ACK bit 
    uint8_t temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit.... EV6 condition
    I2C1->CR1 |= I2C_CR1_STOP;  // Stop I2C
}

void sendData(uint8_t address, uint8_t data)
{
    // Gửi START
    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));

    // Gửi địa chỉ và bit Write
    I2C1->DR = (address << 1) | I2C_DIRECTION_TRANSMIT;
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    (void) I2C1->SR2;

    // Gửi dữ liệu
    I2C1->DR = data;
    while (!(I2C1->SR1 & (I2C_SR1_TXE | I2C_SR1_BTF)));

    // Gửi STOP
    I2C1->CR1 |= I2C_CR1_STOP;
    while (I2C1->CR1 & I2C_CR1_STOP);
}

uint8_t receiveData(uint8_t address){
    start();
    sendAddress(address);
    while (!(I2C1->SR1 & I2C_SR1_RXNE));
    uint8_t data = I2C1->DR;
    stop();
    return data;
}

int main()
{
    CLOCKConfig();
    GPIOConfig();
    I2C1Config();
    while (1)
    {
        sendData(0xaa, 0x02);
    }
}