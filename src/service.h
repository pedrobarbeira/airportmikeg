//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_SERVICE_H
#define MIKEGAIRLINES_SERVICE_H

#include <iostream>
#include "plane.h"
#include "date.h"


static unsigned staffId = 1;
using namespace std;

class Staff{
    /**
     * id is a string defined by a
     * static integer (unique)
     */
    string id{};
    /**
     * name of the worker
     */
    string name;
    /**
     * phone number is an unsigned integer
     */
    unsigned phone;
public:
    /**
     * constructor for the staff objects
     * @param name
     */
    explicit Staff(string name = ""){
        this->name = name; id = to_string(staffId++) + "staff";};

    /**
     * Constructor for the staff object. Receives an Id, a Name and a Phone. Used
     * in the Data Load module
     * @param i the id
     * @param n the name
     * @param p the phone
     */
    Staff(std::string i, std::string n, uint16_t p) : id(i), name(n), phone(p){};
    /**
     * getter for the unique id
     * @return
     */
    string getId() const;
    /**
     * setter for the next id available
     */
    void setId();

    /**
     * Setter for the Id attribute. Used in load module
     * @param i the new Id
     */
    void setId(const std::string& i){
        id = i;
    }
    /**
     * setter for a new name
     * @param name
     */
    void setName(string name){this->name = name;}
    /**
     * setter for the phone attribute
     * @param n
     */
    void setPhone (unsigned n);
    /**
     * getter for the name of the
     * worker
     * @return
     */
    string getName() const;
    /**
     * getter for the worker phone
     * @return
     */
    unsigned getPhone() const;
    /**
     * < overload to sort workers by unique id
     * @param rhs
     * @return
     */
    bool operator<(const Staff& rhs) const{
        return id < rhs.id;
    }
};
/*
class InvalidNumber : public exception{
private:
    string e;
public:
    InvalidNumber(){
        e = "Invalid number";
    };
    string getError() const{
        return e;
    }
};*/


class ServiceTicket{
protected:
    /**
     * plane object to which the repair is being made
     */
    Plane *plane;
    /**
     * responsible is a staff object
     * associated with a ServiceTicket object
     */
    Staff *responsible;
    /**
     * date (through a Time object) to
     * inform when the service was created
     */
    Time *created;
    /**
     * date whenn the service was completed
     * and passed to the list of completed
     * services
     */
    Time *completed;
    /**
     * id is a char to determine the type
     * of serviceTicket (cleaning or maintainance
     */
    char id;
public:
    /**
     * Default constructor for ServiceTicket interface. Initializes all
     * attributes as nullptr
     */
    ServiceTicket(){
        plane = nullptr;
        responsible = nullptr;
        created = nullptr;
        completed = nullptr;
        id = '\0';
    }
    /**
     * constructor for a serviceTicket interface
     * for a plane with the date
     * when it is created
     * @param plane
     * @param id
     */
    ServiceTicket(Plane *plane, char id);
    /**
     * Serviceticket interface creation method
     * that allows to determine a date
     * @param plane
     * @param date different from time.now()
     * @param id
     */
    ServiceTicket(Plane *plane, Time *date, char id);
    /**
     * serviceticket interface for creation of a
     * service on a plane with a responsible
     * @param plane
     * @param staff
     * @param id
     */
    ServiceTicket(Plane *plane, Staff *staff, char id);
    /**
     * service interface creation of a service
     * with all the information
     * @param plane
     * @param date differente from time.now()
     * @param staff
     * @param id
     */
    ServiceTicket(Plane *plane, Time *date, Staff *staff, char id);
    /**
     * interface getter for the type of the service
     * @return
     */
    virtual char getType() const{return id;};
    /**
     * setter interface for the responsible
     * @param staff
     */
    virtual void setResponsible (Staff *staff);
    /**
     * setter interface to change the date it
     * was created
     * @param date
     */
    virtual void setCreated (Time *date);
    /**
     * setter interface for the completion of a service
     * @param date
     */
    virtual void setComplete (Time *date);
    /**
     *
     * getter for the plane under a serviceTicket
     * @return
     */
    Plane* getPlane() const{
        return plane;
    }
    /**
     * getter for the date it was completed
     * @return
     */
    Time* getCompleted() const{
        return completed;
    }
    /**
     * interface for a getter of a vector
     * of all the tasks still left
     * @return
     */
    virtual vector<string> getTasksLeft () const;
    /**
     * interface for a getter of a vector
     * of all the tsks completed within
     * the service
     * @return
     */
    virtual vector<string> getTasksCompleted() const;
    /**
     * getter interface for the
     * responsible of the service
     * @return
     */
    virtual Staff *getResponsible();
    /**
     * interface getter to retrieve
     * the date it was created
     * @return
     */
    virtual Time* getCreated();
    /**
     * interface for a boolean verification
     * if all the tasks are complete
     * @return
     */
    virtual bool verification() const{
        return true;
    };
    /**
     * < overload to organize serviceTickets
     * @param s
     * @return
     */
    bool operator < (ServiceTicket &s);
    /**
     * interface to check the current
     * task as completed
     */
    virtual void checkWc(){};
    /**
    * interface to check the current
    * task as completed
    */
    virtual void checkSeats(){};
    /**
    * interface to check the current
    * task as completed
    */
    virtual void checkFloor(){};
    /**
    * interface to check the current
    * task as completed
    */
    virtual void checkFlightDeck(){};
    /**
    * interface to check the current
    * task as completed
    */
    virtual void checkEngine(){};
    /**
    * interface to check the current
    * task as completed
    */
    virtual void checkLandGear(){};
    /**
    * interface to check the current
    * task as completed
    */
    virtual void checkControls(){};
    /**
    * interface to check the current
    * task as completed
    */
    virtual void checkEmergency(){};

