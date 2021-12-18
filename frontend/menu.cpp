//Created by Pedro Barbeira (up201303693)
#include "menu.h"

/**---Parent Menu---*/
void Menu::mainScreen() {
    std::cout << "blabla\n";
}

void Menu::print(std::vector<AirportPointer> v) const{
    system(CLEAR);
    std::cout << "\n\t::::::::::::::::::\n\t:::  AIRPORTS  :::\n\t::::::::::::::::::\n";
    std::cout << "\t   IdCode  Name                                         Staff\n"
              << "\t   ------  ----------                                 -------";
    for(int i = 0; i < v.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << v[i].getPointer()->getidCode() << ", " << v[i].getPointer()->getName()
                  << std::setw(52-v[i].getPointer()->getName().size())
                  << std::setfill(' ') << v[i].getPointer()->getStaff().size();
    }
}

void Menu::header() {
    std::cin.clear(); std::cin.ignore(INT32_MAX, '\n');
    system(CLEAR);
    //std::cout << "[" << user->getUser() << "]\t\t\t";
    sysTime->print();
}

void Menu::print(std::vector<Staff*> v) {
    system(CLEAR);
    if (v.empty()) {
        std::cout << "\n\tNo workers assigned to this airport\n";
        system("pause");
        return;
    }
    for (unsigned i{}; i < v.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << v[i]->getId() << ", " << v[i]->getName();
    }
}

void Menu::print(std::vector<ServiceTicket*> s){
    if (s.empty()) {
        std::cout << "\n\tThere are no services";
        system("pause");
        return;
    }
    vector<ServiceTicket*> pending, complete;
    for (auto it : s){
        if (it->getCompleted() != nullptr) complete.push_back(it);
        else pending.push_back(it);
    }
    if (pending.empty()) std::cout << "\n\tThere are no scheduled services";
    else{
        for (auto it : pending){
            std::cout << "\n\tServices waiting completion:\n";
            switch (it->getType()){
                case 'c' : {
                    std::cout << "\tCleaning pending --> / ";
                    for (auto i : it->getTasksLeft()) std::cout << i << " / "; break;
                }
                case 'm' : {
                    std::cout << "\tMaintenance pending --> / ";
                    for (auto i : it->getTasksLeft()) std::cout << i << " / "; break;
                }
            }
        }
        for (auto it : complete){
            std::cout << "\n\n\tServices complete:\n";
            switch (it->getType()){
                case 'c' : {
                    std::cout << "\tCleaning, terminated "; it->getCompleted()->printDate();
                }
                case 'm' : {
                    std::cout << "\tMaintenance, terminated "; it->getCompleted()->printDate();
                }
            }
            std::cout << "\n";
        }
    }
}

void Menu::newWorker(Airport *airport){
    string id, name; int phone;
    char a;
    Staff *staff = new Staff;
    cout << "\n\tNew worker addition to airport:";
    std::cin.clear(); std::cin.ignore(INT32_MAX, '\n');
    std::cout << "\n\tNew staff:\n\t\tName >"; std::getline(std::cin, name);
    std::cout << "\n\t\tPhone >"; std::cin >> phone;
    std::cout << "\n\n\tAdding " << name << " with contact - " << phone;
    std::cout << "\n\n\tIs this correct?(y/n) >"; std::cin >> a;
    switch (a){
        case 'y': {
            staff->setName(name); staff->setPhone(phone);
            std::cout << "\n\tNew staff added with idNumber " << staff->getId() << ".";
            airport->addStaff(staff);
            system("pause");
            break;
        }
        case 'n': std::cout << "\n\n\tNew member addition cancelled"; break;
        default: std::cout << "Invalid Option\n"; system("pause");
    }
}

void Menu::editWorker(Staff *staff){
    char a;
    std::cout << "\n\n\tCurrent staff attributes:" << "\n\t\tName: " << staff->getName()
              << "1n\t\tPhone: " << staff->getPhone();
}

