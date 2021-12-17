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
    /**
     * Constructor for Data class. Initializes each BST
     */
    Data() : airports(AirportPointer(nullptr)), planes(PlanePointer(nullptr)),
             clients(ClientPointer(nullptr)), company(CompanyPointer(nullptr)),
             voyages(VoyagePointer(nullptr)), tickets(TicketPointer(nullptr)){}

    /**
     * Converts the airports BST into a vector of AirportPointer objects
     * @return a vector with the data stored in the airports BST
     */
    std::vector<AirportPointer> getAirports() const;

    /**
     * Converts the voyages BST into a vector of Voyage* objects
     * @return a vector with the data stored in the voyages BST
     */
    std::vector<Voyage*> getVoyages() const;

    /**
     * Iterates the airports BST and returns a vector of all the FlightPointer
     * objects containing all flights
     * @return a vector with all the FlightPointer objects in the system
     */
    std::vector<FlightPointer> getFlights() const;

    /**
     * Converts the planes BST into a vector of Plane* objects
     * @return a vector with the data stored in the planes BST
     */
    std::vector<Plane*> getPlanes() const;

    /**
     * Converts the tickets BST into a vector of Ticket* objects
     * @return a vector with the data stored in the tickets BST
     */
    std::vector<Ticket*> getTickets() const;

    /**
     * Converts the clients BST into a vector of Client* objects
     * @return a vector with the data stored in the clients BST
     */
    std::vector<Client*> getClients() const;

    /**
     * Converts the company BST into a vector of Company* objects
     * @return a vector with the data stored in the company BST
     */
    std::vector<Company*> getCompany() const;

    /**
     * Returns the airports BST
     * @return the airports BST
     */
    BST<AirportPointer> getAirportBST() const{
        return airports;
    }

    /**
     * Returns the voyages BST
     * @return the voyages BST
     */
    BST<VoyagePointer> getVoyageBST() const{
        return voyages;};

    /**
     * Returns the planes BST
     * @return the planes BST
     */
    BST<PlanePointer> getPlaneBST() const{
        return planes;};

    /**
     * Creates a FlightPointer BST and iterates through the airports BST
     * adding all FlightPointer objects of the system into the FlightPointer BST
     * @return the created FlightPointer BSt
     */
    BST<FlightPointer> getFlightBST() const;

    /**
     * Returns the tickets BST
     * @return the tickets BST
     */
    BST<TicketPointer> getTicketsBST() const{
        return tickets;
    }

    /**
     * Returns the clients BST
     * @return the clients BST
     */
    BST<ClientPointer> getClientsBST() const{
        return clients;
    }

    /**
     * Returns the company BST
     * @return the company BST
     */
    BST<CompanyPointer> getCompanyBST() const{
        return company;
    }

    /**
     * Adds an airport to the airports BST
     * @param a pointer to Airport that'll be added
     * @return bool upon success, false otherwise
     */
    bool addAirport(Airport* a){
        AirportPointer aptr(a);
        return airports.insert(aptr);
    }

    /**
     * Adds a voyage to the voyages BST
     * @param v pointer to the Voyage that'll be added
     * @return bool upon success. false otherwise
     */
    bool addVoyage(Voyage* v){
        VoyagePointer vptr(v);
        return voyages.insert(vptr);
    }

    /**
     * Adds a flight to the voyages BST
     * @param f pointer to the flight that'll be added
     * @return bool upon success. false otherwise
     */
    bool addFlight(Flight* f);

    /**
     * Adds a plane to the planes BST
     * @param p pointer the plane that'll be added
     * @return bool upon success. false otherwise
     */
    bool addPlane(Plane* p){
        PlanePointer pptr(p);
        return planes.insert(pptr);
    }

    /**
     * Adds a ticket to the tickets BST
     * @param t pointer to the ticket that'll be added
     * @return bool upon success. false otherwise
     */
    bool addTicket(Ticket* t){
        TicketPointer tptr(t);
        return tickets.insert(tptr);
    }

    /**
     * Adds a client account to the clients BST
     * @param c poitner to the client account that'll be added
     * @return bool upon success. false otherwise
     */
    bool addClient(Client* c){
        ClientPointer cptr(c);
        return clients.insert(cptr);
    }

    /**
     * Adds a company account to the company BST
     * @param c pointer to the company account that'll be added
     * @return bool upon success. false otherwise
     */
    bool addCompany(Company* c){
        CompanyPointer cptr(c);
        return company.insert(cptr);
    }

    /**
     * Searches for a given Airport in the airports BST
     * @param id the ID of the Airport to be found
     * @return the result of the search
     */
    AirportPointer findAirport(const std::string& id) const;

    /**
     * Searches for a given Voyage in the voyages BST
     * @param id the ID of the Voyage to be found
     * @return the result of the search
     */
    Voyage* findVoyage(const std::string& id) const;

    /**
     * Searches for a given Flight in the airports BST
     * @param id the ID of the Flight to be found
     * @return the result of the search
     */
    FlightPointer findFlight(const std::string& id) const;

    /**
     * Searches for a given Plane in the planes BST
     * @param id the ID of the Plane to be found
     * @return the result of the search
     */
    Plane* findPlane(const std::string& id) const;

    /**
     * Searches for a given Ticket in the tickets BST
     * @param id the ID of the ticket to be found
     * @return the result of the sarch
     */
    Ticket* findTicket(const std::string& id) const;

    /**
     * Searches for a given client account in the clients BST
     * @param id the ID of the client account to be found
     * @return the result of the saerch
     */
    Client* findClient(const std::string& id) const;

    /**
     * Searches for a given company account in the company BST
     * @param id the ID of the company account to be found
     * @return the result of the search
     */
    Company* findCompany(const std::string& id) const;
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
