/*
* File: calculate_in_string
* Author: Duong Minh An
* Date: 10/06/2023
* Description: This is an example of calculating the result of a string.
*/

#include "main.h"

char arr[] = "15*6-2*{(2+10/2-1)+5*[(4-2*3)-(5*2+1)]}";

int main() {    
    printf("Ket qua phep tinh la: %d\n", calculate(arr));
    return 0;
}
