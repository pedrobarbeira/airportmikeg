//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_AIRPORT_H
#define MIKEGAIRLINES_AIRPORT_H

#include <iostream>
//#include "mainmenu.h"
#include"transport.h"
#include"service.h"
#include<list>
#include<queue>

using namespace std;

class Airport{
    string idName;
    string name;
    string country;
    string city;
    list<Transport*> transport;
    queue<Service*> services;
public:
    Airport(string idName, string name, string country, string city);
    string getidCode();
    string getName ();
    string getCountry();
    string getCity;
    void setTransport (class Transport &transport);
    void delTransport (class Transport &transport);
    void addService (class Service &service);
    void delService (class Date* date);
};

#endif //MIKEGAIRLINES_AIRPORT_H
