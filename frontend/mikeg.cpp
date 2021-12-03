//Created by Pedro Barbeira (up201303693)

#include "mikeg.h"

bool MikeG::save() const {
    std::ofstream outfile;
    //save airports
    outfile.open("./data/airports.txt");
    if(!outfile.is_open()) throw DevLog("[mikeg.cpp/save] Error opening ./data/airports.txt");
    for(auto it: airports)
        //outfile << it->getidCode() << ',' << it->getName() << ',' << it->getCountry() << ',' << it->getCity();
    outfile.close();
    //save planes
    return true;
}

bool MikeG::loadAirport(){return true;}

bool MikeG::loadVoyage(){return true;}

bool MikeG::loadFlight(){return true;}

bool MikeG::loadPlane(){return true;}

bool MikeG::loadTicket(){return true;}

bool MikeG::load(){
    if(!loadAirport()) throw LoadAirportFail();
    if(!loadVoyage()) throw LoadVoyageFail();
    if(!loadFlight()) throw LoadFlightFail();
    if(!loadPlane()) throw LoadPlaneFail();
    if(!loadTicket()) throw LoadTicketFail();
    return true;
}

void DevLog::print() const{
    std::ofstream outfile("./data/devlogs.txt");
    outfile << "*" << error << '\n';
    outfile.close();
}
