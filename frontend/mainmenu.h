//Created by Pedro Barbeira (up201303693)
#ifndef MIKEGAIRLINES_MAINMENU_H
#define MIKEGAIRLINES_MAINMENU_H

#include "company.h"
#include "clients.h"
#include "airport.h"
#include "voyage.h"
#include "passenger.h"
#include "service.h"
#include "staff.h"
#include "transport.h"
#include <vector>
#include <ctime>
#include <fstream>
#include <string>

/**
 * Class to load and pass the objects of the airline
 */
class MikeG{
<<<<<<< HEAD
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
    /**Modifiers*/;
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
=======
public:
    std::vector<class Airport*> airports;
    std::vector<class Voyage*> voyages;
    std::vector<class Flight*> flight;
>>>>>>> 5bf53c4ceaba51575198a7b223b3a9175ab172e5
};

//Main Menu Stub
void menu();
//Menu Stubs
void company();
void dev();
//BackEnd Workhorses
bool checkDev();
bool login(char, char&);
bool checkCredentials(char, char&);

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
    LogOut(){
        message = "Log Out Successful";
    }
    void print() const{
        std::cout << message << '\n';
    }
};

#endif //MIKEGAIRLINES_MAINMENU_H
