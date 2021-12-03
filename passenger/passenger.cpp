#include "passenger.h"
using namespace std;

Passenger::Passenger(string nome, bool checkinpass) {
    this->name=name;
    this->checkinpass= false;
}

string Passenger::getName() const{
    return name;
}

bool Passenger::getCheckinpass() const {
    return checkinpass;
}
