#include <stdio.h>
#include <stdint.h>

void readByte(uint8_t byte){
	uint8_t temp = 0b10000000; // 128 đối với kiểu int
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

int main(){
	uint8_t test = 0b10010001;

	readByte(test);
	
	return 0;
}
