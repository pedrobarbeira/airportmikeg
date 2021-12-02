//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_SERVICE_H
#define MIKEGAIRLINES_SERVICE_H

#include <iostream>
#include "../date.h"


using namespace std;

class Service{
    class Plane *plane;
    class Staff *responsible;
    class Date* created;
    class Date* completed;


public:
    Service(Plane &plane);
    Service(Plane &plane, Date* date);
    Service(Plane &plane, Staff &staff);
    Service(Plane &plane, Date* date, Staff &staff);
    void setResponsible (Staff* staff);
    void setComplete (Date* date);
    Staff* getResponsible();
};





/*
class Cleaning : Service{
    queue<Date> scheduled;
    queue<Date> completed;
    Staff *responsible;
public:
    Cleaning(Plane &plane);
    Cleaning(Plane &plane, Date &date) ;
    Cleaning(Plane &plane, Date &date, Staff &staff) ;
    void setResponsible (Staff &staff);
    void setScheduled (Date &date);
    void setCompleted (Date &date);

};

class Maintenance : Service{
    queue<Date*> scheduled;
    queue<Date*> completed;
public:
    Service(Plane plane);
    Service(Plane plane, Date date);
    Service (Plane plane, Date date, Staff staff);
    void setResponsible (Staff staff);
    void setScheduled (Date &date) override;
    void setCompleted (Date &date) override;
};
*/
#endif //MIKEGAIRLINES_SERVICE_H
