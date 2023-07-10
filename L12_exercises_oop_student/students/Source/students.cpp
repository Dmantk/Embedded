#include "students.h"


students::students(string Name, typeGender Gender, uint8_t Age, float MathScores, float PhysicScores, float ChemistryScores) {
    static uint8_t Id = 100;
    id = Id;
    Id++;
    name = Name;
    gender = Gender;
    age = Age;
    mathScores = MathScores;
    physicScores = PhysicScores;
    chemistryScores = ChemistryScores;
}

void students::setName(string Name) {
    name = Name;
}

void students::setGender(typeGender Gender) {
    gender = Gender;
}

void students::setAge(uint8_t Age) {
    age = Age;
}

void students::setMathScores(float MathScores) {
    mathScores = MathScores;
}

void students::setPhysicScores(float PhysicScores) {
    physicScores = PhysicScores;
}

void students::setChemistryScores(float ChemistryScores) {
    chemistryScores = ChemistryScores;
}

uint8_t students::getId() {
	return id;
	}

string students::getName() {
    return name;
}

typeGender students::getGender() {
    return gender;
}

uint8_t students::getAge() {
    return age;
}

float students::getMathScores() {
    return mathScores;
}

float students::getPhysicScores() {
    return physicScores;
}

float students::getChemistryScores() {
    return chemistryScores;
}

float students::getAvgScores() {
    return (mathScores + physicScores + chemistryScores) / 3;
}

typeRank students::getRank() {
    if (getAvgScores() >= 8.0) {
        rank = EXCELLENT;
    }
    else if (getAvgScores() >= 6.5) {
        rank = GOOD;
    }
    else if (getAvgScores() >= 5.0) {
        rank = AVERAGE;
    }
    else {
        rank = POOR;
    }
    return rank;
}


void menu::addStudent() {
	cout << "----------ADD STUDENTS TO THE LIST----------" << endl;
	do {
		cout << "Enter student's name: ";
		cin >> name;
		while (cin.get() != '\n') {
			continue;
		}
		if(name.empty() || !checkName(name)){
			cout << "Enter error name. Try again!"<<endl;
		}
	} while(name.empty() || !checkName(name));

	string genderStr;
	do {
		cout << "Enter student's gender (MALE/FEMALE): ";
		cin >> genderStr;
		while (cin.get() != '\n') {
			continue;
		}
		if(genderStr != "MALE" && genderStr != "FEMALE") {
			cout << "Enter error gender. Try again!"<<endl;
		}
	} while ( genderStr != "MALE" && genderStr != "FEMALE");
	gender = (genderStr == "MALE") ? MALE : FEMALE;

	do {
		cout << "Enter student's age (1-100): ";
		cin >> age;
		if(age <= 0 || age > 100) {
			cout << "Enter error age. Try again!" << endl;
		}
	} while (age <= 0 || age > 100);

	do {
		cout << "Enter mathScore (0-10): ";
		cin >> mathScores;
		if(mathScores <= 0.0 || mathScores > 10.0) {
			cout << "Enter error score. Try again!" << endl;
		}
	} while (mathScores <= 0.0 || mathScores > 10.0);

		do {
		cout << "Enter physicScore (0-10): ";
		cin >> physicScores;
		if(physicScores <= 0.0 || physicScores > 10.0) {
			cout << "Enter error score. Try again!" << endl;
		}
	} while (physicScores <= 0.0 || physicScores > 10.0);

		do {
		cout << "Enter chemistryScore (0-10): ";
		cin >> chemistryScores;
		if(chemistryScores <= 0.0 || chemistryScores > 10.0) {
			cout << "Enter error score. Try again!" << endl;
		}
	} while (chemistryScores <= 0.0 || chemistryScores > 10.0);

	students student(name,  gender, age, mathScores, physicScores, chemistryScores);
	database.push_back(student);
}

