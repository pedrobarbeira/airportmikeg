//Created by Pedro Barbeira (up201303693)

#include "mikeg.h"
#include "mainmenu.h"

ostream& operator<<(ostream& out, LoadFail lf){
    out << lf.getError();
    return out;
}

void MikeG::start(bool& flag) {
    this->setSysTime();
    system(CLEAR);
    char c;
    if(!flag) {
        std::cout << "Loading data\n";
        if (this->load()) {
            std::cout << "Load successful\n";
            std::cout << "Press enter to continue . . .";
            std::cin.ignore();
            c = getchar();
        } else {
            std::cout << "Load not successful\n";
            do {
                std::cout << "Continue[y/n]?";
                std::cin >> c;
                if (c == 'N' || c == 'n') flag = false;
                else if (c == 'Y' || c == 'y') flag = true;
            } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
            throw DevLog("Error during initial data file load. Check data files for corruption\n", sysTime);
        }
    }
    while (true) {
        system(CLEAR);
        std::cout << "[MikeG Airlines]\t\t\t";
        sysTime->print(std::cout);
        std::cout << "\n\n    [1] Buy Ticket"
                  << "\n    [2] Log In\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        std::cin >> c;
        try {
            switch (c) {
                case '1':
                    menu = new JustBuy();
                    menu->mainScreen();;
                    break;
                case '2':
                    clients();
                    break;
                case '0':
                    return;
                case '-':
                    if (checkDev()) {
                        dev();
                        break;
                    }
                default:
                    std::cout << "Invalid Option\n";
                    int c = getchar();
            }
        }
        catch (DevLog e) {
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
    bool successful = true;
    try {
        loadAirport();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        successful = false;
    }
    try {
        loadVoyage();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        successful = false;
    }
    try {
        loadFlight();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        successful = false;
    }
    try {
        loadPlane();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        successful = false;
    }
    try{
        loadTicket();
        successful = false;
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        successful = false;
    }
    try{
        loadUsers();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        successful = false;
    }
    return successful;
}

void DevLog::print() const{
    std::ofstream outfile("./data/devlogs.txt", ios::app);
    outfile << "*[";
    (*date).print(outfile);
    outfile << "] " << error;
    outfile.close();
}

