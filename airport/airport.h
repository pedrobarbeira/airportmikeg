//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_AIRPORT_H
#define MIKEGAIRLINES_AIRPORT_H

#include <iostream>
#include"service.h"
#include<list>
#include<queue>
#include"../src/date.h"

using namespace std;

class Transport{
    char type; // m --> metro; b --> bus; t --> train
    uint16_t distance;
    list<Time> timetable;
public:
    Transport();
    Transport(char c);
    Transport(char c, uint16_t d);
    string getTransport();
    uint16_t const getDistance ();
    char const getType();
    void addTime(Time time);
    void delTime(Time time);
    list<Time> getTimetable ();
    bool operator <(Transport* t);
};

class Terminal{
    Plane* plane;
    int idNumber;
public:
    friend class Airport;
    Terminal(int i);
    void setPlane(Plane *plane){
        this-> plane = plane;
    }
    bool getOccupied() const{
        return plane!= nullptr;
    }
    int getTerminalNumber() const{
        return idNumber;
    }
    Plane* getPlane() const{
        return plane;
    }
};

class Airport{
    string idName;
    string name;
    string country;
    string city;
    vector<Terminal*> terminals;
    list<Transport*> transport;
    queue<ServiceTicket*> services;
    list<ServiceTicket*> complete;
public:
    Airport();
    Airport(string idName, string name, string country, string city);
    string getidCode() const;
    string getName () const;
    string getCountry() const;
    string getCity() const;
    vector<Terminal*> getTerminals() const;
    vector<ServiceTicket*> getServices();
    ServiceTicket* nextService();
    void setTransport (Transport *transport);
    void delTransport (Transport *transport);
    void addService (ServiceTicket *service);
    void delService (Date date);
    list<Transport*> getTransport() const;
    list<Time>nextTransportMetro (Time time);
    list<Time>nextTransportBus (Time time);
    list<Time>nextTransportTrain (Time time);
    void activateTerminal (int i);
    void setTerminal(Plane *plane);
    /**
     * Operator to define by which order the airport objects should be added to the BST
     * @param s
     * @return ordering by country > city > idName
     */
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