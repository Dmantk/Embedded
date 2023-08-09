#include "room.hpp"

room::room(uint8_t id, string status)
{
    ID = id;
    STATUS = status;
}
void room::setID(uint8_t updateID){
    ID = updateID;
}
void room::setStatus(string updateStatus)
{
    STATUS = updateStatus;
}
uint8_t room::getID()
{
    return ID;
}
string room::getStatus()
{
    return STATUS;
}

int main(){
    
}