void menu::updateInfoStudentByID() {
    cout << "----------UPDATE INFORMATION OF STUDENT BY ID----------" << endl;
    int tempId;
    cout << "Enter ID of student: ";
    cin >> tempId;
    auto itemp = database.begin();
    while (itemp != database.end()) {
        if (tempId == itemp->getId()) {
            cout << "--->Update student information: " << tempId << endl;
            do {
                cout << "Enter student's name: ";
                getline(cin, name);
                if (name.empty() || !checkName(name)) {
                    cout << "Enter error name. Try again!" << endl;
                }
            } while (name.empty() || !checkName(name));
            itemp->setName(name);

            string genderStr;
            do {
                cout << "Enter student's gender (MALE/FEMALE): ";
                cin >> genderStr;
                cin.ignore();
                if (genderStr != "MALE" && genderStr != "FEMALE") {
                    cout << "Enter error gender. Try again!" << endl;
                }
            } while (genderStr != "MALE" && genderStr != "FEMALE");
            gender = (genderStr == "MALE") ? MALE : FEMALE;
            itemp->setGender(gender);

            do {
                cout << "Enter student's age (1-100): ";
                cin >> age;
                cin.ignore();
                if (age <= 0 || age > 100) {
                    cout << "Enter error age. Try again!" << endl;
                }
            } while (age <= 0 || age > 100);
            itemp->setAge(age);

            do {
                cout << "Enter mathScore (0-10): ";
                cin >> mathScores;
                cin.ignore();
                if (mathScores <= 0.0 || mathScores > 10.0) {
                    cout << "Enter error score. Try again!" << endl;
                }
            } while (mathScores <= 0.0 || mathScores > 10.0);
            itemp->setMathScores(mathScores);

            do {
                cout << "Enter physicScore (0-10): ";
                cin >> physicScores;
                cin.ignore();
                if (physicScores <= 0.0 || physicScores > 10.0) {
                    cout << "Enter error score. Try again!" << endl;
                }
            } while (physicScores <= 0.0 || physicScores > 10.0);
            itemp->setPhysicScores(physicScores);

            do {
                cout << "Enter chemistryScore (0-10): ";
                cin >> chemistryScores;
                cin.ignore();
                if (chemistryScores <= 0.0 || chemistryScores > 10.0) {
                    cout << "Enter error score. Try again!" << endl;
                }
            } while (chemistryScores <= 0.0 || chemistryScores > 10.0);
            itemp->setChemistryScores(chemistryScores);

            break;
        }
        ++itemp;
    }

    if (itemp == database.end()) {
        cout << "Student not found." << endl;
    }
}

void menu::delStudentByID() {
	int tempId;
	cout<<"----------DELETE STUDENT BY ID----------"<<endl;
	cout<<"Enter the student ID to delete:";
	cin>>tempId;
	cin.ignore();

    auto it = database.begin();
    while (it != database.end()) {
        if (tempId == it->getId()) {
            cout << "--->Deleting student with ID: " << tempId << endl;

            it = database.erase(it);

            cout << "Student deleted." << endl;
            return;
        }
        ++it;
    }

    cout << "Student not found." << endl;
}

void menu::searchStudentByName() {
	string tempName;
	cout<<"----------SEARCH STUDENT BY NAME----------"<<endl;
	cout<<"Enter the student name to find: ";
	cin>>tempName;
	cin.ignore();

    auto itemp = database.begin();
    while (itemp != database.end()) {
        if (tempName == itemp->getName()) {
            cout << "--->List student with name: " << tempName << endl;

			cout << "ID: " << (int)itemp->getId() << endl;
			cout << "Name: " << itemp->getName() << endl;
			cout << "Gender: " << (itemp->getGender() == MALE ? "Male" : "Female") << endl;
			cout << "Age: " << (int)itemp->getAge() << endl;
			cout << "Math Scores: " << itemp->getMathScores() << endl;
			cout << "Physic Scores: " << itemp->getPhysicScores() << endl;
			cout << "Chemistry Scores: " << itemp->getChemistryScores() << endl;
			cout << "Average Scores: " << itemp->getAvgScores() << endl;
			cout << "Rank: ";
			switch (itemp->getRank()) {
			case EXCELLENT:
				cout << "Excellent";
				break;
			case GOOD:
				cout << "Good";
				break;
			case AVERAGE:
				cout << "Average";
				break;
			case POOR:
				cout << "Poor";
				break;
			default:
				cout << "Unknown";
			}
			cout << endl;

            return;
        }
        ++itemp;
    }

    cout << "Student not found." << endl;
}

