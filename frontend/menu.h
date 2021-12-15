//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <iostream>
#include "user.h"
#include "voyage.h"
#include "airport.h"

//Eventually add Client subclass to user and create a user.h


/**
 * Encapsulation class.
 * Initializes and stores all the system's BST's
 */
class Data{
    BST<AirportPointer> airports;
    std::vector<Voyage*> voyages;
    BST<FlightPointer> flights;
    BST<PlanePointer> planes;
    std::vector<Ticket*> tickets;
    BST<ClientPointer> clients;
    BST<CompanyPointer> company;
    friend class MikeG;
public:
    Data() : airports(AirportPointer(nullptr)), flights(FlightPointer(nullptr)),
             planes(PlanePointer(nullptr)), clients(ClientPointer(nullptr)), company(CompanyPointer(nullptr)){
        voyages.clear();
        tickets.clear();
    }
    //Add get methods
    BST<AirportPointer> getAirport() const{
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
    bool addAirport(const AirportPointer& a){
        return airports.insert(a);
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
    bool addFlight(const FlightPointer& f);
    bool addPlane(const PlanePointer& p){
        return planes.insert(p);
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
    void mainScreen() const override{
        std::cout << "we are @ Admin\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
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
    void mainScreen() const override{
        std::cout << "we are @ Manager\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
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
    void mainScreen() const override{
        std::cout << "we are @ Boarding\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
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
    void mainScreen() const override{
        std::cout << "we are @ Service\n"
                  << "Press enter to continue . . .";
        char c = getchar();
    }
};

std::ostream& operator<<(ostream& out, const UserPointer& user);
void readInput(char& in);
void readInput(std::string& in);

#endif //MAIN_CPP_MENU_H
