#include "luggage.h"

Luggage::Luggage(unsigned int weightlugg, bool checkinlugg){
    this->weight=weightlugg;
    this->checkinlugg=checkinlugg;

}

int Luggage::getWeight(){
    return weight;
}

bool Luggage::getCheckinlugg(){
    return checkinlugg;
}

void Luggage::setWeight(unsigned int weightlugg){
    weight=weightlugg;
}