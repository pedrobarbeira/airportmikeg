//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_AIRPORT_H
#define MIKEGAIRLINES_AIRPORT_H

#include <iostream>
#include"service.h"
#include<list>
#include<queue>
#include"date.h"
#include"bst.h"

using namespace std;

static int idTransport;


class Transport{
    /**
     * the id of a transport is determined by
     * a it's type and a static number
     */
    string id;
    /**
     * the type determines if it is a metro(m)
     * a bus(b) or a train(t)
     */
    char type; // m --> metro; b --> bus; t --> train
    /**
     * distance in meters to the airport
     */
    uint16_t distance;
    /**
     * each transport object has it's own time
     * that can be changed
     */
    Time *time;
    friend class Airport;
public:
    /**
     * Transport constructor
     * @param c character to define type of transport (m->metro;t->train;b->bus)
     */
    explicit Transport(char c);
    /**
     * getter for the id of the transport id string
     * @return string of the id
     */
    string getId() const{
        return id;};
    /**
     * setter for the type of transport
     * @param c the types are 'm', 't' and 'b'
     */
    void setType(char c){
        type = c;}
    /**
     * getter for the type of transport
     * @return a char of the type
     */
    char getType() const{
        return type;};
    /**
     * getter for the descprition of the transport
     * to help populate tables and menus
     * @return
     */
    string getTransport() const;
    /**
     * setter for the distance to the aiport
     * @param distance
     */
    void setDistance (uint16_t distance){
        this->distance = distance;}
    /**
     * getter for the distance
     * @return
     */
    uint16_t getDistance () const{
        return distance;};
    /**
     * set's the time for the transport
     * @param time
     */
    void addTime(Time *time) {
        this->time = time;};
    /**
     * returns the time of the object
     * @return time object
     */
    Time* getTime () const{
        return time;};
    /**
     * Operator < overload to sort Transport objects
     * in airport transport BST
     * @param t
     * @return
     */
    bool operator <(Transport &t);
    /**
     * Operator == overload to sort Transport objects
     * in airport transport BST
     * @param t
     * @return
     */
    bool operator ==(Transport &t);
    bool operator !=(Transport &t);
};


class TransportPointer : public BSTPointer<Transport> {
public:
    /**
     * Creaction of an object of type pointer
     * to facilitate creation and addition to
     * transport BST
     * @param t - transport object pointer
     */
    explicit TransportPointer(Transport *t) {
        pointer = t;
    }

};

class Terminal{
    /**
     * id composed of the terminal number and
     * the airport code
     */
    string id;
    /**
     * pointer to the plane currently docked
     * at the terminal
     */
    Plane* plane;
    friend class Airport;
public:
    /**
     * default terminal coonstructor
     */
    Terminal() {id = ""; plane = nullptr;};
    /**
     * Main terminal constructot, usually called form
     * within an ariport object
     * @param i number of the terminal (ando also it's id)
     * @param airport airport from which is called to
     *          determine it's idCode
     */
    Terminal(string i, string airport){
        id = airport + i;
        plane = nullptr;};
    /**
     * Method to change terminal main definitions
     * @param id new id number
     * @param airport
     */
    void setId (string id, string airport){
        this->id = airport + id;
    }
    /**
     * getter for the terminal id
     * @return
     */
    string getId() const{
        return id;}
        /**
         * returns the numeric part of the id which
         * represents it's number
         * @return
         */
    string getTerminalNumber() const{
        return id.substr(3);};
    /**
     * Docks a plane to the terminal occupying it
     * @param plane
     */
    void setPlane(Plane *plane){
        this-> plane = plane;};
    /**
     * getPlane method
     * @return plane docked at terminal
     */
    Plane* getPlane() const{
        return plane;}
    /**
     * method to remove plane from terminal
     */
    void setUnocccupied(){
        plane->takeOff();
        this->plane = nullptr;
    };
    /**
     * Method to determine if terminal is occupied
     * @return
     */
    bool getOccupied() const {
        return plane != nullptr;
    }
    /**
     * The easiest way to sort terminal objects
     * in case of need
     * @param t
     * @return
     */
    bool operator<(Transport &t){
        return this->getId()<t.getId();
    }
 
};

