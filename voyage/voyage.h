//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_VOYAGE_H
#define AIPORTMIKEG_VOYAGE_H

#include "plane.h"
#include "flight.h"
#include "airport.h"
#include "ticket.h"
#include "../src/date.h"
#include <vector>
#include <list>

class Connection{
    Flight* in;
    Flight* out;
public:
    Connection(Flight* i = nullptr, Flight* o = nullptr);
    ~Connection();
    Flight* getIn() const{
        return in;};
    Flight* getOut() const{
        return out;};
};

class Voyage{
    std::vector<Ticket*> tickets;
    std::list<Flight*> route;
public:
    /**Constructor*/
    Voyage(Flight* f){
        //tickets.clear();
        route.push_back(f);
    }
    ~Voyage();
    /**Getters*/
    std::vector<Ticket*> getTickets() const{
        return tickets;};
    std::list<Flight*> getRoute(){
        return route;};
    Airport* getOrigin() const{
        return route.front()->getOrigin();};
    Airport* getDestination() const{
        return route.back()->getDestination();};
    /**Setters*/
    void setTrickets(std::vector<Ticket*> t){
        tickets = t;};
    void setRoute(std::list<Flight*> r){
        route = std::move(r);};
    /**Adders*/
    bool addTicket(Ticket* t);
    bool addFlight(Flight* f);
    bool addConnection(Connection* c); //gotta finish this one
    void printRoute(std::ostream& out) const;

};


class InvalidConnection{
    std::string error;
public:
    InvalidConnection():error("Invalid Connection"){};
    void print(std::ostream& out) const{
        out << error << '\n';};
};


#endif //AIPORTMIKEG_VOYAGE_H
