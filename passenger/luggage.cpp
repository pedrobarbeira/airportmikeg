#include "luggage.h"

luggage::luggage(unsigned int weightlugg, bool checkinlugg){
    this->weight=weightlugg;
    this->checkinlugg=checkinlugg;

}

int luggage::getWeight(){
    return weight;
}

bool luggage::getCheckinlugg(){
    return checkinlugg;
}

void luggage::setWeight(unsigned int weightlugg){
    weight=weightlugg;
}