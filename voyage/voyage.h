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
    std::list<FlightPointer> route;
public:
    /**Constructor*/
    explicit Voyage(Flight* f = nullptr){
        FlightPointer fptr(f);
        route.push_back(fptr);
    }
    explicit Voyage(std::string id) : voyageId(std::move(id)){
        route.clear();
    }
    /**Getters*/
    std::list<std::vector<Ticket*>> getTickets() const{
        std::list<std::vector<Ticket*>> ret;
        for(const auto& flight : route){
            ret.push_back(flight.getTickets());
        }
        return ret;
    };
    std::list<FlightPointer> getRoute() const{
        return route;};
    TimePlace* getOrigin() const{
        return route.front().getPointer()->getOrigin();};
    TimePlace* getDestination() const{
        return route.back().getPointer()->getDestination();};
    std::string getId() const{
        return voyageId;
    }
    /**Setters*/
    void setRoute(std::list<FlightPointer> r){
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
    bool operator==(const VoyagePointer& rhs) const{
        return pointer->getId() == rhs.pointer->getId();
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
