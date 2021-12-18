//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_AIRPORT_H
#define MIKEGAIRLINES_AIRPORT_H

#include <iostream>
#include"service.h"
#include<list>
#include<queue>
#include"date.h"
#include"bst.h"

using namespace std;


class Transport{
    string id;
    char type; // m --> metro; b --> bus; t --> train
    uint16_t distance;
    Time *time;
    friend class Airport;
public:
    Transport(string id, char c);
    void setId(string id) {
        this->id = id;};
    string getId() const{
        return id;};
    void setType(char c){
        type = c;}
    char getType() const{
        return type;};
    string getTransport() const;
    void setDistance (uint16_t distance){
        this->distance = distance;}
    uint16_t getDistance () const{
        return distance;};
    void addTime(Time *time) {
        this->time = time;};
    Time* getTime () const{
        return time;};
    bool operator <(Transport &t);
    bool operator ==(Transport &t);
    bool operator !=(Transport &t);
};


class TransportPointer : public BSTPointer<Transport> {
public:
    explicit TransportPointer(Transport *t) {
        pointer = t;
    }

};

class Terminal{
    string id;
    Plane* plane;
    friend class Airport;
public:
    Terminal() {id = ""; plane = nullptr;};
    Terminal(string i){
        id = i; plane = nullptr;};
    void setId (string id){
        this->id = id;}
    string getId() const{
        return id;}
    string getTerminalNumber() const{
        return id;};
    void setPlane(Plane *plane){
        this-> plane = plane;};
    Plane* getPlane() const{
        return plane;}
    bool getOccupied() const {
        return plane != nullptr;
    }
 
};

class Airport{
    string idName;
    string name;
    string country;
    string city;
    vector<Terminal*> terminals;
    BST<TransportPointer> transport;
    //BST<Transport> transport;
    queue<ServiceTicket*> services;
    list<ServiceTicket*> complete;
    list<Staff*> staff;
    friend class Terminal;
    friend class Transport;
public:
    explicit Airport(std::string id = "", std::string n = "", std::string ctry = "", std::string cty = "") :
        transport(TransportPointer(nullptr)), idName(std::move(id)),
        name(std::move(n)), country(std::move(ctry)), city(std::move(cty)){}
    void setName(string name){this->name = name;}
    void setId(string id){idName = id;}
    void setCountry(string country){this->country = country;}
    void setCity(string city){this->city = city;}
    string getidCode() const;
    string getName () const;
    string getCountry() const;
    string getCity() const;
    vector<Terminal*> getEmptyTerminals() const;
    vector<Terminal*> getTerminals() const;
    vector<ServiceTicket*> getServices();
    vector<ServiceTicket*> getCompleteServices() const;
    ServiceTicket* nextService();
    vector<Staff*> getStaff() const;
    void setTransport (TransportPointer transport);
    void delTransport (TransportPointer transport);
    void addService (ServiceTicket *service);
    void delService (Time *date);
    bool addStaff(Staff*);
    bool delStaff(Staff*);
    vector<Transport*> getTransport() const;
    /*list<Time*>nextTransportMetro (Time *time) const;
    list<Time*>nextTransportBus (Time *time) const;
    list<Time*>nextTransportTrain (Time *time) const;*/
    void activateTerminal (string i);
    void setTerminal(Plane *plane, string id);
    void printAirport();
    void printService();
    void printStaff();
    bool operator < (Airport &s);
    bool operator==(const Airport& rhs) const{
        return idName == rhs.idName;
    }
    bool operator!=(const Airport& rhs) const{
        return !(*this == rhs);
    }
    bool operator<(const Airport& rhs) const{
        return idName < rhs.idName;
    }

};


class IncorrectLength{
private:
    string e;
public:
    IncorrectLength(){
        e = "Use 3 letter word";
    };
    string getError() const{
        return e;
    }
};
#endif