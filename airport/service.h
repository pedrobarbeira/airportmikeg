//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_SERVICE_H
#define MIKEGAIRLINES_SERVICE_H

#include <iostream>
#include "plane.h"
#include "staff.h"
#include "../src/date.h"


using namespace std;

class Service{
    Plane *plane;
    Staff *responsible;
    Date created;
    Date completed;


public:
    Service(Plane *plane);
    Service(Plane *plane, Date date);
    Service(Plane *plane, Staff *staff);
    Service(Plane *plane, Date date, Staff *staff);
    virtual void setResponsible (Staff *staff);
    virtual void setSchedule (Date date);
    virtual void setComplete (Date date);
    virtual Staff *getResponsible();
};



class Cleaning : public Service{
    bool wc = false;
    bool seats = false;
    bool floor = false;
    bool flightDeck = false;
public:
    Cleaning(Plane *plane);
    Cleaning(Plane *plane, Date date) ;
    Cleaning(Plane *plane, Date date, Staff *staff) ;
    void setResponsible (Staff *staff) override;
    void setSchedule (Date date) override;
    void setComplete (Date date) override;
    Staff* getResponsible() override;

};

class Maintenance : public Service{
    bool engine = false;
    bool landTrain = false;
    bool controls = false;
    bool emergency = false;
public:
    Maintenance(Plane *plane);
    Maintenance(Plane *plane, Date date);
    Maintenance (Plane *plane, Date date, Staff *staff);
    void setResponsible (Staff *staff) override;
    void setSchedule (Date date) override;
    void setComplete (Date date) override;
};

#endif //MIKEGAIRLINES_SERVICE_H
