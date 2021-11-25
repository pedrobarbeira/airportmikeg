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

void now();
void menu();
void admin();
void workers();
void clients();

int login(char);

#endif //MIKEGAIRLINES_MAINMENU_H
