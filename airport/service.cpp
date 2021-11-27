//
// Created by Joao on 27/11/21.
//

#include "service.h"

Service::Service(){
}

Service::Service(Plane &plane, Date &date){
    this->plane = &plane;
    created = &date;
}

Service::Service(Plane &plane, Date &date, Staff &staff){
    this->plane = &plane;
    responsible = &staff;
    created = &date;
}

void Service::setResponsible(Staff &staff) {
    responsible = &staff;
}

void Service::setComplete(Date &date) {
    completed = &date;
}




