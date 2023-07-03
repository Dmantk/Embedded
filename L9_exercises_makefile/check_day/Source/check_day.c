#include "check_day.h"

/*
* Function: dayCheck
* Description: This function is used to calculate the total number of days, then divide by 7 to get the balance and determine the day
* Input:
*   iDayInput - Enter the day
*   iMonthInput - Enter the month
*	iYearInput - Enter the year
* Output:
*   dayOfWeek
*/

char dayOfWeek[8][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

char* dayCheck(int iDayInput, int iMonthInput, int iYearInput) {

    int iNumDay = 0;

	for(int i = 1; i < iYearInput; i++) {
        if(((i % 4 == 0) && (i % 100 != 0)) || ((i % 100 == 0) && (i % 400 == 0))) {
            iNumDay = iNumDay + 366;
        } else {
            iNumDay = iNumDay + 365;
        }
    }

    if(iMonthInput == 1) {
        iNumDay = iDayInput;
    } else {
        for(int i = 1; i < iMonthInput; i++) {
            if(i == 2) {
                if(((iYearInput % 4 == 0) && (iYearInput % 100 != 0)) || ((iYearInput % 100 == 0) && (iYearInput % 400 == 0))) {
                    iNumDay = iNumDay + 29;
                } else {
                    iNumDay = iNumDay + 28;
                }
            } else if(i == 4 || i == 6 || i == 9 || i == 11) {
                iNumDay = iNumDay + 30;
            } else {
                iNumDay = iNumDay + 31;
            }
        }
        iNumDay = iNumDay + iDayInput;
        
    }

    return dayOfWeek[iNumDay % 7];

}