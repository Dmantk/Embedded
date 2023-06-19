#include "main.h"

char arr[] = "15*6-2*{(2+10/2-1)+5*[(4-2*3)-(5*2+1)]}";



int main() {    
    printf("Ket qua phep tinh la: %d\n", calculate(arr));
    return 0;
}
