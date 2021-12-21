//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H

#include <iostream>
#include "bst.h"
#include "ticket.h"

/**
 * User parent class. Acts as an Interface for it's subclasses.
 */
class User{
protected:
    std::string username;
    std::string password;
    char type; //Create A - admin; C - client; S - service; B - boarding
    Date* registration;
    friend class CompanyPointer;
    friend class ClientPointer;
public:
    /**-----Constructor-----*/
    /**
     * Base constructor for the User parent class. Doubles as a default
     * constructor if no parameters are given
     * @param u the username
     * @param p the password
     * @param t the type
     */
    explicit User(std::string u = "", std::string p = "", char t = '\0'):
            username(std::move(u)), password(std::move(p)), type(t){
        Time* reg;
        reg->now();
        Date* d;
        *d = reg->getDate();
        registration = d;
    };

    /**-----Getters-----*/
    /**
     * Getter for the username attribute
     * @return the username attribute
     */
    std::string getUser() const{
        return username;
    }

    /**
     * Getter for the password attribute
     * @return the password attribute
     */
    std::string getPassword() const{
        return password;
    }

    /**
     * Getter for the type attribute
     * @return the type attribute
     */
    char getType() const{
        return type;
    }

    /**
     * Getter for the registration date attribute
     * @return the registration date attribute
     */
    Date* getDate() const{
        return registration;
    }

    /**-----Setters-----*/
    /**
     * Setter for the type attribute
     * @param t the new type
     */
    void setType(char t){
        type = t;
    }

    /**-----Operators-----*/
    /**
     * Compares two Users to see if they are equal
     * @param rhs the right side of the comparison
     * @return true if they have the same username, false otherwise
     */
    bool operator==(const User& rhs) const{
        return username == rhs.username;
    }

    /**
     * Compares two Users to see if left side username comes before right
     * side username
     * @param rhs the right side of the comparison
     * @return true if left side's user comes before right side, false otherwise
     */
    bool operator<(const User& rhs) const{
        return username < rhs.username;
    }
};
//Lets keep this on the "maybe pile" for now
class Client : public User{
    uint16_t miles;
    std::string passenger;
    vector<Ticket*> tickets;
    friend class ClientPointer;
public:
    /**-----Constructor-----*/
    /**
     * Base constructor for the Client class. Doubles as a default constructor
     * if no parameters are given
     * @param u the username
     * @param p the password
     * @param t the type - C
     * @param m the number of miles of the Client
     * @param psgr the name of the passenger associated with the account
     */
    explicit Client(std::string u = "", std::string p = "", char t = '\0', uint16_t m = 0, std::string psgr = "") : miles(m){
        username = std::move(u);
        password = std::move(p);
        tickets.clear();
        passenger = std::move(psgr);
        type = t;
    }

    /**-----Getters-----*/
    /**
     * Getter for the miles attribute
     * @return the miles attribute
     */
    uint16_t getMiles() const{
        return miles;
    }

    /**
     * Getter for the passenger attribute
     * @return the passenger attribute
     */
    std::string getPassenger() const{
        return passenger;
    }

    /**
     * Getter for the tickets vector
     * @return the tickets vector
     */
    vector<Ticket*> getTickets() const{
        return tickets;
    }

    /**-----Setters-----*/
    /**
     * Setter for the tickets attribute
     * @param v the new tickets vector
     */
    void setTickets(std::vector<Ticket*> v){
        std::swap(tickets, v);
        v.clear();
    }

    /**-----Operators-----*/
    /**
     * Compares two clients to see if they have the same username
     * @param rhs the right side of the comparison
     * @return true if clients have the same name, false ohterwise
     */
    bool operator==(const Client& rhs) const{
        return username == rhs.username;
    }
    /**
     * Compares two Clients to see if left side's username comes before
     * right side's username
     * @param rhs the right side of the comparison
     * @return true if left side's username comes before right side's,
     * false otherwise
     */
    bool operator<(const Client& rhs) const{
        return this->getUser() < rhs.getUser();
    }
};

