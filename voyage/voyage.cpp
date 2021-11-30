//Created by Pedro Barbeira (up201303693;
#include "voyage.h"

/**Flight*/
void Flight::print(ostream& out) const{
    out << flightID << " ";
    if(departure != nullptr) departure->print(out);
    if(arrival != nullptr) arrival->print(out);
    //finish with airport and plane
    std::cout << '\n';
}

/**Voyage*/
bool Voyage::addConnection(Connection& c){
    //Add case where connection is direct to the first flight
    //Take a look at control flow for cases where Connection just has 1 flight
    //- these can only be appended to the end or inserted to the begin
    //Fix case where connection is appended to the end
    bool found = false;
    std::list<Flight*>::const_iterator it = this->route.begin();
    while(it != route.end()) {
        if ((*it)->getOrigin() == c.getIn()->getOrigin()) {
            found = true;
            break;
        }
        it++;
    }
    if(!found) return false;
    else{
        if (route.size() == 1) {
            if ((*route.begin())->getDestination() == c.getOut()->getDestination()) {
                this->route.insert(it, c.getIn());
                this->route.insert(it, c.getOut());
                this->route.erase(it);
                return true;
            }
            else return false;
        }
        else {/*
            std::list<Flight*>::const_iterator last = this->route.end();
            if(it == last){
                it--;
                if((*it)->getDestination() == c.getIn()->getOrigin()) {
                    this->route.erase(it);
                    this->route.push_back(c.getIn());
                    this->route.push_back(c.getOut());
                    return true;
                }
                else return false;
            } else {*/
                if ((*it)->getDestination() == c.getOut()->getDestination()) {
                    this->route.insert(it, c.getIn());
                    if(c.getOut() != nullptr) this->route.insert(it, c.getOut());
                    this->route.erase(it);
                    return true;
                } else return false;
            }
        }
    }
//}

void Voyage::printRoute(std::ostream& out) const{
    auto it = route.begin();
    while(it != route.end()){
        (*it)->print(out);
        it++;
    }
}
