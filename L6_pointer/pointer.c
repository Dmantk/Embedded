#include <stdio.h>

void tong(int a, int b){
	printf("tong cua %d va %d la: %d\n", a,b,a+b);
}
void hieu(int a, int b){
	printf("hieu cua %d va %d la: %d\n", a,b,a-b);
}
void tich(int a, int b){
	printf("tich cua %d va %d la: %d\n", a,b,a*b);
}
void thuong(int a, int b){
	printf("thuong cua %d va %d la: %f\n", a,b,(float)a/b);
}
void tinhtoan(int a, int b, void (*ptr)(int,int)){
	printf("Chuong trinh tinh toan:\n");
	ptr(a,b);
}

int main(){
	void (*pheptoan)(int a, int b) = NULL;
	pheptoan = &thuong;
	pheptoan(7,9);
	
	return 0;
}
