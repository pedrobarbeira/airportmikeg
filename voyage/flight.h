//Created by Pedro Barbeira
#ifndef MAIN_CPP_FLIGHT_H
#define MAIN_CPP_FLIGHT_H

#include <iostream>
#include "airport.h"
#include "../src/date.h"
#include "plane.h"

class Flight{
    std::string flightID;
    Airport* origin;
    Airport* destination;
    Plane* plane;
    Time* departure;
    Time* arrival;
public:
    /**Constructor*/
    Flight(Airport* o = nullptr, Airport* d = nullptr, Plane* p = nullptr, Time* dep = nullptr, Time* arr = nullptr):
            origin(o), destination(d), plane(p), departure(dep), arrival(arr){
        flightID = origin->getidCode() + destination->getidCode();
    }
    ~Flight();
    /**Getters*/
    std::string getID() const{
        return flightID;};
    Time* getDeparture() const{
        return departure;};
    Time* getArrival() const{
        return arrival;};
    Airport* getOrigin() const{
        return origin;};
    Airport* getDestination() const{
        return destination;};
    Plane* getPlane() const{
        return plane;};
    /**Setters*/
    void setId(std::string id){
        flightID = id;};
    void setDeparture(Time* d){
        departure = d;};
    void setArrival(Time* d){
        arrival = d;};
    void setOrigin(Airport* a){
        origin = a;};
    void setDestination(Airport* a){
        destination = a;};
    void setPlane(Plane* p){
        plane = p;};
    /**Print*/
    void print(std::ostream& out) const;

};


#endif //MAIN_CPP_FLIGHT_H
