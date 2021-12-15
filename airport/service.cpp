//
// Created by Joao on 27/11/21.
//

#include "service.h"

using namespace std;


Staff::Staff(string name) {
    this->name= name;
}

void Staff::setId() {
    this->id = staffId++;
}

void Staff::setPhone(unsigned phone) {
    if (phone > 999999999 | phone < 910000000) throw InvalidNumber();
    else this->phone = phone;
}

string Staff::getName() const {
    return name;
}

unsigned Staff::getPhone() const {
    return phone;
}

unsigned Staff::getId() const {
    return id;
}

/////////////////

ServiceTicket::ServiceTicket(Plane *plane, char id){
    responsible = nullptr;
    Time* time = new Time;
    time->now();
    created = *time;
}

ServiceTicket::ServiceTicket(Plane *plane, Date date, char id){
    this->plane = plane;
    created = date;
    responsible = nullptr;
}

ServiceTicket::ServiceTicket(Plane *plane, Staff *staff, char id) {
    Time* time = new Time;
    time->now();
    created = *time;
    responsible = staff;
}

ServiceTicket::ServiceTicket(Plane *plane, Date date, Staff *staff, char id){
    this->plane = plane;
    responsible = staff;
    created = date;
}

void ServiceTicket::setResponsible(Staff *staff) {
    responsible = staff;
}

void ServiceTicket::setSchedule(Date date) {
    created = date;
}

void ServiceTicket::setComplete (Date date) {
    if (responsible == NULL) throw NoResponsible();
    completed = date;
}

vector<string> ServiceTicket::getTasksLeft() const {
    vector<string> tl;
    tl.push_back("isto não devia aparecer");
    return tl;
}

vector<string> ServiceTicket::getTasksCompleted() const {
    vector<string> tl;
    tl.push_back("isto não devia aparecer");
    return tl;
}

Staff* ServiceTicket::getResponsible(){
    return responsible;
}

Date ServiceTicket::getSchedule() {
    return created;
}

bool ServiceTicket::operator<(ServiceTicket &s) {
    if (completed.getYear()<s.completed.getYear()) return true;
    else if (completed.getYear()==s.completed.getYear() &&
            completed.getMonth() < s.completed.getMonth()) return true;
    else if (completed.getYear()==s.completed.getYear() &&
            completed.getMonth() == s.completed.getMonth() &&
            completed.getDay()<s.completed.getDay()) return true;
    return false;
}



///////////////////////////////////////////////

Cleaning::Cleaning(Plane *plane) : ServiceTicket(plane, 'c') {}

Cleaning::Cleaning(Plane *plane, Date date) : ServiceTicket(plane, date, 'c'){}

Cleaning::Cleaning(Plane *plane, Date date, Staff *staff) : ServiceTicket(plane, date, staff, 'c') {}

void Cleaning::setResponsible(Staff *staff) {
    ServiceTicket::setResponsible(staff);
}

void Cleaning::setSchedule(Date date) {
    ServiceTicket::setSchedule(date);
}

void Cleaning::setComplete(Date date) {
    if (getResponsible() == NULL) throw NoResponsible();
    ServiceTicket::setComplete(date);
}

Staff* Cleaning::getResponsible() {
    return ServiceTicket::getResponsible();
}

Date Cleaning::getSchedule() {
    return ServiceTicket::getSchedule();
}

vector<string> Cleaning::getTasksLeft() const {
    vector<string> tl;
    if (wc==false) tl.push_back("Bathroom");
    if (seats==false) tl.push_back("Passenger seats");
    if (floor==false) tl.push_back("Plane floor");
    if (flightDeck==false) tl.push_back("Fligh Cabin");
    return tl;
}

vector<string> Cleaning::getTasksCompleted() const {
    vector<string> tl;
    if (wc==true) tl.push_back("Bathroom");
    if (seats==true) tl.push_back("Passenger seats");
    if (floor==true) tl.push_back("Plane floor");
    if (flightDeck==true) tl.push_back("Fligh Cabin");
    return tl;
}

void Cleaning::checkWc() {wc = true;
}

void Cleaning::checkSeats() {seats = true;
}

void Cleaning::checkFloor() {floor = true;
}

void Cleaning::checkFlightDeck() {flightDeck = true;
}

bool Cleaning::verification() const {
    if (wc == true &&
        seats == true &&
        floor == true &&
        flightDeck == true) return true;
    else return false;
}

///////////////////////////////////////////////

Maintenance::Maintenance(Plane *plane) : ServiceTicket(plane, 'm') {}

Maintenance::Maintenance(Plane *plane, Date date): ServiceTicket(plane, date, 'm') {}

Maintenance::Maintenance(Plane *plane, Date date, Staff *staff) : ServiceTicket(plane, date, staff, 'm') {}

void Maintenance::setResponsible(Staff *staff) {
    ServiceTicket::setResponsible(staff);
}

void Maintenance::setSchedule(Date date) {
    ServiceTicket::setSchedule(date);
}

void Maintenance::setComplete(Date date) {
    if (getResponsible() == NULL) throw NoResponsible();
    ServiceTicket::setComplete(date);
}

void Maintenance::checkEngine() {engine= true;
}

void Maintenance::checkLandGear() {landGear = true;
}

void Maintenance::checkControls() {controls = true;
}

void Maintenance::checkEmergency() {emergency = true;
}

Staff* Maintenance::getResponsible() {
    return ServiceTicket::getResponsible();
}

Date Maintenance::getSchedule() {
    return ServiceTicket::getSchedule();
}

vector<string> Maintenance::getTasksLeft() const {
    vector<string> tl;
    if (engine==false) tl.push_back("Engine");
    if (landGear==false) tl.push_back("Landing Gear");
    if (controls==false) tl.push_back("Plane Console and Controls");
    if (emergency==false) tl.push_back("Emergency Equipment");
    return tl;
}

vector<string> Maintenance::getTasksCompleted() const {
    vector<string> tl;
    if (engine==true) tl.push_back("Engine");
    if (landGear==true) tl.push_back("Landing Gear");
    if (controls==true) tl.push_back("Plane Console and Controls");
    if (emergency==true) tl.push_back("Emergency Equipment");
    return tl;
}

bool Maintenance::verification() const {
    if (engine == true &&
        landGear == true &&
        controls == true &&
        emergency == true) return true;
    else return false;
}
