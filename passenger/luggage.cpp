#include "luggage.h"

Luggage::Luggage(unsigned int weight, bool checkinlugg){
    this->weight=weight;
    this->checkinlugg=checkinlugg;

}

int Luggage::getWeight() const{
    return weight;
}

bool Luggage::getCheckinlugg() const{
    return checkinlugg;
}

void Luggage::setWeight(unsigned int weightlugg){
    weight=weightlugg;
}