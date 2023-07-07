/*
 * File: exercises5
 * Author: Duong Minh An
 * Date: 22/06/2023
 * Description: Create a person class with properties name, birth year, and address, and methods to input the person's information and calculate the person's age
 */

#include "ex5.h"
#include <iostream>

using namespace std;

int main()
{
	person ps1 = person("An",1999,"Quang Nam");
	cout<<ps1.getName()<<", sinh nam "<<ps1.getBirthYead()<<" tuc la "<<ps1.ageCalculate()<<" tuoi, que o "<<ps1.getAddress()<<endl;
	return 0;
}