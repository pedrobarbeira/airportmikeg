#include "ticket.h"
using namespace std;

Ticket::Ticket(Seat* s){
    this->seat=s;
    //ticketId pode ser preciso completar
}


string Ticket::getID() const{
    return ticketID;
}

Seat* Ticket::getSeat() const {
    return seat;
}

Passenger* Ticket::getOwner() const {
    return owner;
}

void Ticket::addluggage(Luggage *l) {
    luggage.push_back(l);
}

/*bool Ticket::passengerAbleToBuy() {
    if
}
*/



