/*
 * File: dish.hpp
 * Author: Duong Minh An
 * Date: 09/07/2023
 * Description: Used to create a dish list include ID, name, price
 */
#ifndef __DISH_H__
#define __DISH_H__

#include <iostream>
#include <string>

using namespace std;

/*
 * Function: class dish
 * Description: Used to create a dish list include ID, name, price
 * Property:
 * - ID: ID of dish
 * - NAME: Name of dish
 * - PRICE: Price of dish
 * Contructor:
 * - dish(string Name, int Price): This function is used to add a dish object including self-incrementing ID, name and price
 * Method:
 * - setName(string newName): This function is used to edit the price of the dish
 * - setPrice(int newPrice): This function is used to edit the name of the dish
 * - getId(): This function is used to output the ID value of the dish
 * - getName(): This function is used to output the Name value of the dish
 * - getPrice(): This function is used to output the Price value of the dish
 */
class dish
{
private:
	int ID;
	string NAME;
	int PRICE;

public:
	dish(string Name, int Price);
	void setName(string newName);
	void setPrice(int newPrice);
	int getId();
	string getName();
	int getPrice();
};

#endif