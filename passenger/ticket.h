
#ifndef MIKEGAIRLINES_TICKET_H
#define MIKEGAIRLINES_TICKET_H
#include <iostream>
#include "flight.h"
#include "passenger.h"
using namespace std;

class Ticket {
    int ticketID;
    Seat* seat;
    vector<Luggage*> luggage;
    Passenger* owner;
public:
    Ticket(int ticketID);
    int getID() const;
    Passenger* getOwner() const;
    Seat* getSeat() const;

    void setOwner(Passenger* voyage3){owner=voyage3;}
    void setTID(int ti){ticketID=ti;}

    void addluggage(Luggage *l);

};


#endif //MIKEGAIRLINES_TICKET_H
