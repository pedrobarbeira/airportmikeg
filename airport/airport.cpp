//
// Created by Joao on 27/11/21.
//

#include <algorithm>
#include "airport.h"

Terminal::Terminal(int i) {
    idNumber = i;
    occupied = false;
    plane = nullptr;
}


Airport::Airport() {

}
/**
 * main constructor for Airport objects.
 * @param idName forces the id to be a 3 letter word, all caps;
 * @param name
 * @param country
 * @param city
 */
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

vector<int> Airport::getTerminals() const {
    vector<int> term;
    for (unsigned i{0}; i < terminals.size(); i++){
        if (terminals[i]->getOccupied() == true) {
            term.push_back(i);
        }
    }
    return term;
}

vector<Service*> Airport::getServices()  {
    vector<Service*> temp;
    queue<Service*> q;
    while (!services.empty()){
        temp.push_back(services.front());
        q.push(services.front());
        services.pop();
    }
    services = q;
    return temp;
}

Service* Airport::nextService() {
    return services.front();
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
/**
 * Method to set a service as complete and remove it from the front of the queue of services.
 * @param date
 */
void Airport::delService(Date date) {
    services.front()->getResponsible();
    services.front()->setComplete(date);
    complete.push_back(services.front());
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

void Airport::activateTerminal(int i) {
    Terminal *t = new Terminal(i);
    terminals.push_back(t);
}

void Airport::setTerminal(Plane *plane) {
    for (unsigned i{0}; i < terminals.size(); i++){
        if (terminals[i]->getOccupied() == false) {
            terminals[i]->setOccupied();
            terminals[i]->plane = plane;


        }
    }
}

bool Airport::operator < (Airport &a){

    if (country == a.country) {
        if (city == a.city) return idName < a.idName;
        return city < a.city;
    }
    return country < a.country;
}
