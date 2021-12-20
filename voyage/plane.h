//Created by Pedro Barbeira (up201303693)
#ifndef AIPORTMIKEG_PLANE_H
#define AIPORTMIKEG_PLANE_H

#include <iostream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <vector>
#include "bst.h"
#include "luggage.h"

#define LETTER_MAX  26;
static int airbusCount = 0;
static int otherCount = 0;

/**
 * Interface class for plane seat Classes
 */
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

/**
 * First Class seats
 */
class FirstClass : public Class{
public:
    /**Constructor*/
    explicit FirstClass(uint16_t p = 0){
        type = 'F';
        price = p;
    }
};

/**
 * Business Class seats
 */
class BusinessClass : public Class{
public:
    /**Constructor*/
    explicit BusinessClass(uint16_t p = 0){
        type = 'B';
        price = p;
    };
};

/**
 * Economy Class seats
 */
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
    HandBag* handBag;
    friend class Cabin;
public:
    /**-----Constructor-----*/
    /**
     * Constructor for the Seat class. Receives a row and a columns,
     * which is it's place in the Cabin seats matrix, and a Class object,
     * which will determine de price. Automatically generates the SeatId
     * @param row the row which the seat belongs to
     * @param column the columns which the seat belongs to
     * @param classe pointer to the Class object
     */
    Seat(std::string row, int column, Class* classe);

    /**-----Getters-----*/
    /**
     * Getter for the Seat id
     * @return the seat Id
     */
    std::string getId() const{
        return id;
    }

    /**
     * Checks if seat is taken or free
     * @return true if free, false otherwise
     */
    bool isFree() const{
        return free;
    }

    /**
     * Getter for the classe attribute
     * @return pointer to the Class object
     */
    Class* getClass() const{
        return classe;
    }

    /**
     * Returns the HandBag object stored in the handBag attribute
     * @return the HandBag object
     */
    HandBag* getBag() const{
        return handBag;
    }

    /**
     * Sets the free attribute to false
     */
    void takeSeat(){
        free = false;
    }
};

class Cabin{
    uint16_t seatRows;
    uint16_t seatsPerRow;
    uint16_t capacity;
    std::vector<std::vector<Seat*>> seats;
    friend class Plane;
    friend class Airbus;
    friend class Other;
public:
    Cabin(){
        capacity = seatRows * seatsPerRow;
    };
};

/**
 * Interface for the different types of planes. Implements all the common methods
 */
class Plane{
protected:
    std::string plate;
    std::vector<Class*> classes;
    Cabin* cabin;
    bool grounded;
    friend class PlanePointer;
public:
    /**Constructors*/
    Plane(std::string p, uint16_t c):
        plate(std::move(p)), grounded(true){
        cabin->capacity = c;
        classes.clear();
    };
    Plane(std::string p, uint16_t c, std::vector<Class*> v):
        plate(p), grounded(true), classes(v){
        cabin->capacity = c;
    };
    explicit Plane(std::string id = "") : plate(std::move(id)){}
    ~Plane();
    /**Getters*/
    std::string getPlate() const{
        return plate;};
    uint16_t getCapacity() const{
        return cabin->capacity;};
    std::vector<Class*> getClasses() const{
        return classes;};
    bool isGrounded() const{
        return grounded;};
    int getRows() const{
        return cabin->seatRows;};
    int getColumns() const{
        return cabin->seatsPerRow;};
    std::vector<std::vector<Seat*>> getSeats() const{
        return cabin->seats;};
    int freeSeatNum() const;
    /**Setters*/
    void setPlate(std::string p){
        plate = std::move(p);};
    void setCapacity(uint16_t c){
        cabin->capacity = c;};
    void setClasses(std::vector<Class*> c){
        std::swap(classes, c);};
    Seat* bookSeat(std::string code);
    void takeOff(){
        grounded = false;};
    void land(){
        grounded = true;};
    void showSeats() const;
    void setFClassPrice(uint16_t p){
        classes[0]->setPrice(p);
    }
    void setBClassPrice(uint16_t p){
        if(classes[1] != nullptr) classes[1]->setPrice(p);
    }
    void setEClassPrice(uint16_t p){
        classes[2]->setPrice(p);
    }
    bool operator<(const Plane& rhs) const{
        return plate < rhs.plate;
    }
    bool operator==(const Plane& rhs) const{
        return plate == plate;
    }
    bool operator!=(const Plane& rhs) const{
        return !(*this == rhs);
    }
};

/**
 * Creates a 156 seat Airbus
 */
class Airbus : public Plane {
public:
    /**Constructor*/
    /**
     * Constructor for the Airbus Class. Creates a 156 seat (26*6) Airbus.
     * Receives a queue with the letters of the First Class Rows
     * @param firstClassRows the First Class Rows
     */
    Airbus(std::queue<std::string> firstClassRows);
};

/**
 * Allows Admin to create a type of plane that's not in the system
 * Throws DevLog exception at the end or constructor in order to inform our
 * amazing IT guy, so he can add the class to the system later on
 */
class Other : public Plane{
public:
    Other(uint16_t rows, uint16_t seatPerRow, std::queue<std::string> firstClassRows);
    Other(uint16_t rows, uint16_t seatPerRow, std::queue<std::string> firstClassRows, std::queue<std::string> bizClassRows);
};

std::string getRowLetter(int i);
int getLetterRow(std::string l);

#endif //AIPORTMIKEG_PLANE_H
