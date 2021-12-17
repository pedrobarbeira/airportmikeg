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
    std::string getId() const{
        return flightID;};
    TimePlace* getOrigin() const{
        return origin;};
    TimePlace* getDestination() const{
        return destination;};
    Plane* getPlane() const{
        return plane;};
    /**Setters*/
    void defineId();
    void setOrigin(TimePlace* a){
        origin = a;};
    void setDestination(TimePlace* a){
        destination = a;};
    void setPrice(uint16_t f, uint16_t b, uint16_t e);
    void setPlane(Plane* p){
        plane = p;};
    /**Print*/
    void print(std::ostream& out) const;
    bool operator==(const Flight& rhs){
        return flightID == rhs.flightID;
    }
    bool operator<(const Flight& rhs) const{
        return flightID < rhs.flightID;
    }
};


#endif //MAIN_CPP_FLIGHT_H
