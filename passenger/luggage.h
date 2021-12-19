#ifndef MIKEGAIRLINES_LUGGAGE_H
#define MIKEGAIRLINES_LUGGAGE_H

#include <iostream>
#include <queue>
#include <stack>

class Luggage {
    unsigned int weight;
    bool checkinlugg;
public:
    Luggage(unsigned int weight, bool checkinlugg);
    int getWeight() const;
    void setWeight(unsigned int weight);

};

class HandBag : public Luggage{};

class CellarLuggage : public Luggage{};

//Eventually take this out
class Treadmill{

};

class Carriage {
    int m, n;
    std::queue<std::stack<Luggage *>> bags;
public:
    explicit Carriage(int m = 0, int n = 0) {
    }

    bool loadCarriage(Luggage *) {
        std::queue<std::stack<Luggage *>> load;
        std::stack<Luggage *> stax = bags.front();
        int counter;
        while (!bags.empty()) {
            stax = bags.front();
            bags.pop();
            counter++;
            if (counter == m) {
                load.push(stax);
                while (!stax.empty()) {
                    stax.pop();
                }
                counter = 0;
            }

            return true;
        }
    }
};

class LuggageTransport {
    std::queue<Carriage *> carriages;
public:
    LuggageTransport(std::queue<Luggage *> bags, int m = 0, int n = 0) {
        std::vector<Carriage *> load;
        Carriage *c = new Carriage(m, n);
        load.push_back(c);
        int i = 0;
        while (!bags.empty()) {
            if (load[i]->loadCarriage(bags.front()))
                bags.pop();
            else {
                Carriage *c = new Carriage(2, 3);
                c->loadCarriage(bags.front());
                bags.pop();
                load.push_back(c);
                i++;
            }
        }
        for (auto it: load)
            carriages.push(it);
    }
};
#endif //MIKEGAIRLINES_LUGGAGE_H