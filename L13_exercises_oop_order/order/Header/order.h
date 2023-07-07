#ifndef __ORDER_H__
#define __ORDER_H__

#include "order.h"
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

uint8_t choice(uint8_t start, uint8_t end);

void run();

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

typedef enum
{
    MANAGER = 1,
    EMPLOYEE
} startMenu;

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
list<dish> manager::DATABASE;
int manager::NUMBEROFTABLES;

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
map<int, char> employee::TABLESTATUS;

#endif