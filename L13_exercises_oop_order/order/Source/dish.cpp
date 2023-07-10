/*
 * File: dish.cpp
 * Author: Duong Minh An
 * Date: 09/07/2023
 * Description: Used to create a dish list include ID, name, price
 */
#include "dish.hpp"
#include "order.hpp"

/*
 * Function: dish(string Name, int Price)
 * Description: This function will create dish objects including auto increment ID, name and price of the dish
 * Input:
 *   ID - the dish ID
 *   NAME - the dish name
 *   PRICE - the dish price
 */
dish::dish(string Name, int Price)
{
    static int Id = 100;
    ID = Id;
    Id++;
    NAME = Name;
    PRICE = Price;
}

/*
 * Function: setName(string newName)
 * Description: This function is used to change the name of the dish in the list
 * Input:
 *   newName - the new dish name
 */
void dish::setName(string newName)
{
    NAME = newName;
}

/*
 * Function: setPrice(int newPrice)
 * Description: This function is used to change the price of the dish in the list
 * Input:
 *   newName - the new dish price
 */
void dish::setPrice(int newPrice)
{
    PRICE = newPrice;
}

/*
 * Function: getId()
 * Description: This function will output the id of the dish
 * Output:
 *   return ID - return the dish id
 */
int dish::getId()
{
    return ID;
}

/*
 * Function: getName()
 * Description: This function will output the name of the dish
 * Output:
 *   return NAME - return the dish name
 */
string dish::getName()
{
    return NAME;
}

/*
 * Function: getPrice()
 * Description: This function will output the price of the dish
 * Output:
 *   return PRICE - return the dish price
 */
int dish::getPrice()
{
    return PRICE;
}