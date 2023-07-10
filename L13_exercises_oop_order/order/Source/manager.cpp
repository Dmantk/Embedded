/*
 * File: manager.cpp
 * Author: Duong Minh An
 * Date: 09/07/2023
 * Description: Design interfaces to add, edit, delete, display the dish list
 */
#include "manager.hpp"
#include "order.hpp"
#include "dish.hpp"

/*
 * Macro: MANAGER_MENU()
 * Description: This function is used to display the interface of the manager
 */
#define MANAGER_MENU()                                                                         \
    do                                                                                         \
    {                                                                                          \
        cout << "\033c";                                                                       \
        cout << "------------------------------MANAGER------------------------------" << endl; \
        cout << endl;                                                                          \
        cout << "  1. Add dish" << endl;                                                       \
        cout << "  2. Edit dish" << endl;                                                      \
        cout << "  3. Remove dish" << endl;                                                    \
        cout << "  4. List dish" << endl;                                                      \
        cout << "  5. Set table number" << endl;                                               \
        cout << "  0. Back" << endl;                                                           \
        cout << endl;                                                                          \
        cout << "-------------------------------------------------------------------" << endl; \
    } while (0)

list<dish> manager::DATABASE;
int manager::NUMBEROFTABLES;

/*
 * Function: manager()
 * Description: This is the interface to start the operations of adding, editing, deleting, ... in the dish list, use switch-case to switch the interface.
 */
manager::manager()
{
    MANAGER_MENU();

    uint8_t select = choice(0, 5);
    switch (managerMenu(select))
    {
    case MANAGER:
        run();
        break;
    case ADDDISH:
        addDish();
        break;
    case EDITDISH:
        editDish();
        break;
    case REMOVEDISH:
        removeDish();
        break;
    case LISTDISH:
        listDish();
        break;
    case SETNUMBERTABLE:
        setNumberTable();
        break;
    }
}

/*
 * Function: addDish()
 * Description: This is an additional order delivery, the manager will add the name and price of the dish
 */
void manager::addDish()
{
    cout << "\033c";
    string dishName;
    int dishPrice;
    cout << "-----------------------------ADD DISH------------------------------" << endl;
    cout << endl;
    cout << "-> Enter dish name"
         << "\033[s"
         << ": ";
    processInput(dishName);
    cout << "-> Enter dish price"
         << "\033[s"
         << ": ";
    processInput(dishPrice);
    cout << endl;
    dish newDish(dishName, dishPrice);
    DATABASE.push_back(newDish);
    showList();
    cout << endl;
    cout << "  1. Keep adding dish" << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 1);
    switch (managerMenu(select))
    {
    case ADDDISH:
        addDish();
        break;

    case MANAGER:
        manager();
        break;
    default:
        break;
    }
}

/*
 * Function: editDish()
 * Description: this is the interface to modify the name and price of the previously added dish
 */
void manager::editDish()
{
    cout << "\033c";
    int dishId;
    cout << "-----------------------------EDIT DISH-----------------------------" << endl;
    cout << endl;
    showList();
    cout << endl;
    bool isLoop;
    do
    {
        cout << "\033[s";
        cout << "-> Enter ID: ";
        processInput(dishId);
        for (auto &temp : DATABASE)
        {
            if (temp.getId() == dishId)
            {
                cout << endl;
                cout << "  1. Edit dish name" << endl;
                cout << "  2. Edit dish price" << endl;
                cout << "  0. Back" << endl;
                cout << endl;
                cout << "-------------------------------------------------------------------" << endl;
                uint8_t select = choice(0, 2);
                switch (select)
                {
                case 1:
                    setName(temp);
                    break;
                case 2:
                    setPrice(temp);
                    break;
                default:
                    manager();
                    break;
                }
            }
        }
        isLoop = false;
        char yn;
        if (!isLoop)
        {
            cout << "ID not found!" << endl;
            do
            {
                cout << "-> Re-enter(y/n): ";
                cin >> yn;
                yn = tolower(yn);
            } while (yn != 'y' && yn != 'n');
            if (yn == 'y' || yn == 'Y')
            {
                cout << "\033[u";
                cout << "\033[0J";
                isLoop = true;
            }
            else if (yn == 'n' || yn == 'N')
            {
                isLoop = false;
            }
        }
    } while (isLoop);
    cout << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 0);
    switch (managerMenu(select))
    {
    case 0:
        manager();
        break;
    default:
        break;
    }
}

/*
 * Function: removeDish()
 * Description: This is the interface to delete dishes from the list
 */
void manager::removeDish()
{
    cout << "\033c";
    int dishId;
    cout << "----------------------------REMOVE DISH----------------------------" << endl;
    cout << endl;
    showList();
    cout << endl;
    bool isLoop = true;
    do
    {
        cout << "\033[s";
        cout << "-> Enter ID: ";
        processInput(dishId);
        for (auto temp = DATABASE.begin(); temp != DATABASE.end(); ++temp)
        {
            if ((*temp).getId() == dishId)
            {
                DATABASE.erase(temp);
                cout << "Success!" << endl;
                isLoop = false;
                break;
            }
        }
        char yn;
        if (isLoop)
        {
            cout << "ID not found!" << endl;
            do
            {
                cout << "-> Re-enter(y/n): ";
                cin >> yn;
                yn = tolower(yn);
            } while (yn != 'y' && yn != 'n');
            if (yn == 'y' || yn == 'Y')
            {
                cout << "\033[u";
                cout << "\033[0J";
                isLoop = true;
            }
            else if (yn == 'n' || yn == 'N')
            {
                isLoop = false;
            }
        }
    } while (isLoop);
    cout << endl;
    cout << "  1. Keep removing dish" << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 1);
    switch (select)
    {
    case 1:
        removeDish();
        break;

    default:
        manager();
        break;
    }
}

