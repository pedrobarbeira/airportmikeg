//Created by Pedro Barbeira
#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H

#include <iostream>
#include "bst.h"

/**
 * User parent class. Acts as an Interface for it's subclasses.
 */
class User{
protected:
    std::string username;
    std::string password;
    char type; //Create
    Date* registration;
    friend class UserPointer;
    friend class CompanyPointer;
    friend class ClientPointer;
public:
    explicit User(std::string u = "", std::string p = "", char t = '\0'):
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
    Date* getDate() const{
        return registration;
    }
    bool operator==(const User& rhs) const{
        return username == rhs.username;
    }
    bool operator<(const User& rhs) const{
        return username < rhs.username;
    }
};
//Lets keep this on the "maybe pile" for now
class Client : public User{
    uint16_t miles;
    Passenger* passenger;
    vector<Ticket*> tickets;
    friend class ClientPointer;
public:
    explicit Client(std::string u = "", std::string p = "", char t = '\0', uint16_t m = 0, Passenger* psgr = nullptr) : miles(m){
        username = std::move(u);
        password = std::move(p);
        tickets.clear();
        passenger = psgr;
        type = t;
    }
    bool operator==(const Client& rhs) const{
        return username == rhs.username;
    }
    bool operator<(const Client& rhs) const{
        return username < rhs.username;
    }
};

class Company : public User{
protected:
    Airport* airport;
public:
    explicit Company(std::string u = "", std::string p = "", char t = '\0'){
        username = std::move(u);
        password = std::move(p);
        airport = nullptr;
        type = t;
    }
    bool operator==(const Company& rhs) const{
        return username == rhs.username;
    }
    bool operator<(const Company& rhs) const{
        if(type == rhs.type)
            return username < rhs.username;
        else return type < rhs.type;
    }
};

class Admin : public Company{
public:
    explicit Admin(std::string u = "", std::string p = "", char t = '\0', Airport* a = nullptr){
        username = std::move(u);
        password = std::move(p);
        airport = a;
        type = t;
    }
};

class Manager : public Company{
public:
    explicit Manager(std::string u = "", std::string p = "", char t = '\0', Airport* a = nullptr){
        username = std::move(u);
        password = std::move(p);
        airport = a;
        type = t;
    }
};

class Boarding : public Company{
    Plane* plane;
public:
    explicit Boarding(std::string u = "", std::string p = "", char t = '\0', Airport* a = nullptr, Plane* pln = nullptr){
        username = std::move(u);
        password = std::move(p);
        airport = a;
        plane = pln;
        type = t;
    }
};

class Service : public Company{
    Staff* staff;
    std::queue<ServiceTicket*> serviceList;
    std::list<ServiceTicket*> completedServices;
public:
    explicit Service(std::string u = "", std::string p = "", char t = '\0', Airport* a = nullptr){
        staff = nullptr;
        username = std::move(u);
        password = std::move(p);
        airport = a;
        type = t;
        completedServices.clear();
    }
};



#endif //MAIN_CPP_USER_H
