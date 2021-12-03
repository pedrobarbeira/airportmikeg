#include "ticket.h"

Ticket::Ticket(int number){
    this->number=number;
}

int Ticket::getNumber(){
    return number;
}

Voyage* Ticket::getOrigin() const {
    return origin;
}

Voyage* Ticket::getDestination() const{
    return destination;
}

Passenger* Ticket::getOwner() const {
    return owner;
}

void Ticket::setOrigin(Voyage* voyage) {
    origin=voyage;
}

void Ticket::setDestination(Voyage *voyage2) {
    destination=voyage2;
}

void Ticket::setOwner(Passenger *voyage3) {
    owner=voyage3;
}




