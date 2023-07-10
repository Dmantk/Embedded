/*
* File: exercises1
* Author: Duong Minh An
* Date: 22/06/2023
* Description: This's an example to calculate the distance of two points and the area formed by three points
*/

#include <iostream>
#include <ex1.h>

using namespace std;

int main() {

	Point A(1, 0);
	Point B(0, 3);

	distanceArea example1(A, B);
	float distance = example1.getDistance();
	cout << "Distance is: " << distance << endl;

	Point C(2, 0);
	distanceArea example2(A, B, C);
	float area = example2.getArea();
	cout << "Area is: " << area << endl;

	return 0;
}

