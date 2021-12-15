//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_SERVICE_H
#define MIKEGAIRLINES_SERVICE_H

#include <iostream>
#include "plane.h"
#include "../src/date.h"

static unsigned staffId = 1;
using namespace std;

class Staff{
    unsigned id;
    string name;
    unsigned phone;
public:
    explicit Staff(string name = "");
    void setId();
    void setPhone (unsigned n);
    string getName() const;
    unsigned getPhone() const;
    unsigned getId() const;
};

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
};


class ServiceTicket{
    Plane *plane;
    Staff *responsible;
    Date created;
    Date completed;
    char id;
public:
    ServiceTicket(Plane *plane, char id);
    ServiceTicket(Plane *plane, Date date, char id);
    ServiceTicket(Plane *plane, Staff *staff, char id);
    ServiceTicket(Plane *plane, Date date, Staff *staff, char id);
    virtual char getType() const{return id;};
    virtual void setResponsible (Staff *staff);
    virtual void setSchedule (Date date);
    virtual void setComplete (Date date);
    virtual vector<string> getTasksLeft () const;
    virtual vector<string> getTasksCompleted() const;
    virtual Staff *getResponsible();
    virtual Date getSchedule();
    bool operator < (ServiceTicket &s);
};



class Cleaning : virtual ServiceTicket{
    bool wc = false;
    bool seats = false;
    bool floor = false;
    bool flightDeck = false;
public:
    Cleaning(Plane *plane);
    Cleaning(Plane *plane, Date date);
    Cleaning(Plane *plane, Date date, Staff *staff);
    char getType() const override{return ServiceTicket::getType();};
    void setResponsible (Staff *staff) override;
    void setSchedule (Date date) override;
    void setComplete (Date date) override;
    vector<string> getTasksLeft () const override;
    vector<string> getTasksCompleted() const override;
    Staff* getResponsible() override;
    Date getSchedule() override;
    void checkWc();
    void checkSeats();
    void checkFloor();
    void checkFlightDeck();
    bool verification() const;
};

class Maintenance : virtual ServiceTicket{
    bool engine = false;
    bool landGear = false;
    bool controls = false;
    bool emergency = false;
public:
    Maintenance(Plane *plane);
    Maintenance(Plane *plane, Date date);
    Maintenance (Plane *plane, Date date, Staff *staff);
    virtual char getType() const override{return ServiceTicket::getType();};
    void setResponsible (Staff *staff) override;
    void setSchedule (Date date) override;
    void setComplete (Date date) override;
    vector<string> getTasksLeft () const override;
    vector<string> getTasksCompleted() const override;
    Staff* getResponsible() override;
    Date getSchedule() override;
    void checkEngine();
    void checkLandGear();
    void checkControls();
    void checkEmergency();
    bool verification() const;
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
