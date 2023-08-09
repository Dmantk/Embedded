#ifndef __MANAGER_HPP__
#define __MANAGER_HPP__

#include <map>
#include <room.hpp>
#include <iostream>

class manager
{
private:
    typedef enum
    {
        BOOKER = 1,
        VACANT,
        CLEARNING
    } roomStatus;
    map<uint8_t, room> DATABASEOFROOM;

public:
    void addRoom(uint8_t id);
    void showRoom();
    map<uint8_t, room> getDatabaseRoom();
};

#endif