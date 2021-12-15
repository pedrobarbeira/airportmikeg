//Created by Pedro Barbeira (up201303693)

#include "iostream"
#include "mikeg.h"

ostream& operator<<(ostream& out, LoadFail lf){
    out << lf.getError();
    return out;
}

bool MikeG::loadScreen(bool&flag){
    char c;
    if(!flag) {
        std::cout << "Loading data\n";
        try {
            load();
            flag = true;
            std::cout << "Load successful\n";
            std::cout << "Press enter to continue . . .";
            std::cin.ignore();
            c = getchar();
            return true;
        }
        catch (DevLog& e) {
            do {
                std::cout << "Continue[y/n]?";
                readInput(c);
                if (c == 'N' || c == 'n') flag = false;
                else if (c == 'Y' || c == 'y') flag = true;
            } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
            e.print();
            return false;
        }
    }
}

void MikeG::start(bool& flag) {
    this->setSysTime();
    system(CLEAR);
    bool keep = false;
    while (true) {
        char c;
        if(!flag) {
            flag = loadScreen(keep);
            if(!keep) return;
        }
        system(CLEAR);
        std::cout << "[MikeG Airlines]\t\t\t";
        sysTime->print();
        std::cout << "\n\n    [1] Buy Ticket"
                  << "\n    [2] Check In"
                  << "\n    [3] Register"
                  << "\n    [4] Log In\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        readInput(c);
        try {
            switch (c) {
                case '1' : menu = new JustBuy(data); break;
                case '2' : std::cout << "Register\n"; break;
                case '3':
                    if(!newAccount()) {
                        std::cout << "Could not register account";
                        throw DevLog("Error adding new account to system database\n", sysTime);
                    }
                case '4': menu = logIn(); break;
                case '0': return;
                case '-':
                    if (checkDev()) {
                        menu = new Dev; break;
                    }
                default:
                    std::cout << "Inval1d Option\n\n"
                              << "Press enter to continue . . .";
                    readInput(c);
            }
            if(menu != nullptr) menu->mainScreen();
            else{
                std::cout << "Invalid credentials\n\n"
                          << "Press enter to continue . . .";
                readInput(c);
            }
        }
        catch (DevLog e) {
            e.print();
        }
    }
}

/**
 * LogIn function. Reads credentials from input and searches for a corresponding
 * account in the data.clients and data.company bst's. Once it finds a match,
 * compares input password with the password saved in the system data. If the
 * data checks out, returns corresponding Menu. If not, outputs "Invalid credentials"
 * and returns nullptr.
 * @return the proper menu if the account data is in the system, nullptr otherwise.
 */
Menu* MikeG::logIn() {
    std::string user, pass;
    std::cin.ignore();

    std::cout << "\n\n\n\n\n"
              << "Username\n>";
    readInput(user);
    std::cout << "Password\n>";
    readInput(pass);
    bool flag = true;
    CompanyPointer searchCompany(new Company(user));
    searchCompany = data->company.find(searchCompany);
    char c;
    if (searchCompany.getPointer() == nullptr) {
        ClientPointer searchClient(new Client(user));
        searchClient = data->clients.find(searchClient);
        if (searchClient.getPointer() != nullptr) {
            if ((*searchClient).getPassword() == pass)
                return new ClientMenu(searchClient.getPointer(), data);
        }
    } else {
        if ((*searchCompany).getPassword() == pass) {
            c = (*searchCompany).getType();
            switch (c) {
                case 'A' : return new AdminMenu(searchCompany.getPointer(), data);
                case 'M' : return new ManagerMenu(searchCompany.getPointer(), data);
                case 'B' : return new BoardingMenu(searchCompany.getPointer(), data);
                case 'S' : return new ServiceMenu(searchCompany.getPointer(), data);
            }
        }
    }
    return nullptr;
}

bool MikeG::newAccount(){
    return true;
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
    ifstream infile("./data/company.txt");
    if(!infile.is_open()){
        throw LoadUserFail();
    }
    std::string uName, uPass;
    char uType;
    while(infile >> uName){
        infile >> uPass >> uType;
        Company* c = new Company(uName, uPass, uType);
        CompanyPointer cptr(c);
        data->company.insert(cptr);
    }
    infile.close();

    infile.open("./data/client.txt");
    if(!infile.is_open()){
        throw LoadUserFail();
    }
    while(infile >> uName){
        infile >> uPass >> uType;
        Client* c = new Client(uName, uPass, uType);
        ClientPointer cptr(c);
        data->clients.insert(cptr);
    }
    infile.close();

}

bool MikeG::load(){
    stringstream error;
    bool successful = true;
    try {
        //loadAirport();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try {
        //loadVoyage();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try {
        //loadFlight();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try {
        //loadPlane();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try{
        //loadTicket();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try{
        loadUsers();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e;
        successful = false;
    }
    if(!successful) throw DevLog(error.str(), sysTime);
}

bool MikeG::checkDev() {
    int DEVSIZE = 9;
    std::string DEV = "c3n4";
    std::string in;
    std::getline(std::cin, in);
    if (in.size() == DEVSIZE)
        if (in.substr(0, 4) == "-dev")
            if (in.substr(5, 4) == DEV)
                return true;
    return false;
}

void DevLog::print() const{
    std::ofstream outfile("./data/devlogs.txt", ios::app);
    if(date != nullptr) {
        outfile << "*[";
        (*date).print(outfile);
        outfile << "] ";
    }
    outfile << error << '\n';
    outfile.close();
}
