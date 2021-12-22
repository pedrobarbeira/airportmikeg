//Created by Pedro Barbeira
#ifndef MAIN_CPP_FLIGHT_H
#define MAIN_CPP_FLIGHT_H

#include <iostream>
#include "airport.h"
#include "date.h"
#include "plane.h"

static int count = 0;

/**
 * Encapsulation struct for Airport and Time
 * Stores which airport the plane leaves/lands on and the respective date&time
 */
struct TimePlace{
    /**
     * The Place
     */
    Airport* airport;

    /**
     * The Time
     */
    Time* time;

    /**
     * Constructor to make creation of TimePlace objects easier
     * @param a the airport
     * @param t the time
     */
    TimePlace(Airport* a, Time *t){airport=a;time=t;};
};

class Flight{
    std::string flightID;
    std::string voyageID;
    TimePlace* origin;
    TimePlace* destination;
    Plane* plane;
    friend class FlightPointer;
public:
    /**-----Constructor-----*/
    /**
     * Constructor for the Flight class. Creates an empty flight with
     * just an Id. Used to facilitate the process of finding Flights in
     * the Data::flights BST. Acts as a default constructor if no parameters
     * are given
     * @param id the Id of the Flight to be found
     */
    explicit Flight(const std::string& id = ""){
        flightID = id;
        origin = nullptr;
        destination = nullptr;
        plane = nullptr;
    }

    /**
     * Constructor for the Flight class. Creates a new Flight which goes
     * from o to d in the plane p. TimePlace objects were used so the
     * departure/arrival times are coupled with the origin/destination airports
     * @param o pointer to the origin TimePlace
     * @param d pointer to the destination TimePlace
     * @param p the plane which will make the flight
     */
    explicit Flight(TimePlace* o, TimePlace* d, Plane* p);

    /**
     * Destructor for the Plane class. Sets origin and destination airports
     * to nullptr and deletes the TimePlace attributes. Sets the Plane attribute
     * to nullptr so the Plane object isn't deleted from system
     */
    ~Flight();

    /**-----Getters-----*/
    /**
     * Getter for the Flight id
     * @return the flight Id
     */
    std::string getId() const{
        return flightID;};

    /**
     * Getter for the Voyage Id
     * @return the Voyage id
     */
    std::string getVoyageId(){
        return voyageID;
    }

    /**
     * Getter for the Origin information
     * @return the origin information
     */
    TimePlace* getOrigin() const{
        return origin;};

    /**
     * Getter for the Destination information
     * @return the destination information
     */
    TimePlace* getDestination() const{
        return destination;};

    /**
     * Getter for the Plane object
     * @return pointer to the Plane object
     */
    Plane* getPlane() const{
        return plane;};

    /**-----Setters-----*/
    /**
     * Changes the Origin attribute to a
     * @param a the new Origin
     */
    void setOrigin(TimePlace* a){
        origin = a;};

    /**
     * Changes the Destination attribute to a
     * @param a the new Destination
     */
    void setDestination(TimePlace* a){
        destination = a;};

    /**
     * Changes the price of the different classes of this Flight
     * @param f the new price of the First Class seats
     * @param b the new Price of the Business Class seats
     * @param e the new Price of the Economy Class seats
     */
    void setPrice(uint16_t f, uint16_t b, uint16_t e);

    /**
     * Changes the plane which will take the Flight
     * @param p poitner to the new plane
     */
    void setPlane(Plane* p){
        plane = p;};

    /**
     * Sets the voyageId attribute to v, signaling the Voyage which the
     * Flight belonds to
     * @param v the Voyage id
     */
    void setVoyage(const std::string& v){
        voyageID = v;
    }

    /**-----Print-----*/
    /**
     * Prints flight information in out
     * @param out the ostream which will receive the information to be printed
     */
    void print(std::ostream& out) const;
    bool operator==(const Flight& rhs){
        return flightID == rhs.flightID;
    }
    bool operator<(const Flight& rhs) const{
        return flightID < rhs.flightID;
    }
};


#endif //MAIN_CPP_FLIGHT_H
