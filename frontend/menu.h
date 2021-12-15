//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <iostream>
#include "user.h"
#include "voyage.h"
#include "airport.h"

//Think about making the sorter into a class

/**
 * Encapsulation class.
 * Initializes and stores all the system's BST's
 */
class Data{
    BST<AirportPointer> airports;
    BST<VoyagePointer> voyages;
    BST<PlanePointer> planes;
    BST<ClientPointer> clients;
    BST<CompanyPointer> company;
    friend class MikeG;
public:
    Data() : airports(AirportPointer(nullptr)), planes(PlanePointer(nullptr)),
             clients(ClientPointer(nullptr)), company(CompanyPointer(nullptr)),
             voyages(VoyagePointer(nullptr)){}
    //Turn these to return vectors with information
    BST<AirportPointer> getAirport() const{
        return airports;};
    BST<VoyagePointer> getVoyages() const{
        return voyages;};
    BST<PlanePointer> getPlanes() const{
        return planes;};
    bool addAirport(Airport* a){
        AirportPointer aptr(a);
        return airports.insert(aptr);
    }
    bool addVoyage(Voyage* v){
        VoyagePointer vptr(v);
        return voyages.insert(vptr);
    }
    bool addFlight(Flight* f);
    bool addPlane(Plane* p){
        PlanePointer pptr(p);
        return planes.insert(pptr);
    }
};

/**
 * Frontend class that handles Generic Menus. Acts as an Interface for it's subclasses
 */
class Menu{
protected:
    User* user;
    Data* data;
    Time* sysTime;
public:
    explicit Menu(Data* d = nullptr) : data(d){
        sysTime = new Time;
        sysTime->now();
    };
    virtual void mainScreen() const;
};

//Clear definitons from all the mainScreens() and write them in menu.cpp
//The definitoins below were just to test the control flow and the logIn() function
/**
 * Frontend class that handles Registered Client menus
 */
class ClientMenu : public Menu{
    //This would have a Client* user
public:
    explicit ClientMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override;
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
    void mainScreen() const override;
};

/**
 * Frontend class that handles Company menus
 */
class CompanyMenu : public Menu{

};

/**
 * Frontend class that handles Admin menus
 */
class AdminMenu : public CompanyMenu{
public:
    explicit AdminMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override;
};

/**
 * Frontend class that handles Manager menus
 */
class ManagerMenu : public CompanyMenu{
public:
    explicit ManagerMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override;
};

/**
 * Frontend class that handles Boarding Crew menus
 */
class BoardingMenu : public CompanyMenu{
public:
    explicit BoardingMenu(User* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override;
};

//Eventually split this into BoardingPassenger and CheckinPassenger

/**
 * Frontend class that handles Service Worker menus
 */
class ServiceMenu : public CompanyMenu{
public:
    explicit ServiceMenu(User* u = nullptr, Data*d = nullptr){
        user = u;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() const override;
};

std::ostream& operator<<(ostream& out, const UserPointer& user);
void readInput(char& in);
void readInput(std::string& in);

#endif //MAIN_CPP_MENU_H
