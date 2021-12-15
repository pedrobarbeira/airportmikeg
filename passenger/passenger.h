#ifndef MIKEGAIRLINES_PASSENGER_H
#define MIKEGAIRLINES_PASSENGER_H
#include <iostream>
#include <vector>
#include "luggage.h"

using namespace std;

class Passenger{
    string name;
    vector<Luggage*> luggage;
public:
    Passenger(string name, bool checkinpass);
    string getName() const;
    bool getCheckinpass() const;
    void setName(string name2){name=name2;}
};


#endif //MIKEGAIRLINES_PASSENGER_H
