#ifndef MIKEGAIRLINES_LUGGAGE_H
#define MIKEGAIRLINES_LUGGAGE_H
#include <iostream>


class Luggage {
    unsigned int weight;
public:
    Luggage(unsigned int weightlugg, bool checkinlugg);
    int getWeight() const;
    void setWeight(unsigned int weightlugg);


};

class HandBag : public Luggage{};

class Cellar : public Luggage{};

class LuggageTransport{};

#endif //MIKEGAIRLINES_LUGGAGE_H
