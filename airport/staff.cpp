//
// Created by othello on 27/11/21.
//

#include "staff.h"

Staff::Staff(string name) {
    this->name= name;
}

void Staff::addHistory(Service &service) {
    this->history.push_back(&service);
}
