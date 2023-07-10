#ifndef __EX2_H__
#define __EX2_H__

#include "ex2.h"

class rectangle {
private:
    float width;
    float length;

public:
    rectangle(float wid = 0, float leng = 0);
    float getPerimeter();
    float getArea();
    float getDiagonal();
    bool getCheck();
};

#endif