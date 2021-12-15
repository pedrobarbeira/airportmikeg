#include "ticket.h"
using namespace std;

Ticket::Ticket(int number, string ticketID){
    this->ticketID=ticketID;
}

string Ticket::getID() const{
    return ticketID;
};

Passenger* Ticket::getOwner() const {
    return owner;
}





