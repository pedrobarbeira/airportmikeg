//
// Created by 35191 on 11/25/2021.
//

#ifndef MIKEGAIRLINES_AIRPORT_H
#define MIKEGAIRLINES_AIRPORT_H

#include"transport.h"
#include"service.h"
#include<list>
#include<queue>

using namespace std;

class Airport{
    string name;
    string country;
    string city;
    list<Transport*> transport;
    queue<Service*> services;
public:
    Airport(string name, string country, string city);
    string getName ();
    string getCountry();
    string getCity;
    void setTransport (Transport &transport);
    void delTransport (Transport &transport);
    void addService (Service &service);
    void delService (Date &date);
};

#endif //MIKEGAIRLINES_AIRPORT_H
