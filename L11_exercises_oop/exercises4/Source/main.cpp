/*
 * File: exercises4
 * Author: Duong Minh An
 * Date: 22/06/2023
 * Description: Create an animal class with the attributes name, age, and weight, and method to calculate BMI, compare the age and weight of the different animals.
 */

#include "ex4.h"
#include <iostream>

using namespace std;

int main()
{
	animal dv1 = animal("cho", 5, 2.5);
	animal dv2 = animal("meo", 10, 4.5);
	int age = animal::ageCompare(dv1, dv2);
	if (age > 0)
	{
		cout << "Con " << dv1.getName() << " lon hon con " << dv2.getName() << " " << age << " tuoi." << endl;
	}
	else if (age < 0)
	{
		cout << "Con " << dv1.getName() << " nho hon con " << dv2.getName() << " " << -age << " tuoi." << endl;
	}
	else
	{
		cout << "Con " << dv1.getName() << " va " << dv2.getName() << " co so tuoi bang nhau." << endl;
	}

	float weight = animal::weightCompare(dv1, dv2);
	if (weight > 0)
	{
		cout << "Con " << dv1.getName() << " nang hon con " << dv2.getName() << " " << weight << " kg." << endl;
	}
	else if (weight < 0)
	{
		cout << "Con " << dv1.getName() << " nhe hon con " << dv2.getName() << " " << -weight << " kg." << endl;
	}
	else
	{
		cout << "Con " << dv1.getName() << " va " << dv2.getName() << " co so kg bang nhau." << endl;
	}
	return 0;
}