class Airport{
    /**
     * string to identify each airport
     */
    string idName;
    /**
     * airport name string
     */
    string name;
    /**
     * airport country string
     */
    string country;
    /**
     * airport city string
     */
    string city;
    /**
     * terminals is a vector to store the active
     * terminals of the airport
     */
    vector<Terminal*> terminals;
    /**
     * transport is where the information about
     * transports nearby are stored in a BST
     * container
     */
    BST<TransportPointer> transport;
    //BST<Transport> transport;
    /**
     * queue of services associated with the
     * airport when the airplane is on the ground
     */
    queue<ServiceTicket*> services;
    /**
     * historic of all the services at
     * this airport
     */
    list<ServiceTicket*> complete;
    /**
     * list of all the staff at the aiport
     * at each moment
     */
    list<Staff*> staff;
    friend class Terminal;
    friend class Transport;
public:
    /**
     * Airport constructor - creates a new airport objects
     * where will be stored information about idName(3 letter),
     * name, city, country, which transport there are nearby,
     * what are the services in progress and the staff allocated
     * to the airport
     * @param id 3 letter string
     * @param n string name
     * @param ctry string
     * @param cty string
     */
    explicit Airport(std::string id = "", std::string n = "", std::string ctry = "", std::string cty = "") :
        transport(TransportPointer(nullptr)), idName(std::move(id)),
        name(std::move(n)), country(std::move(ctry)), city(std::move(cty)){}
    /**
     * Method to set a name for the airport
     * @param name string
     */
    void setName(string name){this->name = name;}
    /**
     * Setter for id
     * @param id 3 letter string
     */
    void setId(string id){idName = id;}
    /**
     * set's the country for the airport
     * @param country string
     */
    void setCountry(string country){this->country = country;}
    /**
     * set's the city of the airport
     * @param city string
     */
    void setCity(string city){this->city = city;}
    /**
     * getter for complete idCode of the airport
     * @return airport id string const
     */
    string getidCode() const;
    /**
     * getter for the airport name
     * @return airport name
     */
    string getName () const;
    /**
     * getter for airport country
     * @return airport country
     */
    string getCountry() const;
    /**
     * getter for the airport city
     * @return airport city
     */
    string getCity() const;
    /**
     * method to help identify which terminals
     * through a verification
     * @return vector of terminal objects
     */
    vector<Terminal*> getEmptyTerminals() const;
    /**
     * method to help getting which terminals
     * are free
     * @return vector of terminal objects
     */
    vector<Terminal*> getTerminals() const;
    /**
     * getter of all the services pending
     * at the airport
     * @return vector of all the services
     */
    vector<ServiceTicket*> getServices();
    /**
     * getter for all the completed services at
     * this airport
     * @return vector of serviceTicket objects
     */
    vector<ServiceTicket*> getCompleteServices() const;
    /**
     * method to return the next service in line
     * @return serviceTicket object
     */
    ServiceTicket* nextService();
    /**
     * method to help getting the group of
     * all the workers in the form of vector
     * @return
     */
    vector<Staff*> getStaff() const;
    /**
     * Introduces a new transport in the BST of
     * the airport through a TransportPointer
     * @param transport
     */
    void setTransport (TransportPointer transport);
    /**
     * Removes a transport object from the BST
     * through the pointer
     * @param transport
     */
    void delTransport (TransportPointer transport);
    /**
     * method to add a new serviceTicket to
     * the services queue
     * @param service
     */
    void addService (ServiceTicket *service);
    /**
     * method used to set a service as completed
     * at a given date
     * @param date through a Time object
     */
    void delService (Time *date);
    /**
     * removes a terminal form operation if
     * it is empty
     * @param id
     * @return
     */
    bool delTerminal(string id);
    /**
     * add's a new staff to the list
     * of staff at the airport
     * @return true if successfull
     */
    bool addStaff(Staff*);
    /**
     * removes a staff from the list of
     * staff
     * @return true if successfull
     */
    bool delStaff(Staff*);
    /**
     * getter to organize all the transports of the
     * BST in a vector
     * @return
     */
    vector<Transport*> getTransport() const;
    /**
     * getter to return a transportpointer
     * of a tranpsort of the BST
     * @return
     */
    vector<TransportPointer> getTransportPointer() const;
    /*list<Time*>nextTransportMetro (Time *time) const;
    list<Time*>nextTransportBus (Time *time) const;
    list<Time*>nextTransportTrain (Time *time) const;*/
    /**
     * method through which a new terminal is created
     * with the idCode of the airport and added to the
     * terminals vector
     * @param i
     */
    void activateTerminal (string i);
    /**
     * method to dock a plane in a free terminal
     * @param plane to land
     * @param id of the terminal to check availability
     */
    void setTerminal(Plane *plane, string id);
    /**
     * method to send the information of
     * the airport to the screen
     */
    void printAirport();
    /**
     * method to send information about
     * the next service
     */
    void printService();
    /**
     * < overload to organize the airports
     * int the AirportPointerBST. they are sorted
     * by country > city > idName (unique)
     * @param s
     * @return
     */
    bool operator < (Airport &s);
    /**
     * == overload for the idCode
     * @param rhs
     * @return
     */
    bool operator==(const Airport& rhs) const{
        return idName == rhs.idName;
    }
    /**
     * != overload
     * @param rhs
     * @return
     */
    bool operator!=(const Airport& rhs) const{
        return !(*this == rhs);
    }
    /**
     * < overload to help sorting airport by name
     * @param rhs
     * @return
     */
    bool operator<(const Airport& rhs) const{
        return idName < rhs.idName;
    }

};


class IncorrectLength{
private:
    string e;
public:
    IncorrectLength(){
        e = "Use 3 letter word";
    };
    string getError() const{
        return e;
    }
};
#endif