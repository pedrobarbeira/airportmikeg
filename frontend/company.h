/**Will be deleted soon*/

//Created by Pedro Barbeira (up201303693)
#ifndef MIKEGAIRLINES_ADMIN_H
#define MIKEGAIRLINES_ADMIN_H

#include <iostream>
#include "mikeg.h"

void admin(/*MikeG* mg*/ Data *data);

void airport();

void worker();

void travel(MikeG* mg);
void flightList(MikeG* mg);
void voyage();
void createVoyage();
void changeVoyage();
void deleteVoyage();
void flight();
void createFlight();
void changeFlight();
void deleteFlight();
void plane();

//Airport management menu functions
void createAirport();
void deleteAirport();
void checkAirport();
void listAirport();

//Workers management menu functions
void workers();
void addWorker();
void delWorker();
void checkService();

//Workers menu functions
void pendingServices();
void createService();
void resolveService();
void historyService();

//This function is because in menu navigation it is often required to choose the terms of search of an airport
Airport* selectAirport();

//TODO
//print functions by class
void printAirport(Airport *airport);
void printService(Airport *airport);
void printStaff(Staff *staff);
void printTransport(Airport *airport);

#endif //MIKEGAIRLINES_ADMIN_H
