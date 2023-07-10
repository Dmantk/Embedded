#ifndef __EX4_H__
#define __EX4_H__

#include "ex4.h"
#include <string>

using namespace std;

class animal
{
private:
    string name;
    int age;
    float weight;

public:
    animal(string Name, int Age, float weight);
    string getName();
    int getAge();
    float getWeight();
    static int ageCompare(animal &fistAnimal, animal &secondAnimal);
    static float weightCompare(animal &fistAnimal, animal &secondAnimal);
};

#endif