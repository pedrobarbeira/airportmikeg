#ifndef MIKEGAIRLINES_PASSENGER_H
#define MIKEGAIRLINES_PASSENGER_H
#include <iostream>
#include <vector>
#include "luggage.h"



class Passenger{
    std::string name;
public:
    Passenger(std::string n) : name(std::move(n)){};
    std::string getName() const{
        return name;
    }
    void setName(std::string n) {
        name = n;
    }
};


#endif //MIKEGAIRLINES_PASSENGER_H
