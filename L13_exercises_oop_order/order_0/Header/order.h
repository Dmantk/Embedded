#ifndef __ORDER_H__
#define __ORDER_H__

#include "order.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void clearScreen();
int choice(int start, int end);
void switchTab(int currentTab, int switTab);
void run();

class Item
{
private:
	int itemID;
	string itemName;
	int itemCost;

public:
	Item(string ItemName, int ItemCost);
	int getItemID();
	string getItemName();
	int getItemCost();
	void setItemName(string newItemName);
	void setItemCost(int newItemCost);
};

class manager
{
private:
	int tableNumber;

public:
	void managerHome();
	void listItem();
	void addItem();
	void editItem();
	void removeItem();
	void listItems();
	void setTable();
	int getTable();
	void editName(Item &temp);
	void editCost(Item &temp);
	void processInput(string &var);
	void processInput(int &var);
};

class employee : public manager
{
private:
	int table;
	map<int, int> orderlist;
	map<int, char> tableTick;

public:
	void employeeHome();
	void employeeMenu();
	void addItem();
	void editItem();
	void removeItem();
	void listItems();
	void payments();
	int getNumberOfTable();
	void orderList();
	void editQuantity(int id);
	void editID(int id);
	void dataSave();
	void resetTable();
};

#endif