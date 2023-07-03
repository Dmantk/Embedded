#ifndef __EX1_H__
#define __EX1_H__

#include "ex1.h"

class Point {
	private:
		float x;
		float y;

	public:
		Point(float xVal = 0, float yVal = 0);
		float getX();
		float getY();
};

class distanceArea {
	private:
		Point pointA;
		Point pointB;
		Point pointC;
		enum Mode {
			Distance,
			Area
		};
		Mode chosenMode;

	public:
		distanceArea(Point A, Point B);
		distanceArea(Point A, Point B, Point C);
		float getDistance();
		float getArea();
};

#endif