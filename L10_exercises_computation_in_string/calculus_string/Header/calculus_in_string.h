#ifndef __CALCULUS_IN_STRING_H_
#define __CALCULUS_IN_STRING_H_

#include "calculus_in_string.h"

int calculation(char cSign, int iNum1, int iNum2);
void simplifyExpression(int* arrNumber, char* arrSign,int iIndexSign, int start, int end);
void process(char* arr, int (*calculation)(char, int, int));

#endif
