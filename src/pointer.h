//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_POINTER_H
#define MAIN_CPP_POINTER_H

#include "ticket.h"
#include "user.h"

class TicketPointer : public BSTPointer<Ticket>{
public:
    explicit TicketPointer(Ticket* t){
        pointer = t;
    }
    bool operator==(const std::string& id) const{
        return pointer->getID() == id;
    }
};

/**
 * Encapsulation class for pointers to Plane objects.
 * Used to store Plane pointers in the Data BSTs
 */
class PlanePointer : public BSTPointer<Plane>{
public:
    explicit PlanePointer(Plane* p = nullptr){
        pointer = p;
    }
    bool operator==(std::string p) const{
        return pointer->plate == p;
    }
};

/**
 * Encapsulation class for pointers to FLight objects.
 * Used to store Flight pointers in the Data BSTs
 */
class FlightPointer : public BSTPointer<Flight>{
    BST<TicketPointer> tickets;
public:
    explicit FlightPointer(Flight* f = nullptr) : tickets(TicketPointer(nullptr)) {
        pointer = f;
    }
    bool operator==(const std::string& id) const{
        return pointer->flightID == id;
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
    bool operator==(const std::string& id) const{
        return (*pointer).getidCode() == id;
    }
};

class ClientPointer : public BSTPointer<Client>{
public:
    explicit ClientPointer(Client* u = nullptr){
        pointer = u;
    }
    bool operator==(std::string u) const{
        return (*pointer).getUser() == u;
    }
};

class CompanyPointer : public BSTPointer<Company>{
public:
    explicit CompanyPointer(Company* u = nullptr){
        pointer = u;
    }
    bool operator==(std::string u) const{
        return (*pointer).getUser() == u;
    }
};

#endif //MAIN_CPP_POINTER_H
