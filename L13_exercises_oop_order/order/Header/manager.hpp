/*
 * File: manager.hpp
 * Author: Duong Minh An
 * Date: 09/07/2023
 * Description: Design interfaces to add, edit, delete, display the dish list
 */
#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include "dish.hpp"
#include <string>
#include <list>

using namespace std;

/*
 * Function: class manager
 * Description: Design interfaces to add, edit, delete, display the dish list
 * Property:
 * - enum managerMenu: Used to compare interface switching
 * - static list DATABASE: Save manager's dish list
 * - static int NUMBEROFTABLE: Setting the number of tables
 * Method:
 * - addDish(): Add the dish and its quantity to the list of manager
 * - editDish(): Change dishes
 * - removeDish(): Remove dish from bill
 * - listDish(): Display dish list
 * - setNumberTable(): Number of tables setting interface
 * - setName(): Set the dish name
 * - setPrice(): Set the dish price
 * - showList(): Display dish list
 * - processInput(string &var): Handling string input
 * - processInput(int &var): Handling numeric input
 * - getNumberTable(): Output the number of tables to send to the staff
 * - getListDish(): Export a list of dishes to send to the staff
 * Contructor:
 * - manager(): Show the first interface of the manager
 */
class manager
{
private:
	typedef enum
	{
		MANAGER,
		ADDDISH,
		EDITDISH,
		REMOVEDISH,
		LISTDISH,
		SETNUMBERTABLE
	} managerMenu;
	static list<dish> DATABASE;
	static int NUMBEROFTABLES;
	void addDish();
	void editDish();
	void removeDish();
	void listDish();
	void setNumberTable();
	void setName(dish &temp);
	void setPrice(dish &temp);
	void showList();
	void processInput(string &var);
	void processInput(int &var);

public:
	manager();
	int getNumberTable();
	list<dish> getDishList();
};

#endif