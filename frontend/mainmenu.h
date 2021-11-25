//Created by Pedro Barbeira (up201303693)
#ifndef MIKEGAIRLINES_MAINMENU_H
#define MIKEGAIRLINES_MAINMENU_H

#include "airport.h"
#include "voyage.h"
#include "passenger.h"
#include <vector>
#include <ctime>
#include <fstream>
#include <string>

//Main Menu Stub
void menu();
//People Menu Stubs
void admin();
void workers();
void clients();
//BackEnd Workhorses
bool login(char);
int checkCredentials(char);

#endif //MIKEGAIRLINES_MAINMENU_H
