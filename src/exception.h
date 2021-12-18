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
class Fail : public std::exception{
protected:
    std::string error;
public:
    Fail(){
        error.clear();
    }
    std::string getError() const{
        return error;
    }
};
class LoadAirportFail : public Fail{
public:
    LoadAirportFail(){
        error = "Failed to load Airports";
    }
};
class LoadVoyageFail : public Fail{
public:
    LoadVoyageFail(){
        error = "Failed to load Voyages";
    }
};
class LoadFlightFail : public Fail{
public:
    LoadFlightFail() {
        error = "Failed to load flights";
    };
};
class LoadPlaneFail : public Fail{
public:
    LoadPlaneFail() {
        error = "Failed to load Planes";
    };
};
class LoadTicketFail : public Fail{
public:
    LoadTicketFail() {
        error = "Failed to load Tickets";
    };
};
class LoadUserFail : public Fail{
public:
    LoadUserFail(){
        error = "Failed to load Users";
    };
};


class SaveAirportFail : public Fail{
public:
    SaveAirportFail(std::string id){
        error = "SaveAirportFail::" + id + " error opening outfile\n";
    }
};

class SaveVoyageFail: public Fail{
public:
    SaveVoyageFail(std::string id){
        error = "SaveVoyageFail::::" + id + " error opening outfile\n";
    }
};

class SaveUserFail : public Fail{
public:
    SaveUserFail(std::string id){
        error = "SaveUser::" + id + " error opening outfile\n";
    }
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
