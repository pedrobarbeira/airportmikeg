//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include "data.h"
#include "sorter.h"


/**
 * Frontend class that handles Generic Menus. Acts as an Interface for it's subclasses
 */
class Menu{
protected:
    User* user;
    Data* data;
    Time* sysTime;
public:
    /**
     * Constructor for the menu class. Receives a Data* object from caller,
     * which contains all the system data. Initializes menu clock.
     * @param d the system data
     */
    explicit Menu(Data* d = nullptr) : data(d){
        sysTime = new Time;
        sysTime->now();
        user = nullptr;
    };

    /**
     * Abstract function used to implement the Main Screen of each subclass
     * of Menu. Used to improve code efficiency in Mike G. Acts as an interface
     * for each menu, allowing to navigate each submenu through method calls
     */
    virtual void mainScreen();

    /**
     * Prints an AirportPointer vector to screen, adding an encapsulated index
     * for ease of access by the user.
     * @param v the AirportPointer vector to be printed
     */
    void print(std::vector<AirportPointer> v) const;

    /**
     * Prints a FlightPointer vector to screen, adding an encapsulated index for ease
     * of access by the user.
     * @param v the FlightPointer vector to be printed
     */
    void print(std::vector<FlightPointer> v) const;

    /**
    * Shows airport list and asks user to choose the one he wishes. The user can
    * change the order to the list according to the provided options if he so
    * desires. Returns the chosen airport, or a null if the user returns. Removes
    * from the option list Airports that were already chosen.
    * @return the chosen airport
    */
    virtual AirportPointer selectAirport();

    /**
    * Shows user his reordering options and prompts him to choose one. Creates
    * an AirportPointer and sorts the parameter vector according to user's wishes.
    * Prints the reordered vector afterwards.
    * @param v the airport vector to be sorted.
    */
    void reOrderAirports(std::vector<AirportPointer>& v);

    /**
     * Prints on the screen all the flights that exist in the system
     */
    void showAllFlights() const;

    /**
     * method to show all the transport of an
     * airport to the screen
     * @param t
     */
    void print(std::vector<TransportPointer> t) const;

    void logOut() const;

    /**
     * function to avoid introducing the same information
     * everytime a menu is written
     */
    void header();

    /**
     * new worker menu to create and add a new staff member
     * to an airport
     * @param airport
     */
    void newWorker(Airport *airport);

    /**
     * function to help print a group of
     * staff members that work in an airport
     * to help selection
     * @param v
     */
    void print(std::vector<StaffPointer> v);

    /**
     * funcion to sendo to screen a group of serviceticket
     * @param s
     */
    void print(std::vector<ServiceTicket*> s);

    /**
     * function to allow selection of a staff member
     * and retieve to allow edition of the object
     * @param v
     * @return
     */
    StaffPointer selectStaff(std::vector<StaffPointer> v);

    /**
     *
     * @param plane
     */
    void createPlane(Airbus *plane);

    /**
     *
     * @param plane
     */
    void createPlane(Other *plane);

    /**
     *
     * @return
     */
    FlightPointer selectFlight();

    /**
     *
     * @param f
     */
    void reOrderFlights(std::vector<FlightPointer>& f);

    /**
     * function to retrieve a transport object information
     * @param airport
     * @return a transport pointer to the transport object
     */
    TransportPointer selectTransportPointer(Airport *airport);

    /**
     *
     */
    void print(std::vector<PlanePointer> p);
};

/**
 * Special hidden class, used to access the errors printed by the DevLog
 * exception. Access through main menu using the --dev <password> command
 */
class Dev : public Menu{
    std::vector<std::string> logs;
    std::vector<std::string> newLogs;
public:
    /**
     * Constructor for Dev class. Reads devlogs.txt and stores them into
     * a vector. New error logs will have a '*' flag to mark them as new,
     * and will be parsed into a different vector. Sorts logs by descending
     * order of Date.
     */
    Dev();

    /**
     * Main Screen of Dev Menu. Allows user to see the new error logs, if
     * there are any, or the old ones, by calling showLogs methos.
     */
    void mainScreen();

    /**
     * Prints error logs on screen. Receives a flag from caller to inform
     * if there are any new logs to be printed
     * @param flag indicates if there are new logs to print.
     */
    void showLogs(bool flag) const;

    /**
     * Prints the new logs on screen and stores them in the normal logs
     * vector. Removes the new log character flag before storing them,
     * and sorts the vector afterwards.
     */
    void showNewLogs();

    /**
     * Exit function of the Dev Menu. Saves the error logs in a text file,
     * for future access. Receives a flag to inform if there are unread
     * logs to be stored.
     * @param flag the unread logs flag.
     */
    void save(bool flag);
};

/**
 * Frontend class that handles Registered Client menus
 */
class ClientMenu : public Menu{
protected:
    Client* user;
    AirportPointer origin;
    AirportPointer destination;
    Flight* flight;
    Voyage* voyage;
public:
    /**
     * Constructor for Client Menu class. Receives a Client account Object
     * and the system data from caller. Declares and defines the submenus
     * and initializes the storage values
     * @param u the user that's using the menu
     * @param d the system data
     */
    explicit ClientMenu(Client* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        flight = nullptr;
        voyage = nullptr;
        sysTime = new Time;
        sysTime->now();
    }

    /**
     * Main screen of the Client Menu. Allows user to buy tickets, change
     * tickets, perform the check in or see the ticket history. Only shows
     * partial options if the user just wants to buy a ticket without creating
     * an account or logging in
     */
    void mainScreen() override;

