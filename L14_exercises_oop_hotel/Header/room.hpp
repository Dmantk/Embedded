#ifndef __ROOM_HPP__
#define __ROOM_HPP__

#include <string>

using namespace std;

class room
{
private:
    uint8_t ID;
    string STATUS;

public:
    room(uint8_t id, string status);
    void setID(uint8_t id);
    void setStatus(string updateStatus);
    uint8_t getID();
    string getStatus();
};

#endif