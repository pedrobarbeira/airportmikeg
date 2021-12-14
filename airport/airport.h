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
    int idNumber;
    bool occupied;
public:
    void setOccupied(){
        if (occupied == false) occupied = true;
    }
    bool getOccupaied(int n){
        return occupied;
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
public:
    Airport(string idName, string name, string country, string city);
    string getidCode() const;
    string getName () const;
    string getCountry() const;
    string getCity() const;
    void setTransport (Transport *transport);
    void delTransport (Transport *transport);
    void addService (Service *service);
    void delService (Date date);
    list<Time>nextTransportMetro (Time time);
    list<Time>nextTransportBus (Time time);
    list<Time>nextTransportTrain (Time time);
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