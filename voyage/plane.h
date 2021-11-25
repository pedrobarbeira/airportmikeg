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
public:
    /**Constructors*/
    Classe():type('\0'), price(0){};
    Classe(char t): type(t), price(0){};
    Classe(char t, uint16_t p): type(t), price(p){};
    Classe(const Classe& c):
    type(c.type), price(c.price){};
    /**Getters*/
    std::string getType() const{
        std::string ret = "";
        switch(type) {
            case 'F': ret = "First"; break;
            case 'B': ret = "Business"; break;
            case 'E': ret = "Economy"; break;
            default: ret = "Invalid"; break;
        }
        return ret + " Class";
    };
    uint16_t getPrice() const{
        return price;};
    /**Setters*/
    void setType(char t){
        type = t;};
    void setPrice(uint16_t p){
        price = p;};
};

class PaperPlane: public Plane{
    bool seats[1][1];
};


#endif //AIPORTMIKEG_PLANE_H
