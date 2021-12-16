//Created by Pedro Barbeira
#include "flight.h"

/**Flight*/
Flight::Flight(TimePlace* o, TimePlace* d, Plane* p):
        origin(o), destination(d), plane(p){}

Flight::~Flight(){
    delete origin;
    delete destination;
}

void Flight::defineId(){
    count++;
    std::stringstream ss;
    ss << "MG" << std::setw(3) << std::setfill('0') << count;
    flightID = ss.str();
}

void Flight::setPrice(uint16_t f, uint16_t b, uint16_t e) {
    plane->setFClassPrice(f);
    plane->setBClassPrice(b);
    plane->setEClassPrice(e);
}

void Flight::print(ostream& out) const{
    out << setw(10) << left << setfill(' ') << flightID
        << setw(9) << left << origin->airport->getidCode()
        << setw(10) << left << destination->airport->getidCode();
    //finish with airport and plane
    std::cout << '\n';
}


