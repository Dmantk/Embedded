#include <ex2.h>
#include <cmath>

rectangle::rectangle(float wid, float leng) {
    width = wid;
    length = leng;
}

float rectangle::getPerimeter() {
    float result = 2 * (width + length);
    return result;
}

float rectangle::getArea() {
    float result = width * length;
    return result;
}

float rectangle::getDiagonal() {
    float result = sqrt(pow(width, 2) + pow(length, 2));
    return result;
}

bool rectangle::getCheck() {
    return (width == length);
}