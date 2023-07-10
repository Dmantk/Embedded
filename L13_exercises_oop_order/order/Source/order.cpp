/*
 * File: order.cpp
 * Author: Duong Minh An
 * Date: 08/07/2023
 * Description: This's an example about create an order interface for managers and employees
 */
#include "order.hpp"
#include "dish.hpp"
#include "manager.hpp"
#include "employee.hpp"

/*
 * Function: choice function
 * Description: This function is used to handle selection.
 * Input:
 *   start - the first choose
 *   end - the final choice
 * Output:
 *   return the selected value
 */
uint8_t choice(uint8_t start, uint8_t end)
{
    uint16_t choice;
    bool isLoop = false;
    cout << "\033[s";
    do
    {
        isLoop = false;
        cout << "--> Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "Invalid choice. Please try again!" << endl;
            isLoop = true;
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        else if (choice < start || choice > end)
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "Invalid choice. Please try again!" << endl;
            isLoop = true;
        }
    } while (isLoop);
    return choice;
}

/*
 * Function: setName(string newName)
 * Description: This function is used to change the name of the dish in the list
 * Input:
 *   newName - the new dish name
 */
void run()
{
    manager *Manager = nullptr;
    cout << "\033c";
    cout << "-------------------------------ORDER-------------------------------" << endl;
    cout << endl;
    cout << "  1. Manager" << endl;
    cout << "  2. Employee" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(1, 2);
    switch (startMenu(select))
    {
    case MANAGER:
        Manager = new manager();
        break;
    case EMPLOYEE:
        employee Employee(Manager->getNumberTable(), Manager->getDishList());
        break;
    }
}