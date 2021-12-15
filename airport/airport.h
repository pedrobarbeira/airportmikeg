//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_AIRPORT_H
#define MIKEGAIRLINES_AIRPORT_H

#include <iostream>
#include"transport.h"
#include"service.h"
#include<list>
#include<queue>
#include"../src/date.h"

using namespace std;

class Terminal{
    Plane* plane;
    int idNumber;
    bool occupied;
public:
    friend class Airport;
    Terminal(int i);
    void setOccupied(){
        if (occupied == false) occupied = true;
    }
    bool getOccupied() const{
        return occupied;
    }
    int getTerminalNumber() const{
        return idNumber;
    }
};

class Airport{
    string idName;
    string name;
    string country;
    string city;
    vector<Terminal*> terminals;
    list<Transport*> transport;
    queue<Service*> services;
    list<Service*> complete;
public:
    Airport();
    Airport(string idName, string name, string country, string city);
    string getidCode() const;
    string getName () const;
    string getCountry() const;
    string getCity() const;
    vector<int> getTerminals() const;
    vector<Service*> getServices();
    Service* nextService();
    void setTransport (Transport *transport);
    void delTransport (Transport *transport);
    void addService (Service *service);
    void delService (Date date);
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
    bool operator < (Airport &s);
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