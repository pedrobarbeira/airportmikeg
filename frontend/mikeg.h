//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MIKEG_H
#define MAIN_CPP_MIKEG_H

#include <iostream>
#include "airport.h"
#include "voyage.h"

/**
 * Class to load and pass the objects of the airline
 */
class MikeG{
    std::vector<Airport*> airports;
    std::vector<Voyage*> voyages;
    std::vector<Flight*> flights;
    std::vector<Plane*> planes;
public:
    /**Constructor*/
    MikeG(){
        airports.clear();
        voyages.clear();
        flights.clear();
        planes.clear();
    }
    /**Getters*/
    std::vector<Airport*> getAirport() const{
        return airports;};
    std::vector<Voyage*> getVoyages() const{
        return voyages;};
    std::vector<Flight*> getFlights() const{
        return flights;};
    std::vector<Plane*> getPlanes() const{
        return planes;};
    //need to add remaining classes
    /**Modifiers*/
    bool addAirport(Airport* a){
        if(!airports.empty()) {
            for (auto it : airports) {
                if (it == a) return false;
            }
        }
        airports.push_back(a);
        return true;
    }
    bool addVoyage(Voyage* v){
        if(!voyages.empty()) {
            for (auto it : voyages) {
                if (it == v) return false;
            }
        }
        voyages.push_back(v);
        return true;
    }
    bool addFlight(Flight* f){
        if(!flights.empty()) {
            for (auto it : flights) {
                if (it == f) return false;
            }
        }
        flights.push_back(f);
        return true;
    }
    bool addPlane(Plane* p){
        if(!planes.empty()) {
            for (auto it : planes) {
                if (it == p) return false;
            }
        }
        planes.push_back(p);
        return true;
    }
};

/**Exceptino classes*/
class DevLog {
    std::string error;
public:
    DevLog(std::string e) : error(e) {};
    void print() const;
};

class LogOut{
    std::string message;
public:
    LogOut(): message("Logging Out"){};
    void print() const{
        std::cout << message << '\n';
    }
};

#endif //MAIN_CPP_MIKEG_H
