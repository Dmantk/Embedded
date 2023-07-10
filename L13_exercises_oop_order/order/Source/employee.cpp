/*
 * File: employee.cpp
 * Author: Duong Minh An
 * Date: 09/07/2023
 * Description: Used to design interfaces for adding, editing, deleting, and paying for the order list
 */
#include "employee.hpp"
#include "order.hpp"

/*
 * Macro: EMPLOYEE_MENU()
 * Description: This function is used to display the interface of the employee
 */
#define EMPLOYEE_MENU()                                                                                    \
    do                                                                                                     \
    {                                                                                                      \
        cout << "\033c";                                                                                   \
        if (TABLE < 10)                                                                                    \
        {                                                                                                  \
            cout << "--";                                                                                  \
        }                                                                                                  \
        else                                                                                               \
        {                                                                                                  \
            cout << "-";                                                                                   \
        }                                                                                                  \
        cout << "----------------------------TABLE[" << TABLE << "]-----------------------------" << endl; \
        cout << endl;                                                                                      \
        cout << "  1. Add dish" << endl;                                                                   \
        cout << "  2. Edit dish" << endl;                                                                  \
        cout << "  3. Remove dish" << endl;                                                                \
        cout << "  4. List dishes" << endl;                                                                \
        cout << "  5. Payment" << endl;                                                                    \
        cout << "  0. Back" << endl;                                                                       \
        cout << endl;                                                                                      \
        cout << "-------------------------------------------------------------------" << endl;             \
    } while (0)

map<int, char> employee::TABLESTATUS;

/*
 * Function: employee()
 * Description: Interface for choosing a dining table to order
 * Input:
 * - int numberOfTable: Enter the number of tables the manager entered
 * - list<dish> database: Transmit the dish datalist that the manager has entered
 */
employee::employee(int numberOfTable, list<dish> database)
{
    NUMBEROFTABLE = numberOfTable;
    DISHLIST = database;
    cout << "\033c";
    if (TABLESTATUS.empty())
    {
        for (int i = 1; i <= NUMBEROFTABLE; i++)
        {
            TABLESTATUS[i] = 'O';
        }
    }
    cout << "------------------------------EMPLOYEE-----------------------------" << endl;
    cout << endl;
    cout << "  Table number: ";
    for (auto temp : TABLESTATUS)
    {
        cout << "|" << temp.first;
        if (temp.first == NUMBEROFTABLE)
        {
            cout << "|" << endl;
        }
    }
    cout << "  Status      : ";
    for (auto temp : TABLESTATUS)
    {
        if (temp.first <= 10)
        {
            cout << "|" << temp.second;
            if (temp.first == NUMBEROFTABLE && temp.first < 10)
            {
                cout << "|" << endl;
            }
            else if (temp.first == NUMBEROFTABLE && temp.first == 10)
            {
                cout << " |" << endl;
            }
        }
        else
        {
            cout << " |" << temp.second;
            if (temp.first == NUMBEROFTABLE)
            {
                cout << " |";
            }
        }
    }

    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "(Enter '0' to reset the table state)" << endl;
    bool isLoop = false;
    cout << "\033[s";
    do
    {
        isLoop = false;
        cout << "--> Enter table number: ";
        cin >> TABLE;
        if (cin.fail())
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "Can't find the table. Please try again!" << endl;
            isLoop = true;
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        else if (TABLE < 0 || TABLE > NUMBEROFTABLE)
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "Can't find the table, Please try again!" << endl;
            isLoop = true;
        }
    } while (isLoop);
    switch (TABLE)
    {
    case 0:
        resetStatus();
        break;
    default:
        menu();
        break;
    }
}

/*
 * Function: menu()
 * Description: This is the interface to start the operations of adding, editing, deleting, payment ... in the order list, use switch-case to switch the interface.
 */
