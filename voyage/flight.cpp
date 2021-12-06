//Created by Pedro Barbeira
#include "flight.h"

/**Flight*/
Flight::~Flight(){
    delete origin;
    delete destination;
    delete departure;
    delete arrival;
}

void Flight::print(ostream& out) const{
    out << setw(10) << left << setfill(' ') << flightID
        << setw(9) << left << origin->getidCode()
        << setw(10) << left << destination->getidCode();
    //finish with airport and plane
    std::cout << '\n';
}
