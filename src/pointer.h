//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_POINTER_H
#define MAIN_CPP_POINTER_H

#include "ticket.h"
#include "user.h"

/**
 * Encapsulation class for pointers to Ticket objects.
 * Used to store Plane pointers in the Data BSTs
 */
class TicketPointer : public BSTPointer<Ticket>{
public:
    /**
     * Constructor of TikcetPointer. Receives a pointer to a Ticket object
     * and sabes it in the pointer attribute
     * @param t the Ticket object pointer
     */
    explicit TicketPointer(Ticket* t){
        pointer = t;
    }

    /**
     * Allows comparisons between TikcetPointers and strings. This is used
     * to perform comparisons between TicketPointers and Ticket Id's
     * @param id the Id to be compared with
     * @return bool if the Id is the same as of the Ticket object stores,
     * false otherwise
     */
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
   /**
    * Constructor of PlanePointer. Receives a pointer to a Plane object
    * and sabes it in the pointer attribute
    * @param t the Plane object pointer
    */
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
    bool operator==(const FlightPointer& rhs) const{
        return pointer->getId() == rhs.pointer->getId();
    }
    std::vector<Ticket*> getTickets() const;
    bool addTicket(Ticket* t){
        TicketPointer tptr(t);
        return tickets.insert(tptr);
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
    std::vector<Flight*> getFlightsTo() const;
    std::vector<Flight*> getFlightsTo(Airport* a) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min, Date* max) const;
    std::vector<Flight*> getFlightsFrom() const;
    std::vector<Flight*> getFlightsFrom(Date* min) const;
    std::vector<Flight*> getFlightsFrom(Date* min, Date* max) const;
    std::vector<FlightPointer>getFlights() const;
    BST<FlightPointer> getFlightBST() const{
        return inFlights;
    }
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
        return (*pointer) == (*pointer);
    }
    bool operator==(const AirportPointer& rhs) const{
        return (*pointer) == (*rhs.getPointer());
    }
};

/**
 * Encapsulation class for the Client class
 */
class ClientPointer : public BSTPointer<Client>{
public:
    explicit ClientPointer(Client* u = nullptr){
        pointer = u;
    }
    bool operator==(std::string u) const{
        return (*pointer).getUser() == u;
    }
};

/**
 * Encapsulation class for the Company class
 */
class CompanyPointer : public BSTPointer<Company>{
public:
    explicit CompanyPointer(Company* u = nullptr){
        pointer = u;
    }
    bool operator==(const CompanyPointer& rhs) const{
        return pointer->getUser() == rhs.pointer->getUser();
    }
};

#endif //MAIN_CPP_POINTER_H
