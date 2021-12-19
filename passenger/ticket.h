
#ifndef MIKEGAIRLINES_TICKET_H
#define MIKEGAIRLINES_TICKET_H
#include <iostream>
#include "flight.h"
#include "passenger.h"
using namespace std;

class Ticket {
    string ticketID;
    Flight* flight;
    Seat* seat;
    vector<Luggage*> luggage;
    Passenger* owner;
public:
    explicit Ticket(Flight* f = nullptr, Seat* s= nullptr);
    Ticket(std::string id) : ticketID(std::move(id)){}
    string getID() const;
    std::string getFlightId() const{
        return flight->getId();
    }
    std::vector<Luggage*> getLuggage() const{
        return luggage;
    }
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
