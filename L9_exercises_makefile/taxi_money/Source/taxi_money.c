#include "taxi_money.h"

/*
* Function: calculationMoney
* Description: This function calculate the total amount corresponding to km
* Input:
*   iKilometerInput - number of kilometers traveled
*   iLessThan1km - amount less than 1km
*	iLessThan30km - amount less than 30km
*	iMoreThan30km - amount more than 30km
* Output:
*   iTotalMoney - total money you have to pay
*/

void calculationMoney(int iKilometerInput, int iLessThan1km, int iLessThan30km, int iMoreThan30km) {
	
	int iTotalMoney;
	
	if (iKilometerInput>30) {
		iTotalMoney = iLessThan1km + iLessThan30km * 29 + iMoreThan30km * (iKilometerInput - 30);
	} else if (iKilometerInput <= 30 && iKilometerInput > 1) {
		iTotalMoney = iLessThan1km + iLessThan30km * (iKilometerInput - 1);
	} else {
		iTotalMoney = iLessThan1km;
	}

	printf("Total of money: %d\n", iTotalMoney);
	
}
