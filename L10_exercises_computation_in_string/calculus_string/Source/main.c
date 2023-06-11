/*
* File: main.c
* Author: Duong Minh An
* Date: 09/06/2023
* Description: calculate calculus in string
*/

#include "main.h"

char arr[] = "15*6-2*(2+10/2-1)+5*[(4-2*3)-(5*2+1)]";

int main() {
    
    process(arr, &calculation);
    
    return 0;

}
