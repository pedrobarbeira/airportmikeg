//Created by Pedro Barbeira (up201303693)
#ifndef MIKEGAIRLINES_MAINMENU_H
#define MIKEGAIRLINES_MAINMENU_H

#include "company.h"
#include "clients.h"
#include "airport.h"
#include "voyage.h"
#include "passenger.h"
#include <vector>
#include <ctime>
#include <fstream>
#include <string>

/**
 * Struct to load and pass the objects of the airline
 */
class MikeG{
public:
    std::vector<Airport*> airports;
    std::vector<Voyage*> voyages;
    std::vector<Flight*> flight;
};

//Main Menu Stub
void menu();
//Menu Stubs
void company();
void dev();
//BackEnd Workhorses
bool checkDev();
bool login(char, char&);
bool checkCredentials(char, char&);

/**Exceptino classes*/
class DevLog {
    std::string error;
public:
    DevLog(std::string e) : error(e) {};
    void print() const;
};

class LogOut{
    std::string message;
public:
    LogOut(){
        message = "Log Out Successful";
    }
    void print() const{
        std::cout << message << '\n';
    }
};

#endif //MIKEGAIRLINES_MAINMENU_H
