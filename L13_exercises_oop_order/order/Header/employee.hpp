/*
 * File: employee.hpp
 * Author: Duong Minh An
 * Date: 09/07/2023
 * Description: Used to design interfaces for adding, editing, deleting, and paying for the order list
 */
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "dish.hpp"
#include <string>
#include <list>
#include <map>

using namespace std;

/*
 * Function: class employee
 * Description: Design interfaces for adding, editing, deleting, and paying for the order list
 * Property:
 * - enum employeeMenu: Used to compare interface switching
 * - map ORDERLIST: Used to store ID and order quantity
 * - static map TABLESTATUS: To save the state of the tables
 * - TABLE: The number of the table selected to order
 * - NUMBEROFTABLE: Save the number of installed manager's desks
 * - list DISHLIST: Used to save the list of dishes that the manager has updated
 * Method:
 * - menu(): Display the interface of the employee's menu
 * - addDish(): Add the dish and its quantity to the bill
 * - editDish(): Change dishes
 * - removeDish(): Remove dish from bill
 * - showOrderList(): Display order list
 * - payment(): Payment interface
 * - resetStatus(): Reset the state of the table
 * - listdish(): manager's menu
 * - processInput(): Handling numeric input
 * - orderList(): Ordered dish list
 * - editId(): Change to another dish
 * - editQuantity(): Change the quantity of the dish
 * Contructor:
 * - employee(): Will display the first interface of employee
 */
class employee
{
private:
	typedef enum
	{
		MENU,
		ADDDISH,
		EDITDISH,
		REMOVEDISH,
		LISTORDER,
		PAYMENT
	} employeeMenu;
	map<int, int> ORDERLIST;
	static map<int, char> TABLESTATUS;
	int TABLE;
	int NUMBEROFTABLE;
	list<dish> DISHLIST;
	void menu();
	void addDish();
	void editDish();
	void removeDish();
	void showOrderList();
	void payment();
	void resetStatus();
	void listdish();
	void processInput(int &var);
	void orderList();
	void editID(int id);
	void editQuantity(int id);

public:
	employee(int numberOfTable, list<dish> database);
};

#endif