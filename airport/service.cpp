//
// Created by Joao on 27/11/21.
//

#include "service.h"

using namespace std;

//////////////////////////////////// S T A F F /////////////////////////



void Staff::setId() {
    this->id = staffId++;
}

void Staff::setPhone(unsigned phone) {
    if (phone > 999999999 | phone < 910000000) {/*throw InvalidNumber()*/;
        std::cout << "\t Invalid number";
    }
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

///////////////////// S E R V I C E T I C K E T /////////////////////////

ServiceTicket::ServiceTicket(Plane *plane, char id){
    responsible = nullptr;
    Time* time = new Time;
    time->now();
    created = time;
}

ServiceTicket::ServiceTicket(Plane *plane, Time *date, char id){
    this->plane = plane;
    created = date;
    responsible = nullptr;
    this->id = id;
}

ServiceTicket::ServiceTicket(Plane *plane, Staff *staff, char id) {
    Time* time = new Time;
    time->now();
    created = time;
    responsible = staff;
    this->id = id;

}

ServiceTicket::ServiceTicket(Plane *plane, Time *date, Staff *staff, char id){
    this->plane = plane;
    responsible = staff;
    created = date;
    this->id = id;

}

void ServiceTicket::setResponsible(Staff *staff) {
    responsible = staff;
}

void ServiceTicket::setCreated(Time *date){
    created = date;
}

void ServiceTicket::setComplete (Time *date) {
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

Time* ServiceTicket::getCreated() {
    return created;
}

bool ServiceTicket::operator<(ServiceTicket &s) {
    if (completed<s.completed) return true;
    else if (completed==s.completed && completed < s.completed) return true;
    else if (completed == s.completed && completed == s.completed && completed < s.completed) return true;
    return false;
}



///////////////////////////////////////////////

Cleaning::Cleaning(Plane *plane) : ServiceTicket(plane, 'c') {}

Cleaning::Cleaning(Plane *plane, Time *date) : ServiceTicket(plane, date, 'c'){}

Cleaning::Cleaning(Plane *plane, Time *date, Staff *staff) : ServiceTicket(plane, date, staff, 'c') {}

void Cleaning::setResponsible(Staff *staff) {
    ServiceTicket::setResponsible(staff);
}

void Cleaning::setCreated(Time *date) {
    ServiceTicket::setCreated(date);
}

void Cleaning::setComplete(Time *date) {
    if (getResponsible() == NULL) throw NoResponsible();
    ServiceTicket::setComplete(date);
}

Staff* Cleaning::getResponsible() {
    return ServiceTicket::getResponsible();
}

Time* Cleaning::getCreated() {
    return ServiceTicket::getCreated();
}

vector<string> Cleaning::getTasksLeft() const {
    vector<string> tl;
    if (!wc) tl.push_back("Bathroom");
    if (!seats) tl.push_back("Passenger seats");
    if (!floor) tl.push_back("Plane floor");
    if (!flightDeck) tl.push_back("Fligh Cabin");
    return tl;
}

vector<string> Cleaning::getTasksCompleted() const {
    vector<string> tl;
    if (wc) tl.push_back("Bathroom");
    if (seats) tl.push_back("Passenger seats");
    if (floor) tl.push_back("Plane floor");
    if (flightDeck) tl.push_back("Fligh Cabin");
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
    if (wc && seats && floor && flightDeck) return true;
    else return false;
}

///////////////////////////////////////////////

Maintenance::Maintenance(Plane *plane) : ServiceTicket(plane, 'm') {}

Maintenance::Maintenance(Plane *plane, Time *date): ServiceTicket(plane, date, 'm') {}

Maintenance::Maintenance(Plane *plane, Time *date, Staff *staff) : ServiceTicket(plane, date, staff, 'm') {}

void Maintenance::setResponsible(Staff *staff) {
    ServiceTicket::setResponsible(staff);
}

void Maintenance::setCreated(Time *date) {
    ServiceTicket::setCreated(date);
}

void Maintenance::setComplete(Time *date) {
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

Time* Maintenance::getCreated() {
    return ServiceTicket::getCreated();
}

vector<string> Maintenance::getTasksLeft() const {
    vector<string> tl;
    if (!engine) tl.push_back("Engine");
    if (!landGear) tl.push_back("Landing Gear");
    if (!controls) tl.push_back("Console and Controls");
    if (!emergency) tl.push_back("Emergency Equipment");
    return tl;
}

vector<string> Maintenance::getTasksCompleted() const {
    vector<string> tl;
    if (engine) tl.push_back("Engine");
    if (landGear) tl.push_back("Landing Gear");
    if (controls) tl.push_back("Plane Console and Controls");
    if (emergency) tl.push_back("Emergency Equipment");
    return tl;
}

bool Maintenance::verification() const {
    if (engine && landGear && controls && emergency) return true;
    else return false;
}