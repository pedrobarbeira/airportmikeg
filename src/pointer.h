//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_POINTER_H
#define MAIN_CPP_POINTER_H

#include "bst.h"
#include "voyage.h"
#include "user.h"

/**
 * Encapsulation class for pointers to Plane objects.
 * Used to store Plane pointers in the Data BSTs
 */
class PlanePointer : public BSTPointer<Plane>{
public:
    explicit PlanePointer(Plane* p = nullptr){
        pointer = p;
    }
    bool operator==(Plane* p) const{
        return pointer->plate == p->plate;
    }
    bool operator==(std::string p) const{
        return pointer->plate == p;
    }
    bool operator<(const PlanePointer& rhs) const {
        return pointer->plate < rhs.pointer->plate;
    }
};

/**
 * Encapsulation class for pointers to FLight objects.
 * Used to store Flight pointers in the Data BSTs
 */
class FlightPointer : public BSTPointer<Flight>{
public:
    explicit FlightPointer(Flight* f = nullptr) {
        pointer = f;
    }
    bool operator==(const Flight* f) const{
        return f->flightID == pointer->flightID;
    }
    bool operator==(const std::string& id) const{
        return pointer->flightID == id;
    }
    bool operator<(const FlightPointer& rhs) const{
        return this->pointer->flightID < (*rhs).flightID;
    }
};

/**
 * Encapsulation class for the Airport class
 * Stores the created Airports and which flights are related to them in
 * order to avoid unnecessary searches.
 */
class AirportPointer : public BSTPointer<Airport>{
    BST<FlightPointer> inFlights;
    BST<FlightPointer> outFlights;
public:
    explicit AirportPointer(Airport* a = nullptr) :
            inFlights(FlightPointer(nullptr)), outFlights(FlightPointer(nullptr)){
        pointer = a;
    };
    bool addFlight(Flight* f);
    std::vector<Flight*> getFlightsTo(Airport* a) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min) const;
    std::vector<Flight*> getFlightsTo(Airport* a, Date* min, Date* max) const;
    std::vector<Flight*> getFlightsFrom() const;
    std::vector<Flight*> getFlightsFrom(Date* min) const;
    std::vector<Flight*> getFlightsFrom(Date* min, Date* max) const;
    Flight* find(std::string id) const;
    bool addIn(Flight* f){
        FlightPointer fptr(f);
        return inFlights.insert(fptr);
    }
    bool addOut(Flight* f){
        FlightPointer fptr;
        return outFlights.insert(fptr);
    }
    //Add operator overloading to allow diffrent types of searches
    bool operator==(const AirportPointer& rhs) const{
        return (*pointer).getidCode() == (*pointer).getidCode();
    }
    bool operator<(const AirportPointer& apf) const{
        return pointer->getidCode() < apf.pointer->getidCode();
    }
};

class VoyagePointer : public BSTPointer<Voyage>{
public:
    explicit VoyagePointer(Voyage* v = nullptr){
        pointer = v;
    }
    bool operator==(const VoyagePointer& rhs) const{
        return (*pointer).getId() == (*rhs.pointer).getId();
    }
    bool operator<(const VoyagePointer& rhs) const{
        return (*pointer).getId() < (*rhs.pointer).getId();
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
    bool operator==(UserPointer& rhs) {
        return pointer->username == rhs.pointer->username;
    }
    bool operator<(const UserPointer& rhs) const{
        return pointer->username < rhs.pointer->username;
    }
};

class ClientPointer : public UserPointer{
public:
    explicit ClientPointer(Client* u = nullptr){
        pointer = u;
    }
    bool operator==(const ClientPointer & rhs) const{
        return pointer->username == rhs.pointer->username;
    }
    bool operator==(ClientPointer & rhs) const{
        return pointer->username == rhs.pointer->username;
    }
    bool operator<(const ClientPointer& rhs) const{
        return pointer->username < rhs.pointer->username;
    }
};

class CompanyPointer : public UserPointer{
public:
    explicit CompanyPointer(Company* u = nullptr){
        pointer = u;
    }
    bool operator==(const CompanyPointer & rhs) const{
        return pointer->username == rhs.pointer->username;
    }
    bool operator==(CompanyPointer & rhs) const{
        return pointer->username == rhs.pointer->username;
    }
    bool operator<(const CompanyPointer& rhs) const{
        return pointer->username < rhs.pointer->username;
    }
};


#endif //MAIN_CPP_POINTER_H