class Company : public User{
protected:
    Airport* airport;
    Plane* plane;
    Staff* staff;
    std::queue<ServiceTicket*> serviceList;
    std::list<ServiceTicket*> completedServices;
public:
    /**-----Constructor-----*/
    /**
     * Base constructor for Company objects. Takes an username, a password,
     * a type, an airport, a plane, a staff object, a queue of Service Tickets
     * and a list of Service Tickets which were complete. Which attributes are
     * given depends on the type of account which is created - Admin accounts
     * don't take any attributes, Manager accounts take an Airport, Boarding
     * accounts take an Airport and a Plane, Service accounts take an Airport,
     * a Staff object and a queue of ServiceTickets which must be completed
     * @param u the username
     * @param p the password
     * @param t the type
     * @param a the airport
     * @param pln the plane
     * @param s the ServiceTicket queue
     */
    explicit Company(std::string u = "", std::string p = "", char t = '\0', Airport* a = nullptr, Plane* pln = nullptr, Staff* s = nullptr){
        username = std::move(u);
        password = std::move(p);
        airport = a;
        plane = pln;
        type = t;
        staff = s;
    }

    /**-----Getters-----*/
    /**
     * Getter for the airport attribute
     * @return the airport attribute
     */
    Airport* getAirport() const{
        return airport;
    }

    /**
     * Getter for the serviceList attribute
     * @return the serviceList queue
     */
    std::queue<ServiceTicket*> getService() const{
        return serviceList;
    }

    /**
     * Getter for the completed attribute
     * @return the completed ServiceTicket list
     */
    std::list<ServiceTicket*> getCompleted() const{
        return completedServices;
    }

    /**
     * Getter for the plane attribute
     * @return the plane attribute
     */
    Plane* getPlane() const{
        return plane;
    }

    /**
     * Getter for the staff attribute
     * @return the staff attribute
     */
    Staff* getStaff() const{
        return staff;
    }

    /**-----Setters-----*/
    /**
     * Setter for the staff attribute
     * @param staff the new staff
     */
    void setStaff(Staff* s){
        this->staff = s;
    }

    /**
     * Setter for the plane attribute
     * @param p the new plane
     */
    void setPlane(Plane* p){
        plane = p;
    }

    /**
     * Setter for the airport attribute
     * @param airport the new airport
     */
    void setAirport(Airport* a){
        this->airport = a;
    }

    /**
     * Sets a Service Ticket from the serviceList to completed by popping
     * it from the serviceList queue and adding it to the completedService
     * list
     */
    void  serviceFinished(){
        if(!serviceList.empty()) {
            if(serviceList.size() == 1) {
                std::cout << "You're completed all your services\n"
                          << "\nPress enter to continue . . ";
                getchar();
            }
            ServiceTicket *s = serviceList.front();
            serviceList.pop();
            completedServices.push_back(s);
        }
        else{
            std::cout << "There are no services to finish\n"
                      << "\nPress enter to continue . . .";
            getchar();
        }
    }

    /**-----Adders-----*/
    /**
     * Adds a new ServiceTicket to the serviceList queue
     * @param service the Service Ticket to the badded
     */
    void addService(ServiceTicket *service){
        serviceList.push(service);
    }

    /**
     * Adds a Service ticket to the completedService list
     * @param service the completed Service Ticket to be added
     */
    void addCompleteService(ServiceTicket *service){
        completedServices.push_back(service);
    }

    /**-----Operators-----*/
    /**
     * Compares two Company objects to see if they have the same username
     * @param rhs the right side of the comparison
     * @return true if objects have the same username, false otherwise
     */
    bool operator==(const Company& rhs) const{
        return username == rhs.username;
    }

    /**
     * Compares two Company objects to see if left side type comes before
     * the right side type. If they have the same type, compares usernames
     * to see which one is lower
     * @param rhs the right side of the comparison
     * @return true if left side's type or username comes before right side's
     * type or username
     */
    bool operator<(const Company& rhs) const{
        if(this->getType() != '\0' && rhs.getType() != '\0'){
            if(this->getType() == rhs.getType())
                return this->getUser() < rhs.getUser();
            else return type < rhs.type;
        }
        return this->getUser() < rhs.getUser();
    }
};

#endif //MAIN_CPP_USER_H
