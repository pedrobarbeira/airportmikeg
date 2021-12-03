#include "ticket.h"

Ticket::Ticket(int number){
    this->number=number;
}

int Ticket::getNumber(){
    return number;
}
string Ticket::getID(){
    return ticketID;
};

Passenger* Ticket::getOwner() const {
    return owner;
}

void Ticket::setOwner(Passenger *voyage3) {
    owner=voyage3;
}




