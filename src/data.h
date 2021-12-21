//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_DATA_H
#define MAIN_CPP_DATA_H

#include <iostream>
#include "voyage.h"
#include "exception.h"

//Rearrange modules so the company subclass is all treated in one
/**
 * Encapsulation class.
 * Initializes and stores all the system's BST's
 */
class Data{
    BST<AirportPointer> airports;
    BST<VoyagePointer> voyages;
    BST<PlanePointer> planes;
    BST<FlightPointer> flights;
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
    Data() : airports(AirportPointer(nullptr)), voyages(VoyagePointer(nullptr)),
             planes(PlanePointer(nullptr)), flights(FlightPointer(nullptr)),
             clients(ClientPointer(nullptr)), company(CompanyPointer(nullptr)) {
        BST<AirportPointer> a(AirportPointer(nullptr));
        airports = a;
        BST<VoyagePointer> v(VoyagePointer(nullptr));
        voyages = v;
        BST<FlightPointer> f(FlightPointer(nullptr));
        flights = f;
        BST<PlanePointer> p(PlanePointer(nullptr));
        planes = p;
        BST<ClientPointer> c(ClientPointer(nullptr));
        clients = c;
        BST<CompanyPointer> cp(CompanyPointer(nullptr));
        company = cp;
    };

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
    std::vector<PlanePointer> getPlanes() const;

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

    std::vector<ServiceTicket*> getServiceTicket() const;

    /**
     * Getter for the airports BSt
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
    BST<FlightPointer> getFlightBST() const{
        return flights;
    }

    /**
     * Iterates through the flights BST and creates a TicketPointer BST with
     * all the tickets stored in the system
     * @return the BST with all the existing tickets
     */
    BST<TicketPointer> getTicketBST() const;

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

 /*   BST<ServicePointer> getServicesBST() const{
        return services;
    }*/

    /**
     * Adds an airport to the airports BST
     * @param a pointer to Airport that'll be added
     * @return true upon success, false otherwise
     */
    bool addAirport(Airport* a){
        AirportPointer aptr(a);
        return airports.insert(aptr);
    }

    /**
     * Adds an Airport to the airports BST
     * @param aptr the Airport that'll be added
     * @return tue upon success, false otherwise
     */
    bool addAirport(const AirportPointer& aptr){
        return airports.insert(aptr);
    }

    /**
     * Deletes an airport from the airports BST
     * @param a the airport to be deleted
     * @return result of the deletion
     */
    bool delAirport(Airport *a){
        AirportPointer aptr(a);
        return airports.remove(aptr);
    }


    /**
     * Adds a voyage to the voyages BST
     * @param v pointer to the Voyage that'll be added
     * @return true upon success. false otherwise
     */
    bool addVoyage(Voyage* v){
        VoyagePointer vptr(v);
        return voyages.insert(vptr);
    }

    /**
     * Adds a flight to the voyages BST
     * @param f pointer to the flight that'll be added
     * @return true upon success. false otherwise
     */
    bool addFlight(Flight* f);

    /**
     * Adds a flight to the flights BST
     * @param f the Flight to be added
     * @return true upon success, false otherwise
     */
    bool addFlight(const FlightPointer& f){
        return flights.insert(f);
    }

    /**
     * Adds a plane to the planes BST
     * @param p pointer the plane that'll be added
     * @return true upon success. false otherwise
     */
    bool addPlane(Plane* p){
        PlanePointer pptr(p);
        return planes.insert(pptr);
    }

    /**
     * Adds a ticket to the tickets BST
     * @param t pointer to the ticket that'll be added
     * @return true upon success. false otherwise
     */
    static bool addTicket(FlightPointer& f, Ticket* t){
        return f.addTicket(t);
    }


    /**
     * Adds a client account to the clients BST
     * @param c poitner to the client account that'll be added
     * @return true upon success. false otherwise
     */
    bool addClient(Client* c){
        ClientPointer cptr(c);
        return clients.insert(cptr);
    }

    /**
     * Adds a company account to the company BST
     * @param c pointer to the company account that'll be added
     * @return true upon success. false otherwise
     */
    bool addCompany(Company* c){
        CompanyPointer cptr(c);
        return company.insert(cptr);
    }

    /**
     * Removes a company account from the company BST
     * @param c pointer to the company account that'll be added
     * @return true upon success. false otherwise
     */
    bool delCompany(Company* c){
        CompanyPointer cptr(c);
        return company.remove(cptr);
    }

