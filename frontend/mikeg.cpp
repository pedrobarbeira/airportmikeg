//Created by Pedro Barbeira (up201303693)

#include "mikeg.h"
#include "mainmenu.h"

void MikeG::open(){
    char c;
    while(true) {
        this->setSysTime();
        system(CLEAR);
        std::cout << "[MikeG Airlines]\t\t\t";
        sysTime->print(std::cout);
        std::cout << "\n    [1] Buy Ticket"
                  << "\n    [2] Log In\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        std::cin >> c;
        try {
            switch (c) {
                case '1': menu = new JustBuy();
                        menu->mainScreen();
                        ;break;
                case '2': clients(); break;
                case '0': return;
                case '-': if (checkDev()) {dev();break;}
                default: std::cout << "Invalid Option\n";
                    int c = getchar();
            }
        }
        catch(DevLog e){
            e.print();
        }
    }
}

bool MikeG::save() const {
    return true;
}

bool MikeG::loadAirport(){
    throw LoadAirportFail();
}

bool MikeG::loadVoyage(){
    throw LoadVoyageFail();
}

bool MikeG::loadFlight(){
    throw LoadFlightFail();
}

bool MikeG::loadPlane(){
    throw LoadPlaneFail();
}

bool MikeG::loadTicket(){
    throw LoadTicketFail();
}

void MikeG::loadUsers(){
    ifstream infile("./data/users.txt");
    if(!infile.is_open()){
        throw LoadUserFail();
    }
    std::string uName, uPass;
    char uType;
    while(infile >> uName){
        infile >> uPass >> uType;
        addUser(new User(uName, uPass, uType));
    }
    infile.close();
}

bool MikeG::load(){
    try {
        loadAirport();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
    }
    try {
        loadVoyage();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
    }
    try {
        loadFlight();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
    }
    try {
        loadPlane();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
    }
    try{
        loadTicket();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
    }
    try{
        loadUsers();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
    }
    return true;
}

void DevLog::print() const{
    std::ofstream outfile("./data/devlogs.txt");
    outfile << "*" << error << '\n';
    outfile.close();
}

ostream& operator<<(ostream& out, LoadFail lf){
    out << lf.getError();
    return out;
}