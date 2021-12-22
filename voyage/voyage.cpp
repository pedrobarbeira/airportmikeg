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
    f->setVoyage(voyageId);
    FlightPointer fptr(f);
    if(!route.empty()) {
        std::list<FlightPointer>::iterator it = route.begin();
        if (f->getDestination()->airport == (*it).getPointer()->getOrigin()->airport &&
            (*it).getPointer()->getOrigin()->time < f->getDestination()->time) {
            route.push_front(fptr);
            return true;
        } else if (f->getOrigin()->airport == (*it).getPointer()->getDestination()->airport &&
                   (*it).getPointer()->getDestination()->time < f->getOrigin()->time) {
            f->setVoyage(voyageId);
            route.push_back(fptr);
            return true;
        } else {
            f->setVoyage("");
            return false;
        }
    }
    else{
        route.push_front(fptr);
        return true;
    }
}

bool Voyage::addConnection(Connection* c) {
    //Add Date check
    bool added = false;
    FlightPointer in(c->getIn());
    FlightPointer out(c->getOut());
    in.getPointer()->setVoyage(voyageId);
    out.getPointer()->setVoyage(voyageId);
    std::list<FlightPointer>::iterator it = route.begin();
    if (route.size() == 1) {
        if (c->getOut()->getDestination()->airport == it->getPointer()->getDestination()->airport &&
            it->getPointer()->getDestination()->time < c->getOut()->getDestination()->time) {
            route.push_front(out);
            route.push_front(in);
            added = true;
        } else if (c->getIn()->getOrigin()->airport == it->getPointer()->getDestination()->airport &&
                   it->getPointer()->getOrigin()->time < c->getOut()->getOrigin()->time) {
            route.push_back(in);
            route.push_back(out);
            added = true;
        } else if (c->getIn()->getOrigin()->airport == it->getPointer()->getDestination()->airport &&
                   it->getPointer()->getOrigin()->time < c->getOut()->getOrigin()->time &&
                   c->getOut()->getDestination()->airport == it->getPointer()->getDestination()->airport &&
                   it->getPointer()->getDestination()->time < c->getOut()->getDestination()->time) {
            route.insert(it, in);
            route.insert(it, out);
            route.erase(it);
            added = true;
        } else {
            added = false;
        }
    } else {
        bool found = false;
        while (it != route.end()) {
            if (it->getPointer()->getOrigin()->airport == c->getIn()->getOrigin()->airport &&
                it->getPointer()->getOrigin()->time < c->getOut()->getOrigin()->time &&
                it->getPointer()->getDestination()->airport == c->getOut()->getDestination()->airport&&
                it->getPointer()->getDestination()->time < c->getOut()->getDestination()->time) {
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
    if(!added){
        in.getPointer()->setVoyage("");
        out.getPointer()->setVoyage("");
    }
    return added;
}
