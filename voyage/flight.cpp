//Created by Pedro Barbeira
#include "flight.h"

/**Flight*/
Flight::Flight(TimePlace* o, TimePlace* d, Plane* p):
        origin(o), destination(d), plane(p){
    count++;
    std::stringstream ss;
    ss << "MG" << std::setw(3) << std::setfill('0') << count;
    flightID = ss.str();
}

Flight::~Flight(){
    delete origin;
    delete destination;
}

bool Flight::operator<(const Flight& rhs) const{
    return flightID < rhs.flightID;
}

void Flight::print(ostream& out) const{
    out << setw(10) << left << setfill(' ') << flightID
        << setw(9) << left << origin->airport->getidCode()
        << setw(10) << left << destination->airport->getidCode();
    //finish with airport and plane
    std::cout << '\n';
}


