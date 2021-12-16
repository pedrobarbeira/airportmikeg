//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_VOYAGE_H
#define AIPORTMIKEG_VOYAGE_H

#include "pointer.h"
#include "../src/date.h"
#include <vector>
#include <list>


class Connection{
    Flight* in;
    Flight* out;
public:
    explicit Connection(Flight* i = nullptr, Flight* o = nullptr);
    ~Connection();
    Flight* getIn() const{
        return in;};
    Flight* getOut() const{
        return out;};
};

class Voyage{
    std::string voyageId;
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
    TimePlace* getOrigin() const{
        return route.front()->getOrigin();};
    TimePlace* getDestination() const{
        return route.back()->getDestination();};
    std::string getId() const{
        return voyageId;
    }
    /**Setters*/
    void setTickets(std::vector<Ticket*> t){
        tickets = t;};
    void setRoute(std::list<Flight*> r){
        route = std::move(r);};
    /**Adders*/
    bool addTicket(Ticket* t);
    bool addFlight(Flight* f);
    bool addConnection(Connection* c); //gotta finish this one
    void printRoute(std::ostream& out) const;
    bool operator==(const Voyage& rhs) const{
        return voyageId == rhs.voyageId;
    }
    bool operator<(const Voyage& rhs) const{
        return voyageId < rhs.voyageId;
    }

};

class VoyagePointer : public BSTPointer<Voyage>{
public:
    explicit VoyagePointer(Voyage* v = nullptr){
        pointer = v;
    }
    bool operator==(std::string id) const{
        return pointer->getId() == id;
    }
};

class InvalidConnection{
    std::string error;
public:
    InvalidConnection():error("Invalid Connection"){};
    void print(std::ostream& out) const{
        out << error << '\n';};
};


#endif //AIPORTMIKEG_VOYAGE_H
