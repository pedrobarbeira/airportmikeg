//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MIKEG_H
#define MAIN_CPP_MIKEG_H

#include <iostream>
#include <fstream>
#include "airport.h"
#include "voyage.h"
#include "menu.h"
#include "crossplatform.h"

/**
 * Encapsulation class.
 * Initializes and stores all the system's BST's
 */
class Data{
    BST<AirportFlightList> airports;
    std::vector<Voyage*> voyages;
    BST<FlightPointer> flights;
    BST<PlanePointer> planes;
    std::vector<Ticket*> tickets;
    BST<UserPointer> users;
    friend class MikeG;
public:
    Data() : airports(AirportFlightList()), flights(FlightPointer()),
             planes(PlanePointer()), users(UserPointer()){
        voyages.clear();
        tickets.clear();
    }
    //Add get methods
    BST<AirportFlightList> getAirport() const{
        return airports;};
    std::vector<Voyage*> getVoyages() const{
        return voyages;};
    BST<FlightPointer> getFlights() const{
        return flights;};
    BST<PlanePointer> getPlanes() const{
        return planes;};
    std::vector<Ticket*> getTickets() const{
        return tickets;
    }
    BST<UserPointer> getUsers() const{
        return users;
    }
    //Add find methos
    //Add add methods
};

/**
 * System Interface
 */
class MikeG{
    Time* sysTime;
    Data* data;
    Menu* menu;
public:
    /**-----Constructor-----*/
    MikeG(){
        sysTime = new Time;
        data = new Data;
        menu = nullptr;
    }
    /**-----Getters-----*/
    /** Actualizes current system time and returns it
     * @return Time pointer with current system time
     */
    Time* getTime() const{
        sysTime->now();
        return sysTime;};
    Data* getData() const{
        return data;
    }
    //need to add remaining classes
    /**Modifiers*/
    void setSysTime(){
        sysTime->now();};
    bool addAirport(Airport* a){
        return data->airports.insert(AirportFlightList(a));
    }
    bool addVoyage(Voyage* v){
        if(!data->voyages.empty()) {
            for (auto it : data->voyages) {
                if (it == v) return false;
            }
        }
        data->voyages.push_back(v);
        return true;
    }
    bool addFlight(Flight* f);
    bool addPlane(Plane* p){
        return data->planes.insert(PlanePointer(p));
    }
    /*bool addTicket(Ticket* t) {
        if (!data->flights.empty()) {
            for (auto it : data->tickets) {
                if (it == t) return false;
            }
        }
        data->tickets.push_back(t);
        return true;
    }*/
    bool addUser(User * u){
        return data->users.insert(UserPointer(u));
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
    void loadScreen(bool& flag);

    Menu* logIn();
    bool newAccount();
    void start();
    template<typename T>
    static void readInput(T& in);
};


/**Exception classes*/
/**
     * Stores special system error messages into the DevLogs file, so the company's
     * amazing and much valued "IT guy" can keep everything running smoothly
     */
class DevLog : public exception {
    std::string error;
    Date* date;
public:
    explicit DevLog(std::string e, Date* d = nullptr) : error(std::move(e)), date(d) {};
    void print() const;
};

/**
 * Communicate to DevLogs if any problem happens while loading Airline data
 */
class LoadFail : public exception{
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
        error = "Failed to load Airports";
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
        error = "Failed to load Planes";
    };
};
class LoadTicketFail : public LoadFail{
public:
    LoadTicketFail() {
        error = "Failed to load Tickets";
    };
};
class LoadUserFail : public LoadFail{
public:
    LoadUserFail(){
        error = "Failed to load Users";
    };
};

/**
 * Acts as a goto to quickly logout in any layer of the system
 */
class LogOut : public exception{
    std::string message;
public:
    LogOut(): message("Logging Out"){};

    void print() const{
        std::cout << message << '\n';
    }
};



#endif //MAIN_CPP_MIKEG_H
