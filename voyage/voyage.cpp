//Created by Pedro Barbeira (up201303693;
#include "voyage.h"

Connection::Connection(Flight *i, Flight *o) {
        if(i->getDestination() == o->getOrigin()) {
            in = new FlightTicket(i);
            out = new FlightTicket(o);
        }
        else throw InvalidConnection();
}

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
    std::list<FlightTicket*>::iterator it = route.begin();
    if(f->getDestination() == (*it)->getFlight()->getOrigin()) {
        route.push_front(new FlightTicket(f));
        return true;
    }
    else if(f->getOrigin() == (*it)->getFlight()->getDestination()){
        route.push_back(new FlightTicket(f));
        return true;
    }
    else return false;
}

bool Voyage::addConnection(Connection* c) {
    bool added = false;
    std::list<FlightTicket*>::iterator it = route.begin();
    if (route.size() == 1) {
        if (c->getOut()->getFlight()->getDestination() == (*it)->getFlight()->getOrigin()) {
            route.push_front(c->getOut());
            route.push_front(c->getIn());
            added = true;
        } else if (c->getIn()->getFlight()->getOrigin() == (*it)->getFlight()->getDestination()) {
            route.push_back(c->getIn());
            route.push_back(c->getOut());
            added = true;
        } else if (c->getIn()->getFlight()->getOrigin() == (*it)->getFlight()->getOrigin() &&
                   c->getOut()->getFlight()->getDestination() == (*it)->getFlight()->getDestination()) {
            route.insert(it, c->getIn());
            route.insert(it, c->getOut());
            route.erase(it);
            added = true;
        } else added = false;
    } else {
        bool found = false;
        while (it != route.end()) {
            if ((*it)->getFlight()->getOrigin() == c->getIn()->getFlight()->getOrigin() &&
                (*it)->getFlight()->getDestination() == c->getOut()->getFlight()->getDestination()) {
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
        (*it)->getFlight()->print(out);
        it++;
    }
}
