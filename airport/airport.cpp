//
// Created by Joao on 27/11/21.
//

#include <algorithm>
#include "airport.h"
using namespace std;

///////////////////////////////////// T R A N S P O R T /////////////////////////////

Transport::Transport(string id, char c) {
    this->id = id;
    type=c;
    distance=0;
    this->time = nullptr;
}

string Transport::getTransport() const{
    string t;
    switch (type) {
        case 'm':
            t = "Metro";
            break;
        case 'b':
            t = "Bus";
            break;
        case 't':
            t = "Train";
            break;
    }
    if (t.empty()) return "invalid transport";
    return t;
}

bool Transport::operator<(Transport &t) {
    if (time == t.time) {
        if (distance == t.distance) return type < t.type;
        return distance < t.distance;
    }
    return time < t.time;
}

bool Transport::operator==(Transport &t){
    if (time == t.time && distance == t.distance && type == t.type) return true;
    return false;
}

bool Transport::operator!=(Transport &t){
    return !((*this)==t);
}


////////////////////////////////////// T E R M I N A L //////////////////////////////




/////////////////////////////////////// A I R P O R T ///////////////////////////////

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

vector<Terminal*> Airport::getEmptyTerminals() const {
    vector<Terminal*> ret;
    for (auto terminal : terminals)
        if(!terminal->getOccupied())
            ret.push_back(terminal);
    return ret;
}

vector<Terminal*> Airport::getTerminals() const {
    return terminals;
}

vector<ServiceTicket*> Airport::getServices() {
    vector<ServiceTicket*> temp;
    queue<ServiceTicket*> q;
    while (!services.empty()){
        temp.push_back(services.front());
        q.push(services.front());
        services.pop();
    }
    services = q;
    return temp;
}

ServiceTicket* Airport::nextService() {
    return services.front();
}

void Airport::setTransport(TransportPointer transport) {
    this->transport.insert(transport);
}

void Airport::delTransport(TransportPointer transport) {
    this->transport.remove(transport);
}

void Airport::addService(ServiceTicket *service) {
    services.push(service);
}
/**
 * Method to set a service as complete and remove it from the front of the queue of services.
 * @param date
 */
void Airport::delService(Date *date) {
    //services.front()->getResponsible();
    services.front()->setComplete(date);
    complete.push_back(services.front());
    services.pop();
}

vector<Transport*> Airport::getTransport() const {
    vector<Transport*> temp;
    BSTItrIn<TransportPointer> itr(transport);
    while (!itr.isAtEnd()){
        temp.push_back(itr.retrieve().getPointer());
        itr.advance();
    }
    return temp;
}
/*
list<Time*> Airport::nextTransportBus(Time *time) const {
    list<Time*> next;
    list<Time*> temp;
    BSTItrIn<TransportPointer> itr(transport);
    while (!itr.isAtEnd()){
        if (itr.retrieve().getPointer()->getType() == 'b'){
            temp.push_back(itr.retrieve().getPointer()->getTime());
            for (auto it : temp){
                if (time < it) next.push_back(it);
            }
        }
    }
    return next;
}

list<Time*> Airport::nextTransportMetro(Time *time) const {
    list<Time*> next;
    list<Time*> temp;
    BSTItrIn<TransportPointer> itr(transport);
    while (!itr.isAtEnd()){
        if (itr.retrieve().getPointer()->getType() == 'm'){
            temp.push_back(itr.retrieve().getPointer()->getTime());
            for (auto it : temp){
                if (time < it) next.push_back(it);
            }
        }
    }
    return next;
}

list<Time*> Airport::nextTransportTrain(Time *time) const {
    list<Time*> next;
    list<Time*> temp;
    BSTItrIn<TransportPointer> itr(transport);
    while (!itr.isAtEnd()){
        if (itr.retrieve().getPointer()->getType() == 't'){
            temp.push_back(itr.retrieve().getPointer()->getTime());
            for (auto it : temp){
                if (time < it) next.push_back(it);
            }
        }
    }
    return next;
}
*/
void Airport::activateTerminal(string i) {
    Terminal *t = new Terminal(i);
    terminals.push_back(t);
}

void Airport::setTerminal(Plane *plane, string id = "") {
    for (unsigned i{0}; i < terminals.size(); i++){
        if (!terminals[i]->getOccupied() && terminals[i]->id == ""){
            terminals[i]->setPlane(plane); break;}
        else if (!terminals[i]->getOccupied() && terminals[i]->id == id) {
            terminals[i]->setPlane(plane); break;}
        else cout << "No Terminals available to dock plane with plate " << plane->getPlate() << endl;
    }
}

void Airport::printAirport() {
    cout << "\n\t(" << idName << ") " << name << " - " << city << ", " << country;
    if (!terminals.empty()) {
        cout << "\n\t\t" << "Active Terminals:";
        for (auto it : terminals){
            cout << "\n\t\t" << it->getId();
            switch (it->getOccupied()){
                case true: cout << " - " << it->getPlane()->getPlate() << "\n"; break;
                case false:  cout << " - empty\n";
            }
        }
        cout << "\t\tServices - ";
        switch (!services.empty()){
            case true: cout << "has " << services.size() << " scheduled\n\n"; break;
            case false: cout << "no services scheduled\n\n"; break;
        }
    }
    system("pause");
}

void Airport::printService() {
    char a;
    cout << "\n\t(" << idName << ") " << name << " - " << city << ", " << country;
    switch (services.empty()){
        case true: cout << "\tno services scheduled\n"; break;
        case false: {
            cout << "\thas " << services.size() << " scheduled\n";
            cout << "\tnext service is a ";
            switch (nextService()->getType()){
                case 'c' : {
                    cout << "cleaning service with " << nextService()->getTasksLeft().size() << " left (";
                    for (int i=0; i < nextService()->getTasksLeft().size(); i++) {
                        cout << nextService()->getTasksLeft()[i];
                        if (i == nextService()->getTasksLeft().size()) cout << ") ";
                        else cout << ", ";
                    }
                }
                case 'm' : {
                    cout << "maintenance service with " << nextService()->getTasksLeft().size() << " left (";
                    for (int i=0; i < nextService()->getTasksLeft().size(); i++) {
                        cout << nextService()->getTasksLeft()[i];
                        if (i == nextService()->getTasksLeft().size()) cout << ") ";
                        else cout << ", ";
                    }
                }
            }
        }
    cout << "\n\tschedulled for " << nextService()->getSchedule()->getDay() << "/"
                                  << nextService()->getSchedule()->getMonth() << "/"
                                  << nextService()->getSchedule()->getYear() << ",";
    //TODO
    if (nextService()->getResponsible() == NULL){
        cout << "\n\tand has no responsible attributed. Do you want to determine one?(y/n)\n>";
        cin >> a;
        switch (a){
            case 'n' : break;
            case 'y' :; //TODO criar funçao geral para introdução de staff
        }
    }
    }
    cout << "\t"    ;
}

bool Airport::operator < (Airport &a){

    if (country == a.country) {
        if (city == a.city) return idName < a.idName;
        return city < a.city;
    }
    return country < a.country;
}


