//
// Created by Joao on 27/11/21.
//

#include "airport.h"


Airport::Airport(string idName, string name, string country, string city) {
    this->idName = idName;
    this->name = name;
    this->country = country;
    this->city = city;
}

string Airport::getidCode(){
    return idName;
}

void Airport::setTransport(class Transport *transport) {
    Airport::transport.push_back(transport);
}

void Airport::delTransport(class Transport *transport) {
    this->transport.remove(transport);
}

void Airport::addService(class Service *service) {
    services.push(service);
}

void Airport::delService(class Date date) {
    services.front()->getResponsible();
    services.front()->setComplete(date);
    services.pop();
}

