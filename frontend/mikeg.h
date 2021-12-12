//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MIKEG_H
#define MAIN_CPP_MIKEG_H

#include <iostream>
#include <fstream>
#include "airport.h"
#include "voyage.h"
#include "menu.h"
#include "crossplatform.h"



//Do the same for remainng classes

/**
 * Stores the created Airports and which flights are related to them
 */
class AirportFlightList{
    Airport* airport;
    BST<PointerFlight> inFlights;
    BST<PointerFlight> outFlights;
public:
    //Constructor
    //Get that returns a vector (for easy acess through menu) for in and out
    // - overloaded with a find
    //Find function for in and out
    //Add for in and out
    //Remove for in and out
};

//Do the same for remaing classes


/**
 * System Interface
 */
class MikeG{
    Time* sysTime;
    //Exchange these vectors for appropriate BST's
    //Encapsulate vectors in AirlineData class
    std::vector<Airport*> airports;
    std::vector<Voyage*> voyages;
    std::vector<Flight*> flights;
    std::vector<Plane*> planes;
    std::vector<Ticket*> tickets;
    std::vector<User*> users;
    //till here
    Menu* menu;
public:
    /**Constructor*/
    MikeG(){
        sysTime = new Time;
        airports.clear();
        voyages.clear();
        flights.clear();
        planes.clear();
        tickets.clear();
        users.clear();
        menu = nullptr;
    }
    /**Getters*/
    Time* getTime() const{
        return sysTime;};
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
    std::vector<User*> getUsers() const{
        return users;
    }
    //need to add remaining classes
    /**Modifiers*/
    void setSysTime(){
        sysTime->now();};
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
    bool addUser(User * u){
        if(!users.empty()) {
            for (auto user: users) {
                if (user == u) return false;
            }
        }
        users.push_back(u);
        return true;
    }
    /**Load/Save*/
    bool save() const;
    bool loadAirport();
    bool loadVoyage();
    bool loadFlight();
    bool loadPlane();
    bool loadTicket();
    void loadUsers();
    bool load();

    void start();
};


/**Exceptino classes*/
/**
     * Stores special system error messages into the DevLogs file, so the company's
     * amazing and much valued "IT guy" can keep everything running smoothly
     */
class DevLog {
    std::string error;
public:
    DevLog(std::string e) : error(std::move(e)) {};
    void print() const;
};

/**
 * Communicate to DevLogs if any problem happens while loading Airline data
 */
class LoadFail{
protected:
    std::string error;
public:
    LoadFail(){
        error.clear();
    }
    std::string getError() const{
        return error;
    }
};
class LoadAirportFail : public LoadFail{
public:
    LoadAirportFail(){
        error = "Failed to load airports";
    }
};
class LoadVoyageFail : public LoadFail{
public:
    LoadVoyageFail(){
        error = "Failed to load Voyages";
    }
};
class LoadFlightFail : public LoadFail{
public:
    LoadFlightFail() {
        error = "Failed to load flights";
    };
};
class LoadPlaneFail : public LoadFail{
public:
    LoadPlaneFail() {
        error = "Failed to load planes";
    };
};
class LoadTicketFail : public LoadFail{
public:
    LoadTicketFail() {
        error = "Failed to load tickets";
    };
};
class LoadUserFail : public LoadFail{
public:
    LoadUserFail(){
        error = "Failed to load users";
    };
};
ostream& operator<<(ostream& out, LoadFail lf);

/**
 * Acts as a goto to quickly logout in any layer of the system
 */
class LogOut{
    std::string message;
public:
    LogOut(): message("Logging Out"){};

    void print() const{
        std::cout << message << '\n';
    }
};



#endif //MAIN_CPP_MIKEG_H