void menu::sortByAvg() {
    list<students> sortAvg;

    for (auto itemp : database) {
        bool insertFlag = false;
        for (auto itempAvg = sortAvg.begin(); itempAvg != sortAvg.end(); ++itempAvg) {
            if (itemp.getAvgScores() > itempAvg->getAvgScores()) {
                sortAvg.insert(itempAvg, itemp);
                insertFlag = true;
                break;
            }
        }

        if (!insertFlag) {
            sortAvg.push_back(itemp);
        }
    }

	cout << "----------LIST OF STUDENT SORTED BY AVERAGE----------" << endl;
	for (auto itemp : sortAvg) {
		cout << "--->ID: " << (int)itemp.getId() << endl;
		cout << "Name: " << itemp.getName() << endl;
		cout << "Gender: " << (itemp.getGender() == MALE ? "Male" : "Female") << endl;
		cout << "Age: " << (int)itemp.getAge() << endl;
		cout << "Math Scores: " << itemp.getMathScores() << endl;
		cout << "Physic Scores: " << itemp.getPhysicScores() << endl;
		cout << "Chemistry Scores: " << itemp.getChemistryScores() << endl;
		cout << "Average Scores: " << itemp.getAvgScores() << endl;
		cout << "Rank: ";
		switch (itemp.getRank()) {
		case EXCELLENT:
			cout << "Excellent";
			break;
		case GOOD:
			cout << "Good";
			break;
		case AVERAGE:
			cout << "Average";
			break;
		case POOR:
			cout << "Poor";
			break;
		default:
			cout << "Unknown";
		}
		cout << endl;
	}
	
}

void menu::sortByName() {
	list<students> sortName;

    for (auto itemp : database) {
        bool insertFlag = false;
        for (auto itempName = sortName.begin(); itempName != sortName.end(); ++itempName) {
            if (itemp.getName() < itempName->getName()) {
                sortName.insert(itempName, itemp);
                insertFlag = true;
                break;
            }
        }

        if (!insertFlag) {
            sortName.push_back(itemp);
        }
    }

	cout << "----------LIST OF STUDENT SORTED BY NAME----------" << endl;
	for (auto itemp : sortName) {
		cout << "--->ID: " << (int)itemp.getId() << endl;
		cout << "Name: " << itemp.getName() << endl;
		cout << "Gender: " << (itemp.getGender() == MALE ? "Male" : "Female") << endl;
		cout << "Age: " << (int)itemp.getAge() << endl;
		cout << "Math Scores: " << itemp.getMathScores() << endl;
		cout << "Physic Scores: " << itemp.getPhysicScores() << endl;
		cout << "Chemistry Scores: " << itemp.getChemistryScores() << endl;
		cout << "Average Scores: " << itemp.getAvgScores() << endl;
		cout << "Rank: ";
		switch (itemp.getRank()) {
		case EXCELLENT:
			cout << "Excellent";
			break;
		case GOOD:
			cout << "Good";
			break;
		case AVERAGE:
			cout << "Average";
			break;
		case POOR:
			cout << "Poor";
			break;
		default:
			cout << "Unknown";
		}
		cout << endl;
	}
}

void menu::showList() {
	cout << "----------LIST OF STUDENTS----------" << endl;
	for (auto itemp : database) {

		cout << "ID: " << (int)itemp.getId() << endl;
		cout << "Name: " << itemp.getName() << endl;
		cout << "Gender: " << (itemp.getGender() == MALE ? "Male" : "Female") << endl;
		cout << "Age: " << (int)itemp.getAge() << endl;
		cout << "Math Scores: " << itemp.getMathScores() << endl;
		cout << "Physic Scores: " << itemp.getPhysicScores() << endl;
		cout << "Chemistry Scores: " << itemp.getChemistryScores() << endl;
		cout << "Average Scores: " << itemp.getAvgScores() << endl;
		cout << "Rank: ";
		switch (itemp.getRank()) {
		case EXCELLENT:
			cout << "Excellent";
			break;
		case GOOD:
			cout << "Good";
			break;
		case AVERAGE:
			cout << "Average";
			break;
		case POOR:
			cout << "Poor";
			break;
		default:
			cout << "Unknown";
		}
		cout << endl;
	}
}

bool checkName(const string& name) {
    for (char c : name) {
        if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) {
            return false;
        }
    }
    return true;
}