/*
* File: exercises2
* Author: Duong Minh An
* Date: 22/06/2023
* Description: This is an example for two sides of a rectangle then calculate perimeter, area, diagonal of that rectangle and check is it square or not
*/

#include <iostream>
#include <ex2.h>

using namespace std;


int main() {

    rectangle example(3, 3);

    cout << "Perimeter is: " << example.getPerimeter() << endl;
    cout << "Area is: " << example.getArea() << endl;
    cout << "Diagonal is: " << example.getDiagonal() << endl;
    
    if(example.getCheck()==1) {
    	cout << "This is a Square" << endl;
    } else {
    	cout << "This isn't a Square" << endl;
    }

    return 0;
}

