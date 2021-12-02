//Created by Pedro Barbeira (up201303693)
#ifndef MIKEGAIRLINES_MAINMENU_H
#define MIKEGAIRLINES_MAINMENU_H

#include "company.h"
#include "clients.h"
#include "mikeg.h"
#include "passenger.h"
#include "service.h"
#include "staff.h"
#include "transport.h"
#include <vector>
#include <ctime>
#include <fstream>
#include <string>


//Main Menu Stub
void menu(MikeG* mg);
//Menu Stubs
void company(MikeG* mg);
void dev();
//BackEnd Workhorses
bool checkDev();
bool login(char, char&);
bool checkCredentials(char, char&);

#endif //MIKEGAIRLINES_MAINMENU_H
