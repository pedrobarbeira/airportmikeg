//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_STAFF_H
#define MIKEGAIRLINES_STAFF_H

#include <iostream>
#include <list>

using namespace std;

class Staff{
    unsigned id;
    string name;
    unsigned phone;
public:
    explicit Staff(string name = "");
    void setId(size_t id);
    void setPhone (unsigned n);
    string getName() const;
    unsigned getPhone() const;
    unsigned getId() const;
};

class InvalidNumber : public exception{
private:
    string e;
public:
    InvalidNumber(){
        e = "Invalid number";
    };
    string getError() const{
        return e;
    }
};



#endif //MIKEGAIRLINES_STAFF_H


