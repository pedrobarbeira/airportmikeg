
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
    int getNumber();
    string getID();
    Passenger* getOwner() const;

    void setOwner(Passenger* voyage3);

};


#endif //MIKEGAIRLINES_TICKET_H
