//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <iostream>
#include "bst.h"
#include "voyage.h"
#include "airport.h"

//Eventually add Client subclass to user and create a user.h

/**
 * User parent class. Acts as an Interface for it's subclasses.
 */
class User{
    std::string username;
    std::string password;
    char type; //Create
    friend class UserPointer;
public:
    User(){
        username.clear();
        password.clear();
        type = '\0';
    };
    User(std::string u = "", std::string p = "", char t = '\0'):
            username(std::move(u)), password(std::move(p)), type(t){};
    std::string getUser() const{
        return username;
    }
    std::string getPassword() const{
        return password;
    }
    char getType() const{
        return type;
    }
};

class UserPointer : public BSTPointer<User>{
public:
    explicit UserPointer(User* u = nullptr){
        pointer = u;
    }
    bool operator==(const UserPointer& rhs) const{
        return pointer->username == rhs.pointer->username;
    }
    bool operator<(const UserPointer& rhs) const{
        return pointer->username < rhs.pointer->username;
    }
};


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
    Data() : airports(AirportFlightList(nullptr)), flights(FlightPointer(nullptr)),
             planes(PlanePointer(nullptr)), users(UserPointer(nullptr)){
        BST<UserPointer> u(UserPointer(nullptr));
        users = u;
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
 * Frontend class that handles Generic Menus. Acts as an Interface for it's subclasses
 */
class Menu{
protected:
    User* user;
    Data* data;
public:
    explicit Menu(User* u = nullptr, Data* d = nullptr): user(u), data(d){};
    bool setUser(User* u){
        if(user != nullptr) return false;
        user = u;
        return true;
    }
    virtual void mainScreen() const;
};

/**
 * Frontend class that handles Unregistered Client menus
 */
class JustBuy : public Menu{
public:
    JustBuy(Data* d = nullptr){
        user = nullptr;
        data = d;
    }
    void mainScreen() const override;
};

/**
 * Frontend class that handles Registered Client menus
 */
class ClientMenu : public Menu{
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
    }
    void mainScreen() const override{
        std::cout << "here we are\n";
        system("pause");
    }
};

/**
 * Frontend class that handles Manager menus
 */
class ManagerMenu : public CompanyMenu{

};

/**
 * Frontend class that handles Boarding Crew menus
 */
class BoardingMenu : public CompanyMenu{

};

/**
 * Frontend class that handles Service Worker menus
 */
class ServiceMenu : public CompanyMenu{

};

template<typename T>
T readInput();

std::ostream& operator<<(ostream& out, const UserPointer& user);


#endif //MAIN_CPP_MENU_H