    /**
     * Removes a Plane from the Planes BST
     * @param p the Plane to be removed
     * @return true upon success, false otherwise
     */
    bool delPlane(Plane* p){
        PlanePointer pptr(p);
        return planes.remove(pptr);
    }

    /**
     * Searches for a given Airport in the airports BST
     * @param id the ID of the Airport to be found
     * @return the result of the search
     */
    AirportPointer findAirport(const std::string& id) const;

    /**
     * Searches for a given Ticket in the tickets BST
     * @param id the ID of the ticket to be found
     * @return the result of the sarch
     */
    static Staff* findStaff(const Airport* a, const std::string& id);

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
     * Finds the Flight which is associated to a given Plane
     * @param p the Plane
     * @return the result of the search
     */
    FlightPointer findFlight(const Plane* p) const;

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

    /**
     * Removes an Airport from the Airports BST
     * @param id the Id of the Airport to be removed
     * @return true upon success, false otherwise
     */
    bool removeAirport(const std::string& id){
        AirportPointer aptr = findAirport(id);
        return airports.remove(aptr);
    }

    /**
     * Removes a given Flight from the flights BSt
     * @param id the Id of the Flight to be removed
     * @return true upon success, false otherwise
     */
    bool removeFlight(const std::string& id){
        FlightPointer fptr = findFlight(id);
        return flights.remove(fptr);
    }

};

class Load{
protected:
    Data* data;
public:
    /**
     * Constructor for the Parent Class Load. Receives a Data object, which
     * will contain the loaded data
     * @param d pointer to the Data object
     */
    explicit Load(Data* d = nullptr) : data(d){}

    /**
     * High level abstraction method. Creates an object of a child class
     * and calls it's load() method. Ensures the data is loaded in the proper
     * order, so there are no memory errors during the load process. Allows
     * programmer to quickly find and modigy any error-prone line in case
     * any problem occurs. Catches and handles any thrown exceptions
     */
    virtual void load();
};

class LoadAirport : public Load{
    /**
     * Loads Plane related information
     */
    void loadPlane();

    /**
     * Loads Airport related information. Calls methods loadTerminal,
     * loadStaff, loadService and loadTransport. Catches and handles
     * any thrown exceptions
     */
    void loadAirport();

    /**
     * Loads the Terminal related information of a given Airport. The
     * data is sent from loadAirport through a string
     * @param a pointer to the Airport
     * @param tData string with Terminal information
     */
    void loadTerminal(Airport* a,std::vector<std::string>& tData);

    /**
     * Loads the Staff related information of a given Airport
     * @param a pointer to the Airport
     */
    static void loadStaff(Airport* a, const std::string& sData);

    /**
     * Loads the Service related information of a given Airport. The
     * data is sent from loadAirport through a string. Loads completed
     * and non-completed Services
     * @param a pointer to the Airport
     * @param l1 the non-completed Service data
     * @param l2 the completed Service data
     */
    void loadService(Airport* a,const std::string& l1, const std::string& l2);

    /**
     * Loads the Transport related information of a given Airport. The
     * data is sent from loadAirport through a string
     * @param a pointer to the Airport
     * @param l the Transport data
     */
    static void loadTransport(Airport* a, std::string& l);
public:
    /**
     * Constructor for the LoadAirport class. Receives a Data object
     * and stores it in the data attribute
     * @param d pointer to the Data object which will loaded
     */
    explicit LoadAirport(Data*d = nullptr){
        data = d;
    }

    /**
     * Public method which ensures the Airport load is done in the proper
     * sequential order. Catches and handles any thrown exception
     */
    void load() override;
};

class LoadVoyage : public Load{
    /**
     * Loads Flight related information into the Data object
     */
    void loadFlight();

    /**
     * Loads Voyage related information into the Data object
     */
    void loadVoyage();

    /**
     * Loads Ticket related information into the Data object
     */
    void loadTicket();
public:
    /**
     * Constructor for the LoadVoyage class. Receives a Data object
     * and stores it in the data attribute
     * @param d pointer to the Data object which will be loaded
     */
    explicit LoadVoyage(Data* d = nullptr){
        data = d;
    }

    /**
     * Public method which ensures the Voyage load is done in the proper
     * sequenctal order. Catches and handles any thrown exceptions
     */
    void load() override;
};

class LoadUser : public Load{
    /**
     * Loads Client account related information into the Data object
     */
    void loadClient();

