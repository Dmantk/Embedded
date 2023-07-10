/*
* File: student.cpp
* Author: Duong Minh An
* Date: 24/06/2023
* Description: This's an example about create a program to manage students
*/

#include "students.h"

int main() {
	menu sv;
	sv.addStudent();
	sv.addStudent();
	sv.addStudent();
	sv.sortByAvg();
	sv.sortByName();
	sv.showList();
	/*sv.updateInfoStudentByID();
	sv.showList();
	sv.delStudentByID();
	sv.showList();
	sv.searchStudentByName();*/
    return 0;
}
