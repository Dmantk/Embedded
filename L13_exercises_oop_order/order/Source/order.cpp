#include "order.h"



/*
 * Function: class dish
 * Description: Used to create a dish list include ID, name, price
 */

dish::dish(string Name, int Price)
{
	static int Id = 100;
	Id++;
	ID = Id;
	NAME = Name;
	PRICE = Price;
}
void dish::setName(string newName)
{
	NAME = newName;
}
void dish::setPrice(int newPrice)
{
	PRICE = newPrice;
}
int dish::getId()
{
	return ID;
}
string dish::getName()
{
	return NAME;
}
int dish::getPrice()
{
	return PRICE;
}


/*
 * Function: class manager
 * Description: Design interfaces to add, edit, delete, display the dish list
 */

manager::manager()
{
	cout << "\033c";
	cout << "------------------------------MANAGER------------------------------" << endl;
	cout << endl;
	cout << "  1. Add dish" << endl;
	cout << "  2. Edit dish" << endl;
	cout << "  3. Remove dish" << endl;
	cout << "  4. List dish" << endl;
	cout << "  5. Set table number" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

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
	}
}
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
int manager::getNumberTable()
{
	return NUMBEROFTABLES;
}
list<dish> manager::getDishList()
{
	return DATABASE;
}
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

/*
 * Function: class employee
 * Description: Design interfaces for adding, editing, deleting, and paying for the order list
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
			if (temp.first == NUMBEROFTABLE)
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
void employee::menu()
{
	cout << "\033c";
	if (TABLE < 10)
	{
		cout << "--";
	}
	else
	{
		cout << "-";
	}
	cout << "----------------------------TABLE[" << TABLE << "]-----------------------------" << endl;
	cout << endl;
	cout << "  1. Add dish" << endl;
	cout << "  2. Edit dish" << endl;
	cout << "  3. Remove dish" << endl;
	cout << "  4. List dishes" << endl;
	cout << "  5. Payment" << endl;
	cout << "  0. Back" << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------" << endl;

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
			if (temp.first == NUMBEROFTABLE)
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
	} while (TABLE < 1 || TABLE > NUMBEROFTABLE);
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

/*
 * Function: run function
 * Description: Start interface
 */
void run()
{
	manager *Manager;
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

/*
 * Function: choice function
 * Description: This function is used to handle selection.
 * Input:
 *   start - the first choose
 *   end - final choice
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
