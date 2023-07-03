/*
* File: check_day.c
* Author: Duong Minh An
* Date: 07/06/2023
* Description: For any given time date check what day it is 
*/

#include "main.h"

int iDayInput = 7;
int iMonthInput = 6;
int iYearInput = 2023;

int main() {
	
    char* day = dayCheck(iDayInput, iMonthInput, iYearInput);
    printf("%s\n", day);

    return 0;
    
}

