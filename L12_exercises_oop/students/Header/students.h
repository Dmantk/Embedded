#ifndef __STUDENTS_H__
#define __STUDENTS_H__

#include "students.h"
#include <iostream>
#include <string>
#include <cmath>
#include <list>

using namespace std;

bool checkName(const string& name);

enum typeGender {
    MALE,
    FEMALE
};

enum typeRank {
    EXCELLENT,
    GOOD,
    AVERAGE,
    POOR
};

class students {
private:
    uint8_t id;
    string name;
    typeGender gender;
    uint8_t age;
    float mathScores;
    float physicScores;
    float chemistryScores;
    typeRank rank;
public:
    students(string Name, typeGender Gender, uint8_t Age, float MathScores,
        float PhysicScores, float ChemistryScores);
	void setName(string Name);
    void setGender(typeGender Gender);
    void setAge(uint8_t Age);
    void setMathScores(float MathScores);
    void setPhysicScores(float PhysicScores);
    void setChemistryScores(float ChemistryScores);
	uint8_t getId();
    string getName();
    typeGender getGender();
    uint8_t getAge();
    float getMathScores();
    float getPhysicScores();
    float getChemistryScores();
    float getAvgScores();
    typeRank getRank();
};

class menu {
	private:
		string name;
		typeGender gender;
    	int age;
    	float mathScores;
		float physicScores;
		float chemistryScores;
		typeRank rank;
		list<students> database;
	public:
		void addStudent();
		void updateInfoStudentByID();
		void delStudentByID();
		void searchStudentByName();
		void sortByAvg();
		void sortByName();
		void showList();
};




#endif