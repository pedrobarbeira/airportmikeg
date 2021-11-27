//
// Created by Joao on 27/11/21.
//

#include "airport.h"

Airport::Airport(string name, string country, string city) {
    this->name = name;
    this->country = country;
    this->city = city;
}

void Airport::setTransport(Transport &transport) {

}

void Airport::delTransport(Transport &transport) {

}

void Airport::addService(Service &service) {
    services.push(&service);
}

void Airport::delService(Date &date) {
    services.front()->setComplete(date);
    services.pop();
}