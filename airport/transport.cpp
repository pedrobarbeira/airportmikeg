//
// Created by Joao on 27/11/21.
//

#include "transport.h"

Transport::Transport(char c) {
    type=c;
}

Transport::Transport(char c, uint16_t d) {
    type=c;
    distance=d;
}

string Transport::getTransport() {
    string t;
    switch (type) {
        case 'm':
            t = "Metro";
            break;
        case 'b':
            t = "Bus";
            break;
        case 't':
            t = "Train";
            break;
    }
    if (t.empty()) return "invalid transport";
    return t;
}

uint16_t const Transport::getDistance (){
    return distance;
}

char const Transport::getType(){
    return type;
}

void Transport::addTime(Time time){
    timetable.push_back(time);
}

list<Time> Transport::getTimetable () {
    list<Time>::iterator it;
    return timetable;
}


