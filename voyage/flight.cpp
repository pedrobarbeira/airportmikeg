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

bool AirportPointer::addFlight(Flight*f){
    if(f->getDestination()->airport == pointer)
        return inFlights.insert(FlightPointer(f));
    else if(f->getOrigin()->airport == pointer)
        return outFlights.insert(FlightPointer(f));
    else return false;
}

std::vector<Flight*> AirportPointer::getFlightsTo(Airport* a) const {
    std::vector<Flight*> ret;
    iteratorBST<FlightPointer> it = outFlights.begin();
    while (it != outFlights.end()) {
        if((**it).getDestination()->airport == a)
            ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}

std::vector<Flight*> AirportPointer::getFlightsTo(Airport* a, Date* min) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = outFlights.begin();
    while (it != outFlights.end()) {
        if((**it).getDestination()->airport == a && min <= (**it).getDestination()->time)
            ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}

std::vector<Flight*> AirportPointer::getFlightsTo(Airport* a, Date* min, Date* max) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = outFlights.begin();
    Time* temp;
    while (it != outFlights.end()) {
        temp = (**it).getDestination()->time;
        if((**it).getDestination()->airport == a && min <= temp && temp <= max)
            ret.push_back((*it).getPointer());
        it++;
    }
    delete temp;
    return ret;
}

std::vector<Flight*> AirportPointer::getFlightsFrom() const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = inFlights.begin();
    while (it != inFlights.end()) {
            ret.push_back((*it).getPointer());
            it++;
    }
    return ret;
}

std::vector<Flight*> AirportPointer::getFlightsFrom(Date* min) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = inFlights.begin();
    while (it != inFlights.end()) {
        if(min <= (**it).getOrigin()->time)
            ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}

std::vector<Flight*> AirportPointer::getFlightsFrom(Date* min, Date* max) const {
    std::vector<Flight *> ret;
    iteratorBST<FlightPointer> it = inFlights.begin();
    Time* temp;
    while (it != inFlights.end()) {
        temp = (**it).getOrigin()->time;
        if(min <= temp && temp <= max)
            ret.push_back((*it).getPointer());
        it++;
    }
    delete temp;
    return ret;
}

Flight* AirportPointer::find(std::string id) const{
    Flight* find;
    find = inFlights.find(FlightPointer(new Flight(id))).getPointer();
    if(find == nullptr)
        find = outFlights.find(FlightPointer(new Flight(id))).getPointer();
    return find;
}
