#include "order.h"

int currentPos = 0;

/*
 * Function: enum Item
 * Description: Used to create a item list include ID, name, price
 */
vector<Item> items;

Item::Item(string ItemName, int ItemCost)
{
	static int ItemID = 100;
	itemID = ItemID;
	ItemID++;
	itemName = ItemName;
	itemCost = ItemCost;
}
int Item::getItemID()
{
	return itemID;
}
string Item::getItemName()
{
	return itemName;
}
int Item::getItemCost()
{
	return itemCost;
}
void Item::setItemName(string newItemName)
{
	itemName = newItemName;
}
void Item::setItemCost(int newItemCost)
{
	itemCost = newItemCost;
}

/*
 * Function: class manager
 * Description: Design interfaces to add, edit, delete, display the dish list
 */
void manager::managerHome()
{
	currentPos = 1;
	cout << "------------------------------MANAGER------------------------------" << endl;
	cout << endl;
	cout << "  1. Add item" << endl;
	cout << "  2. Edit item" << endl;
	cout << "  3. Remove item" << endl;
	cout << "  4. List items" << endl;
	cout << "  5. Set table number" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

	int select = choice(0, 5);
	switchTab(currentPos, select);
}
void manager::addItem()
{
	currentPos = 2;
	string itemName;
	int itemCost;
	cout << "-----------------------------ADD ITEM------------------------------" << endl;
	cout << endl;
	cout << "-> Enter item name: ";
	processInput(itemName);
	cout << "-> Enter item cost: ";
	processInput(itemCost);
	cout << endl;
	Item newItem(itemName, itemCost);
	items.push_back(newItem);
	listItem();
	cout << endl;
	cout << "  1. Keep adding item" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 1);
	switchTab(currentPos, select);
}
void manager::editItem()
{
	currentPos = 3;
	int itemID;
	string itemName;

	cout << "-----------------------------EDIT ITEM-----------------------------" << endl;
	cout << endl;
	listItem();
	cout << endl;
	bool flag = true;
	do
	{
		cout << "-> Enter ID: ";
		processInput(itemID);
		cout << endl;
		for (auto &temp : items)
		{
			if (temp.getItemID() == itemID)
			{
				cout << "  1. Edit item name" << endl;
				cout << "  2. Edit item cost" << endl;
				cout << "  0. Back" << endl;
				cout << endl;
				cout << "-------------------------------------------------------------------" << endl;
				int select = choice(0, 2);
				switch (select)
				{
				case 1:

					editName(temp);
					break;
				case 2:

					editCost(temp);
					break;
				default:
					switchTab(currentPos, select);
					break;
				}
			}
		}
		char yn;
		if (flag)
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
				flag = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				flag = false;
			}
		}
	} while (flag);
	cout << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 0);
	switchTab(currentPos, select);
}
void manager::removeItem()
{
	currentPos = 4;
	int itemID;
	cout << "----------------------------REMOVE ITEM----------------------------" << endl;
	cout << endl;
	listItem();
	cout << endl;
	bool flag = true;
	do
	{
		cout << "-> Enter ID: ";
		processInput(itemID);
		for (auto temp = items.begin(); temp != items.end(); ++temp)
		{
			if ((*temp).getItemID() == itemID)
			{
				items.erase(temp);
				cout << "Success!" << endl;
				flag = false;
				break;
			}
		}
		char yn;
		if (flag)
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
				flag = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				flag = false;
			}
		}
	} while (flag);
	cout << endl;
	cout << "  1. Keep removing item" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 1);
	switchTab(currentPos, select);
}
void manager::listItems()
{
	currentPos = 5;
	cout << "-----------------------------LIST ITEM-----------------------------" << endl;
	cout << endl;
	listItem();
	cout << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 0);
	switchTab(currentPos, select);
}
void manager::setTable()
{
	currentPos = 6;
	cout << "-------------------------SET TABLE NUMBER--------------------------" << endl;
	cout << endl;
	cout << "-> Enter table number: ";
	processInput(tableNumber);
	cout << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 0);
	switchTab(currentPos, select);
}
int manager::getTable()
{
	return tableNumber;
}
void manager::listItem()
{
	int idWidth = 8;
	int nameWidth = 15;

	cout << "           >----------------List items----------------<" << endl;
	if (items.empty())
	{
		cout << "                          No items found" << endl;
	}
	else
	{
		cout << "             Item ID" << string(idWidth - 6, ' ') << " | "
			 << "Item Name" << string(nameWidth - 9, ' ') << " | "
			 << "Item Cost" << endl;
		for (auto &item : items)
		{
			cout << "             " << item.getItemID() << string(idWidth + 1 - to_string(item.getItemID()).length(), ' ') << " | "
				 << item.getItemName() << string(nameWidth - item.getItemName().length(), ' ') << " | "
				 << item.getItemCost() << endl;
		}
	}
	cout << "           >------------------------------------------<" << endl;
}
void manager::editName(Item &temp)
{
	clearScreen();
	string itemName;
	cout << "-----------------------------EDIT ITEM-----------------------------" << endl;
	cout << endl;
	cout << "Old item name is: " << temp.getItemName() << endl;
	cout << "-> Enter new item name: ";
	processInput(itemName);
	temp.setItemName(itemName);
	cout << "Success!" << endl;
	cout << endl;
	cout << "  1. Edit another item" << endl;
	cout << "  2. Edit item cost" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 2);
	if (select == 2)
	{
		editCost(temp);
	}
	else
	{
		switchTab(currentPos, select);
	}
}
void manager::editCost(Item &temp)
{
	clearScreen();
	int itemCost;
	cout << "-----------------------------EDIT ITEM-----------------------------" << endl;
	cout << endl;
	cout << "Old item cost is: " << temp.getItemCost() << endl;
	cout << "-> Enter new item cost: ";
	processInput(itemCost);
	temp.setItemCost(itemCost);
	cout << "Success!" << endl;
	cout << endl;
	cout << "  1. Edit another item" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 1);
	switchTab(currentPos, select);
}
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
			cout << "Maximum number of characters is " << (maxChars - 1) << ". Try again: ";
		}
		else
		{
			break;
		}
	} while (true);
	var = stringVar;
}
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
			cout << "Please enter a valid number. Try again: ";
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		else if (intVar < minInt)
		{
			cout << "Please enter a number greater than 0. Try again: ";
		}
		else
		{
			validInput = true;
		}
	} while (!validInput);
	var = intVar;
}

