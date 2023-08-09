#include "manager.hpp"

typedef enum
{
    ADDROOM = 1,
    EDITROOM,
    REMOVEROOM,
    SHOWROOM
} managerTab;

void manager::addRoom(uint8_t id)
{
    room newroom(id, "VACANT");
    DATABASEOFROOM[id] = newroom;
}
void manager::showRoom()
{
    for (auto &temp : DATABASEOFROOM)
    {
        cout << "Room " << temp.first << ": " << temp.second << endl;
    }
}
int main()
{
    manager managerObj;
    int choose;
    cin >> choose;
    switch (managerTab(choose))
    {
    case ADDROOM:
        int id;
        cin >> id;
        managerObj.addRoom(id);
        break;
    case SHOWROOM:
        managerObj.showRoom();
        break;
    default:
        break;
    }
    return 0;
};