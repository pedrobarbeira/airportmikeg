//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_VOYAGE_H
#define AIPORTMIKEG_VOYAGE_H

#include "plane.h"
#include "airport.h"
#include "../date.h"
#include <vector>
#include <list>

class Flight;

struct Connection{  //Lets say we have porto-barcelona and want to insert a lisbon connection
    Flight* in;     //We add porto-lisbon here
    Flight* out;    //We add lisbon-barcelona here
};

class Flight{
    std::string flightID;
    Date* departure;
    Date* arrival;
    Airport* origin;
    Airport* destination;
    Plane* plane;
public:
    /**Constructor*/
    Flight(std::string id = "", Date* d = NULL, Date* a = NULL,
           Airport* o = NULL, Airport* dest = NULL, Plane* p = NULL):
           flightID(id), departure(d), arrival(a), origin(o), destination(dest), plane(p){};
    /**Getters*/
    std::string getID() const{
        return flightID;};
    Date* getDeparture() const{
        return departure;};
    Date* getArrival() const{
        return arrival;};
    Airport* getOrigin() const{
        return origin;};
    Airport* getDestination() const{
        return destination;};
    Plane* getPlane() const{
        return plane;};
    /**Setters*/
    void setId(std::string id){
        flightID = id;};
    void setDeparture(Date* d){
        departure = d;};
    void setArrival(Date* d){
        arrival = d;};
    void setOrigin(Airport* a){
        origin = a;};
    void setDestination(Airport* a){
        destination = a;};
    void setPlane(Plane* p){
        plane = p;};

};

class Voyage{
    //std::vector<Ticket*> tickets;
    std::list<Flight*> route;
public:
    /**Constructor*/
    Voyage(Airport* origin = NULL, Airport* destination = NULL){
        //tickets.clear();
        Flight* f = new Flight("", NULL, NULL, origin, destination);
        route.push_back(f);
    }
    /**Getters*/
    /*std::vector<Ticket*> getTickets() const{
        return tickets;};
    */
    std::list<Flight*> getRoute(){
        return route;};
    Flight* getOrigin() const{
        return route.front();};
    Flight* getDestination() const{
        return route.back();};
    /**Setters*/
    /*void setTrickets(std::list<Ticket*> t){
        tickets = t;};*/
    void setRoute(std::list<Flight*> r){
        route = r;};
    /**Adders*/
    //bool addTicket(Ticket* t);
    bool addConnection(Connection c); //gotta finish this one

};

#endif //AIPORTMIKEG_VOYAGE_H