    /**
     * Allows user to buy a ticket. Prompts him to select an origin airport,
     * a destination airport, see the list of flights or see the list of
     * voyages. Updates attributes accordingly. The option to actually buy
     * the ticket unlocks once the user has chose which ticket he wants to buy.
     */
    void buyTicket();

    /**
     * Shows list of flights and prompts user to choose one, updating the
     * flight attribute accordingly.
     */
    void selectFlight(bool);

    /**
     * Shows airport list and asks user to choose the one he wishes. The user can
     * change the order to the list according to the provided options if he so
     * desires. Returns the chosen airport, or a null if the user returns. Removes
     * from the option list Airports that were already chosen.
     * @return the chosen airport
     */
    AirportPointer selectAirport();

    void seeFlights();

    void seeVoyages();

    void changeTicket();

    void checkIn();

    void ticketHistory();

    void purchase();
};

/**
 * Frontend class that handles Unregistered Client menus
 */
class JustBuy : public ClientMenu{
public:
    explicit JustBuy(Data* d = nullptr){
        user = nullptr;
        data = d;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

class CheckIn : public ClientMenu{};

class Register : public ClientMenu{};

/**
 * Frontend class that handles Company menus
 */
class CompanyMenu : public Menu{
protected:
    Company* user;
    Airport* airport;
    //Add an airport
    //Add service ticket queue
    //add complete service queue
public:
    /**
     * menu to retrieve informarion of an airport
     * this can be accessed to all company members
     */
    void checkAirport();

    /**
     *
     */
    void checkFlights();

    /**
     * menu to customize a terminals of a certain
     * airport
     */
    void checkTerminal();

    /**
     * function to allow input to add a new terminal
     * to an existing airport
     */
    void addTerminal();

    /**
     * function to delete an airport terminal
     * with the contingency of beeing without
     * a plane
     */
    void delTerminal();

    /**
     * allows the user with previleges to change
     * information about the terminal, wether change
     * the number or to remove plane
     */
    void editTerminal();

    /**
     * function to access transport edition menu
     */
    void checkTransport();

    /**
     * funtion to add a new transport to an
     * airport allowing through input to create
     * a new object
     */
    void addTransport();

    /**
     * funciton to delete an existing transport
     * from a list of transport of an airport
     */
    void delTransport();

    /**
     * change time of a transport, but
     * doesn't allow to change type or distance
     */
    void editTransport();

    /**
     * creation of a new serviceTicket of an
     * airport that is previously selected and passed
     * by pointer
     * @param airport
     */
    void createService(Airport *airport, Plane *plane);

    /**
     * function to assess the tasks left in a service
     * and allows to terminate them. If all tasks are
     * complete the service is removed form the
     * queue
     * @param airport
     */
    void checkTasks(Airport *airport);

    /**
     * function to select a terminal wether to
     * remove it or edit
     * @param airport
     * @return
     */
    Terminal* selectTerminal(Airport *airport);

    /**
     * funciton to select a plane from an airport
     * previously selected and passed by pointer
     * @param airport
     * @return
     */
    PlanePointer selectPlane(Airport *airport);

    PlanePointer selectPlane();


    /**
     * menu to access workers management
     */
    void workers();

    /**
     * funciton to allow a creation and introducion
     * of a worker int he company and attribute
     * to an airport
     */
    void addWorker();

    /**
     * function to allow after selection the deletion
     * of an worker, removing him from any
     * pending serviceTickets
     */
    void delWorker();

    /**
     * function to edit information of a staff worker
     */
    void changeWorker();

    /**
     * funcion to allow the admin to move a worker
     */
    void moveWorker();

    /**
     * function to assess the service in the queue of an
     * airport
     */
    void checkService();
};

/**
 * Frontend class that handles Admin menus
 */
class AdminMenu : public CompanyMenu{
public:
    explicit AdminMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;

    /**
     * function to access airport menu
     * accessible only by the admin
     */
    void airportMenu();

    /**
     * creation and insertion of a new airport
     * in the data
     */
    void createAirport();

    /**
     * allows through input to eliminate
     * an airport with which the company no long
     * operates in
     */
    void deleteAirport();


    void travel();

    /**
     * funciton to access plane management menu
     */
    void plane();

    /**
     * function that allows to add a new airplane
     * to the fleet, which con be predetermined or
     * a custom
     */
    void addPlane();

    /**
     * function to remove a certain airplane form
     * the fleet
     */
    void deletePlane();

    /**
     * function to retrieve plane information
     */
    void checkPlane();

    /**
     * should allow to map all planes across
     * the airport and in the sky
     */
    void mapPlane();

    void newTravel();
    void deleteTravel();
    void editTravel();

};

/**
 * Frontend class that handles Manager menus
 */
class ManagerMenu : public CompanyMenu{
public:
    explicit ManagerMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;

};

/**
 * Frontend class that handles Boarding Crew menus
 */
class BoardingMenu : public CompanyMenu{
public:
    explicit BoardingMenu(Company* u = nullptr, Data* d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

//Eventually split this into BoardingPassenger and CheckinPassenger

/**
 * Frontend class that handles ServiceTicket Worker menus
 */
class ServiceMenu : public CompanyMenu{
public:
    explicit ServiceMenu(Company* u = nullptr, Data*d = nullptr){
        user = u;
        data = d;
        airport = nullptr;
        sysTime = new Time;
        sysTime->now();
    }
    void mainScreen() override;
};

void readInput(char& in);
void readInput(std::string& in);

std::ostream& operator<<(ostream& out, const AirportPointer& aptr);
std::ostream& operator<<(ostream& out, const FlightPointer & fptr);

#endif //MAIN_CPP_MENU_H
