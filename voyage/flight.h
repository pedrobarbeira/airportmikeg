//Created by Pedro Barbeira
#ifndef MAIN_CPP_FLIGHT_H
#define MAIN_CPP_FLIGHT_H

#include <iostream>
#include "airport.h"
#include "../src/date.h"
#include "plane.h"
#include "bst.h"

/**
 * Encapsulation struct for Airport and Time
 * Stores which airport the plane leaves/lands on and the respective date&time
 */
struct TimePlace{
    Airport* airport;
    Time* time;
};

class Flight{
    //Switch Aiport and Time for encapsulation class
    std::string flightID;
    TimePlace* origin;
    TimePlace* destination;
    Plane* plane;
public:
    /**Constructor*/
    Flight(TimePlace* o = nullptr, TimePlace* d = nullptr, Plane* p = nullptr):
            origin(o), destination(d), plane(p){
        flightID = origin->airport->getidCode() + destination->airport->getidCode();
    }
    ~Flight();
    /**Getters*/
    std::string getID() const{
        return flightID;};
    TimePlace* getOrigin() const{
        return origin;};
    TimePlace* getDestination() const{
        return destination;};
    Plane* getPlane() const{
        return plane;};
    /**Setters*/
    void setId(std::string id){
        flightID = id;};
    void setOrigin(TimePlace* a){
        origin = a;};
    void setDestination(TimePlace* a){
        destination = a;};
    void setPlane(Plane* p){
        plane = p;};
    /**Print*/
    void print(std::ostream& out) const;
    bool operator<(const Flight& rhs) const;

};

class FlightPointer : public BSTPointer<Flight>{
public:
    explicit FlightPointer(Flight* f = nullptr){
        pointer = f;
    }
};

/**
 * Stores the created Airports and which flights are related to them
 */
class AirportFlightList{
    Airport* airport;
    BST<FlightPointer> inFlights;
    BST<FlightPointer> outFlights;
public:
    explicit AirportFlightList(Airport* a = nullptr) :
            airport(a), inFlights(FlightPointer()), outFlights(FlightPointer()){};
    Airport* getAirport() const{
        return airport;
    }
    std::vector<Flight*> getFlightsTo(Airport* a) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min, Date* max) const;
    std::vector<Flight*> getFlightsFrom(Airport* a) const;
    std::vector<Flight*> getFlightsFrom(Airport* a, Date* min) const;
    std::vector<Flight*> getFlightsFrom(Airport* a, Date* min, Date* max) const;
    Flight* find(std::string id) const;
    bool addIn(Flight* f){
        return inFlights.insert(FlightPointer(f));
    }
    bool addOut(Flight* f){
        return outFlights.insert(FlightPointer(f));
    }
    //Add operator overloading to allow diffrent types of searches
};

#endif //MAIN_CPP_FLIGHT_H
