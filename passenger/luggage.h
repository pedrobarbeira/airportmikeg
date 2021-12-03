#ifndef MIKEGAIRLINES_LUGGAGE_H
#define MIKEGAIRLINES_LUGGAGE_H
#include <iostream>

class Luggage {
    unsigned int weight;
    bool checkinlugg;

public:
    Luggage(unsigned int weightlugg, bool checkinlugg);

    int getWeight() const;

    bool getCheckinlugg() const;

    void setWeight(unsigned int weightlugg);

    void setCheckinlugg(bool ch){
        checkinlugg=ch;};

};

#endif //MIKEGAIRLINES_LUGGAGE_H
