//Created by Pedro Barbeira (up201303693;
#include "voyage.h"

Connection::~Connection(){
    delete in;
    delete out;
}

/**Voyage*/
Voyage::~Voyage(){
    for (auto ticket: tickets)
        delete ticket;
    for (auto flight : route)
        delete flight;
}
bool Voyage::addTicket(Ticket* t){
    for(auto it : tickets){
        if (it == t) return false;
    }
    tickets.push_back(t);
    return true;
}
bool Voyage::addFlight(Flight* f){
    std::list<Flight*>::iterator it = route.begin();
    if(f->getDestination() == (*it)->getOrigin()) {
        route.push_front(f);
        return true;
    }
    else if(f->getOrigin() == (*it)->getDestination()){
        route.push_back(f);
        return true;
    }
    else return false;
}
bool Voyage::addConnection(Connection* c) {
    bool added = false;
    std::list<Flight *>::iterator it = route.begin();
    if (route.size() == 1) {
        if (c->getOut()->getDestination() == (*it)->getOrigin()) {
            route.push_front(c->getOut());
            route.push_front(c->getIn());
            added = true;
        } else if (c->getIn()->getOrigin() == (*it)->getDestination()) {
            route.push_back(c->getIn());
            route.push_back(c->getOut());
            added = true;
        } else if (c->getIn()->getOrigin() == (*it)->getOrigin() &&
                   c->getOut()->getDestination() == (*it)->getDestination()) {
            route.insert(it, c->getIn());
            route.insert(it, c->getOut());
            route.erase(it);
            added = true;
        } else added = false;
    } else {
        bool found = false;
        while (it != route.end()) {
            if ((*it)->getOrigin() == c->getIn()->getOrigin() &&
                (*it)->getDestination() == c->getOut()->getDestination()) {
                found = true;
                break;
            }
            it++;
        }
        if (!found) return found;
        else {
            route.insert(it, c->getIn());
            route.insert(it, c->getOut());
            route.erase(it);
            added = true;
        }
    }
    delete c;
    return added;
}

void Voyage::printRoute(std::ostream& out) const{
    auto it = route.begin();
    while(it != route.end()){
        (*it)->print(out);
        it++;
    }
}
