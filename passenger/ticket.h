
#ifndef MIKEGAIRLINES_TICKET_H
#define MIKEGAIRLINES_TICKET_H
#include <iostream>

class Ticket {
    int number;
    class Voyage* origin;
    class Voyage* destination;
    class Passenger* owner;


public:
    Ticket(int number);
    int getNumber();

};
#endif //MIKEGAIRLINES_TICKET_H

//lugar: *Voo

//origem: *Voo
//destino: *Voo

//lugar: Lugar*