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
    BST<TicketPointer> tickets;
    BST<ClientPointer> clients;
    BST<CompanyPointer> company;
    friend class MikeG;
    friend class Menu;
    friend class LoadAirport;
    friend class LoadUser;
    friend class SaveUser;
public:
    Data() : airports(AirportPointer(nullptr)), planes(PlanePointer(nullptr)),
             clients(ClientPointer(nullptr)), company(CompanyPointer(nullptr)),
             voyages(VoyagePointer(nullptr)), tickets(TicketPointer(nullptr)){}

    std::vector<AirportPointer> getAirports() const;
    std::vector<Voyage*> getVoyages() const;
    std::vector<FlightPointer> getFlights() const;
    std::vector<Plane*> getPlanes() const;
    std::vector<Ticket*> getTickets() const;
    std::vector<Client*> getClients() const;
    std::vector<Company*> getCompany() const;

    BST<AirportPointer> getAirportBST() const{
        return airports;
    }
    BST<VoyagePointer> getVoyageBST() const{
        return voyages;};
    BST<PlanePointer> getPlaneBST() const{
        return planes;};
    BST<FlightPointer> getFlightBST() const;
    BST<TicketPointer> getTicketsBST() const{
        return tickets;
    }
    BST<ClientPointer> getClientsBST() const{
        return clients;
    }
    BST<CompanyPointer> getCompanyBST() const{
        return company;
    }

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
    bool addClient(Client* c){
        ClientPointer cptr(c);
        return clients.insert(cptr);
    }
    bool addCompany(Company* c){
        CompanyPointer cptr(c);
        return company.insert(cptr);
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
    void save() const;
};

class SaveAirport : public Save{
    /**
     * Saves all the information of a given Airprort in text files
     * @param a pointer to the Airport
     */
    void saveAirport(AirportPointer a) const;

    /**
     * Saves all the Terminal-related information of an Airport  in a text file
     * @param a pointer to the Airport
     */
    void saveTerminal(Airport* a) const;

    /**
     * Saves all the Transport-related information of an Airport  in a text file
     * @param a pointer to the Airport
     */
    void saveTransport(Airport* a) const;

    /**
     * Saves all the ServiceTicket-related information of an Airport  in a text file
     * @param a pointer to the Airport
     */
    void saveService(Airport* a) const;

    /**
     * Saves all the Staff-related information of an Airport in a text file
     * @param a pointer to the Airport
     */
    void saveStaff(Airport* a) const;
public:
    /**
     * Constructor for SaveAirport class. Receives a pointer to a data
     * object and loads it into the data attribute
     * @param d pointer to a data object
     */
    explicit SaveAirport(Data* d = nullptr){
        data = d;
    }
    void save() const;

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
    void saveClient() const;
    void saveAdmin() const;
    void savemanager() const;
    void saveBoarding() const;
    void saveService() const;
    void saveServiceList() const;
};

#endif //MAIN_CPP_DATA_H