    /**
     * Loads Company account related information into the Data object
     */
    void loadCompany();
public:
    /**
     * Constructor for the LoadUser class. Reiceives a Data object
     * and stores it in the data attribute
     * @param d pointer to the Data object which will be loaded
     */
    explicit LoadUser(Data* d = nullptr){
        data = d;
    }

    /**
     * Public method which ensured the User load is done in the proper
     * sequential order. Catches and handles any thrown exceptions
     */
    void load() override;
};

class Save{
protected:
    Data* data;
public:
    /**
     * Constructor for the Parent Class Save. Receives a Data object containing
     * the data to be saved and stores it in the data attribute
     * @param d pointer to the Data object
     */
    explicit Save(Data* d = nullptr) : data(d){}

    /**
     * High level abstraction method. This method creates an object of a child
     * class and calls it's save method. Allows programmer to easily figure out
     * which part of the save process has gone wrong, in case of bugs. Allows
     * programmer to easily shift how each module is saved in the system.
     * Catches any exceptions that might be thrown - as do the overloaded versions
     */
    virtual void save() const;
};

class SaveAirport : public Save{
    /**
     * Saves all the information of a given Airprort in text files
     * @param a pointer to the Airport
     */
    static void saveAirport(const AirportPointer& a);

    /**
     * Saves all the Terminal-related information of an Airport  in a text file
     * @param a pointer to the Airport
     */
    static void saveTerminal(const Airport* a);

    /**
     * Saves all the Transport-related information of an Airport  in a text file
     * @param a pointer to the Airport
     */
    static void saveTransport(const Airport* a);

    /**
     * Saves all the ServiceTicket-related information of an Airport  in a text file
     * @param a pointer to the Airport
     */
    static void saveService(Airport* a);

    /**
     * Saves all the Staff-related information of an Airport in a text file
     * @param a pointer to the Airport
     */
    static void saveStaff(const Airport* a);
public:
    /**
     * Constructor for SaveAirport class. Receives a pointer to a data
     * object and loads it into the data attribute
     * @param d pointer to a data object
     */
    explicit SaveAirport(Data* d = nullptr){
        data = d;
    }

    /**
     * Public method which ensures the Airport save is done in the expected
     * sequential order.
     */
    void save() const override;

};

class SaveVoyage : public Save{
    /**
     * Saves the Voyage related information in a text file
     */
    void saveVoyage() const;

    /**
     * Saves the Flight related information in a text file
     */
    void saveFlight() const;

    /**
     * Saves the informations of the tickets of a flight in a text file
     */
    static void saveTicket(const FlightPointer& fp);

    /**
     * Thes the information of the planes in a text file
     */
    void savePlane() const;
public:
    /**
     * Constructor for the SaveVoyage class. Saves information of the
     * Voygae, Flight, Plane and Ticket classes. Receives a Data object
     * with the information to be saved
     * @param d pointer to the Data object
     */
    explicit SaveVoyage(Data* d = nullptr){
        data = d;
    }

    /**
     * Public method which ensures the information is saved in the proper
     * sequential order.
     */
    void save() const override;
};

class SaveUser : public Save{
    /**
     * Saves the Client related information in a text file. Calls saveTickets
     * with the appropriate Client object
     */
    void saveClient() const;

    /**
     * Saves the ticket list of a given Client in a textfile. Uses specific
     * flags to inform the Loader where the tickets of one given client start
     * and end
     * @param c pointer to the Client object
     */
    static void saveTickets(Client* c);

    /**
     * Saves the Company related information in a text file. Acts as a higher
     * level interface for the different types of client account, calling them
     * in a similar fashion that the save() method calls the private functions
     */
    void saveCompany() const;

    /**
     * Saves the Admin and Manager accounts in a text file
     */
    void saveAdmin() const;

    /**
     * Saves the Boarding accounts in a text file
     */
    void saveBoarding() const;

    /**
     * Saves the Service arrounds in a text file
     */
    void saveService() const;
public:
    /**
     * Constructor for the SaveUser class. Saves information of the Account
     * module. Receives a Data object with the information to be saved
     * @param d pointer to the Data object
     */
    explicit SaveUser(Data* d = nullptr){
        data = d;
    }

    /**
     * Public method which ensures the information is saved in the proper
     * sequential order
     */
    void save() const override;
};

#endif //MAIN_CPP_DATA_H
