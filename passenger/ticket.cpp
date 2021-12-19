#include "ticket.h"
using namespace std;

Ticket::Ticket(Flight* f, Seat* s){
    int ticketNum = f->getPlane()->getCapacity() - f->getPlane()->freeSeatNum() + 1;
    ticketID = f->getId() + to_string(ticketNum);
    this->seat=s;
    flight = f;
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



