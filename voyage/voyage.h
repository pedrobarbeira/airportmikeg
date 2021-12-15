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

//Shift this and add Flight* flight ticket
/**
 * Encapsulatin class for Flights and Tickets
 * Stores the Flight and the tickets associated with it
 */
class FlightTicket{
    Flight* flight;
    //add ticket BST
public:
    explicit FlightTicket(Flight* f = nullptr) : flight(f){}; //addticket
    Flight* getFlight() const{
        return flight;
    }
};

class Connection{
    FlightTicket* in;
    FlightTicket* out;
public:
    explicit Connection(Flight* i = nullptr, Flight* o = nullptr);
    ~Connection();
    FlightTicket* getIn() const{
        return in;};
    FlightTicket* getOut() const{
        return out;};
};

class Voyage{
    std::string voyageId;
    std::vector<Ticket*> tickets;
    std::list<FlightTicket*> route;
public:
    /**Constructor*/
    Voyage(Flight* f){
        //tickets.clear();
        route.push_back(new FlightTicket(f));
    }
    ~Voyage();
    /**Getters*/
    std::vector<Ticket*> getTickets() const{
        return tickets;};
    std::list<FlightTicket*> getRoute(){
        return route;};
    TimePlace* getOrigin() const{
        return route.front()->getFlight()->getOrigin();};
    TimePlace* getDestination() const{
        return route.back()->getFlight()->getDestination();};
    std::string getId() const{
        return voyageId;
    }
    /**Setters*/
    void setTickets(std::vector<Ticket*> t){
        tickets = t;};
    void setRoute(std::list<FlightTicket*> r){
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