/*
 * Function: listDish()
 * Description: This is the interface to display the list of dishes
 */
void manager::listDish()
{
    cout << "\033c";
    cout << "-----------------------------LIST DISH-----------------------------" << endl;
    cout << endl;
    showList();
    cout << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 0);
    switch (managerMenu(select))
    {
    case MANAGER:
        manager();
        break;
    default:
        break;
    }
}

/*
 * Function: setNumberTable()
 * Description: This is the interface for setting the number of tables
 */
void manager::setNumberTable()
{
    cout << "\033c";
    cout << "-----------------------SET NUMBER OF TABLES------------------------" << endl;
    cout << endl;
    cout << "-> Enter number of tables"
         << "\033[s"
         << ": ";
    processInput(NUMBEROFTABLES);
    cout << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 0);
    switch (managerMenu(select))
    {
    case MANAGER:
        manager();
        break;
    default:
        break;
    }
}

/*
 * Function: getNumberTable()
 * Description: This is a function that returns the number of tables for the employee
 * Output:
 * - return NUMBEROFTABLES: Return number of tables
 */
int manager::getNumberTable()
{
    return NUMBEROFTABLES;
}

/*
 * Function: getDishList()
 * Description: This is a function that returns the dish list for the employee
 * Output:
 * - return DATABASE: Return the dish list
 */
list<dish> manager::getDishList()
{
    return DATABASE;
}

/*
 * Function: setName(dish &temp)
 * Description: Here is the function to change the name in the dish list
 * Input:
 * - dish &temp: The address of the item needs to be changed
 * Output:
 * - Returns the new name of the dish, which has been changed
 */
void manager::setName(dish &temp)
{
    cout << "\033c";
    string dishName;
    cout << "-----------------------------EDIT DISH-----------------------------" << endl;
    cout << endl;
    cout << "Old dish name is: " << temp.getName() << endl;
    cout << "-> Enter new dish name"
         << "\033[s"
         << ": ";
    processInput(dishName);
    temp.setName(dishName);
    cout << "Success!" << endl;
    cout << endl;
    cout << "  1. Keep editing another dish" << endl;
    cout << "  2. Keep editing this dish price" << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 2);
    switch (select)
    {
    case 1:
        editDish();
        break;
    case 2:
        setPrice(temp);
        break;
    default:
        manager();
        break;
    }
}

/*
 * Function: setPrice(dish &temp)
 * Description: Here is the function to change the price in the dish list
 * Input:
 * - dish &temp: The address of the item needs to be changed
 * Output:
 * - Returns the new price of the dish, which has been changed
 */
void manager::setPrice(dish &temp)
{
    cout << "\033c";
    int dishPrice;
    cout << "-----------------------------EDIT DISH-----------------------------" << endl;
    cout << endl;
    cout << "Old dish price is: " << temp.getPrice() << endl;
    cout << "-> Enter new dish price"
         << "\033[s"
         << ": ";
    processInput(dishPrice);
    temp.setPrice(dishPrice);
    cout << "Success!" << endl;
    cout << endl;
    cout << "  1. Keep editing another dish" << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 1);
    switch (managerMenu(select))
    {
    case 1:
        editDish();
        break;
    default:
        manager();
        break;
    }
}

/*
 * Function: showList()
 * Description: Display the list of imported dishes in tabular form
 */
void manager::showList()
{
    int idWidth = 8;
    int nameWidth = 15;

    cout << "           >----------------List dishes---------------<" << endl;
    if (DATABASE.empty())
    {
        cout << "                          No items found" << endl;
    }
    else
    {
        cout << "             Dish ID" << string(idWidth - 6, ' ') << " | "
             << "Dish Name" << string(nameWidth - 9, ' ') << " | "
             << "Dish Price" << endl;
        for (auto temp : DATABASE)
        {
            cout << "             " << temp.getId() << string(idWidth + 1 - to_string(temp.getId()).length(), ' ') << " | "
                 << temp.getName() << string(nameWidth - temp.getName().length(), ' ') << " | "
                 << temp.getPrice() << endl;
        }
    }
    cout << "           >------------------------------------------<" << endl;
}

/*
 * Function: processInput(string &var)
 * Description: This is a function that handles string input with limited characters, and handles input errors
 * Input:
 * - string &var: The address of the variable to enter
 * Output:
 * - Returns the correct input and assigns it to the variable
 */
void manager::processInput(string &var)
{
    int maxChars = 16;
    string stringVar;
    cin.ignore();
    do
    {
        getline(cin, stringVar);
        if (stringVar.length() > static_cast<std::string::size_type>(maxChars - 1))
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "(No more than " << (maxChars - 1) << " characters. Again!): ";
        }
        else
        {
            break;
        }
    } while (true);

    var = stringVar;
}

/*
 * Function: processInput(int &var)
 * Description: This is a function that handles numeric input, has a numeric limit, and handles input errors
 * Input:
 * - int &var: The address of the variable to enter
 * Output:
 * - Returns the correct input and assigns it to the variable
 */
void manager::processInput(int &var)
{
    int minInt = 0;
    int intVar;
    bool validInput = false;
    do
    {
        cin >> intVar;

        if (cin.fail())
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "(Please enter a valid number. Again!): ";
            cin.clear();
            while (cin.get() != '\n')
                continue;
            ;
        }
        else if (intVar < minInt)
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "(Please enter a number greater than 0. Again!): ";
        }
        else
        {
            validInput = true;
        }
    } while (!validInput);
    var = intVar;
}
