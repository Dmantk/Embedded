/*
* File: taxi_money.c
* Author: Duong Minh An
* Date: 07/06/2023
* Description: Calculate the taxi fare corresponding to the number of kilometers traveled
*/

#include "main.h"

int iKilometerInput = 35;
int iLessThan1km = 14000;
int iLessThan30km = 10000;
int iMoreThan30km = 8000;

int main() {

	int money;
	money = calculationMoney(iKilometerInput, iLessThan1km, iLessThan30km, iMoreThan30km);
	printf("Total of money: %d\n", money);
	return 0;
	
}
