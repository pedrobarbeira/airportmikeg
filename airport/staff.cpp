//
// Created by othello on 09/12/21.
//

#include "staff.h"

using namespace std;


Staff::Staff(string name) {
    this->name= name;
}

void Staff::setId(size_t id) {
    this->id = id;
}

void Staff::setPhone(unsigned phone) {
    if (phone > 999999999 | phone < 910000000) throw InvalidNumber();
    else this->phone = phone;
}

string Staff::getName() const {
    return name;
}

unsigned Staff::getPhone() const {
    return phone;
}

unsigned Staff::getId() const {
    return id;
}
