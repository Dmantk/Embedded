#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000000;

void readByte(uint8_t byte){
	uint8_t temp = 0b10000000;
	printf("0b");
	for(int i = 0; i<8; i++){
	int kq = byte & temp;
	if(kq == 0)
		printf("0");
	else
		printf("1");
	temp = temp >> 1;
	}
	printf("\n");
}

typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}s_pins;

typedef enum{
	LOW,
	HIGH
}s_status;

void digitalWrite(s_pins pin, s_status status){
	if(status == 1)
		PORTA = PORTA | (1 << pin);   // int 1 tướng đương với 0b00000001
	else
		PORTA = PORTA & ~(1 << pin);
}

int main(){

	digitalWrite(PIN3, HIGH);
	digitalWrite(PIN2, HIGH);
	digitalWrite(PIN5, LOW);
	digitalWrite(PIN1, HIGH);
	digitalWrite(PIN0, HIGH);
	digitalWrite(PIN7, HIGH);
	digitalWrite(PIN7, LOW);
	readByte(PORTA);

	return 0;
}