manager Manager;

/*
 * Function: class employee
 * Description: Design interfaces for adding, editing, deleting, and paying for the order list
 */
void employee::employeeHome()
{
	currentPos = 7;
	if (tableTick.empty())
	{
		for (int i = 1; i <= Manager.getTable(); i++)
		{
			tableTick[i] = 'O';
		}
	}
	cout << "------------------------------EMPLOYEE-----------------------------" << endl;
	cout << endl;
	cout << "  Table number: ";
	for (auto temp : tableTick)
	{
		cout << "|" << temp.first;
		if (temp.first == Manager.getTable())
		{
			cout << "|" << endl;
		}
	}
	cout << "  Status      : ";
	for (auto temp : tableTick)
	{
		if (temp.first <= 10)
		{
			cout << "|" << temp.second;
			if (temp.first == Manager.getTable())
			{
				cout << " |" << endl;
			}
		}
		else
		{
			cout << " |" << temp.second;
			if (temp.first == Manager.getTable())
			{
				cout << " |";
			}
		}
	}

	cout << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "(Enter '0' to reset the table state)" << endl;
	do
	{
		cout << "--> Enter table number: ";
		cin >> table;
		if (cin.fail())
		{
			cout << "Can't find the table. Please try again!" << endl;
			cin.clear();
			cin.ignore();
			table = Manager.getTable() + 1;
		}
		else if (table < 0 || table > Manager.getTable())
		{
			cout << "Can't find the table, Please try again!" << endl;
		}
	} while (table < 0 || table > Manager.getTable());

	switchTab(currentPos, table);
}
void employee::employeeMenu()
{
	currentPos = 8;
	if (table < 10)
	{
		cout << "--";
	}
	else
	{
		cout << "-";
	}
	cout << "----------------------------TABLE[" << table << "]-----------------------------" << endl;
	cout << endl;
	cout << "  1. Add item" << endl;
	cout << "  2. Edit item" << endl;
	cout << "  3. Remove item" << endl;
	cout << "  4. List items" << endl;
	cout << "  5. Payment" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

	int select = choice(0, 5);
	switchTab(currentPos, select);
}
void employee::addItem()
{
	currentPos = 9;
	int itemID;
	int numberOfItem;
	cout << "-----------------------------ADD ITEM------------------------------" << endl;
	cout << endl;
	listItem();
	cout << endl;
	bool flag = true;
	do
	{
		cout << "-> Enter item ID: ";
		processInput(itemID);
		for (auto temp : items)
		{
			if (temp.getItemID() == itemID)
			{
				cout << "Item name is: " << temp.getItemName() << endl;
				flag = false;
			}
		}
		char yn;
		if (flag)
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
				flag = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				flag = false;
			}
		}
	} while (flag);
	cout << "-> Enter number of the item: ";
	processInput(numberOfItem);
	orderlist[itemID] = numberOfItem;
	cout << endl;
	orderList();
	cout << endl;
	cout << "  1. keep adding item" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

	int select = choice(0, 1);
	switchTab(currentPos, select);
}
void employee::editItem()
{
	currentPos = 10;
	int itemID;
	cout << "-----------------------------EDIT ITEM-----------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	bool flag = true;
	do
	{
		cout << "-> Enter ID: ";
		processInput(itemID);
		cout << endl;
		for (auto temp : orderlist)
		{
			if (temp.first == itemID)
			{
				cout << "  1. Edit new item" << endl;
				cout << "  2. Edit item quantity" << endl;
				cout << "  0. Back" << endl;
				cout << endl;
				cout << "-------------------------------------------------------------------" << endl;
				int select = choice(0, 2);
				switch (select)
				{
				case 1:
					editID(itemID);
					break;
				case 2:
					editQuantity(itemID);
					break;
				default:
					switchTab(currentPos, select);
					break;
				}
			}
		}
		char yn;
		if (flag)
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
				flag = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				flag = false;
			}
		}
	} while (flag);

	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 0);
	switchTab(currentPos, select);
}
void employee::removeItem()
{
	currentPos = 11;
	int itemID;
	cout << "----------------------------REMOVE ITEM----------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	bool flag = true;
	do
	{
		cout << "-> Enter ID: ";
		processInput(itemID);
		for (auto temp : orderlist)
		{
			if (temp.first == itemID)
			{
				orderlist.erase(itemID);
				cout << "Success!" << endl;
				flag = false;
				break;
			}
		}
		char yn;
		if (flag)
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
				flag = true;
			}
			else if (yn == 'n' || yn == 'N')
			{
				flag = false;
			}
		}
	} while (flag);
	cout << endl;
	cout << "  1. Keep removing item" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 1);
	switchTab(currentPos, select);
}
void employee::listItems()
{
	currentPos = 12;
	cout << "-----------------------------LIST ITEM-----------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 0);
	switchTab(currentPos, select);
}
void employee::payments()
{
	currentPos = 13;
	int total = 0;
	cout << "------------------------------PAYMENT------------------------------" << endl;
	cout << endl;
	orderList();
	cout << endl;
	for (auto temp : orderlist)
	{
		for (auto &item : items)
		{
			if (temp.first == item.getItemID())
			{
				total = total + temp.second * item.getItemCost();
			}
		}
	}
	cout << "-> Total: " << total << endl;
	cout << endl;
	cout << "  1. Issue an invoice" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 1);
	switchTab(currentPos, select);
}
int employee::getNumberOfTable()
{
	return table;
}
void employee::orderList()
{
	int noWidth = 3;
	int idWidth = 7;
	int nameWidth = 15;
	int costWidth = 9;
	int no = 1;
	cout << "  >--------------------------Order list--------------------------<" << endl;
	if (orderlist.empty())
	{
		cout << "                        No items found" << endl;
	}
	else
	{
		cout << "    N.o" << string(noWidth - 3, ' ') << " | "
			 << "Item ID" << string(idWidth - 7, ' ') << " | "
			 << "Item Name" << string(nameWidth - 9, ' ') << " | "
			 << "Item Cost" << string(costWidth - 9, ' ') << " | "
			 << "Item quantity" << endl;
		for (auto &temp : orderlist)
		{
			int id = temp.first;
			int quant = temp.second;

			cout << "    " << no << string(noWidth - to_string(no).length(), ' ') << " | ";
			no++;
			for (auto &item : items)
			{
				if (item.getItemID() == id)
				{
					cout << item.getItemID() << string(idWidth - to_string(item.getItemID()).length(), ' ') << " | "
						 << item.getItemName() << string(nameWidth - item.getItemName().length(), ' ') << " | "
						 << item.getItemCost() << string(costWidth - to_string(item.getItemCost()).length(), ' ') << " | ";
				}
			}
			cout << quant << endl;
		}
	}
	cout << "  >--------------------------------------------------------------<" << endl;
}
void employee::editQuantity(int id)
{
	clearScreen();
	int quantity;
	for (auto temp : orderlist)
	{
		if (temp.first == id)
		{
			cout << "-----------------------------EDIT ITEM-----------------------------" << endl;
			cout << endl;
			orderList();
			cout << endl;
			cout << "Old item quantity is: " << temp.second << endl;
			cout << "-> Enter new item quantity: ";
			processInput(quantity);
			orderlist[id] = quantity;
			cout << "Success!" << endl;
			cout << endl;
			cout << "  1. Edit another item" << endl;
			cout << "  0. Back" << endl;
			cout << endl;
			cout << "-------------------------------------------------------------------" << endl;
			int select = choice(0, 1);
			switchTab(currentPos, select);
		}
	}
}
void employee::editID(int id)
{
	clearScreen();
	int itemID;
	int quantity;
	for (auto temp : orderlist)
	{
		if (temp.first == id)
		{
			cout << "-----------------------------EDIT ITEM-----------------------------" << endl;
			cout << endl;
			Manager.listItem();
			cout << endl;
			cout << "Old item ID is: " << temp.first << endl;
			cout << "-> Enter new item ID: ";
			processInput(itemID);
			quantity = temp.second;
			orderlist.erase(temp.first);
			orderlist[itemID] = quantity;
			cout << "Success!" << endl;
			cout << endl;
			cout << "  1. Edit another item" << endl;
			cout << "  2. Edit item quantity" << endl;
			cout << "  0. Back" << endl;
			cout << endl;
			cout << "-------------------------------------------------------------------" << endl;
			int select = choice(0, 2);
			if (select == 2)
			{
				editQuantity(itemID);
			}
			else
			{
				switchTab(currentPos, select);
			}
		}
	}
}
void employee::dataSave()
{
	currentPos = 14;

	cout << endl;
	cout << endl;
	cout << "------------------------Successful invoice!------------------------" << endl;
	cout << endl;
	cout << endl;
	tableTick[table] = 'X';
	orderlist.clear();
	cout << "  0. New order" << endl;
	cout << endl;
	int select = choice(0, 0);
	switchTab(currentPos, select);
}
void employee::resetTable()
{
	currentPos = 15;
	if (tableTick.empty())
	{
		for (int i = 1; i <= Manager.getTable(); i++)
		{
			tableTick[i] = 'O';
		}
	}
	cout << "------------------------RESET STATUS TABLE-------------------------" << endl;
	cout << endl;
	cout << "  Table number: ";
	for (auto temp : tableTick)
	{
		cout << "|" << temp.first;
		if (temp.first == Manager.getTable())
		{
			cout << "|" << endl;
		}
	}
	cout << "  Status      : ";
	for (auto temp : tableTick)
	{
		if (temp.first <= 10)
		{
			cout << "|" << temp.second;
			if (temp.first == Manager.getTable())
			{
				cout << " |" << endl;
			}
		}
		else
		{
			cout << " |" << temp.second;
			if (temp.first == Manager.getTable())
			{
				cout << " |";
			}
		}
	}

	cout << endl;
	cout << endl;

	do
	{
		cout << "--> Enter the number of desks to reset: ";
		cin >> table;
		if (cin.fail())
		{
			cout << "Can't find the table. Please try again!" << endl;
			cin.clear();
			cin.ignore();
			table = Manager.getTable() + 1;
		}
		else if (table < 1 || table > Manager.getTable())
		{
			cout << "Can't find the table, Please try again!" << endl;
		}
	} while (table < 1 || table > Manager.getTable());
	tableTick[table] = 'O';
	cout << endl;
	cout << "Success!" << endl;
	cout << endl;
	cout << "1. Keep reseting status of table" << endl;
	cout << "0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(0, 1);
	switchTab(currentPos, select);
}
employee Employee;