    void removeResponsible(){
        responsible = nullptr;
    }
};


/**
 * One of the 2 classes that inherite
 * ServiceTicket class with 4 exclusive
 * attributes
 */
class Cleaning : public ServiceTicket{
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool wc = false;
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool seats = false;
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool floor = false;
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool flightDeck = false;
public:
    /**
     * Constructor for cleaning service
     * objects that determine the attribute
     * type of ServiceTicket to 'c'
     * with only the plane defined
     * (date is determined by time.now())
     * @param plane
     */
    Cleaning(Plane *plane);
    /**
     * Constructor for cleaning service
     * objects that determine the attribute
     * type of ServiceTicket to 'c'
     * with the plane and a date defined
     * @param plane
     * @param date
     */
    Cleaning(Plane *plane, Time *date);
    /**
     * Constructor for cleaning service
     * objects that determine the attribute
     * type of ServiceTicket to 'c'
     * with the plane, a date and the responsible
     * defined
     * @param plane
     * @param date
     * @param staff
     */
    Cleaning(Plane *plane, Time *date, Staff *staff);

    /**
     * Constructor for completed cleaning Service Tickets. Receives a second
     * Time parameter, which is the time of completion. Sets all boolean
     * attributes of the class to true, since service is completed. Used in
     * the Data Load module
     * @param p
     * @param t1
     * @param t2
     * @param s
     */
    Cleaning(Plane* p, Time* t1, Time* t2, Staff* s){
        plane = p;
        created = t1;
        completed = t2;
        responsible = s;
        id = 'c';
        wc = true;
        seats = true;
        floor = true;
        flightDeck = true;
    }
    /**
     * getter override for the type
     * of service
     * @return
     */
    char getType() const override{return ServiceTicket::getType();};
    /**
     * setter override to determine
     * the staff responsible
     * @param staff
     */
    void setResponsible (Staff *staff) override;
    /**
     * setter overrid to alter the
     * date this service was created
     * @param date
     */
    void setCreated (Time *date) override;
    /**
     * setter override to determine when
     * the service was completed and remove it
     * from the service queue
     * @param date
     */
    void setComplete (Time *date) override;
    /**
     * getter overide to retrieve a vector
     * of string of the tasks left
     * helpful to send to screen
     * @return
     */
    vector<string> getTasksLeft () const override;
    /**
     * getter overide to retrieve a vector
     * of string of the tasks completed
     * helpful to send to screen
     * @return
     */
    vector<string> getTasksCompleted() const override;
    /**
     * getter overrid to retrieve
     * the responsible
     * @return
     */
    Staff* getResponsible() override;
    /**
     * getter override to retrieve
     * the date it was created
     * @return
     */
    Time* getCreated() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkWc() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkSeats() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkFloor() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkFlightDeck() override;
    /**
     * method to remove service from the queue
     * if all the tasks are complete
     * @return
     */
    bool verification() const override;
};

class Maintenance : public ServiceTicket{
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool engine = false;
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool landGear = false;
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool controls = false;
    /**
     * sttribute to determine if
     * it is still left or not
     */
    bool emergency = false;
public:
    /**
     * constructor for maintainance objects
     * with only the plane defined
     * @param plane
     */
    Maintenance(Plane *plane);
    /**
     * constructor for maintainance objects
     * with the plane and creation date defined
     * @param plane
     */
    Maintenance(Plane *plane, Time *date);
    /**
     * constructor for maintainance objects
     * with the plane, creation date and
     * staff responsible defined
     * @param plane
     */
    Maintenance (Plane *plane, Time *date, Staff *staff);

    /**
     * Constructor for completed Maintenance ServiceTickets. Receives a
     * second Time parameter, which is the time of completion. Sets all
     * boolean attributes of the class to true, since the service is
     * completed. Used in the Data Load module.
     * @param p
     * @param t1
     * @param t2
     * @param s
     */
    Maintenance(Plane* p, Time* t1, Time* t2, Staff* s){
        plane = p;
        created = t1;
        completed = t2;
        responsible = s;
        id = 'm';
        engine = true;
        landGear = true;
        controls = true;
        emergency = true;
    }
    /**
     * getter override to get this service
     * type ('m')
     * @return
     */
    virtual char getType() const override{return ServiceTicket::getType();};
    /**
     * getter override to get responsible
     * @param staff
     */
    void setResponsible (Staff *staff) override;
    /**
     * setter override to alter the date of
     * creation
     * @param date
     */
    void setCreated (Time *date) override;
    /**
     * setter override to define the date of
     * completion and remove from queue
     * @param date
     */
    void setComplete (Time *date) override;
    /**
     * method override to help retrieving
     * the tasks left of this service in the
     * form of a vector
     * @return
     */
    vector<string> getTasksLeft () const override;
    /**
     * method override to help retrieving
     * the tasks completed of this service in the
     * form of a vector
     * @return
     */
    vector<string> getTasksCompleted() const override;
    /**
     * getter override to retrieve
     * the responsible staff
     * @return
     */
    Staff* getResponsible() override;
    /**
     * getter override to retrieve
     * the date of creation
     * @return
     */
    Time* getCreated() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkEngine() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkLandGear() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkControls() override;
    /**
     * method to determine this exclusive
     * task as complete
     */
    void checkEmergency() override;
    /**
     * method to verify if all the
     * tasks are complete and if so
     * removes from the queue to the complete
     * services list
     */
    bool verification() const override;
};

class NoResponsible{
    string e;
public:
    NoResponsible(){
        e = "Must set Staff responsible first";
    }
    string getError() const{
        return e;
    }
};


#endif //MIKEGAIRLINES_SERVICE_H