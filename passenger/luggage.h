#ifndef MIKEGAIRLINES_LUGGAGE_H
#define MIKEGAIRLINES_LUGGAGE_H

#include <iostream>
#include <queue>
#include <stack>

class Luggage {
    unsigned int weight;
public:
    Luggage(unsigned int weightlugg, bool checkinlugg);
    int getWeight() const;
    void setWeight(unsigned int weightlugg);
};

class HandBag : public Luggage{};

class CellarLuggage : public Luggage{};

//Eventually take this out
class Treadmill{

};

class Carriage{
    std::queue<std::stack<Luggage*>> bags;
public:
    explicit Carriage(int m = 0, int n = 0){

    }
};

class LuggageTransport{
    std::queue<Carriage*> carriages;
};

#endif //MIKEGAIRLINES_LUGGAGE_H
