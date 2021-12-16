//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_EXCEPTION_H
#define MAIN_CPP_EXCEPTION_H

#include <iostream>
#include "date.h"

/**Exception classes*/
/**
     * Stores special system error messages into the DevLogs file, so the company's
     * amazing and much valued "IT guy" can keep everything running smoothly
     */
class DevLog : public std::exception {
    std::string error;
    Date* date;
public:
    explicit DevLog(std::string e) : error(std::move(e)){
        Time* t;
        t->now();
        date = t;
    };
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
class LoadFail : public std::exception{
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
class LogOut : public std::exception{
    std::string message;
public:
    LogOut(): message("Logging Out"){};

    void print() const{
        std::cout << message << '\n';
    }
};


#endif //MAIN_CPP_EXCEPTION_H
