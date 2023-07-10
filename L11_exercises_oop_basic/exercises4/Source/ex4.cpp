#include <ex4.h>

animal::animal(string Name, int Age, float Weight)
{
    name = Name;
    age = Age;
    weight = Weight;
}
string animal::getName()
{
    return name;
}
int animal::getAge()
{
    return age;
}
float animal::getWeight()
{
    return weight;
}
int animal::ageCompare(animal &firstAnimal, animal &secondAnimal)
{
    return firstAnimal.getAge() - secondAnimal.getAge();
}

float animal::weightCompare(animal &firstAnimal, animal &secondAnimal)
{
    return firstAnimal.getWeight() - secondAnimal.getWeight();
}