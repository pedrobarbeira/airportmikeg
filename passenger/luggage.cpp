#include "luggage.h"

Luggage::Luggage(unsigned int weight, bool checkinlugg) {
    this->weight=weight;
    checkinlugg=false;

}

int Luggage::getWeight() const{
    return weight;
}

void Luggage::setWeight(unsigned int weightlugg){
    weight=weightlugg;
}




