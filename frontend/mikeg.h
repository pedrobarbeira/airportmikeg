//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MIKEG_H
#define MAIN_CPP_MIKEG_H

#include <iostream>
#include <fstream>
#include "airport.h"
#include "voyage.h"

/**Exceptino classes*/
class DevLog {
    std::string error;
public:
    DevLog(std::string e) : error(std::move(e)) {};
    /**
     * Stores special system error messages into the DevLogs file, so the company's
     * amazing and much valued "IT guy" can keep everything running smoothly
     */
    void print() const;
};

class LoadAirportFail{
    std::string error;
public:
    LoadAirportFail():
            error("Failed to load airports"){};
    void print(ostream& out){
        out << error << '\n';
    }
};

class LoadVoyageFail{
    std::string error;
public:
    LoadVoyageFail():
            error("Failed to load voyages"){};
    void print(ostream& out){
        out << error << '\n';
    }
};

class LoadFlightFail{
    std::string error;
public:
    LoadFlightFail():
            error("Failed to load flights"){};
    void print(ostream& out){
        out << error << '\n';
    }
};

class LoadPlaneFail{
    std::string error;
public:
    LoadPlaneFail():
            error("Failed to load planes"){};
    void print(ostream& out){
        out << error << '\n';
    }
};

class LoadTicketFail{
    std::string error;
public:
    LoadTicketFail():
            error("Failed to load tickets"){};
    void print(ostream& out){
        out << error << '\n';
    }
};

class LogOut{
    std::string message;
public:
    LogOut(): message("Logging Out"){};

    void print() const{
        std::cout << message << '\n';
    }
};


/**
 * Class to load and pass the objects of the airline
 */
class MikeG{
    std::vector<Airport*> airports;
    std::vector<Voyage*> voyages;
    std::vector<Flight*> flights;
    std::vector<Plane*> planes;
    std::vector<Ticket*> tickets;
public:
    /**Constructor*/
    MikeG(){
        airports.clear();
        voyages.clear();
        flights.clear();
        planes.clear();
        tickets.clear();
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
    std::vector<Ticket*> getTickets() const{
        return tickets;
    }
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
    bool addTicket(Ticket* t) {
        if (!flights.empty()) {
            for (auto it : tickets) {
                if (it == t) return false;
            }
        }
        tickets.push_back(t);
        return true;
    }
    /**Load/Save*/
    bool save() const;
    bool loadAirport();
    bool loadVoyage();
    bool loadFlight();
    bool loadPlane();
    bool loadTicket();
    bool load();
};



#endif //MAIN_CPP_MIKEG_H
