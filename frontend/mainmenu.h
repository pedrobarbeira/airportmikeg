//Created by Pedro Barbeira (up201303693)
#ifndef MIKEGAIRLINES_MAINMENU_H
#define MIKEGAIRLINES_MAINMENU_H

#include "admin.h"
#include "clients.h"
#include "workers.h"
#include "airport.h"
#include "voyage.h"
#include "passenger.h"
#include <vector>
#include <ctime>
#include <fstream>
#include <string>

//Main Menu Stub
void menu();
//Menu Stubs
void dev();
//BackEnd Workhorses
bool checkDev();
bool login(char);
int checkCredentials(char);

#endif //MIKEGAIRLINES_MAINMENU_H
