//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_VOYAGE_H
#define AIPORTMIKEG_VOYAGE_H

#include "pointer.h"
#include "../src/date.h"
#include <vector>
#include <list>
#include "exception.h"

static int voyageCount = 0;

class Connection{
    Flight* in;
    Flight* out;
public:
    /**
     * Constructor for Connection class. Receives two flights and makes sure
     * the dates line up. This class exists to easily extend voyages by breaking
     * one flight into two
     * @param i the first flight to be taken
     * @param o the second flight to be taken
     */
    explicit Connection(Flight* i = nullptr, Flight* o = nullptr);

    /**
     * Destructor of Connection class. Sets in and out to nullptr before deletion
     * in order to preserve the information in the system
     */
    ~Connection();

    /**
     * Getter for the first flight
     * @return the first flight
     */
    Flight* getIn() const{
        return in;};

    /**
     * Getter for the second flight
     * @return the second flight
     */
    Flight* getOut() const{
        return out;};
};

class Voyage{
    std::string voyageId;
    std::list<FlightPointer> route;
public:
    /**-----Constructors-----*/
    /**
     * Creates a voyage using a flight. Sets the voyageId by concatenating
     * the Id of the origin airport with the Id of the destination airport
     * and the voyageCount, which is incremented beforehand. Acts as a
     * default constructor if no flight parameter is given.
     * @param f the flight to be added
     */
    explicit Voyage(Flight* f = nullptr){
        if(f!=nullptr) {
            voyageCount++;
            stringstream vId;
            vId << f->getOrigin()->airport->getidCode()
                << f->getDestination()->airport->getidCode()
                << setw(2) << setfill('0') << voyageCount;
            voyageId = vId.str();
            FlightPointer fptr(f);
            route.push_back(fptr);
        }
        else{
            voyageId = "";
            route.clear();
        }
    }

    /**
     * This constructor screates a Voyage object using an Id. It's used to
     * facilitate searched in the Voyage BST
     * @param id the Id of the voyage to be found
     */
    explicit Voyage(std::string id) : voyageId(std::move(id)){
        route.clear();
    }

    /**-----Getters------*/
    /**
     * Getter for the Voyage ticket list. Iterates through the route
     * attribute, gathering the tickets in a vector, and then puts them
     * in a list
     * @return the voyage ticket list
     */
    std::list<std::vector<Ticket*>> getTickets() const{
        std::list<std::vector<Ticket*>> ret;
        for(const auto& flight : route){
            ret.push_back(flight.getTickets());
        }
        return ret;
    };

    /**
     * Getter for the attribute route
     * @return the flights of the Voyage
     */
    std::list<FlightPointer> getRoute() const{
        return route;};

    /**
     * Getter for the Voyage's Origin data - Airport and Time. Accesses
     * the first Flight of the route and returns that flight's Origin
     * @return the Voyage's origin
     */
    TimePlace* getOrigin() const{
        return route.front().getPointer()->getOrigin();};

    /**
     * Getter for the Voyage's Destination data - AIrport and Time. Accesses
     * the last Flight of the route and returns that flight's Destination
     * @return the Voyage's destination
     */
    TimePlace* getDestination() const{
        return route.back().getPointer()->getDestination();};

    /**
     * Getter for the Voyage's id
     * @return the Voyage's id
     */
    std::string getId() const{
        return voyageId;
    }
    /**-----Setters-----*/

    /**
     * Changes the Voyage route by setting the route attribute to r
     * @param r the new route
     */
    void setRoute(std::list<FlightPointer> r){
        route = std::move(r);};

    /**-----Adders-----*/
    /**
     * Adds a Flight to the Voyage. Ensures the flight connects
     * @param f the flight to be added
     * @return true upon success, false otherwise
     */
    bool addFlight(Flight* f);

    /**
     * Adds a connection to the Voyage. Ensures both flight in the connection
     * object connect
     * @param c the Connection to be added
     * @return true upon success. false otherwise
     */
    bool addConnection(Connection* c);

    /**
     * Comparison operator for Voyage objects
     * @param rhs the right side of the comparion
     * @return true if the voyages share the same Id
     */
    bool operator==(const Voyage& rhs) const{
        return voyageId == rhs.voyageId;
    }

    /**
     * Comparsion operator for Voyage objects. Ensures objects are ordered
     * by ascending Id's
     * @param rhs the right side of the comparion
     * @return true if this has a "smaller" id then rhs, false otherwise
     */
    bool operator<(const Voyage& rhs) const{
        return voyageId < rhs.voyageId;
    }

};

class VoyagePointer : public BSTPointer<Voyage>{
public:
    /**
     * Construction for VoyageId encapsulation class. Receives a pointer
     * to a Voyage object
     * @param v the Voyage object to be encapsulates
     */
    explicit VoyagePointer(Voyage* v = nullptr){
        pointer = v;
    }

    bool operator==(const VoyagePointer& rhs) const{
        return pointer->getId() == rhs.pointer->getId();
    }
};


#endif //AIPORTMIKEG_VOYAGE_H
