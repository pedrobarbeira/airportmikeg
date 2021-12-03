
#ifndef MIKEGAIRLINES_TICKET_H
#define MIKEGAIRLINES_TICKET_H
#include <iostream>
#include "voyage.h"
#include "passenger.h"

class Ticket {
    int number;
    Voyage* origin;
    Voyage* destination;
    Passenger* owner;


public:
    Ticket(int number);
    int getNumber();
    Voyage* getOrigin() const;
    Voyage* getDestination() const;
    Passenger* getOwner() const;
    void setOrigin(Voyage* voyage);
    void setDestination(Voyage* voyage2);
    void setOwner(Passenger* voyage3);

};


#endif //MIKEGAIRLINES_TICKET_H
