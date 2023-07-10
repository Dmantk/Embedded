#include "ex5.h"

person::person(string Name, int BirthYear, string Address){
    name = Name;
    birthyear = BirthYear;
    address = Address;
}
string person::getName(){
    return name;
}
int person::getBirthYead(){
    return birthyear;
}
string person::getAddress(){
    return address;
}
int person::ageCalculate(){
    int currentYear = 2023;
    return currentYear - birthyear;
}