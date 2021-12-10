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

void Airport::setTransport(Transport *transport) {
    Airport::transport.push_back(transport);
}

void Airport::delTransport(Transport *transport) {
    this->transport.remove(transport);
}

void Airport::addService(Service *service) {
    services.push(service);
}

void Airport::delService(Date date) {
    services.front()->getResponsible();
    services.front()->setComplete(date);
    services.pop();
}

