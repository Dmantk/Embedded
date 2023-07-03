#ifndef __EX3_H__
#define __EX3_H__

#include "ex3.h"

class circle {
	private:
		float radius;
		float pi = 3.141592;
	public:
		circle(float r = 0);
		float getPerimeter();
		float getArea();
};

#endif