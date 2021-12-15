#include "ticket.h"
using namespace std;

Ticket::Ticket(int ticketID){
    this->ticketID=ticketID;
}


int Ticket::getID() const{
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



