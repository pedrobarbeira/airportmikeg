//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_DATA_H
#define MAIN_CPP_DATA_H

#include <iostream>
#include "user.h"
#include "voyage.h"
#include "airport.h"

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
    friend class MikeG;
public:
    Data() : airports(AirportPointer(nullptr)), planes(PlanePointer(nullptr)),
             clients(ClientPointer(nullptr)), company(CompanyPointer(nullptr)),
             voyages(VoyagePointer(nullptr)){}
    //Turn these to return vectors with information
    BST<AirportPointer> getAirport() const{
        return airports;};
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
};

class Load{
    Data* data;
};

class Save{
    Data* data;
};

#endif //MAIN_CPP_DATA_H
