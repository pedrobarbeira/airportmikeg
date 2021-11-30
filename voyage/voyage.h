//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_VOYAGE_H
#define AIPORTMIKEG_VOYAGE_H

#include "plane.h"
#include "airport.h"
#include "../date.h"
#include <vector>
#include <list>

class Flight;

class Error{
    std::string error;
public:
    Error(std::string e):error(e){};
    void print(std::ostream& out) const{
        out << error << '\n';};
};

class Flight{
    std::string flightID;
    Airport* origin;
    Airport* destination;
    Plane* plane;
    Time* departure;
    Time* arrival;
public:
    /**Constructor*/
    Flight(std::string id = "", Airport* o = nullptr, Airport* d = nullptr, Plane* p = nullptr, Time* dep = nullptr, Time* arr = nullptr):
        flightID(std::move(id)), origin(o), destination(d), plane(p), departure(dep), arrival(arr){
    }
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

class Connection{  //Lets say we have porto-barcelona and want to insert a lisbon connection
    Flight* in;     //We add porto-lisbon here
    Flight* out;    //We add lisbon-barcelona here
public:
    Connection(Flight* i = nullptr, Flight* o = nullptr){
        if(i->getDestination() == o->getOrigin()) {
            in = i;
            out = o;
        }
        else throw Error("Invalid Connection\n");
    }
    Flight* getIn() const{
        return in;};
    Flight* getOut() const{
        return out;};
};

class Voyage{
    //std::vector<Ticket*> tickets;
    std::list<Flight*> route;
public:
    /**Constructor*/
    Voyage(Flight* f){
        //tickets.clear();
        route.push_back(f);
    }
    /**Getters*/
    /*std::vector<Ticket*> getTickets() const{
        return tickets;};
    */
    std::list<Flight*> getRoute(){
        return route;};
    Airport* getOrigin() const{
        return route.front()->getOrigin();};
    Airport* getDestination() const{
        return route.back()->getDestination();};
    /**Setters*/
    /*void setTrickets(std::list<Ticket*> t){
        tickets = t;};*/
    void setRoute(std::list<Flight*> r){
        route = std::move(r);};
    /**Adders*/
    //bool addTicket(Ticket* t);
    bool addConnection(Connection& c); //gotta finish this one
    void printRoute(std::ostream& out) const;

};

#endif //AIPORTMIKEG_VOYAGE_H
