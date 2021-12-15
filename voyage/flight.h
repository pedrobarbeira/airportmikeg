//Created by Pedro Barbeira
#ifndef MAIN_CPP_FLIGHT_H
#define MAIN_CPP_FLIGHT_H

#include <iostream>
#include "airport.h"
#include "../src/date.h"
#include "plane.h"

static int count = 0;

/**
 * Encapsulation struct for Airport and Time
 * Stores which airport the plane leaves/lands on and the respective date&time
 */
struct TimePlace{
    Airport* airport;
    Time* time;
};

class Flight{
    std::string flightID;
    TimePlace* origin;
    TimePlace* destination;
    Plane* plane;
    friend class FlightPointer;
public:
    /**Constructor*/
    explicit Flight(std::string id = ""){
        flightID = id;
    }
    explicit Flight(TimePlace* o = nullptr, TimePlace* d = nullptr, Plane* p = nullptr);
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

/**
 * Encapsulation class for pointers to FLight objects.
 * Used to store Flight pointers in the Data BSTs
 */
class FlightPointer : public BSTPointer<Flight>{
public:
    explicit FlightPointer(Flight* f = nullptr) {
        pointer = f;
    }
    bool operator==(const Flight* f) const{
        return f->flightID == pointer->flightID;
    }
    bool operator==(const std::string& id) const{
        return pointer->flightID == id;
    }
    bool operator<(const FlightPointer& rhs) const{
        return this->pointer->flightID < (*rhs).flightID;
    }
};

/**
 * Encapsulation class for the Airport class
 * Stores the created Airports and which flights are related to them in
 * order to avoid unnecessary searches.
 */
class AirportPointer : public BSTPointer<Airport>{
    BST<FlightPointer> inFlights;
    BST<FlightPointer> outFlights;
public:
    explicit AirportPointer(Airport* a = nullptr) :
            inFlights(FlightPointer(nullptr)), outFlights(FlightPointer(nullptr)){
        pointer = a;
    };
    bool addFlight(Flight* f);
    std::vector<Flight*> getFlightsTo(Airport* a) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min, Date* max) const;
    std::vector<Flight*> getFlightsFrom() const;
    std::vector<Flight*> getFlightsFrom(Date* min) const;
    std::vector<Flight*> getFlightsFrom(Date* min, Date* max) const;
    Flight* find(std::string id) const;
    bool addIn(Flight* f){
        FlightPointer fptr(f);
        return inFlights.insert(fptr);
    }
    bool addOut(Flight* f){
        FlightPointer fptr;
        return outFlights.insert(fptr);
    }
    //Add operator overloading to allow diffrent types of searches
    bool operator==(const AirportPointer& rhs) const{
        return (*pointer).getidCode() == (*pointer).getidCode();
    }
    bool operator<(const AirportPointer& apf) const{
        return pointer->getidCode() < apf.pointer->getidCode();
    }
};

#endif //MAIN_CPP_FLIGHT_H
