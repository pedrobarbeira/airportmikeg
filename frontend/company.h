/**Will be deleted soon*/

//Created by Pedro Barbeira (up201303693)
#ifndef MIKEGAIRLINES_ADMIN_H
#define MIKEGAIRLINES_ADMIN_H

#include <iostream>
#include "mikeg.h"

void admin(MikeG* mg);
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

//Airport menu functions
void createAirport();
void deleteAirport();
void checkAirport();
void listAirport();

//Worrs menu functions
void workers();
void addWorker();
void delWorker();
void checkService();


#endif //MIKEGAIRLINES_ADMIN_H
