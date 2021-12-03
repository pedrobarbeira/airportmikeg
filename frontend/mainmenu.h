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


/**
 * Main Menu Interface
 */
void menu(MikeG* mg);

/**
 * Company members log-in Screen
 * @param mg the Airline DataStructure
 */
void company(MikeG* mg);

/**
 * Client page
 * @param mg the Airline DataStructure
 */
void clients(MikeG* mg);

/**
 * Interface for the hidden Developer Inferface
 */
void dev();

/**
 * Checks devlogs.txt to see if there are any new errors
 * @return true if there are new errors, false otherwise
 */
bool newErrors();

/**
 * Checks if user is a Dev upon --dev call
 * @return true if yes, false otherwise
 */
bool checkDev();

/**
 * Interface function that validates login data
 * @param c acts has a three-way flag: 'a' for admins, 'w' for workers and 'c' for clients
 * @return true if login is valid, false otherwise
 */
bool login(char, char&);

/**
 * Checks data in the respective credential folder, determined by the value of c.
 * Validates them and returns an integer code.
 * @param c 'a' for admins, 'w' for workers, 'c' for clients
 * @return 0 upon failure, 1 upon success, 2 upon file error
 */
bool checkCredentials(char, char&);

#endif //MIKEGAIRLINES_MAINMENU_H