void employee::menu()
{
    EMPLOYEE_MENU();

    uint8_t select = choice(0, 5);
    switch (employeeMenu(select))
    {
    case ADDDISH:
        addDish();
        break;
    case EDITDISH:
        editDish();
        break;
    case REMOVEDISH:
        removeDish();
        break;
    case LISTORDER:
        showOrderList();
        break;
    case PAYMENT:
        payment();
        break;
    default:
        employee(NUMBEROFTABLE, DISHLIST);
        break;
    }
}

/*
 * Function: addDish()
 * Description: Interface for adding dishes and the quantity of dishes to the order list, based on the manager's database
 */
void employee::addDish()
{
    cout << "\033c";
    int dishId;
    int numberOfDish;
    cout << "-----------------------------ADD DISH------------------------------" << endl;
    cout << endl;
    listdish();
    cout << endl;
    bool isLoop = true;
    do
    {
        cout << "\033[s";
        cout << "-> Enter dish ID: ";
        processInput(dishId);
        for (auto temp : DISHLIST)
        {
            if (temp.getId() == dishId)
            {
                cout << "Dish name is: " << temp.getName() << endl;
                isLoop = false;
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
    cout << "-> Enter number of the dish: ";
    processInput(numberOfDish);
    ORDERLIST[dishId] = numberOfDish;
    cout << endl;
    orderList();
    cout << endl;
    cout << "  1. keep adding dish" << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;

    uint8_t select = choice(0, 1);
    switch (employeeMenu(select))
    {
    case ADDDISH:
        addDish();
        break;
    case MENU:
        menu();
        break;
    default:
        break;
    }
}

/*
 * Function: editDish()
 * Description: this is the interface to modify the name and quantity of the previously added dish
 */
void employee::editDish()
{
    cout << "\033c";
    int dishId;
    cout << "-----------------------------EDIT DISH-----------------------------" << endl;
    cout << endl;
    orderList();
    cout << endl;
    bool isLoop = true;
    cout << "\033[s";
    do
    {
        cout << "-> Enter ID: ";
        processInput(dishId);
        cout << endl;
        for (auto temp : ORDERLIST)
        {
            if (temp.first == dishId)
            {
                cout << "  1. Edit new dish" << endl;
                cout << "  2. Edit dish quantity" << endl;
                cout << "  0. Back" << endl;
                cout << endl;
                cout << "-------------------------------------------------------------------" << endl;
                uint8_t select = choice(0, 2);
                switch (select)
                {
                case 1:
                    editID(dishId);
                    break;
                case 2:
                    editQuantity(dishId);
                    break;
                default:
                    menu();
                    break;
                }
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

    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 0);
    switch (employeeMenu(select))
    {
    case MENU:
        menu();
        break;

    default:
        break;
    }
}

/*
 * Function: removeDish()
 * Description: This is the interface to delete dishes from the order list
 */
void employee::removeDish()
{
    cout << "\033c";
    int dishId;
    cout << "----------------------------REMOVE DISH----------------------------" << endl;
    cout << endl;
    orderList();
    cout << endl;
    bool isLoop = true;
    do
    {
        cout << "-> Enter ID"
             << "\033[s"
             << ": ";
        processInput(dishId);
        for (auto temp : ORDERLIST)
        {
            if (temp.first == dishId)
            {
                ORDERLIST.erase(dishId);
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
        menu();
        break;
    }
}

/*
 * Function: showOrderList()
 * Description: This is the interface to display the list of dishes ordered
 */
void employee::showOrderList()
{
    cout << "\033c";
    cout << "-----------------------------LIST DISH-----------------------------" << endl;
    cout << endl;
    orderList();
    cout << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 0);
    switch (employeeMenu(select))
    {
    case MENU:
        menu();
        break;

    default:
        break;
    }
}

/*
 * Function: payment()
 * Description: this is the current checkout, and will return X status for the ordered table
 */
void employee::payment()
{
    cout << "\033c";
    int total = 0;
    cout << "------------------------------PAYMENT------------------------------" << endl;
    cout << endl;
    orderList();
    cout << endl;
    for (auto temp : ORDERLIST)
    {
        for (auto &item : DISHLIST)
        {
            if (temp.first == item.getId())
            {
                total = total + temp.second * item.getPrice();
            }
        }
    }
    cout << "-> Total: " << total << endl;
    cout << endl;
    cout << "  1. Issue an invoice" << endl;
    cout << "  0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 1);
    switch (select)
    {
    case 1:
    {
        cout << "\033c";
        cout << endl;
        cout << endl;
        cout << "------------------------Successful invoice!------------------------" << endl;
        cout << endl;
        cout << endl;
        TABLESTATUS[TABLE] = 'X';
        ORDERLIST.clear();
        cout << "  0. New order" << endl;
        cout << endl;
        uint8_t select = choice(0, 0);
        switch (select)
        {
        case 0:
            employee(NUMBEROFTABLE, DISHLIST);
            break;

        default:
            break;
        }
    }
    break;
    default:
        menu();
        break;
    }
}

/*
 * Function: resetStatus()
 * Description: this is the interface to reset the table state to O.
 */
void employee::resetStatus()
{
    cout << "\033c";
    if (TABLESTATUS.empty())
    {
        for (int i = 1; i <= NUMBEROFTABLE; i++)
        {
            TABLESTATUS[i] = 'O';
        }
    }
    cout << "------------------------RESET STATUS TABLE-------------------------" << endl;
    cout << endl;
    cout << "  Table number: ";
    for (auto temp : TABLESTATUS)
    {
        cout << "|" << temp.first;
        if (temp.first == NUMBEROFTABLE)
        {
            cout << "|" << endl;
        }
    }
    cout << "  Status      : ";
    for (auto temp : TABLESTATUS)
    {
        if (temp.first <= 10)
        {
            cout << "|" << temp.second;
            if (temp.first == NUMBEROFTABLE && temp.first < 10)
            {
                cout << "|" << endl;
            }
            else if (temp.first == NUMBEROFTABLE && temp.first == 10)
            {
                cout << " |" << endl;
            }
        }
        else
        {
            cout << " |" << temp.second;
            if (temp.first == NUMBEROFTABLE)
            {
                cout << " |";
            }
        }
    }

    cout << endl;
    cout << endl;
    bool isLoop = false;
    cout << "\033[s";
    do
    {
        isLoop = false;
        cout << "--> Enter the number of desks to reset: ";
        cin >> TABLE;
        if (cin.fail())
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "Can't find the table. Please try again!" << endl;
            isLoop = true;
            cin.clear();
            while (cin.get() != '\n')
                continue;
        }
        else if (TABLE < 0 || TABLE > NUMBEROFTABLE)
        {
            cout << "\033[u";
            cout << "\033[0J";
            cout << "\033[s";
            cout << "Can't find the table, Please try again!" << endl;
            isLoop = true;
        }
    } while (isLoop);
    TABLESTATUS[TABLE] = 'O';
    cout << endl;
    cout << "Success!" << endl;
    cout << endl;
    cout << "1. Keep reseting status of table" << endl;
    cout << "0. Back" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    uint8_t select = choice(0, 1);
    switch (select)
    {
    case 1:
        resetStatus();
        break;

    default:
        employee(NUMBEROFTABLE, DISHLIST);
        break;
    }
}

/*
 * Function: listdish()
 * Description: This is display a dish list of manager
 */
void employee::listdish()
{
    int idWidth = 8;
    int nameWidth = 15;

    cout << "           >----------------List dishes---------------<" << endl;
    if (DISHLIST.empty())
    {
        cout << "                         No dishes found" << endl;
    }
    else
    {
        cout << "             Dish ID" << string(idWidth - 6, ' ') << " | "
             << "Dish Name" << string(nameWidth - 9, ' ') << " | "
             << "Dish Price" << endl;
        for (auto temp : DISHLIST)
        {
            cout << "             " << temp.getId() << string(idWidth + 1 - to_string(temp.getId()).length(), ' ') << " | "
                 << temp.getName() << string(nameWidth - temp.getName().length(), ' ') << " | "
                 << temp.getPrice() << endl;
        }
    }
    cout << "           >------------------------------------------<" << endl;
}

/*
 * Function: processInput(int &var)
 * Description: This is a function that handles numeric input, has a numeric limit, and handles input errors
 * Input:
 * - int &var: The address of the variable to enter
 * Output:
 * - Returns the correct input and assigns it to the variable
 */
void employee::processInput(int &var)
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

/*
 * Function: orderList()
 * Description: This is to create a list of ordered dishes
 */
void employee::orderList()
{
    int noWidth = 3;
    int idWidth = 7;
    int nameWidth = 15;
    int priceWidth = 10;
    int no = 1;
    cout << "  >--------------------------Order list--------------------------<" << endl;
    if (ORDERLIST.empty())
    {
        cout << "                       No dishes found" << endl;
    }
    else
    {
        cout << "    N.o" << string(noWidth - 3, ' ') << " | "
             << "Dish ID" << string(idWidth - 7, ' ') << " | "
             << "Dish Name" << string(nameWidth - 9, ' ') << " | "
             << "Dish Price" << string(priceWidth - 10, ' ') << " | "
             << "Dish quantity" << endl;
        for (auto &temp : ORDERLIST)
        {
            int id = temp.first;
            int quant = temp.second;

            cout << "    " << no << string(noWidth - to_string(no).length(), ' ') << " | ";
            no++;
            for (auto &item : DISHLIST)
            {
                if (item.getId() == id)
                {
                    cout << item.getId() << string(idWidth - to_string(item.getId()).length(), ' ') << " | "
                         << item.getName() << string(nameWidth - item.getName().length(), ' ') << " | "
                         << item.getPrice() << string(priceWidth - to_string(item.getPrice()).length(), ' ') << " | ";
                }
            }
            cout << quant << endl;
        }
    }
    cout << "  >--------------------------------------------------------------<" << endl;
}

/*
 * Function: editID(int id)
 * Description: This is the function to enter the id to redeem the dish for the customer
 * Input:
 * - int id: the ID of dish
 */
void employee::editID(int id)
{
    cout << "\033c";
    int dishId;
    int quantity;
    for (auto temp : ORDERLIST)
    {
        if (temp.first == id)
        {
            cout << "-----------------------------EDIT DISH-----------------------------" << endl;
            cout << endl;
            listdish();
            cout << endl;
            cout << "Old dish ID is: " << temp.first << endl;
            cout << "-> Enter new dish ID"
                 << "\033[s"
                 << ": ";
            processInput(dishId);
            quantity = temp.second;
            ORDERLIST.erase(temp.first);
            ORDERLIST[dishId] = quantity;
            cout << "Success!" << endl;
            cout << endl;
            cout << "  1. Edit another dish" << endl;
            cout << "  2. Edit dish quantity" << endl;
            cout << "  0. Back" << endl;
            cout << endl;
            cout << "-------------------------------------------------------------------" << endl;
            int select = choice(0, 2);
            switch (select)
            {
            case 1:
                editDish();
                break;
            case 2:
                editQuantity(dishId);
                break;
            default:
                menu();
                break;
            }
        }
    }
}

/*
 * Function: editQuantity(int id)
 * Description: this is the function to enter the id to change the number of dishes for the customer
 * Input:
 * - int id: the ID of dish
 */
void employee::editQuantity(int id)
{
    cout << "\033c";
    int quantity;
    for (auto temp : ORDERLIST)
    {
        if (temp.first == id)
        {
            cout << "-----------------------------EDIT DISH-----------------------------" << endl;
            cout << endl;
            orderList();
            cout << endl;
            cout << "Old dish quantity is: " << temp.second << endl;
            cout << "-> Enter new dish quantity"
                 << "\033[s"
                 << ": ";
            processInput(quantity);
            ORDERLIST[id] = quantity;
            cout << "Success!" << endl;
            cout << endl;
            cout << "  1. Edit another dish" << endl;
            cout << "  0. Back" << endl;
            cout << endl;
            cout << "-------------------------------------------------------------------" << endl;
            uint8_t select = choice(0, 1);
            switch (select)
            {
            case 1:
                editDish();
                break;

            default:
                menu();
                break;
            }
        }
    }
}
