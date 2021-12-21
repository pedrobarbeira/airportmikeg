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

std::string getRowLetter(int i);
int getLetterRow(std::string l);

/**
 * Interface class for plane seat Classes
 */
class Class{
protected:
    uint16_t price;
    char type;
public:
    /**-----Constructors-----*/
    /**
     * Constructor for the Parent class Class. Receives price and stores it
     * in the price attribute
     * @param p the price of the class
     */
    explicit Class(uint16_t p = 0): price(p){
        type = '\0';
    };
    /**-----Getters-----*/
    /**
     * Getter for the price attribute
     * @return the price of the Class
     */
    uint16_t getPrice() const{
        return price;};

    /**
     * Getter for the price attribute
     * @return the type of the Class
     */
    char getType() const{
        return type;};

    /**-----Setters-----*/
    /**
     * Changes the price of the class to a new price
     * @param p the new price
     */
    void setPrice(uint16_t p){
        price = p;};
};

/**
 * First Class seats
 */
class FirstClass : public Class{
public:
    /**-----Constructor-----*/
    /**
     * Constructor for the FirstClass class. Initializes parent class
     * using the parameter. Sets parent type to F
     * @param p the price of the Class
     */
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
    /**-----Constructor-----*/
    /**
     * Constructor for the BusinessClass class. Initializes the parent
     * class using the parameter. Sets parent type to B
     * @param p the price of the Class
     */
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
    /**-----Constructor-----*/
    /**
     * Constructor for the EconomyClass class. Initializes the praent
     * class using the parameter. Sets parent type to E
     * @param p the price of the Class
     */
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
    /**
     * Constructor for the Cabin class. Initializes the Seat matrix. Defines
     * if each seat is a First Class seat or an Economy Class seat. Doubles as
     * a default constructor if no parameters are given.
     * @param sRows the number of seat rows
     * @param sPerRow the number of seats per row
     * @param first the seat rows which are first class
     */
    explicit Cabin(uint16_t sRows = 0, uint16_t sPerRow = 0,
          std::vector<Class*> c = std::vector<Class*>(),
          std::queue<std::string> first = std::queue<std::string>());

    /**
     * Constructor for the Cabin class. Initializes the Seat matrix. Defines
     * if each seat is a First Class seat, a Business Class seat or an Economy
     * Class seat
     * @param sRows the number of seat rows
     * @param sPerRow the number of seats per row
     * @param first the seat rows which are first class
     * @param biz the seat rows which are business class
     */
    Cabin(uint16_t sRows, uint16_t sPerRow, std::vector<Class*> v,
          std::queue<std::string>& first, std::queue<std::string>& biz);
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
    /**-----Constructor-----*/
    /**
     * Constructor for the Plane Class. Creates an abstract plane and sets
     * the Id. Used for searches in the Data::planes BST. Acts as a default
     * constructor if no Id is provided
     * @param p the Id of the plane
     */
    explicit Plane(std::string p = ""):
        plate(std::move(p)), grounded(true){
        classes.clear();
        cabin = new Cabin;
    };

    /**
     * Destructor for the Plane Class. Deletes the cabin attribute and each
     * class in the classes vector
     *
     */
    ~Plane();
    /**-----Getters-----*/
    /**
     * Getter for the Plane's plate
     * @return the plate attribute
     */
    std::string getPlate() const{
        return plate;};

    /**
     * Getter for the Plane's capacity
     * @return the plane's capacity
     */
    uint16_t getCapacity() const{
        return cabin->capacity;};

    /**
     * Getter for the Plane's classes
     * @return a vector with the Plane's classes
     */
    std::vector<Class*> getClasses() const{
        return classes;};

    /**
     * Getter for the Plane's state
     * @return true if plane is grounded, false otherwise
     */
    bool isGrounded() const{
        return grounded;};

    /**
     * Getter for the Plane's rows
     * @return the plane's rows
     */
    int getRows() const{
        return cabin->seatRows;};

    /**
     * Getter for the Plane's columns
     * @return the plane's columns
     */
    int getColumns() const{
        return cabin->seatsPerRow;};

    /**
     * Getter for the Plane's seats
     * @return the Plane's seat matrix
     */
    std::vector<std::vector<Seat*>> getSeats() const{
        return cabin->seats;};

    /**
     * Getter for the Plane's number of free seats
     * @return the number of free seats
     */
    int freeSeatNum() const;

    /**-----Setters-----*/
    /**
     * Sets the Plane's plate attribute to p
     * @param p the new plate
     */
    void setPlate(std::string p){
        plate = std::move(p);};

    /**
     * Set's the Plane's classes vector to c.
     * @param c the new classes
     */
    void setClasses(std::vector<Class*> c){
        (*classes[0]) = (*c[0]);
        (*classes[1]) = (*c[1]);
        (*classes[2]) = (*c[2]);
    }

    /**
     * Books a seat in the plane. Uses the code to find the seat in the
     * cabin's seat matrix, calls takeSeat and returns the booked seat
     * @param code the Id of the seat to be booked
     * @return pointer to the booked seat
     */
    Seat* bookSeat(std::string code);

    /**
     * Changes the gounded attribute to false, signaling the plane's take off
     */
    void takeOff(){
        grounded = false;};

    /**
     * Changes the grounded attribute to true, signaling the plane's landing
     */
    void land(){
        grounded = true;};

    /**
     * Frontend function which shows the cabin's seat matrix. Seats appear
     * inside two brackets []. Free seats are signaled with an o and taken
     * seats are signales with an x. The Function also displays the row letters
     * and seat numbers, so the user can easily choose his seat
     */
    void showSeats() const;

    /**
     * Changes First Class seat price to p
     * @param p the new price
     */
    void setFClassPrice(uint16_t p){
        classes[0]->setPrice(p);
    }

    /**
     * Changes the Business Class seat price to p
     * @param p the new price
     */
    void setBClassPrice(uint16_t p){
        if(classes[1] != nullptr) classes[1]->setPrice(p);
    }

    /**
     * Changes the Economy Class seat price to p
     * @param p the new price
     */
    void setEClassPrice(uint16_t p){
        classes[2]->setPrice(p);
    }

    /**-----Operators-----*/
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
    /**-----Constructor-----*/
    /**
     * Constructor for the Airbus Class. Creates a 156 seat (26*6) Airbus.
     * Receives a queue with the letters of the First Class Rows
     * @param firstClassRows the First Class Rows
     */
    Airbus(std::queue<std::string>& firstClassRows);
};

    /**
     * Allows Admin to create a type of plane that's not in the system
     * Throws DevLog exception at the end or constructor in order to inform our
     * amazing IT guy, so he can add the class to the system later on
     */
class Other : public Plane{
public:
    /**-----Constructors-----*/
    /**
     * Constructor for the Other Plane subclass. Allows admin to create a new
     * type of plane with the same template as an Airbus.
     * @param rows the rows of the new plane
     * @param seatPerRow the seat rows of the new plane
     * @param firstClassRows the rows which are first class
     */
    Other(uint16_t rows, uint16_t seatPerRow, std::queue<std::string> firstClassRows);

    /**
     * Constructor for the Other Plane subclass. Allows admin to create a new
     * type of plane with a template different from an Airbus
     * @param rows the rows of the new plane
     * @param seatPerRow the seat rows of the new plane
     * @param firstClassRows the rows which are first class
     * @param bizClassRows the rows which are business class
     */
    Other(uint16_t rows, uint16_t seatPerRow, std::queue<std::string> firstClassRows, std::queue<std::string> bizClassRows);
};

#endif //AIPORTMIKEG_PLANE_H
