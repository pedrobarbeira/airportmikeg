//
// Created by Joao on 27/11/21.
//

#include "service.h"

Service::Service(class Plane &plane){
    Time time;
    int d = time.now()->getDay();
    size_t m = time.now()->getMonth();
    size_t y = time.now()->getYear();
    Date date (d, m, y);
    created = date;
}

Service::Service(class Plane &plane, class Date &date){
    this->plane = &plane;
    created = date;
}

Service::Service(class Plane &plane, class Staff &staff) {
    Time time;
    created = *time.now();
    responsible = &staff;
}

Service::Service(class Plane &plane, class Date &date, class Staff &staff){
    this->plane = &plane;
    responsible = &staff;
    created = date;
}

void Service::setResponsible(class Staff &staff) {
    responsible = &staff;
}

void Service::setComplete(class Date &date) {
    completed = date;
}

Staff& Service::getResponsible(){
    return *responsible;
}






