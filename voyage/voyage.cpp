//Created by Pedro Barbeira (up201303693)
#include "voyage.h"

Connection::Connection(Flight *i, Flight *o) {
        if(i->getDestination() == o->getOrigin()) {
            in = i;
            out = o;
        }
        else throw InvalidConnection();
}

Connection::~Connection(){
    in = nullptr;
    out = nullptr;
}

/**Voyage*/

bool Voyage::addFlight(Flight* f){
    //add Date check
    std::list<FlightPointer>::iterator it = route.begin();
    FlightPointer fptr(f);
    if(f->getDestination() == (*it).getPointer()->getOrigin()) {
        route.push_front(fptr);
        return true;
    }
    else if(f->getOrigin() == (*it).getPointer()->getDestination()){
        route.push_back(fptr);
        return true;
    }
    else return false;
}

bool Voyage::addConnection(Connection* c) {
    //Add Date check
    bool added = false;
    FlightPointer in(c->getIn());
    FlightPointer out(c->getOut());
    std::list<FlightPointer>::iterator it = route.begin();
    if (route.size() == 1) {
        if (c->getOut()->getDestination() == it->getPointer()->getDestination()) {
            route.push_front(out);
            route.push_front(in);
            added = true;
        } else if (c->getIn()->getOrigin() == it->getPointer()->getDestination()) {
            route.push_back(in);
            route.push_back(out);
            added = true;
        } else if (c->getIn()->getOrigin() == it->getPointer()->getDestination() &&
                   c->getOut()->getDestination() == it->getPointer()->getDestination()) {
            route.insert(it, in);
            route.insert(it, out);
            route.erase(it);
            added = true;
        } else added = false;
    } else {
        bool found = false;
        while (it != route.end()) {
            if (it->getPointer()->getOrigin() == c->getIn()->getOrigin() &&
                it->getPointer()->getDestination() == c->getOut()->getDestination()) {
                found = true;
                break;
            }
            it++;
        }
        if (!found) return found;
        else {
            route.insert(it, in);
            route.insert(it, out);
            route.erase(it);
            added = true;
        }
    }
    delete c;
    return added;
}
