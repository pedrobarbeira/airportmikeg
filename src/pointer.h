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
    bool operator==(const std::string& p) const{
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
    /**
     * Constructor for FlightPointer. Receives a pointer to a Flight object
     * and stores it in the pointer attribute
     * @param f pointer to a Flight object
     */
    explicit FlightPointer(Flight* f = nullptr) : tickets(TicketPointer(nullptr)) {
        BST<TicketPointer> t(TicketPointer(nullptr));
        tickets = t;
        pointer = f;
    }
    bool operator==(const FlightPointer& rhs) const{
        return pointer->getId() == rhs.pointer->getId();
    }
    /**
     * Returns a vector with pointers to all the Tickets stored in the
     * tickets BST
     * @return the vector with the Tickets
     */
    std::vector<Ticket*> getTickets() const;

    /**
     * Returns a vector with all the TicketPointers stored in the tickets BST
     * @return the vector with the TicketPointers
     */
    std::vector<TicketPointer> getTicketsPointer() const;

    /**
     * Getter for the tickets BST
     * @return the tickets BST
     */
    BST<TicketPointer> getTicketBST() const{
        return tickets;
    }

    /**
     * Encapsulates a given Ticket object and adds it to the tickets BST
     * @param t pointer to the Ticket object
     * @return true upon success, false otherwise
     */
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
    /**
     * Constructor for the AirportPointer class. Receives an Airport and
     * encapsulates it
     * @param a pointer to an Airport
     */
    explicit AirportPointer(Airport* a = nullptr) :
            inFlights(FlightPointer(nullptr)), outFlights(FlightPointer(nullptr)){
        BST<FlightPointer> in(FlightPointer(nullptr));
        inFlights = in;
        BST<FlightPointer> out(FlightPointer(nullptr));
        outFlights = out;
        pointer = a;
    };
    /**
     * Adds a Flight to either the inFlights or the outFlights BST, depending
     * if the Flight lands or takes off from the Airport. Checks if the Flight
     * object is related to the Airport
     * @param f pointer to the Flight that'll be added
     * @return true upon success, false otherwise
     */
    bool addFlight(Flight* f);

    /**
     * Returns a vector with all the Flights that take off from the airport
     * @return the vector with the Flights
     */
    std::vector<Flight*> getFlightsTo() const;

    /**
     * Returns a vector with all the Flights that go from the Airport to a
     * given target Airport
     * @param a pointer to the target Airport
     * @return the vector with said Flights
     */
    std::vector<Flight*> getFlightsTo(Airport* a) const;
    /**
     * Returns a vector with all the Flights that go from the Airport to a
     * given target Airport that depart after a given Date
     * @param a pointer to the target Airport
     * @param min pointer to the minimum Date
     * @return the vector with said Flights
     */
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min) const;

    /**
     * Returns a vector with all the Flights that go from the Airport to a
     * given target Airport that depart between two given Dates
     * @param a pointer to the target Airport
     * @param min pointer to the lower bound Date
     * @param max pointer to the upper bound Date
     * @return the vector with said Flights
     */
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min, Date* max) const;

    /**
     * Returns a vector with all the Flights that land on the Airport
     * @return the vector with said Flights
     */
    std::vector<Flight*> getFlightsFrom() const;

    /**
     * Returns a vector with all the Flights that land on the Airport after
     * a given Date
     * @param min poitner to the lower bound Date
     * @return the vector with said Flights
     */
    std::vector<Flight*> getFlightsFrom(Date* min) const;

    /**
     * Returns a vector with all the Flights that land on the Airport between
     * two given Dates
     * @param min pointer to the lower bound Date
     * @param max pointer to the upper bound Date
     * @return the vector with said Flights
     */
    std::vector<Flight*> getFlightsFrom(Date* min, Date* max) const;

    /**
     * Returns a vector with all the Flights related to the Airport, both
     * coming in and going out
     * @return the vector with said flights
     */
    std::vector<FlightPointer>getFlights() const;

    /**
     * Returns a BST with all the Flights related to the Airport, both
     * coming in and going out
     * @return the BST with said Flights
     */
    BST<FlightPointer> getFlightBST() const{
        return inFlights;
    }

    /**
     * Returns a vector with all the FlightPointers stored in both the
     * inFlights and outFlights BST's
     * @return the vector with said FlightPointers
     */
    std::vector<FlightPointer> getFlightPointers() const;

    /**
     * Searches the inFlights and outFlights BSTs for the Flight which
     * has a given Id
     * @param id the target Id
     * @return the result of the sarch
     */
    FlightPointer find(std::string id) const;

    /**
     * Adds a Flight to the inFlights BST
     * @param f the Flight to be added
     * @return true upon success, false otherwise
     */
    bool addIn(Flight* f){
        FlightPointer fptr(f);
        return inFlights.insert(fptr);
    }

    /**
     * Adds a Flight to the outFlights BST
     * @param f the Flight to be added
     * @return true upon success. false otherwise
     */
    bool addOut(Flight* f){
        FlightPointer fptr(f);
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
    /**
     * Constructor for ClientPointer class. Receives a Client object
     * and encapsulates it
     * @param u pointer to the Client object
     */
    explicit ClientPointer(Client* u = nullptr){
        pointer = u;
    }
};

/**
 * Encapsulation class for the Company class
 */
class CompanyPointer : public BSTPointer<Company>{
public:
    /**
     * Constructor for the CompanyPointer. Receives a Company object
     * and encapsulates it
     * @param u pointer to the Company object
     */
    explicit CompanyPointer(Company* u = nullptr){
        pointer = u;
    }
};

class StaffPointer : public BSTPointer<Staff>{
    Airport *airport = nullptr;
public:
    /**
     * Constructor for the StaffPointer class. Reiceives a Staff object
     * and encapsulates it
     * @param s pointer to the Staff object
     */
    explicit StaffPointer(Staff* s = nullptr){
        pointer = s;
    }
};

class ServicePointer : public BSTPointer<ServiceTicket>{
public:
    /**
     * Constructor for the ServicePointer class. Receives a ServiceTicket
     * object and encapsulates it
     * @param s pointer to the ServiceTicket object
     */
    explicit ServicePointer(ServiceTicket* s = nullptr){
        pointer = s;
    }
};


#endif //MAIN_CPP_POINTER_H
