#ifndef MIKEGAIRLINES_PASSENGER_H
#define MIKEGAIRLINES_PASSENGER_H
#include <iostream>
#include <vector>
#include "luggage.h"

class Passenger{
    std::string nome;
    bool checkinpass;
    std::vector<Luggage*> luggage;
public:

};

#endif //MIKEGAIRLINES_PASSENGER_H


//-  nome: string
//+ bilhete: voo(class)
//+ bagagem vector<bagagem>
//+ check in : bool