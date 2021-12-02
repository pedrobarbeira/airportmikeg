//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_TRANSPORT_H
#define MIKEGAIRLINES_TRANSPORT_H

#include <iostream>
#include "../date.h"
#include <list>

using namespace std;

class Transport{
    char type; // m --> metro; b --> bus; t --> train
    uint16_t distance;
    list<Time> timetable;
public:
    Transport(char c);
    Transport(char c, uint16_t d);
    string getTransport();
    uint16_t const getDistance ();
    char const getType();
    void addTime(Time time);
    list<Time> getTimetable ();

};

#endif //MIKEGAIRLINES_TRANSPORT_H
