#ifndef MIKEGAIRLINES_PASSENGER_H
#define MIKEGAIRLINES_PASSENGER_H
#include <iostream>
#include <vector>
#include "luggage.h"



class Passenger{
    std::string name;
public:
    Passenger(std::string name, bool checkinpass);
    std::string getName() const;
    bool getCheckinpass() const;
    void setName(std::string name2){name=name2;}

};


#endif //MIKEGAIRLINES_PASSENGER_H
