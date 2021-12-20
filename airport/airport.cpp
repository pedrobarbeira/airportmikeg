//
// Created by Joao on 27/11/21.
//

#include <algorithm>
#include "airport.h"
using namespace std;

///////////////////////////////////// T R A N S P O R T /////////////////////////////

Transport::Transport(char c) {
    this->id = c + to_string(idTransport);
    idTransport++;
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

vector<ServiceTicket*> Airport::getCompleteServices() const {
    vector<ServiceTicket*> temp;
    for (auto it: complete) temp.push_back(it);
    return temp;
}

vector<Staff*> Airport::getStaff() const {
    vector<Staff*> temp;
    for (auto it : staff) temp.push_back(it);
    return temp;
    /*
    vector<Staff *> ret;
    queue<ServiceTicket *> s = services;
    Staff *check;
    bool found;
    while (!s.empty()) {
        check = s.front()->getResponsible();
        found = false;
        for (auto it: ret) {
            if (check == it) {
                found = true;
                break;
            }
        }
        if (!found) ret.push_back(check);
        s.pop();
    }
    for (auto it : complete) {
        while (!s.empty()) {
            check = s.front()->getResponsible();
            found = false;
            for (auto it: ret) {
                if (check == it) {
                    found = true;
                    break;
                }
            }
            if (!found) ret.push_back(check);
        }
        return ret;
    }*/
}

ServiceTicket* Airport::nextService() {
    return services.front();
}

void Airport::setTransport(TransportPointer transport) {
    this->transport.insert(transport);
}

vector<TransportPointer> Airport::getTransportPointer() const {
    vector<TransportPointer> t;
    BSTItrIn<TransportPointer> it(transport);
    while(!it.isAtEnd()){
        t.push_back(it.retrieve());
        it.advance();
    }
    return t;
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
void Airport::delService(Time *date) {
    //services.front()->getResponsible();
    services.front()->setComplete(date);
    complete.push_back(services.front());
    services.pop();
}

bool Airport::addStaff(Staff* staff){
    for (auto i : this->staff){
        if (i == staff) {
            cout << staff->getName() << " with id " << staff->getId() << "already in Airport staff";
            system("pause");
            return false;
        }
    }
    this->staff.push_back(staff);
    return true;
}

bool Airport::delStaff(Staff *staff) {
    for (auto i : this->staff) {
        if (i == staff) this->staff.remove(i);
        return true;
    }
    cout << staff->getName() << " not found in Airport staff";
    system("pause");
    return false;
    }

//vector<Staff*> getStaff() const{}

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
    Terminal *t = new Terminal(i, this->idName);
    terminals.push_back(t);
}

void Airport::setTerminal(Plane *plane, string id = "") {
    for (unsigned i{0}; i < terminals.size(); i++){
        if (!terminals[i]->getOccupied() && terminals[i]->getId() == ""){
            terminals[i]->setPlane(plane); break;}
        else if (!terminals[i]->getOccupied() && terminals[i]->getTerminalNumber() == id) {
            terminals[i]->setPlane(plane); break;}
    }
}

bool Airport::delTerminal(string id){
    for (unsigned it{}; it < terminals.size(); it++){
        if (terminals[it]->id == id && terminals[it]->getOccupied()) return false;
        else if (terminals[it]->id == id) {
            terminals.erase(terminals.begin()+it);
            return true;
        }
    }
    return false;
}

void Airport::printAirport() {
    if (!terminals.empty()) {
        cout << "\n\t\t" << "Active Terminals:";
        for (auto it : terminals){
            cout << "\n\t\t" << it->getId();
            switch (it->getOccupied()){
                case true: cout << " - " << it->getPlane()->getPlate(); break;
                case false:  cout << " - empty";
            }
        }
    }
}

void Airport::printService() {
    char a;
    switch (services.empty()){
        case true: cout << "\n\t======  No services scheduled  ======\n"; break;
        case false: {
            cout << "\n\t========  Has " << services.size() << " scheduled service(s)  =========\n";
            cout << "\t\tNext service is a ";
            switch (nextService()->getType()){
                case 'c' : {
                    cout << "cleaning service with " << nextService()->getTasksLeft().size() << " task(s) left (";
                    for (int i=0; i < nextService()->getTasksLeft().size(); ) {
                        cout << nextService()->getTasksLeft()[i];
                        i++;
                        if (i == nextService()->getTasksLeft().size()) cout << ") ";
                        else cout << ", ";
                    }
                    cout << "\n\tscheduled for ";
                    nextService()->getCreated()->printDate();
                    system("pause");
                    break;
                }
                case 'm' : {
                    cout << "maintenance service with " << nextService()->getTasksLeft().size() << " task(s) left (";
                    for (int i=0; i < nextService()->getTasksLeft().size();) {
                        cout << nextService()->getTasksLeft()[i];
                        i++;
                        if (i == nextService()->getTasksLeft().size()) cout << ") ";
                        else cout << ", ";
                    }
                    cout << "\n\tscheduled for ";
                    nextService()->getCreated()->printDate();
                    system("pause");
                    break;
                }
            }
            if (nextService()->getResponsible() == nullptr) cout << ".";
            else cout << " under " << nextService()->getResponsible()->getName() << "'s("
                      << nextService()->getResponsible()->getPhone() << ") supervision";
        }
    }
    std::cout <<"\n\n"; system("pause");
}

bool Airport::operator < (Airport &a){

    if (country == a.country) {
        if (city == a.city) return idName < a.idName;
        return city < a.city;
    }
    return country < a.country;
}


