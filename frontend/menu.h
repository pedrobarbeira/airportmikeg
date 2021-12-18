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

//Think about making the sorter into a class

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

    void logOut() const;

    void header();

    void newWorker(Airport *airport);

    void editWorker(Staff *staff);

    void print(std::vector<Staff*> v);

    void print(std::vector<ServiceTicket*> s);

    Staff* selectStaff(std::vector<Staff*> v);
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

    void airportMenu();
    void createAirport();
    void deleteAirport();
    void checkAirport();

    void workers();
    void addWorker();
    void delWorker();
    void changeWorker();
    void moveWorker();
    void checkService();

    void travel();

    void plane();
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
