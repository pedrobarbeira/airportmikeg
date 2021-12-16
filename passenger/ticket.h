
#ifndef MIKEGAIRLINES_TICKET_H
#define MIKEGAIRLINES_TICKET_H
#include <iostream>
#include "flight.h"
#include "passenger.h"
using namespace std;

class Ticket {
    string ticketID;
    Seat* seat;
    vector<Luggage*> luggage;
    Passenger* owner;
public:
    explicit Ticket(Seat* s= nullptr);
    string getID() const;
    Passenger* getOwner() const;
    Seat* getSeat() const;

    void setOwner(Passenger* voyage3){owner=voyage3;}
    void setTID(int ti){ticketID=ti;}

    void addluggage(Luggage *l);
    bool operator==(const Ticket& rhs) const{
        return ticketID == rhs.ticketID;
    }
    bool operator<(const Ticket& rhs) const{
        return ticketID < rhs.ticketID;
    }
};


#endif //MIKEGAIRLINES_TICKET_H
