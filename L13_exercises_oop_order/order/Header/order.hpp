/*
 * File: order.hpp
 * Author: Duong Minh An
 * Date: 08/07/2023
 * Description: This's an example about create an order interface for managers and employees
 */
#ifndef __ORDER_HPP__
#define __ORDER_HPP__

#include <iostream>

typedef enum
{
	MANAGER = 1,
	EMPLOYEE
} startMenu;

/*
 * Function: choice function
 * Description: This function is used to handle selection.
 * Input:
 *   start - the first choose
 *   end - the final choice
 * Output:
 *   return the selected value
 */
uint8_t choice(uint8_t start, uint8_t end);

/*
 * Function: run function
 * Description: Start interface
 */
void run();

#endif