//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_PLANE_H
#define AIPORTMIKEG_PLANE_H

#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>

static int LETTER_MAX = 26;

class Class{
protected:
    uint16_t price;
    char type;
public:
    /**Constructors*/
    explicit Class(uint16_t p = 0): price(p){
        type = '\0';
    };
    explicit Class(const Class& c): price(c.price){
        type = '\0';
    };
    /**Getters*/
    uint16_t getPrice() const{
        return price;};
    char getType() const{
        return type;};
    /**Setters*/
    void setPrice(uint16_t p){
        price = p;};
};

class FirstClass : public Class{
public:
    /**Constructor*/
    explicit FirstClass(uint16_t p = 0){
        type = 'F';
        price = p;
    }
};

class BusinessClass : public Class{
public:
    /**Constructor*/
    explicit BusinessClass(uint16_t p = 0){
        type = 'B';
        price = p;
    };
};

class EconomyClass : public Class{
public:
    /**Constructor*/
    explicit EconomyClass(uint16_t p = 0){
        type = 'E';
        price = p;
    };
};

class Seat {
    std::string id;
    bool free;
    Class* classe;
    friend class Plane;
public:
    /**Constructor*/
    Seat(std::string row, int column, Class* classe);
    ~Seat();
    /*Getters*/
    std::string getId() const{
        return id;
    }
    bool isFree() const{
        return free;
    }
    Class* getClass() const{
        return classe;
    }
};

class Plane{
protected:
    std::string plate;
    uint16_t capacity;
    std::vector<Class*> classes;
    bool grounded;
    //Eventually fit this into a cabin
    int seatRows;
    int seatsPerRow;
    std::vector<std::vector<Seat*>> seats;
public:
    /**Constructors*/
    Plane(): plate(""), capacity(0), grounded(true){
        classes.clear();
    };
    Plane(std::string p, uint16_t c):
        plate(std::move(p)), capacity(c), grounded(true){
        classes.clear();
    };
    Plane(std::string p, uint16_t c, std::vector<Class*> v):
        plate(p), capacity(c), grounded(true), classes(v){};
    ~Plane();
    /**Getters*/
    std::string getPlate() const{
        return plate;};
    uint16_t getCapacity() const{
        return capacity;};
    std::vector<Class*> getClasses() const{
        return classes;};
    bool isGrounded() const{
        return grounded;};
    int getRows() const{
        return seatRows;};
    int getColumns() const{
        return seatsPerRow;};
    std::vector<std::vector<Seat*>> getSeats() const{
        return seats;};
    int freeSeatNum() const;
    /**Setters*/
    void setPlate(std::string p){
        plate = std::move(p);};
    void setCapacity(uint16_t c){
        capacity = c;};
    void setClasses(std::vector<Class*> c){
        std::swap(classes, c);};
    bool bookSeat(std::string code);
    void takeOff(){
        grounded = false;};
    void land(){
        grounded = true;};
    void showSeats() const;
};

class Airbus : public Plane {
public:
    /**Constructor*/
    Airbus(std::string p, uint16_t fClassPrice, uint16_t eClassPrice, std::queue<std::string> first);
};

std::string getRowLetter(int i);
int getLetterRow(std::string l);

#endif //AIPORTMIKEG_PLANE_H