Staff* Menu::selectStaff(std::vector<Staff*> v) {
    while(true){
        print(v);
        string a;
        std::cout <<"\n........................................................\n\tEnter staff row (0 to cancel): ";
        while (true) {
            std::cin >> a;
            if (a == "0") return nullptr;
            int i = stoi(a);
            return v[i - 1];
        }
    }
}

AirportPointer Menu::selectAirport(){
    std::vector<AirportPointer> airports = data->getAirports();
    while(true) {
        system(CLEAR);
        print(airports);
        char c;
        //TODO std::cout << "[" << user->getUser() << " - Airports]\t\t\t";
        //TODO sysTime->print();
        std::cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t[1] Select Airport"
                  << "\n\t[2] Order By\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1': {
                std::cout << "Enter Airport row: ";
                std::string in;
                //readInput(in);
                std::cin.clear(); std::cin.ignore(INT32_MAX, '\n');
                std::cin >> in;
                int i = stoi(in);
                if (i < 1 | i > airports.size()) break;
                return airports[i-1];
            }
            case '2': reOrderAirports(airports); break;
            case '0': return AirportPointer(nullptr);
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

void Menu::createPlane(Airbus *plane) {
    header();
    char a;
    string f;
    std::queue<std::string> first;
    std::cout << "\nCreating Airbus";
    std::cout << "\n\tInput first class rows letter (up until " << (char)(96+26) << ") --> ";
    std::cin.ignore(INT32_MAX, '\n'); std::getline(std::cin, f);
    for (auto i : f){
        if (i < (char)(96+26)) {
            std::string s; s = toupper(i); first.push(s);
        }
    }
    *plane = Airbus(first);
    data->addPlane(plane);
    return;
}

void Menu::createPlane(Other *plane) {
    header();
    uint16_t rows, seatPerRow, fClassPrice, eClassPrice;
    string f;
    std::queue<std::string> first;
    std::cout << "\n\tInput number of rows --> "; std::cin >> rows;
    std::cout << "\n\tInput seats per row --> "; std::cin >> seatPerRow;
    std::cout << "\n\tInput first class tickets price --> "; std::cin >> fClassPrice;
    std::cout << "\n\tInput economic class tickets price --> "; std::cin >> eClassPrice;
    std::cout << "\n\tInput first class rows letter (up until " << (char)(96+rows) << ") --> ";
    std::cin.ignore(INT32_MAX, '\n'); std::cin.clear(); std::getline(std::cin, f);
    for (auto i : f){
        if (i < (char)(96+rows)) {
            std::string s; s = toupper(i); first.push(s);
        }
    }
    *plane = Other(rows, seatPerRow, fClassPrice, eClassPrice, first );
    data->addPlane(plane);
}

void Menu::reOrderAirports(std::vector<AirportPointer> &v) {
    return;
}

void Menu::showAllFlights() const{
    system(CLEAR);
    std::vector<FlightPointer> out = data->getFlights();
    for (auto flight : out)
        std::cout << flight << '\n';
    std::cin.ignore();
    std::cout << "Press enter to continue . . .";
    getchar();
}

void Menu::logOut() const {
    Save save;
    save = SaveAirport(data);
    save.save();
    //repeat for all other SaveSubclass
}


/**---Dev Menu---*/
Dev::Dev(){
    ifstream infile("./data/devlogs.txt");
    if(!infile.is_open()){
        std::cout << "Developer Logs are corrupted\n"
                  << "Press enter to continue . . . ";
        getchar();
    }
    std::string line;
    while(std::getline(infile, line)){
        if(line[0] == '*') newLogs.push_back(line);
        else logs.push_back(line);
    }
    LogSorter sort;
    sort(logs);
    sort(newLogs);
}

void Dev::mainScreen() {
    char c;
    while (true) {
        bool flag = !newLogs.empty();
        system(CLEAR);
        std::cout << "[Dev]\t\t\t";
        sysTime->print();
        std::cout << "\n    [1] See Logs";
        if(flag) std::cout << "\n    [2]New Errors";
        std::cout << "\n\n    [0] Exit\n"
                  << "\n>";
        readInput(c);
        switch(c){
            case '1' : showLogs(flag); break;
            case '0' : save(flag); return;
            case '2' :
                if(flag) {
                    showNewLogs(); break;
                }
            default:{
                std::cout << "Invalid option\n\n"
                          << "Press enter to continue . . .";
                getchar();
            }
        }
    }
}

void Dev::showLogs(bool flag) const{
    system(CLEAR);
    for(auto log : logs)
        std::cout << log << '\n';
    if(flag){
        for(auto log : newLogs)
            std::cout << log << '\n';
    }

    std::cout << "\nPress enter to continue . . .\n";
    cin.ignore();
    int c = getchar();
}

void Dev::showNewLogs(){
    system(CLEAR);
    std::string line;
    for(auto log: newLogs){
        line = log.substr(1);
        std::cout << line << '\n';
        logs.push_back(line);
    }
    newLogs.clear();
    std::cout << "\nPress enter to continue . . .\n";
    cin.ignore();
    int c = getchar();
}

void Dev::save(bool flag){
    std::ofstream outfile("./data/devlogs");
    if(!outfile.is_open()){
        std::cout << "Error saving system logs\n\n"
                  << "Press enter to continue . . .";
        int c = getchar();
        return;
    }
    for(auto log : logs)
        outfile << log << '\n';
    if(flag){
        for(auto log : newLogs)
            outfile << log << '\n';
    }
    outfile.close();
}

/**---Client Menu---*/
void ClientMenu::mainScreen() {
    while(true) {
        system(CLEAR);
        char c;
        std::cout << "[" << user->getUser() << "]\t\t\t";
        sysTime->print();
        std::cout << "\n\t[1] Buy Ticket"
                  << "\n\t[2] Check In";
        if(user != nullptr)
            std::cout << "\n\t[3] Change Ticket"
                      << "\n\t[4] Ticket History\n";
        std::cout << "\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1': buyTicket(); break;
            case '2': checkIn(); break;
            case '0': return;
            case '3': if(user != nullptr) {
                changeTicket(); break;
            }
            case '4': if(user != nullptr){
                ticketHistory(); break;
            }
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

void ClientMenu::buyTicket(){
    while(true) {
        system(CLEAR);
        char c;
        std::cout << "[" << user->getUser() << "]\t\t\t";
        sysTime->print();
        std::cout << "\n\t[1] Sett Origin Airport"
                  << "\n\t[2] Set Destination Airport"
                  << "\n\t[3] See Flights"
                  << "\n\t[4] See Voyages";
        if(flight != nullptr || voyage != nullptr)
            std::cout << "\n\t[5] Buy Ticket\n";
        else std::cout << '\n';
        std::cout << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1': origin = selectAirport(); break;
            case '2': destination = selectAirport(); break;
            case '3': showAllFlights(); break;
            case '4': ticketHistory(); break;
            case '0': return;
            case '5': if(flight != nullptr || voyage != nullptr){
                purchase(); break;
            }
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

void ClientMenu::selectFlight(bool origin) {
    //Will print flights and give user option to select one or reorder
    while (true) {
        system(CLEAR);
        char c;
        std::cout << "[" << user->getUser() << "]\t\t\t";
        sysTime->print();
        std::cout << "\n\t[1] Search Origin Airport"
                  << "\n\t[2] Search Destination Airport"
                  << "\n\t[3] See Flights"
                  << "\n\t[4] See Voyages\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1':
                buyTicket();
                break;
            case '2':
                changeTicket();
                break;
            case '3':
                checkIn();
                break;
            case '4':
                ticketHistory();
                break;
            case '0':
                return;
            default:
                std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

AirportPointer ClientMenu::selectAirport(){
    std::vector<AirportPointer> airports = data->getAirports();
    if(destination.getPointer() != nullptr){
        for(std::vector<AirportPointer>::iterator it = airports.begin(); it != airports.end(); it++){
            if((*it) == destination){
                airports.erase(it);
                break;
            }
        }
    }
    else if(origin.getPointer() != nullptr){
        for(std::vector<AirportPointer>::iterator it = airports.begin(); it != airports.end(); it++){
            if((*it) == origin){
                airports.erase(it);
                break;
            }
        }
    }
    while(true) {
        system(CLEAR);
        print(airports);
        char c;
        std::cout << "[" << user->getUser() << " - Airports]\t\t\t";
        sysTime->print();
        std::cout << "\n\t[1] Select Airport"
                  << "\n\t[2] Order By\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1': {
                std::cout << "Enter Airport row: ";
                std::string in;
                readInput(in);
                int i = stoi(in);
                return airports[i-1];
            }
            case '2': reOrderAirports(airports); break;
            case '0': return AirportPointer(nullptr);
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

void ClientMenu::seeFlights(){}

void ClientMenu::seeVoyages(){}

void ClientMenu::purchase(){}

void ClientMenu::changeTicket(){}

void ClientMenu::checkIn(){}

void ClientMenu::ticketHistory(){}

/**---JustBuy Menu---*/
void JustBuy::mainScreen() {
    //Add error check
    system(CLEAR);
    std::cout << "[Buy Ticket]\t\t\t";
    std::string origin, destination, oDate, dDate;
    //Get Origin
    std::cout << "\nFrom:\n>";
    std::cin >> origin;
    std::cin.ignore();
    std::cout << "\nDate [DD/MM]:\n>";
    if(getchar() == '\n') oDate = "";
    else std::cin >> oDate;
    //Get Destination
    std::cout << "\nTo:\n>";
    std::cin >> destination;
    std::cin.ignore();
    std::cout << "\nDate:\n>";
    if(getchar() == '\n') dDate = "";
    else std::cin >> dDate;
    std::cout << origin << " " << oDate << " "
              << destination << " " << dDate << '\n';
    system("pause");
}

/**---Admin Menu---*/
void AdminMenu::mainScreen() {
    header();
    char c;
    //Shows real ADMIN menu after user has proven his identity
    while(true) {
        std::cout << "[ADMIN]\n"
                  << "\n\t[1] Airport Management"
                  << "\n\t[2] Worker Management"
                  << "\n\t[3] Travel Management"
                  << "\n\t[4] Plane Management"
                  << "\n\n\t[0] Log Out\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': airportMenu(); break;
            case '2': workers(); break;
            case '3': travel(); break;
            case '4': plane(); break;
            case '0': logOut(); throw LogOut();
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void AdminMenu::airportMenu() {
    header();
    char c;
    std::cout << "Airport Management Menu\n";
    while(true) {
        std::cout << "[AIRPORT]\n"
                  << "\n\t[1] Add Airport"
                  << "\n\t[2] Delete Airport"
                  << "\n\t[3] Check Airport"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': createAirport(); break;
            case '2': deleteAirport(); break;
            case '3': checkAirport(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void AdminMenu::createAirport(){
    header();
    char c;
    Airport *airport = new Airport;
    string id, name, city, country;
    char a;
    std::cout << "\n\tAirport creation menu"
              << "\n\n\tIntroduce Airport Location:"
              << "\n\tCountry > "; std::getline(std::cin, country);
    std::cout << "\n\tCity > "; std::getline(std::cin, city);
    std::cout << "\n\tName > "; std::getline(std::cin, name);
    std::cout << "\n\tIdentification code (3 letter word) > "; std::cin >> id;
    std::cout << "\n\n\tAirport (" << id << ") " << name
              << "\n\tat " << city << ", " << country
              << "\n\n\n\tIs this information correct(y/n)?\n\n >"; std::cin >> a;
    if (tolower(a) == 'y') {
        airport->setId(id); airport->setCountry(country); airport->setCity(city); airport->setName(name);
        data->addAirport(airport);
    }
    else {
        std::cout << "\n\nOperation canceled, returning to Airport management menu";
        system("pause");
    }
    return;
}

void AdminMenu::deleteAirport() {
    header();
    char a;
    bool test;
    while (true){
        Airport *airport = selectAirport().getPointer();
        if (airport == nullptr){
            std::cout << "Canceled deletion operation. Returning to Airport Management menu.\n";
            system("pause");
            return;
        } else
            std::cout << "\n\t" << "(" << airport->getidCode() << ")" << airport->getName()
                      << " is going to be deleted.\n\t Confirm deletion?(y/n)\n";
            std::cin >> a;
            switch (a) {
                case 'y':
                    test = data->delAirport(airport);
                    break;
                case 'n':
                    test = false;
                    break;
                default:
                    std::cout << "Invalid Option\n";
                    system("pause");
            }
        if (test) {
            std::cout << "\n\nAirport " << airport->getName() << " successfullly deleted.";
            system("pause");
        }
        else std::cout << "\n\nDeletion unsuccessfull.";
        system("pause");
        return;
    }
}
void AdminMenu::checkAirport() {
    header();
    char a;
    while (true){
        Airport *airport = selectAirport().getPointer();
        if (airport == nullptr) return;
        cout << "\n\t(" << airport->getidCode() << ") " << airport->getName() << " - " << airport->getCity() << ", " << airport->getCountry();
        airport->printAirport();
        airport->printService();
        if (airport->nextService() != NULL && airport->nextService()->getResponsible()==NULL){
            std::cout << "\n\tNo responsible set. Do you want attribute one?(y/n)"; std::cin >> a;
            switch (a){
                case 'y': {
                    Staff *staff = selectStaff(airport->getStaff());
                    airport->nextService()->setResponsible(staff);
                    break;
                }

                case 'n': break;
                default: std::cout << "Invalid Option\n"; system("pause");
            }
        }
        system("pause");
        return;
    }
}


void AdminMenu::workers() {
    char c;
    while(true) {
        system(CLEAR);
        std::cout << "[WORKER]\n"
                  << "\n\t[1] Add Worker"
                  << "\n\t[2] Delete Worker"
                  << "\n\t[3] Edit Worker"
                  << "\n\t[4] Move worker"
                  << "\n\t[5] Check ServiceTicket"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': addWorker(); break;
            case '2': delWorker(); break;
            case '3': changeWorker(); break;
            case '4': moveWorker(); break;
            case '5': checkService(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void AdminMenu::addWorker(){
    system(CLEAR);
    Airport *airport = selectAirport().getPointer();
    if (airport == nullptr) return;
    newWorker(airport);
    system("pause");
    return;
}
void AdminMenu::delWorker(){
    char a;
    system(CLEAR);
    Airport *airport = selectAirport().getPointer();
    Staff *staff = selectStaff(airport->getStaff());
    if (staff == nullptr) return;
    std::cout << "\n\tConfirm deletion of " << staff->getName() << " currently at " << airport->getName()<< "?(y/n)\n";
    while(true){
        std::cout << ">"; std::cin >> a;
        switch (a){
            case 'y' : airport->delStaff(staff); std::cout << "\n\n\tDeletion complete."; system("pause"); return;
            case 'n' : std::cout << "\n\n\tElimination of " << staff->getName() << " from " << airport->getName() << "cancelled."; return;
            default: std::cout << "Invalid Option\n"; std::cin.ignore(INT32_MAX, '\n'); system("pause");
        }
    }
}

void AdminMenu::changeWorker() {
    system(CLEAR);
    Airport *airport = selectAirport().getPointer();
    Staff *staff = selectStaff(airport->getStaff());
    if (staff == nullptr) return;
    editWorker(staff);
    return;
}

void AdminMenu::moveWorker() {
    char a;
    system(CLEAR);
    std::cout << "\n\tSelect airport from which you want to move worker:";
    Airport *airportOrigin = selectAirport().getPointer();
    Staff *staff = selectStaff(airportOrigin->getStaff());
    Airport *airportDest = selectAirport().getPointer();
    std::cout << "\n\tConfirm that you want to change " << staff->getName() << " from "
              << airportOrigin->getName() << " to " << airportDest->getName() << "?(y/n)"
              << "\n\t\t IMPORTANT: all pending services from " << staff->getName()
              << " will need a new staff assignement\n\n";
    while (true) {
        std::cout << ">";
        std::cin >> a;
        switch (a) {
            case 'n':
                std::cout << "\t\tWorker migration cancelled\n";
                system("pause");
                return;
            case 'y':
                airportDest->addStaff(staff);
                airportOrigin->delStaff(staff);
                system("pause");
                return;
            default:
                std::cout << "Invalid Option\n";
                std::cin.ignore(INT32_MAX, '\n');
                system("pause");
                break;
        }
    }
}

void AdminMenu::checkService(){
    system(CLEAR);
    vector<ServiceTicket*> temp;
    std::cout << "\n\tSelect Airport to check pending services:";
    Airport *airport = selectAirport().getPointer();
    print(airport->getServices());
    Staff *staff = selectStaff(airport->getStaff());
    for (auto it : airport->getServices()){
        if (it->getResponsible()!= nullptr && it->getResponsible()->getId() == staff->getId()) temp.push_back(it);
    }
    if (!temp.empty()) print(temp);
    else std::cout << "\n\tNo services atributted to this worker\n";
    system("pause");
    return;
}

void AdminMenu::travel() {}

void AdminMenu::plane() {
    header();
    char c;
    std::cout << "Plane Management Menu\n";
    while(true) {
        std::cout << "[PLANE]\n"
                  << "\n\t[1] Add Plane"
                  << "\n\t[2] Delete Plane"
                  << "\n\t[3] Check Plane"
                  << "\n\t[4] Plane Map"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': addPlane(); break;
            case '2': deletePlane(); break;
            case '3': checkPlane(); break;
            case '4': mapPlane(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void AdminMenu::addPlane(){
    header();
    char c;
    std::cout << "Plane Management Menu\n";
    while(true) {
        std::cout << "[ADD PLANE]\n"
                  << "\n\t[1] Airbus"
                  << "\n\t[2] Custom"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': Airbus *airbus; createPlane(airbus); break;
            case '2': Other *aircraft; createPlane(aircraft); break;
            case '3': checkPlane(); break;
            case '4': mapPlane(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void AdminMenu::deletePlane(){

}

void AdminMenu::checkPlane() {

}

void AdminMenu::mapPlane(){

}

/**---Manager Menu---*/
void ManagerMenu::mainScreen() {
    std::cout << "we are @ Manager\n"
              << "Press enter to continue . . .";
    char c = getchar();
}

/**---BoardingMenu---*/
void BoardingMenu::mainScreen(){
    std::cout << "we are @ Boarding\n"
              << "Press enter to continue . . .";
    char c = getchar();
}

/**---Service Menu---*/
void ServiceMenu::mainScreen() {
    std::cout << "we are @ Service\n"
              << "Press enter to continue . . .";
    char c = getchar();
}


/**---Helper Function---*/
void readInput(char& in){
    std::cin >> in;
}

void readInput(std::string& in){
    std::string line;
    std::getline(std::cin, line);
    if(line[0] == '-') std::cout << "Process syscalls\n";
    else in = line;
}

/**---Extraction Operators---*/
std::ostream& operator<<(std::ostream& out, const AirportPointer& aptr){
    Airport* a = aptr.getPointer();
    out << a->getidCode() << " " << a->getCountry() << " "
        << a->getCity() << " " << a->getName();
    return out;
}
std::ostream& operator<<(ostream& out, const FlightPointer & fptr){
    out << "hey";
    return out;
}