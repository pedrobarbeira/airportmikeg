//Created by Pedro Barbeira
#include "flight.h"

/**Flight*/
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

std::vector<Flight*> AirportFlightList::getFlightsTo(Airport* a) const {
    std::vector<Flight*> ret;
    iteratorBST<FlightPointer> it = outFlights.begin();
    while (it != outFlights.end()) {
        if((**it).getDestination()->airport == a)
            ret.push_back((*it).getPointer());
    }
    return ret;
}

std::vector<Flight*> AirportFlightList::getFlightsTo(Airport* a, Date* min) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = outFlights.begin();
    while (it != outFlights.end()) {
        if((**it).getDestination()->airport == a && min <= (**it).getDestination()->time)
            ret.push_back((*it).getPointer());
    }
    return ret;
}

std::vector<Flight*> AirportFlightList::getFlightsTo(Airport* a, Date* min, Date* max) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = outFlights.begin();
    while (it != outFlights.end()) {
        Time* temp = (**it).getDestination()->time;
        if((**it).getDestination()->airport == a && min <= temp && temp <= max)
            ret.push_back((*it).getPointer());
        delete temp;
    }
    return ret;
}

std::vector<Flight*> AirportFlightList::getFlightsFrom(Airport* a) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = inFlights.begin();
    while (it != inFlights.end()) {
        if((**it).getOrigin()->airport == a)
            ret.push_back((*it).getPointer());
    }
    return ret;
}

std::vector<Flight*> AirportFlightList::getFlightsFrom(Airport* a, Date* min) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = inFlights.begin();
    while (it != inFlights.end()) {
        if((**it).getOrigin()->airport == a && min <= (**it).getOrigin()->time)
            ret.push_back((*it).getPointer());
    }
    return ret;
}

std::vector<Flight*> AirportFlightList::getFlightsFrom(Airport* a, Date* min, Date* max) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = inFlights.begin();
    while (it != inFlights.end()) {
        Time* temp = (**it).getOrigin()->time;
        if((**it).getOrigin()->airport == a && min <= temp && temp <= max)
            ret.push_back((*it).getPointer());
        delete temp;
    }
    return ret;
}
