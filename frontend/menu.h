//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include "data.h"
#include "sorter.h"

//Think about making the sorter into a class

/**
 * Frontend class that handles Generic Menus. Acts as an Interface for it's subclasses
 */

class Menu{
protected:
    Data* data;
    Time* sysTime;
public:
    explicit Menu(Data* d = nullptr) : data(d){
        sysTime = new Time;
        sysTime->now();
    };
    virtual void mainScreen();
};

class Dev : public Menu{
    std::vector<std::string> logs;
    std::vector<std::string> newLogs;
public:
    Dev();
    void mainScreen();
    void showLogs(bool flag) const;
    void showNewLogs();
    void save(bool flag);
};


/**
 * Frontend class that handles Registered Client menus
 */
class ClientMenu : public Menu{
protected:
    Client* user;
    AirportPointer airport;
    Flight* flight;
public:
    explicit ClientMenu(Client* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        flight = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
    void buyTicket();
    void print(std::vector<AirportPointer> v) const;
    void print(std::vector<Flight*> v) const;
    void selectFlight();
    void reOrder();
    void originAirport();
    void destinationAirport();
    void seeFlights();
    void seeVoyages();
    void changeTicket();
    void checkIn();
    void ticketHistory();
};

/**
 * Frontend class that handles Unregistered Client menus
 */
class JustBuy : public ClientMenu{
public:
    explicit JustBuy(Data* d = nullptr){
        user = nullptr;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

class CheckIn : public ClientMenu{};

class Register : public ClientMenu{};

/**
 * Frontend class that handles Company menus
 */
class CompanyMenu : public Menu{
protected:
    Company* user;
    Airport* airport;
    //Add an airport
    //Add service ticket queue
    //add complete service queue
};

/**
 * Frontend class that handles Admin menus
 */
class AdminMenu : public CompanyMenu{
public:
    explicit AdminMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

/**
 * Frontend class that handles Manager menus
 */
class ManagerMenu : public CompanyMenu{
public:
    explicit ManagerMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

/**
 * Frontend class that handles Boarding Crew menus
 */
class BoardingMenu : public CompanyMenu{
public:
    explicit BoardingMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

//Eventually split this into BoardingPassenger and CheckinPassenger

/**
 * Frontend class that handles ServiceTicket Worker menus
 */
class ServiceMenu : public CompanyMenu{
public:
    explicit ServiceMenu(Company* u = nullptr, Data*d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

void readInput(char& in);
void readInput(std::string& in);

#endif //MAIN_CPP_MENU_H
