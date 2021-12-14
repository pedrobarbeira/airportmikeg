//Created by Pedro Barbeira (up201303693)

#include "mikeg.h"
#include "mainmenu.h"

ostream& operator<<(ostream& out, LoadFail lf){
    out << lf.getError();
    return out;
}

template<>
void MikeG::readInput<char>(char& in){
    cin.ignore();
    std::cin >> in;
}

template<>
void MikeG::readInput<std::string>(std::string& in){
    cin.ignore();
    std::string line;
    std::getline(std::cin, line);
    if(line[0] == '-') std::cout << "Process syscalls\n";
    else in = line;
}

void MikeG::loadScreen(bool&flag){
    char c;
    if(!flag) {
        std::cout << "Loading data\n";
        try {
            load();
        }
        catch (DevLog e) {
            do {
                std::cout << "Continue[y/n]?";
                readInput(c);
                if (c == 'N' || c == 'n') flag = false;
                else if (c == 'Y' || c == 'y') flag = true;
            } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
            throw e;
        }
        std::cout << "Load successful\n";
        std::cout << "Press enter to continue . . .";
        std::cin.ignore();
        c = getchar();
    }
}

void MikeG::start() {
    this->setSysTime();
    system(CLEAR);
    char c;
    bool flag = false;
    while (true) {
        try{
            loadScreen(flag);
        }
        catch(DevLog e){
            e.print();
            if(!flag) return;
        }
        loadScreen(flag);
        system(CLEAR);
        std::cout << "[MikeG Airlines]\t\t\t";
        sysTime->print(std::cout);
        std::cout << "\n\n    [1] Buy Ticket"
                  << "\n    [2] Check In"
                  << "\n    [3] Register"
                  << "\n    [4] Log In\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        readInput(c);
        try {
            switch (c) {
                case '1':
                    menu = new JustBuy(data);
                    break;
                case '2':
                    menu = logIn();
                    break;
                case '3':
                    if(!newAccount()) {
                        std::cout << "Could not register account";
                        throw DevLog("Error adding new account to system database\n", sysTime);
                    }
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
            if(menu != nullptr) menu->mainScreen();
        }
        catch (DevLog e) {
            e.print();
        }
    }
}

Menu* MikeG::logIn() {
    std::string line;
    std::cout << "> ";
    readInput(line);
    if (line == "client")
        return new ClientMenu();
    if (line == "admin")
        return new AdminMenu();
    if (line == "manager")
        return new ManagerMenu();
    if (line == "boarding")
        return new BoardingMenu();
    if (line == "servce")
        return new ServiceMenu();
    /*std::string user, pass;
    std::cout << "\n\n\n\n\n";
    std::cout << "Username\n>";
    readInput(user);
    std::cout << "Password\n>";
    readInput(pass);
    UserPointer find(new User(user));
    find = data->users.find(find);
    char c;
    if((*find).getPassword() == pass){
        c = (*find).getType();
        switch(c){
            case 'A' :
                Menu* ret = new AdminMenu(find.getPointer());
                return ret;
        }
    }
    else {
        std::cout << "Invalid credentials\n"
                  << "Press enter to continue . . .";
        c = getchar();
        return nullptr;
    }*/
}

bool MikeG::newAccount(){
    return true;
}

bool MikeG::addFlight(const FlightPointer& f){
    bool flag;
    AirportFlightList addIn = data->airports.find(AirportFlightList((*f).getOrigin()->airport));
    data->airports.remove(addIn);
    AirportFlightList addOut = data->airports.find(AirportFlightList((*f).getDestination()->airport));
    data->airports.remove(addOut);
    flag = addIn.addFlight(f.getPointer()) && addOut.addOut(f.getPointer());
    if(flag){
        data->airports.insert(addIn);
        data->airports.insert(addOut);
        flag &= data->flights.insert(f);
    }
    return flag;
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
    //Fix this so UserPointers store the desired values
    while(infile >> uName){
        infile >> uPass >> uType;
        User* u = new User(uName, uPass, uType);
        UserPointer uptr(u);
        addUser(uptr);
    }
    infile.close();
}

bool MikeG::load(){
    stringstream error;
    bool successful = true;
    try {
        loadAirport();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try {
        loadVoyage();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try {
        loadFlight();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try {
        loadPlane();
    }
    catch (LoadFail e){
        std::cout << e << '\n';
        error << e << ", ";
        successful = false;
    }
    try{
        loadTicket();
        successful = false;
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
