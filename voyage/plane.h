//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_PLANE_H
#define AIPORTMIKEG_PLANE_H

#include <iostream>
#include <vector>

class Classe;

class Plane{
    std::string plate;
    uint16_t capacity;
    std::vector<Classe*> classes;
};

class Classe{
    char type;
    uint16_t price;
};

class PaperPlane: public Plane{
    bool seats[1][1];
};


#endif //AIPORTMIKEG_PLANE_H
