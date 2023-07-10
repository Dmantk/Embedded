#ifndef __EX5_H__
#define __EX5_H__

#include "ex5.h"
#include <string>

using namespace std;

class person
{
private:
    string name;
    int birthyear;
    string address;

public:
    person(string Name, int BirthYear, string Address);
    string getName();
    int getBirthYead();
    string getAddress();
    int ageCalculate();
};
#endif