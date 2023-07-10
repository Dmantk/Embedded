#include <iostream>
#include <cmath>
#include <ex1.h>

using namespace std;

Point::Point(float xVal, float yVal) {
	x = xVal;
	y = yVal;
}

float Point::getX() {
	return x;
}

float Point::getY() {
	return y;
}

distanceArea::distanceArea(Point A, Point B) {
	chosenMode = Distance;
	pointA = A;
	pointB = B;
}

distanceArea::distanceArea(Point A, Point B, Point C) {
	chosenMode = Area;
	pointA = A;
	pointB = B;
	pointC = C;
}

float distanceArea::getDistance() {
	if (chosenMode == Distance) {
		float result = sqrt(pow((pointA.getX() - pointB.getX()), 2) + pow((pointA.getY() - pointB.getY()), 2));
		return result;
	} else {
		cout << "This data is not suitable for distance calculation" << endl;
		return 0.0f;
	}
}

float distanceArea::getArea() {
	if (chosenMode == Area) {
		float result = 0.5 * abs((pointB.getX() - pointA.getX()) * (pointC.getY() - pointA.getY()) - 
								(pointC.getX() - pointA.getX()) * (pointB.getY() - pointA.getY()));
		return result;
	} else {
		cout << "This data is not suitable for area calculation" << endl;
		return 0.0f;
	}
}