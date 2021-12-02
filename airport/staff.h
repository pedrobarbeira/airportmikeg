//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_STAFF_H
#define MIKEGAIRLINES_STAFF_H

#include <iostream>
#include "service.h"
#include <list>


using namespace std;

class Staff{
    string name;
    list<Service*> history;
public:
    Staff(string name);
    void addHistory (Service &service);
    void getName();
    list<class Service*> getHistory ();
};

#endif //MIKEGAIRLINES_STAFF_H


