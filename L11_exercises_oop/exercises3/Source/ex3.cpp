#include <ex3.h>
#include <cmath>

circle::circle(float r) {
	radius = r;
}

float circle::getPerimeter() {
	float result = 2 * pi * radius;
	return result;
}

float circle::getArea() {
	float result = pi * pow(radius,2);
	return result;
}