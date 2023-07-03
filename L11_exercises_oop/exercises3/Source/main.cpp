/*
* File: exercises3
* Author: Duong Minh An
* Date: 22/06/2023
* Description: This's an example for two sides of a rectangle then calculate the circumference, area, of the circle
*/

#include <iostream>
#include <ex3.h>

using namespace std;

int main() {

	circle example(3);

	cout << "Perimeter is: " << example.getPerimeter() << endl;
	cout << "Area is: " << example.getArea() << endl;

	return 0;
}