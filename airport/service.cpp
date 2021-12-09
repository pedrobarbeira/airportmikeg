//
// Created by Joao on 27/11/21.
//

#include "service.h"

Service::Service(Plane *plane){
    responsible = nullptr;
    Time* time;
    time->now();
    created = *time;
}

Service::Service(Plane *plane, Date date){
    this->plane = plane;
    created = date;
    responsible = nullptr;
}

Service::Service(Plane *plane, Staff *staff) {
    Time* time;
    time->now();
    created = *time;
    responsible = staff;
}

Service::Service(Plane *plane, Date date, Staff *staff){
    this->plane = plane;
    responsible = staff;
    created = date;
}

void Service::setResponsible(Staff *staff) {
    responsible = staff;
}

void Service::setSchedule(Date date) {
    created = date;
}

void Service::setComplete (Date date) { //throw NoResponsible
    completed = date;
}

Staff* Service::getResponsible(){
    return responsible;
}

Cleaning::Cleaning(Plane *plane) : Service(plane) {}

Cleaning::Cleaning(Plane *plane, Date date) : Service(plane, date){}

Cleaning::Cleaning(Plane *plane, Date date, Staff *staff) : Service(plane, date, staff) {}

void Cleaning::setResponsible(Staff *staff) {
    Service::setResponsible(staff);
}

void Cleaning::setSchedule(Date date) {
    Service::setSchedule(date);
}

void Cleaning::setComplete(Date date) {
    Service::setComplete(date);
}

Staff* Cleaning::getResponsible() {
    return Service::getResponsible();
}


Maintenance::Maintenance(Plane *plane) : Service(plane) {

}

Maintenance::Maintenance(Plane *plane, Date date) : Service(plane, date) {

}

Maintenance::Maintenance(Plane *plane, Date date, Staff *staff) : Service(plane, date, staff) {

}

void Maintenance::setResponsible(Staff *staff) {
    Service::setResponsible(staff);
}

void Maintenance::setSchedule(Date date) {
    Service::setSchedule(date);
}

void Maintenance::setComplete(Date date) {
    Service::setComplete(date);
}
