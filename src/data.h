//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_DATA_H
#define MAIN_CPP_DATA_H

#include <iostream>
#include "voyage.h"
#include "exception.h"

/**
 * Encapsulation class.
 * Initializes and stores all the system's BST's
 */
class Data{
    BST<AirportPointer> airports;
    BST<VoyagePointer> voyages;
    BST<PlanePointer> planes;
    BST<ClientPointer> clients;
    BST<CompanyPointer> company;
    BST<TicketPointer> tickets;
    friend class MikeG;
    friend class Menu;
public:
    Data() : airports(AirportPointer(nullptr)), planes(PlanePointer(nullptr)),
             clients(ClientPointer(nullptr)), company(CompanyPointer(nullptr)),
             voyages(VoyagePointer(nullptr)), tickets(TicketPointer(nullptr)){}
    //Turn these to return vectors with information
    std::vector<AirportPointer> getAirports() const;
    std::vector<FlightPointer> getFlights() const;
    BST<VoyagePointer> getVoyages() const{
        return voyages;};
    BST<PlanePointer> getPlanes() const{
        return planes;};
    bool addAirport(Airport* a){
        AirportPointer aptr(a);
        return airports.insert(aptr);
    }
    bool addVoyage(Voyage* v){
        VoyagePointer vptr(v);
        return voyages.insert(vptr);
    }
    bool addFlight(Flight* f);
    bool addPlane(Plane* p){
        PlanePointer pptr(p);
        return planes.insert(pptr);
    }
    bool addTicket(Ticket* t){
        TicketPointer tptr(t);
        return tickets.insert(tptr);
    }
};

class Load{
protected:
    Data* data;
public:
    explicit Load(Data* d = nullptr) : data(d){}
};

class LoadAirport : public Load{
public:
    explicit LoadAirport(Data*d = nullptr){
        data = d;
    }
};

class LoadVoyage : public Load{
public:
    explicit LoadVoyage(Data* d = nullptr){
        data = d;
    }
};

class LoadPlane : public Load{
public:
    explicit LoadPlane(Data* d = nullptr){
        data = d;
    }
};

class LoadUser : public Load{
public:
    explicit LoadUser(Data* d = nullptr){
        data = d;
    }
};

class Save{
protected:
    Data* data;
public:
    explicit Save(Data* d = nullptr) : data(d){}
};

class SaveAirport : public Save{
public:
    explicit SaveAirport(Data* d = nullptr){
        data = d;
    }
};

class SaveVoyage : public Save{
public:
    explicit SaveVoyage(Data* d = nullptr){
        data = d;
    }
};

class SavePlane : public Save{
public:
    explicit SavePlane(Data* d = nullptr){
        data = d;
    }
};

class SaveUser : public Save{
public:
    explicit SaveUser(Data* d = nullptr){
        data = d;
    }
};

#endif //MAIN_CPP_DATA_H
