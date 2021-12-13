//
// Created by Joao on 27/11/21.
//

#include <algorithm>
#include "airport.h"


Airport::Airport(string idName, string name, string country, string city) {
    if (idName.length() != 3) throw IncorrectLength();
    else {
        for (auto &c : idName){
            c = toupper(c);}
        this->idName = idName;
    }
    this->name = name;
    this->country = country;
    this->city = city;
}

string Airport::getidCode() const{
    return idName;
}

string Airport::getName() const {
    return name;
}

string Airport::getCountry() const {
    return country;
}

string Airport::getCity() const {
    return city;
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

list<Time> Airport::nextTransportBus(Time time) {
    list<Time> next;
    list<Time> temp;
    for (auto it : transport){
        if (it->getType() == 'b'){
            temp = it->getTimetable();
            for (auto itr : temp){
                if (time.getHour() < itr.getHour()) next.push_back(itr);
                else if (time.getHour() == itr.getHour() && time.getMinute() < itr.getMinute()) next.push_back(itr);
            }
        }
    }
    return next;
}

list<Time> Airport::nextTransportMetro(Time time) {
    list<Time> next;
    list<Time> temp;
    for (auto it : transport){
        if (it->getType() == 'm'){
            temp = it->getTimetable();
            for (auto itr : temp){
                if (time.getHour() < itr.getHour()) next.push_back(itr);
                else if (time.getHour() == itr.getHour() && time.getMinute() < itr.getMinute()) next.push_back(itr);
            }
        }
    }
    return next;
}

list<Time> Airport::nextTransportTrain(Time time) {
    list<Time> next;
    list<Time> temp;
    for (auto it : transport){
        if (it->getType() == 't'){
            temp = it->getTimetable();
            for (auto itr : temp){
                if (time.getHour() < itr.getHour()) next.push_back(itr);
                else if (time.getHour() == itr.getHour() && time.getMinute() < itr.getMinute()) next.push_back(itr);
            }
        }
    }
    return next;
}

