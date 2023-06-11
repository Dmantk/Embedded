#include "calculus_in_string.h"

/*
* Function: 
* Description: 
* Input:

* Output:

*/

int calculation(char cSign, int iNum1, int iNum2){
    int result = 0;
    if(cSign == '+')    result = iNum1 + iNum2;
    if(cSign == '-')    result = iNum1 - iNum2;
    if(cSign == '*')    result = iNum1 * iNum2;
    if(cSign == '/')    result = iNum1 / iNum2;
    return result;
}

void simplifyExpression(int* arrNumber, char* arrSign,int iIndexSign, int start, int end){

    for(int i = start; i < end; i++){
        if(arrSign[i] == '*' || arrSign[i] == '/'){
            arrNumber[i] = calculation(arrSign[i], arrNumber[i], arrNumber[i+1]);
            arrSign[i] = arrSign[i+1];
            end--;
            for(int j = i+1; j < iIndexSign; j++){
                arrNumber[j] = arrNumber[j+1];
                arrSign[j] = arrSign[j+1];
            }
        }
    }
	
    for(int i = start; i < end; i++){
        if(arrSign[start] == '+' || arrSign[start] == '-'){
            arrNumber[start] = calculation(arrSign[start], arrNumber[start], arrNumber[start+1]);
            arrSign[start] = arrSign[start+1];
            for(int j = start+1; j < iIndexSign; j++){
                arrNumber[j] = arrNumber[j+1];
                arrSign[j] = arrSign[j+1];
            }
        }
    }
}


void process(char* arr, int (*calculation)(char, int, int)){

    int i = 0, flag = 0;
    int arrNumber[20];
    int iIndexNumber = -1;
    char arrSign[20];
    int iIndexSign = -1;
    char arrSpecialSign[20];
    int iIndexSpecialSign = -1;
    int arrSpecialPosition[20];
    
    while (arr[i] != '\0') {
        if (arr[i] == '-' && iIndexNumber == -1) {
            flag = 1;
        }
        if (arr[i] >= '0' && arr[i] <= '9') {
            int number = 0;
            while (arr[i] >= '0' && arr[i] <= '9') {
                number = number * 10 + (arr[i] - '0');
                i++;
            }
            iIndexNumber++;
            if(flag == 1){
                arrNumber[iIndexNumber] = -number;
            } else {
                arrNumber[iIndexNumber] = number;
            }
            flag = 0;
        } else if ((arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') && iIndexNumber >= 0) {
            iIndexSign++;
            arrSign[iIndexSign] = arr[i];
            i++;
        } else if (arr[i] == '(' || arr[i] == ')' || arr[i] == '[' || arr[i] == ']') { 
            iIndexSpecialSign++;
            arrSpecialSign[iIndexSpecialSign] = arr[i];
            arrSpecialPosition[iIndexSpecialSign] = iIndexSign+1;
            i++;
        } else {
            i++;
        }
    }
    
    iIndexSpecialSign++;
    arrSpecialSign[iIndexSpecialSign] = 'f';
    iIndexSign++;
    arrSign[iIndexSign] = 'f';

	while(arrSpecialSign[0] != 'f'){
		for(i=0;i<iIndexSpecialSign;i++){
			if((arrSpecialSign[i]=='(' && arrSpecialSign[i+1]==')')||(arrSpecialSign[i]=='[' && arrSpecialSign[i+1]==']')){
				
				simplifyExpression(arrNumber, arrSign, iIndexSign, arrSpecialPosition[i], arrSpecialPosition[i+1]);
				int move = arrSpecialPosition[i+1]- arrSpecialPosition[i];
				for(int j = i;arrSpecialSign[j-1] != 'f';j++){
					arrSpecialSign[j] = arrSpecialSign[j+2];
					arrSpecialPosition[j] = arrSpecialPosition[j+2];
					arrSpecialPosition[j] -= move;
				}			
			}
		}
	}

    simplifyExpression(arrNumber, arrSign,iIndexSign, 0, iIndexSign);
    printf("The result of the calculation is: %d\n", arrNumber[0]);
}
