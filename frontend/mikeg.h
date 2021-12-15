//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MIKEG_H
#define MAIN_CPP_MIKEG_H

#include <iostream>
#include <fstream>
#include "menu.h"
#include "crossplatform.h"

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
    /*bool addTicket(Ticket* t) {
        if (!data->flights.empty()) {
            for (auto it : data->tickets) {
                if (it == t) return false;
            }
        }
        data->tickets.push_back(t);
        return true;
    }*/
    /**Load/Save*/
    bool save() const;
    bool loadAirport();
    bool loadVoyage();
    bool loadFlight();
    bool loadPlane();
    bool loadTicket();
    void loadUsers();
    bool load();
    bool loadScreen(bool& flag);

    Menu* logIn();
    bool newAccount();
    void start(bool& flag);
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
    std::string getError() const{
        return error;
    }
    Date* getDate() const{
        return date;
    }
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
