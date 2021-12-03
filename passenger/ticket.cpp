#include "ticket.h"
using namespace std;

Ticket::Ticket(int number, string ticketID){
    this->number=number;
    this->ticketID=ticketID;
}

int Ticket::getNumber() const{
    return number;
}
string Ticket::getID() const{
    return ticketID;
};

Passenger* Ticket::getOwner() const {
    return owner;
}