/*
 * Function: clearScreen function
 * Description: Clear terminal screen
 */
void clearScreen()
{
	cout << "\033c";
}

/*
 * Function: run function
 * Description: Start interface
 */
void run()
{
	clearScreen();
	currentPos = 0;
	cout << "-------------------------------ORDER-------------------------------" << endl;
	cout << endl;
	cout << "  1. Manager" << endl;
	cout << "  2. Employee" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;
	int select = choice(1, 2);
	switchTab(currentPos, select);
}

/*
 * Function: switchTab
 * Description: This function is used to switch interfaces.
 * Input:
 *   currentTab - Current interface
 *   switTab - Interface you want to move to
 */
void switchTab(int currentTab, int switTab)
{
	switch (currentTab)
	{
	case 1:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Manager.addItem();
			break;
		case 2:
			clearScreen();
			Manager.editItem();
			break;
		case 3:
			clearScreen();
			Manager.removeItem();
			break;
		case 4:
			clearScreen();
			Manager.listItems();
			break;
		case 5:
			clearScreen();
			Manager.setTable();
			break;
		default:
			clearScreen();
			run();
			break;
		}
		break;
	case 2:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Manager.addItem();
			break;
		default:
			clearScreen();
			Manager.managerHome();
			break;
		}
		break;
	case 3:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Manager.editItem();
			break;
		default:
			clearScreen();
			Manager.managerHome();
			;
			break;
		}
		break;
	case 4:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Manager.removeItem();
			break;
		default:
			Manager.managerHome();
			break;
		}
		break;
	case 5:
		switch (switTab)
		{
		case 0:
			clearScreen();
			Manager.managerHome();
			break;
		}
		break;
	case 6:
		switch (switTab)
		{
		case 0:
			clearScreen();
			Manager.managerHome();
			break;
		}
		break;
	case 7:
		switch (switTab)
		{
		case 0:
			clearScreen();
			Employee.resetTable();
			break;
		default:
			clearScreen();
			Employee.employeeMenu();
			break;
		}
		break;
	case 8:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Employee.addItem();
			break;
		case 2:
			clearScreen();
			Employee.editItem();
			break;
		case 3:
			clearScreen();
			Employee.removeItem();
			break;
		case 4:
			clearScreen();
			Employee.listItems();
			break;
		case 5:
			clearScreen();
			Employee.payments();
			break;
		default:
			clearScreen();
			Employee.employeeHome();
			break;
		}
		break;
	case 9:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Employee.addItem();
			break;
		default:
			clearScreen();
			Employee.employeeMenu();
			break;
		}
		break;
	case 10:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Employee.editItem();
			break;
		default:
			clearScreen();
			Employee.employeeMenu();
			break;
		}
		break;
	case 11:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Employee.removeItem();
			break;
		default:
			clearScreen();
			Employee.employeeMenu();
			break;
		}
		break;
	case 12:
		switch (switTab)
		{
		case 0:
			clearScreen();
			Employee.employeeMenu();
			break;
		}
		break;
	case 13:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Employee.dataSave();
			break;
		default:
			clearScreen();
			Employee.employeeMenu();
			break;
		}
		break;
	case 14:
		switch (switTab)
		{
		case 0:
			clearScreen();
			Employee.employeeHome();
			break;
		}
		break;
	case 15:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Employee.resetTable();
			break;
		default:
			clearScreen();
			Employee.employeeHome();
			break;
		}
		break;
	default:
		switch (switTab)
		{
		case 1:
			clearScreen();
			Manager.managerHome();
			break;
		default:
			clearScreen();
			Employee.employeeHome();
			break;
		}
		break;
	}
}

/*
 * Function: choice function
 * Description: This function is used to handle selection.
 * Input:
 *   start - the first choose
 *   end - final choice
 * Output:
 *   return the selected value
 */
int choice(int start, int end)
{
	int choice;
	bool flag = false;
	do
	{
		flag = false;
		cout << "--> Enter your choice: ";
		cin >> choice;
		if (cin.fail())
		{
			cout << "Invalid choice. Please try again!" << endl;
			flag = true;
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		else if (choice < start || choice > end)
		{
			cout << "Invalid choice. Please try again!" << endl;
			flag = true;
		}
	} while (flag);
	return choice;
}