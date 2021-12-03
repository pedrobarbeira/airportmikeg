
#ifndef MIKEGAIRLINES_TICKET_H
#define MIKEGAIRLINES_TICKET_H
#include <iostream>
#include "flight.h"
#include "passenger.h"
using namespace std;

class Ticket {
    int number;
    string ticketID;
    Passenger* owner;


public:
    Ticket(int number, string ticketID);
    int getNumber() const;
    string getID() const;
    Passenger* getOwner() const;
    void setOwner(Passenger* voyage3){owner=voyage3;}
    void setTID(string ti){ticketID=ti;}
    void setNumber(int num){number=num;}

};


#endif //MIKEGAIRLINES_TICKET_H
