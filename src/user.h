//Created by Pedro Barbeira
#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H

#include <iostream>
#include "bst.h"
#include "ticket.h"

/**
 * User parent class. Acts as an Interface for it's subclasses.
 */
class User{
protected:
    std::string username;
    std::string password;
    char type; //Create A - admin; C - client; S - service; B - boarding
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
    std::string passenger;
    vector<std::string> tickets;
    friend class ClientPointer;
public:
    explicit Client(std::string u = "", std::string p = "", char t = '\0', uint16_t m = 0, std::string psgr = "") : miles(m){
        username = std::move(u);
        password = std::move(p);
        tickets.clear();
        passenger = psgr;
        type = t;
    }
    uint16_t getMiles() const{
        return miles;
    }
    std::string getPassenger() const{
        return passenger;
    }
    vector<std::string> getTickets() const{
        return tickets;
    }
    void setTickets(std::vector<std::string> v){
        tickets = v;
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
    Plane* plane;
    Staff* staff;
    std::queue<ServiceTicket*> serviceList;
    std::list<ServiceTicket*> completedServices;
public:
    explicit Company(std::string u = "", std::string p = "", char t = '\0', Airport* a = nullptr, Plane* pln = nullptr){
        username = std::move(u);
        password = std::move(p);
        airport = a;
        plane = pln;
        type = t;
    }
    Airport* getAirport() const{
        return airport;
    }
    void setAirport(Airport* airport){
        this->airport = airport;
    }
    Staff* getStaff() const{
        return staff;
    }
    void setStaff(Staff* staff){
        this->staff = staff;
    }
    void addNewService(ServiceTicket *service){
        serviceList.push(service);
    }
    void addCompleteService(ServiceTicket *service){
        completedServices.push_back(service);
    }
    std::queue<ServiceTicket*> getService() const{
        return serviceList;
    }
    std::list<ServiceTicket*> getCompleted() const{
        return completedServices;
    }
    Plane* getPlane() const{
        return plane;
    }
    void setType(char t){
        type = t;
    }
    bool operator==(const Company& rhs) const{
        return username == rhs.username;
    }
    bool operator<(const Company& rhs) const{
        if(type != '\0' && rhs.type != '\0'){
            if(type == rhs.type)
                return username < rhs.username;
            else return type < rhs.type;
        }
        return username < rhs.username;
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
