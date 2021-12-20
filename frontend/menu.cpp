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

void Menu::print(std::vector<FlightPointer> f) const{
    system(CLEAR);
    std::cout << "\n\t::::::::::::::::::\n\t:::  FLIGHTS  :::\n\t::::::::::::::::::\n";
    std::cout << "\t     IdCode  Origin    Time        Destiny     Time    Plane\n"
              << "\t     ------- -------   --------    --------    ------   -------";
    for(int i = 0; i < f.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << f[i].getPointer()->getOrigin()->airport->getidCode() << "-"
                  << f[i].getPointer()->getDestination()->airport->getidCode()
                  << " " << f[i].getPointer()->getOrigin()->airport->getCity()
                  << "    ";
                  f[i].getPointer()->getOrigin()->time->printTime();
        std::cout << "   " << f[i].getPointer()->getDestination()->airport->getCity()
                  << "    ";
                  f[i].getPointer()->getDestination()->time->printTime();
        std::cout << "   " << f[i].getPointer()->getPlane()->getPlate();
    }
}

void Menu::print(std::vector<Flight*> f) const{
    system(CLEAR);
    std::cout << "\n\t::::::::::::::::::\n\t:::  FLIGHTS  :::\n\t::::::::::::::::::\n";
    std::cout << "\t     IdCode  Origin    Time        Destiny     Time    Plane\n"
              << "\t     ------- -------   --------    --------    ------   -------";
    for(int i = 0; i < f.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << f[i]->getOrigin()->airport->getidCode() << "-"
                  << f[i]->getDestination()->airport->getidCode()
                  << " " << f[i]->getOrigin()->airport->getCity()
                  << "    ";
        f[i]->getOrigin()->time->printTime();
        std::cout << "   " << f[i]->getDestination()->airport->getCity()
                  << "    ";
        f[i]->getDestination()->time->printTime();
        std::cout << "   " << f[i]->getPlane()->getPlate();
    }
}

void Menu::print(std::vector<TransportPointer> t)const{
    system(CLEAR);
    std::cout << "\n\t::::::::::::::::::\n\t:::  TRANSPORT  ::\n\t::::::::::::::::::\n";
    std::cout << "\t     Type(distance)    Time\n"
              << "\t     ---------------   ---------";
    for(int i = 0; i < t.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << t[i].getPointer()->getTransport() << "("
                  << t[i].getPointer()->getDistance() << "m)"
                  << " -          "; t[i].getPointer()->getTime()->printTime();
    }
    std::cout << "\n\n";
    system("pause");
}

void Menu::print(std::vector<PlanePointer> p){
    system(CLEAR);
    std::cout << "\n\t::::::::::::::::::\n\t:::    PLANE   :::\n\t::::::::::::::::::\n";
    std::cout << "\tPlate(Capacity)   Location     nextflight\n"
              << "\t---------------------------------------------";
    for(int i = 0; i < p.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << p[i].getPointer()->getPlate();

        for (auto j : data->getAirports()){
            for (auto k : j.getPointer()->getTerminals()){
                if (k->getOccupied() && p[i].getPointer()->getPlate() == k->getPlane()->getPlate()){
                    std::cout << " at (" << j.getPointer()->getidCode() << ")"
                              << j.getPointer()->getCity() << ", "
                              << j.getPointer()->getCountry();
                }
            }

        }
        for (auto j : data->getFlights()){
            if (j.getPointer()->getPlane()->getPlate() == p[i].getPointer()->getPlate()){
                std::cout << " " << j.getPointer()->getOrigin()->airport->getidCode()
                          << "-" << j.getPointer()->getDestination()->airport->getidCode()
                          << " - "; j.getPointer()->getOrigin()->time->printDate();
            }
        }
    }
    std::cout << "\n\n";
    system("pause");
}

void Menu::print(std::vector<TicketPointer> t) const{
    system(CLEAR);
    std::cout << "\n\t::::::::::::::::::\n\t:::  TICKETS  :::\n\t::::::::::::::::::\n";
    std::cout << "\t   Code    Flight   Owner       Seat     Luggage(hold)         \n"
              << "\t   ------  -------  --------   -----     -------------";
    for(int i = 0; i < t.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << t[i].getPointer()->getID() << "  "
                  << t[i].getPointer()->getFlightId() << "  "
                  << t[i].getPointer()->getOwner()->getName() << "  "
                  << t[i].getPointer()->getSeat()->getId() << "  "
                  << "[";
        if (t[i].getPointer()->getLuggage().empty()) std::cout << " ]";
        else std::cout << "X]";
        /*
        << std::setw(52-t[i].getPointer()->getName().size())
        << std::setfill(' ') << t[i].getPointer()->getStaff().size();*/
    }
}


void Menu::header() {
    std::cin.clear(); std::cin.ignore(INT32_MAX, '\n');
    system(CLEAR);
    //std::cout << "[" << user->getUser() << "]\t\t\t";
    sysTime->print();
}

void Menu::print(std::vector<StaffPointer> v) {
    system(CLEAR);
    if (v.empty()) {
        std::cout << "\n\tNo workers assigned to this airport\n";
        system("pause");
        return;
    }
    for (unsigned i{}; i < v.size(); i++){
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << v[i].getPointer()->getId() << ", " << v[i].getPointer()->getName() << "(" << v[i].getPointer()->getPhone() << ")";
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
    char c;
    std::cout << "\n\tWhich function in the company you to attribute this new worker?"
              << "\n\t\t[1] Airport Manager"
              << "\n\t\t[2] Boarding Staff"
              << "\n\t\t[3] Service Staff"
              << "\n\n\t\t[0] Cancel\n>";
    while (true) {
        std::cin >> c;
        switch (c) {
            case '1':{
                Company *man = new Company(staff->getId(), staff->getId(), 'M');
                man->setStaff(staff);
                data->addCompany(man);
                return;}
            case '2':{
                Company *board = new Company(staff->getId(), staff->getId(), 'B', airport);
                board->setStaff(staff);
                data->addCompany(board);
                return;}
            case '3':{
                Company*serv = new Company(staff->getId(), staff->getId(), 'S', airport);
                serv->setStaff(staff);
                data->addCompany(serv);
                return;}
            case '0':
                std::cout << "\nAddition cancelled";
                system("pause");
                return;
            default:
                std::cout << "Invalid Option\n"; std::cin.ignore(INT32_MAX, 'n');
                break;
        }
    }
}

StaffPointer Menu::selectStaff(std::vector<StaffPointer> v) {
    while(true){
        print(v);
        string a;
        std::cout <<"\n........................................................\n\tEnter staff row (0 to cancel): ";
        while (true) {
            std::cin >> a;
            if (a == "0") return StaffPointer(nullptr);
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

FlightPointer Menu::selectFlight(){
    std::vector<FlightPointer> flights = selectAirport().getFlightPointers();
    while(true) {
        system(CLEAR);
        if (flights.empty()) {
            std::cout << "\n\tNo flights scheduled";
            return FlightPointer(nullptr);
        }
        print(flights);
        char c;
        //TODO std::cout << "[" << user->getUser() << " - Airports]\t\t\t";
        //TODO sysTime->print();
        std::cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t[1] Select Flight"
                  << "\n\t[2] Order By\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1': {
                std::cout << "Enter flight row: ";
                std::string in;
                //readInput(in);
                std::cin.clear(); std::cin.ignore(INT32_MAX, '\n');
                std::cin >> in;
                int i = stoi(in);
                if (i < 1 | i > flights.size()) break;
                return flights[i-1];
            }
            case '2': reOrderFlights(flights); break;
            case '0': return FlightPointer(nullptr);
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

Terminal* CompanyMenu::selectTerminal(Airport *airport){
    Terminal* terminal = new Terminal;
    vector<Terminal*> temp = airport->getTerminals();
    std::cout << "\n\tCurrent active terminals:";
    if (airport->getTerminals().empty()) {
        std::cout << "\n\t\tNo active terminals";
    }
    std::sort(temp.begin(), temp.end());
    for (unsigned i{}; i <temp.size(); i++) {
        std::cout << "\n\t[" << std::setw(2) << std::setfill(' ') << i+1 << "] "
                  << "\t" << temp[i]->getTerminalNumber() << " - ";
        if (temp[i]->getOccupied()) std::cout << temp[i]->getPlane()->getPlate();
        else std::cout << "Free";
    }
    std::cout << "\n---------------------------------";
    int i;
    std::cout << "\nWhich terminal option you want to select?(0 to go back)\n>";
    std::cin >> i;
    if (i == 0) {
        std::cout << "Selection cancelled"; return nullptr;
    }
    else if (i > 0 && i <= temp.size()){
        terminal = temp[i-1];
        system("pause");
    }
    else {
        std::cout << "Invalid option. Returning to previous menu.";
        system("pause");
        return nullptr;
    }
    return terminal;
}

TransportPointer Menu::selectTransportPointer(Airport *airport) {
    //TODO
    /*if (this->user->getType() == 'a') */
    //else airport = this->airport;
    header();
    vector<TransportPointer> temp = airport->getTransportPointer();
    print(temp);
    std::cout << "\n---------------------------------";
    int i;
    std::cout << "\nWhich transport option you want to select?(0 to go back)\n>";
    std::cin >> i;
    if (i == 0) {
        std::cout << "Selection cancelled"; return TransportPointer(nullptr);
    }
    else if (i > 0 && i <= temp.size()){
        system("pause");
        return temp[i-1];
    }
    else {
        std::cout << "Invalid option. Returning to previous menu.";
        system("pause");
        return TransportPointer(nullptr);
    }
}

PlanePointer CompanyMenu::selectPlane(Airport *airport){
    PlanePointer pptr = PlanePointer(nullptr);
    vector<PlanePointer> p;
    vector<Plane*> temp;
    for (auto it : airport->getTerminals()){
        if (it->getOccupied()) temp.push_back(it->getPlane());
    }
    print(data->getPlanes());
    std::cout << "\n---------------------------------";
    int i;
    std::cout << "\nWhich transport option you want to select?(0 to go back)\n>";
    std::cin >> i;
    if (i == 0) {
        std::cout << "Selection cancelled"; return pptr;
    }
    else if (i > 0 && i <= temp.size()){
        system("pause");
        pptr = PlanePointer(temp[i-1]);
        return pptr;
    }
    else {
        std::cout << "Invalid option. Returning to previous menu.";
        system("pause");
        return pptr;
    }
}

PlanePointer CompanyMenu::selectPlane(){
    PlanePointer pptr = PlanePointer(nullptr);
    print(data->getPlanes());
    std::cout << "\n---------------------------------";
    int i;
    std::cout << "\nWhich transport option you want to select?(0 to go back)\n>";
    std::cin >> i;
    if (i == 0) {
        std::cout << "Selection cancelled"; return pptr;
    }
    else if (i > 0 && i <= data->getPlanes().size()){
        system("pause");
        pptr = PlanePointer(data->getPlanes()[i-1]);
        return pptr;
    }
    else {
        std::cout << "Invalid option. Returning to previous menu.";
        system("pause");
        return pptr;
    }
}

void Menu::createPlane(Airbus *plane) {
    header();
    char a;
    string f;
    std::queue<std::string> first;
    std::cin.ignore(INT32_MAX, '\n');
    std::cout << "\nCreating Airbus";
    std::cout << "\n\tInput first class rows letter (up until " << (char)(96+26) << ") --> ";
    std::getline(std::cin, f);
    for (auto i : f){
        if (i < (char)(96+26)) {
            std::string s; s = toupper(i); first.push(s);
        }
    }
    plane = new Airbus(first);
    Airport *airport = selectAirport().getPointer();
    for (auto it : airport->getTerminals()){
        if (!it->getOccupied()) {
            it->setPlane(plane);
            data->addPlane(plane);
            return;
        }
    }
    std::cout << "\n\n\tNew plane addition cancelled"; system("pause");
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
    *plane = Other(rows, seatPerRow, first);
    plane ->setFClassPrice(fClassPrice);
    plane ->setEClassPrice(eClassPrice);
    data->addPlane(plane);
}

void Menu::reOrderAirports(std::vector<AirportPointer> &v) {
    return;
}

void Menu::reOrderFlights(std::vector<FlightPointer> &f) {
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
                  << "\n\t[3] Check Terminals"
                  << "\n\t[4] Check Transports"
                  << "\n\t[5] Check Flights"
                  << "\n\t[6] Check Airport"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': createAirport(); break;
            case '2': deleteAirport(); break;
            case '3': checkTerminal(); break;
            case '4': checkTransport(); break;
            case '5': checkFlights();break;
            case '6': checkAirport(); break;
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

void CompanyMenu::checkTerminal() {
    header();
    char c;
    std::cout << "Airport Terminal Management Menu\n";
    while(true) {
        std::cout << "[AIRPORT]\n"
                  << "\n\t[1] Add Terminal"
                  << "\n\t[2] Delete Terminal"
                  << "\n\t[3] Edit Terminal"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': addTerminal(); break;
            case '2': delTerminal(); break;
            case '3': editTerminal(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void CompanyMenu::addTerminal() {
    Airport *airport = new Airport;
    //TODO
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    std::cout << "\n\tCurrent active terminals:";
    if (airport->getTerminals().empty()) {
        std::cout << "\n\t\tNo active terminals";
    }
    for (auto it: airport->getTerminals()) {
        std::cout << "\n\t\t[" << it->getTerminalNumber() << "] - ";
        if (it->getOccupied() == true) std::cout << it->getPlane()->getPlate();
        else std::cout << "Free";
    }
    std::cout << "\n";
    system("pause");
    std::cout << "\n\tWhich terminal number you want to activate?\n>";
    int a;
    char b;
    std::cin >> a;
    std::cout << "\n\tYou are going to activate terminal " << a << " at ("
              << airport->getidCode() << ")" << airport->getName() << ". \nIs this correct?(y/n)\n>";
    while (true){
        std::cin >> b;
        switch (tolower(b)) {
            case 'n': {
                std::cout << "\n\tOperation cancelled";
                system("pause");
                return;
            }
            case 'y': {
                airport->activateTerminal(std::to_string(a));
                system("pause");
                return;
            }
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}


void CompanyMenu::delTerminal() {
    Airport *airport = new Airport;
    //TODO
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    Terminal *terminal = new Terminal;
    std::cout << "\n";
    system("pause");
    std::cout << "\n\tWARNING\n\tSystem doesn't allow to delete occupied terminals.\n\tRemove plane first if needed.\n";
    terminal = selectTerminal(airport);
    if (terminal == nullptr) return;
    if (airport->delTerminal(terminal->getId())){
        std::cout << "\n\tDeletion complete";
        system("pause");
        return;
    }
    else std::cout << "\n\tUnable to complete deletion\n";
    system("pause");
    return;
}

void CompanyMenu::editTerminal(){
    Airport *airport = new Airport;
    //TODO
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    Terminal *terminal = new Terminal;
    std::cout << "\n";
    terminal = selectTerminal(airport);
    if (terminal == nullptr) return;
    char a;
    std::cout << "\n\t\t[1] Change terminal"
                 "\n\t\t[2] Remove plane"
                 "\n\t\t[3] Assign plane\n>";
    std::cin >> a;
    switch (a){
        case '1':{
            terminal->setUnocccupied();
            break;
        }
        case '2':{
            int id;
            std::cout << "\n\tInsert new terminal number >"; std::cin >> id;
            terminal->setId(to_string(id), airport->getidCode());
        }
        case '3': {
            PlanePointer pptr = selectPlane();
            for (auto i: data->getAirports()) {
                for (auto j: i.getPointer()->getTerminals()) {
                    if (j->getOccupied() && j->getPlane()->getPlate() == pptr.getPointer()->getPlate())
                        j->setUnocccupied();
                }
            }
            Plane *plane = pptr.getPointer();
            terminal->setPlane(plane);
            break;
        }
        default: std::cout << "Invalid Option\n"; system("pause");
    }
    return;
}

void CompanyMenu::checkTransport() {
    header();
    char c;
    std::cout << "Airport Transport Management Menu\n";
    while(true) {
        std::cout << "[AIRPORT]\n"
                  << "\n\t[1] Add Transport"
                  << "\n\t[2] Delete Transport"
                  << "\n\t[3] Edit Transport"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': addTransport(); break;
            case '2': delTransport(); break;
            case '3': editTransport(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void CompanyMenu::addTransport() {
    Airport *airport = new Airport;
    //TODO
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    header();
    char a, b;
    int d, h, m;
    Transport *transport;
    Time *time;
    while (true){
        std::cout << "\n\tWhich transport you want to add?\n\t\t[m] Metro\n\t\t[b] Bus\n\t\t[t] Train\n>";
        std::cin >> a;
        switch (a){
            case 'm': {
                std::cout << "\n\tInsert distance (meters)>"; std::cin >> d;
                std::cout << "\n\tInsert time:\n\thour>"; std::cin >> h;
                std::cout << "\n\tminute>"; std::cin >> m;
                time = new Time(h, m, 0);
                std::cout << "\n\n\tNew Metro(" << d << ") at "; time->printTime(); std::cout << ".\n\tIs this correct?(y/n)\n>";
                std::cin >> b;
                switch (b){
                    case 'y': {
                        transport = new Transport(a); transport->setDistance(d); transport->addTime(time);
                        TransportPointer nptr = TransportPointer(transport);
                        airport->setTransport(nptr);
                        break;
                    }
                    case 'n': std::cout << "\n\tNew transport insertion cancelled"; break;
                }
                return;
            }
            case 'b': {
                std::cout << "\n\tInsert distance (meters)>"; std::cin >> d;
                std::cout << "\n\tInsert time:\n\thour>"; std::cin >> h;
                std::cout << "\n\tminute>"; std::cin >> m;
                time = new Time(h, m, 0);
                std::cout << "\n\n\tNew Bus(" << d << ") at "; time->printTime(); std::cout << ".\n\tIs this correct?(y/n)\n>";
                std::cin >> b;
                switch (b){
                    case 'y': {
                        transport = new Transport(a);
                        transport->setDistance(d);
                        transport->addTime(time);
                        TransportPointer nptr = TransportPointer(transport);
                        airport->setTransport(nptr);
                        break;
                    }
                    case 'n': std::cout << "\n\tNew transport insertion cancelled"; break;
                }
                return;
            }
            case 't': {
                std::cout << "\n\tInsert distance (meters)>"; std::cin >> d;
                std::cout << "\n\tInsert time:\n\thour>"; std::cin >> h;
                std::cout << "\n\tminute>"; std::cin >> m;
                time = new Time(h, m, 0);
                std::cout << "\n\n\tNew Train(" << d << ") at "; time->printTime(); std::cout << ".\n\tIs this correct?(y/n)\n>";
                std::cin >> b;
                switch (b){
                    case'y': {
                        transport = new Transport(a);
                        transport->setDistance(d);
                        transport->addTime(time);
                        TransportPointer nptr = TransportPointer(transport);
                        airport->setTransport(nptr);
                        break;
                    }
                    case 'n': std::cout << "\n\tNew transport insertion cancelled"; break;
                    default: std::cout << "Incorrect output"; cin.ignore(INT32_MAX, '\n');
                }
                return;
            }
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void CompanyMenu::delTransport(){
    Airport *airport = new Airport;
    //TODO
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    header();
    TransportPointer nptr = selectTransportPointer(airport);
    airport->delTransport(nptr);
    std::cout << "\n\tTransport successfully deleted";
    return;
}

void CompanyMenu::editTransport(){
    Airport *airport = new Airport;
    //TODO
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    char b;
    int h, m;
    TransportPointer nptr = selectTransportPointer(airport);
    if (nptr.getPointer() == nullptr) return;
    std::cout << "\n\tWhat is the new schedule?\n\tHour>"; std::cin >> h;
    std::cout << "\n\tMinutes>"; std::cin >> m;
    std::cout << "\n\n\tIs the time " << h << ":" << m << " correct?(y/n)\n>"; std::cin >> b;
    switch (b){
        case 'y':{
            Time *time = new Time (h, m, 0);
            nptr.getPointer()->addTime(time);
            break;
        }
        case 'n': std::cout << "\n\tNew transport edition cancelled"; break;
        default: std::cout << "Incorrect output"; cin.ignore(INT32_MAX, '\n');
    }
    return;
}

void CompanyMenu::checkAirport() {
    Airport *airport = new Airport;
    //TODO
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    header();
    char a;
    if (airport == nullptr) return;
    char c;
    while(true) {
        std::cout << "[AIRPORT]\n"
                  << "\n\t[1] Create Service"
                  << "\n\t[2] Check Service Tasks"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': createService(airport, nullptr); break;
            case '2': checkTasks(airport); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
    return;
}

void CompanyMenu::createService(Airport *airport, Plane *plane) {
    system(CLEAR);
    char s, t, a;
    int d, m, y;
    vector<StaffPointer> staffptr;
    for (auto it : airport->getStaff()){
        staffptr.push_back(StaffPointer(it));
    }
    Time *time = new Time;
    time->now();
    while (true){
        std::cout << "\n\tMenu for creating a service in airport"
                  << "\n\n\tType of service: Cleaning(c) or Maintenance(m)?\n>"; std::cin >> s;
        if (s!='c' && s != 'm'){
            std::cout << "Invalid Option. Cancelling creation\n";
            system("pause");
            return;
        }
        std::cout << "\n\n\tSelect responsible:";
        StaffPointer sptr = selectStaff(staffptr);
        if (plane == nullptr) plane = selectPlane(airport).getPointer();
        std::cout << "\n\n\tCreate ";
        if (s == 'c') std::cout << "cleaning";
        else if (s == 'm') std::cout << "maintenance";
        std::cout << " service scheduled on ";  time->printDate();
        std::cout << " for plane " << plane->getPlate() << " by " << sptr.getPointer()->getName() << "?(y/n)"; std::cin >> a;
        if (s == 'c' && a == 'y'){
            Cleaning *cle = new Cleaning(plane, time, sptr.getPointer());
            airport->addService(cle);
            //data->addService(cle);
            std::cout << "\n\tNew ServiceTicket created"; system("pause");
            return;
        }
        else if (s == 'm' && a == 'y'){
            Maintenance *mai = new Maintenance(plane, time, sptr.getPointer());
            airport->addService(mai);
            //data->addService(mai);
            std::cout << "\n\tNew ServiceTicket created"; system("pause");
            return;
        }
        else if (a == 'n'){
            std::cout << "\n\tServiceTicket creation cancelled";
            return;
        }

    }
}

void CompanyMenu::checkTasks(Airport *airport) {
    char a;
    while (true){
        std::cout << "\n\t=================================================="
                  << "\n\t(" << airport->getidCode() << ") " << airport->getName() << " - " << airport->getCity() << ", " << airport->getCountry()
                  << "\n\t==================================================";
        airport->printAirport();
        airport->printService();
        vector<StaffPointer> staffptr;

        for (auto it : airport->getStaff()){
            staffptr.push_back(StaffPointer(it));
        }
        if (airport->nextService() != NULL && airport->nextService()->getResponsible()==NULL){
            std::cout << "\n\tNo responsible set. Do you want attribute one?(y/n)\n>"; std::cin >> a;
            switch (a){
                case 'y': {
                    StaffPointer sptr;
                    sptr = selectStaff(staffptr);
                    airport->nextService()->setResponsible(sptr.getPointer());
                    break;
                }
                case 'n': std::cout << "\n\t While there is no responsible service can't procede"; return;
                default: std::cout << "Invalid Option\n"; system("pause");
            }
        }
        string id = airport->nextService()->getResponsible()->getId();
        Company *user = data->findCompany(id);
        for (unsigned i{}; i < airport->nextService()->getTasksCompleted().size(); i++){
            std::cout << "\n\t\t" << airport->nextService()->getTasksCompleted()[i] << "\t[X]";
        }
        for (unsigned i{}; i < airport->nextService()->getTasksLeft().size(); i++){
            std::cout << "\n\t\t" << airport->nextService()->getTasksLeft()[i] << "\tDone?(y/n)";
            std::cin >> a;
            switch (a){
                case 'y': {
                    if (airport->nextService()->getTasksLeft()[i] == "Bathroom") airport->nextService()->checkWc();
                    else if (airport->nextService()->getTasksLeft()[i] == "Passenger seats") airport->nextService()->checkSeats();
                    else if (airport->nextService()->getTasksLeft()[i] == "Plane floor") airport->nextService()->checkFloor();
                    else if (airport->nextService()->getTasksLeft()[i] == "Fligh Cabin") airport->nextService()->checkFlightDeck();
                    else if (airport->nextService()->getTasksLeft()[i] == "Emergency Equipment") airport->nextService()->checkEmergency();
                    else if (airport->nextService()->getTasksLeft()[i] == "Console and Controls") airport->nextService()->checkControls();
                    else if (airport->nextService()->getTasksLeft()[i] == "Landing Gear") airport->nextService()->checkLandGear();
                    else if (airport->nextService()->getTasksLeft()[i] == "Engine") airport->nextService()->checkEngine();
                    std::cout << "\t\t[X]";
                    i--;
                    break;
                };
                case 'n': std::cout << "\t[ ]\n"; break;
                default: std::cout << "Invalid Option\n"; system("pause");
            }
        }
        if (airport->nextService()->verification()) {
            Time *time = new Time; time->now();
            user->addCompleteService(airport->nextService());
            airport->nextService()->setComplete(time);
            return;
        }
        system("pause");
        return;
    }
}

void CompanyMenu::checkFlights() {
    header();
    char a;
    while (true){
        Flight *flight = selectFlight().getPointer();
        system("pause");
        return;
    }
}

void CompanyMenu::workers() {
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

void CompanyMenu::addWorker(){
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    system(CLEAR);
    if (airport == nullptr) return;
    newWorker(airport);
    system("pause");
    return;
}
void CompanyMenu::delWorker(){
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    char a;
    system(CLEAR);
    vector<StaffPointer> staffptr;
    for (auto it : airport->getStaff()){
        staffptr.push_back(StaffPointer(it));
    }
    StaffPointer sptr = selectStaff(staffptr);
    if (sptr.getPointer() == nullptr) return;
    std::cout << "\n\tConfirm deletion of " << sptr.getPointer()->getName() << " currently at " << airport->getName()<< "?(y/n)\n";
    while(true){
        std::cout << ">"; std::cin >> a;
        switch (a){
            case 'y' : {
                data->delCompany(data->findCompany(sptr.getPointer()->getId()));
                airport->delStaff(sptr.getPointer());
                std::cout << "\n\n\tDeletion complete.";
                system("pause"); return;
            }
            case 'n' : std::cout << "\n\n\tElimination of " << sptr.getPointer()->getName() << " from " << airport->getName() << "cancelled."; return;
            default: std::cout << "Invalid Option\n"; std::cin.ignore(INT32_MAX, '\n'); system("pause");
        }
    }
}

void CompanyMenu::changeWorker() {
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    system(CLEAR);
    vector<StaffPointer> staffptr;
    for (auto it : airport->getStaff()){
        staffptr.push_back(StaffPointer(it));
    }
    StaffPointer sptr = selectStaff(staffptr);
    if (sptr.getPointer() == nullptr) return;
    while (true){
        char a;
        string name;
        int phone;
        std::cout << "\n\tSet a new name?(y/n)\n>"; std::cin >> a;
        std::cin.ignore(INT32_MAX, '\n');
        switch (a){
            case 'y' : std::cout << "\n\n\tNew name>"; getline(std::cin, name); sptr.getPointer()->setName(name); break;
            case 'n' : system("pause"); break;
            default: std::cout << "Invalid Option\n"; std::cin.ignore(INT32_MAX, '\n'); system("pause");
        }
        std::cout << "\n\tSet a new phone?(y/n)\n>"; std::cin >> a;
        std::cin.ignore(INT32_MAX, '\n');
        switch (a){
            case 'y' : std::cout << "\n\n\tNew phone>"; std::cin >> phone; sptr.getPointer()->setPhone(phone); break;
            case 'n' : system("pause"); break;
            default: std::cout << "Invalid Option\n"; std::cin.ignore(INT32_MAX, '\n'); system("pause");
        }
    }
    return;
}

void CompanyMenu::moveWorker() {
    if (this->user->getType() != 'A') {
        airport = this->user->getAirport();
        std::cout << "Permission denied. Use administrator previlege to access this menu";
        system("pause");
        return;
    }
    char a;
    system(CLEAR);
    std::cout << "\n\tSelect airport from which you want to move worker:";
    Airport *airportOrigin = selectAirport().getPointer();
    vector<StaffPointer> staffptr;
    for (auto it : airportOrigin->getStaff()){
        staffptr.push_back(StaffPointer(it));
    }
    StaffPointer sptr = selectStaff(staffptr);
    Airport *airportDest = selectAirport().getPointer();
    std::cout << "\n\tConfirm that you want to change " << sptr.getPointer()->getName() << " from "
              << airportOrigin->getName() << " to " << airportDest->getName() << "?(y/n)"
              << "\n\t\t IMPORTANT: all pending services from " << sptr.getPointer()->getName()
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
                airportDest->addStaff(sptr.getPointer());
                airportOrigin->delStaff(sptr.getPointer());
                data->findCompany(sptr.getPointer()->getId())->setAirport(airportDest);
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

void CompanyMenu::checkService(){
    if (this->user->getType() == 'A') airport = selectAirport().getPointer();
    else airport = this->user->getAirport();
    system(CLEAR);
    vector<ServiceTicket*> temp;
    print(airport->getServices());
    vector<StaffPointer> staffptr;
    for (auto it : airport->getStaff()){
        staffptr.push_back(StaffPointer(it));
    }
    StaffPointer sptr = selectStaff(staffptr);
    for (auto it : airport->getServices()){
        if (it->getResponsible()!= nullptr && it->getResponsible()->getId() == sptr.getPointer()->getId()) temp.push_back(it);
    }
    if (!temp.empty()) print(temp);
    else std::cout << "\n\tNo services atributted to this worker\n";
    system("pause");
    return;
}

void AdminMenu::travel() {
    header();
    char c;
    std::cout << "Plane Management Menu\n";
    while(true) {
        std::cout << "[TRAVEL]\n"
                  << "\n\t[1] New Travel"
                  << "\n\t[2] Delete Travel"
                  << "\n\t[3] Edit Travel"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': newTravel(); break;
            case '2': deleteTravel(); break;
            case '3': editTravel(); break;
            case '4': mapPlane(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void AdminMenu::newTravel(){
    while (true){
        int h, m, l;
        std::cout << "\n\tSelect airport origin:";
        Airport *airportOri = selectAirport().getPointer();
        std::cout << "\n\n\tSelect plane to operate flight:";
        Plane *plane = selectPlane().getPointer();
        std::cout << "\n\n\tSelect airport destination:";
        Airport *airportDest = selectAirport().getPointer();
        std::cout << "\n\n\tDetermine departure time:\n>";
        std::cin >> h;
        std::cout << "\n>";
        std::cin >> m;
        Time *timeOri = new Time(h, m, 0);
        std::cout << "\n\n\tDetermine flight lenth in minutes:\n>";
        std::cin >> l;
        h = l / 60;m = l & 60;
        Time *timeDest = new Time((timeOri->getHour()+h)%24, (timeOri->getMinute()+m)%60, 0);
        TimePlace *ori = new TimePlace(airportOri, timeOri);
        TimePlace *dest = new TimePlace(airportDest, timeDest);
        Flight *flight = new Flight(ori, dest, plane);
        data->addFlight(flight);
        return;
    }
}

void AdminMenu::deleteTravel(){

}

void AdminMenu::editTravel() {

}

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
    while (true) {
        char c;
        PlanePointer plane = selectPlane();
        if (plane.getPointer() == nullptr) return;
        std::cout << "\n\tAre you sure you want to delete this plane?(y/n)\n>";
        std::cin >> c;
        switch (c) {
            case 'y': {
                data->delPlane(plane.getPointer());
                std::cout << "\n\tAirplane successfully removed from database";
                system("pause");
                return;
            }
            case 'n': {
                std::cout << "\n\tOperation cancelled";
                system("pause");
                return;
            }
            default: std::cout << "Invalid Option\n"; system("pause");
            }
    }
}

void AdminMenu::checkPlane() {
    while (true) {
        char c;
        PlanePointer plane = selectPlane();
        if (plane.getPointer() == nullptr) return;
        std::cout << "\n\tInformation regarding plane with plate " << plane.getPointer()->getPlate();
        std::cout << "\n\tCapacity  Rows   Seats/Row\n\t---------------------------";
        std::cout << "\n\n\t"<< plane.getPointer()->getCapacity() << "        "
                  << plane.getPointer()->getRows() << "        "
                  << plane.getPointer()->getColumns();
        std::cout << "\n\n\tThis plane has ";
        int count{};
        vector<AirportPointer> allair = data->getAirports();
        vector<ServiceTicket*> temp;
        for (auto it : allair){
            for (auto itr : it.getPointer()->getServices()){
                temp.push_back(itr);
            }
        }
        count = temp.size();
        std::cout << count << " service(s) scheduled\n\n\tDo you want to create a new one?(y/n)>";
        std::cin >> c;
        switch (c) {
            case 'y': {
                Airport *airport;
                if (plane.getPointer()->isGrounded()){
                    vector<AirportPointer> air = data->getAirports();
                    for (auto it : air){
                        vector<Terminal*> ter = it.getPointer()->getTerminals();
                        for (auto itter : ter){
                            if (itter->getPlane()->getPlate()==plane.getPointer()->getPlate()){
                                airport = it.getPointer();
                            }
                        }
                    }
                    createService(airport, plane.getPointer());
                    return;
                }
                else std::cout << "\n\n\tReturn plane to the ground first"; system("pause"); return;
            }
            case 'n': {
                system("pause");
                return;
            }
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void AdminMenu::mapPlane(){
    header();
    Plane *plane = selectPlane().getPointer();
}

/**---Manager Menu---*/
void ManagerMenu::mainScreen() {
    header();
    char c;
    //Shows real ADMIN menu after user has proven his identity
    while(true) {
        std::cout << "[AIRPORT MANAGER]\n"
                  << "\n\t[1] Terminal Management"
                  << "\n\t[2] Worker Management"
                  << "\n\t[3] Service Management"
                  << "\n\t[4] Transport Management"
                  << "\n\n\t[0] Log Out\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': checkTerminal(); break;
            case '2': workers(); break;
            case '3': checkAirport(); break;
            case '4': checkTransport(); break;
            case '0': logOut(); throw LogOut();
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}


/**---BoardingMenu---*/
void BoardingMenu::mainScreen(){
    header();
    char c;
    //Shows real ADMIN menu after user has proven his identity
    while(true) {
        std::cout << "[BOARDING SERVICE]\n"
                  << "\n\t[1] All Flights"
                  << "\n\t[2] Out Flights"
                  << "\n\t[3] In Flights"
                  << "\n\t[4] Today's Flights"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': allFlight(); break;
            case '2': outFlight(); break;
            case '3': inFlight(); break;
            case '4': todayFlight(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void BoardingMenu::allFlight() {
    header();
    Time *time = new Time; time->now();
    vector<FlightPointer> allflight;
    for (auto i : data->getAirports()){
        if (i.getPointer() == this->airport){
            for (auto j : i.getFlightPointers()){
                if (j.getPointer()->getOrigin()->time >= time) allflight.push_back(j);
            }
        }
    }
    FlightPointer flight = selectFlight(allflight);
    if (flight.getPointer() == nullptr) return;
    checkMenu(flight);
}

void BoardingMenu::inFlight(){
    header();
    Time *time = new Time; time->now();
    vector<FlightPointer> inflight;
    for (auto i : data->getAirports()){
        if (i.getPointer() == this->airport){
            for (auto j : i.getFlightPointers()){
                if (j.getPointer()->getDestination()->airport==this->airport && j.getPointer()->getDestination()->time >= time) inflight.push_back(j);
            }
        }
    }
    FlightPointer flight = selectFlight(inflight);
    if (flight.getPointer() == nullptr) return;
    checkMenu(flight);
}

void BoardingMenu::outFlight(){
    header();
    Time *time = new Time; time->now();
    vector<FlightPointer> outflight;
    for (auto i : data->getAirports()){
        if (i.getPointer() == this->airport){
            for (auto j : i.getFlightPointers()){
                if (j.getPointer()->getOrigin()->airport==this->airport && j.getPointer()->getOrigin()->time >= time) outflight.push_back(j);
            }
        }
    }
    FlightPointer flight = selectFlight(outflight);
    if (flight.getPointer() == nullptr) return;
    checkMenu(flight);
}

void BoardingMenu::todayFlight() {
    header();
    Time *time = new Time; time->now();
    vector<FlightPointer> todayflight;
    for (auto i : data->getAirports()){
        if (i.getPointer() == this->airport){
            for (auto j : i.getFlightPointers()){
                if ((j.getPointer()->getOrigin()->airport==this->airport && j.getPointer()->getOrigin()->time == time)
                    | (j.getPointer()->getDestination()->airport==this->airport && j.getPointer()->getDestination()->time == time)) {
                    todayflight.push_back(j);
                }
            }
        }
    }
    FlightPointer flight = selectFlight(todayflight);
    if (flight.getPointer() == nullptr) return;
    checkMenu(flight);
}

void BoardingMenu::checkMenu(FlightPointer flight) {
    char c;
    while(true) {
        std::cout << "[" << flight.getPointer()->getId() << "]\n"
                  << "\n\t[1] Check Ticket"
                  << "\n\t[2] Check Luggage"
                  << "\n\n\t[0] Back\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': checkTicket(flight); break;
            case '2': checkLuggage(flight); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

void BoardingMenu::checkTicket(const FlightPointer& flight){
    header();
    while (true){
        TicketPointer ticket = selectTicket(flight.getTicketsPointer());
    }
}

void BoardingMenu::checkLuggage(FlightPointer flight) {
    header();
    char c;
    while(true) {

    }
}


FlightPointer BoardingMenu::selectFlight(std::vector<FlightPointer> flights){
    while(true) {
        system(CLEAR);
        if (flights.empty()) {
            std::cout << "\n\t====== No flights scheduled ======\n\n";
            system("pause"); system(CLEAR);
            return FlightPointer(nullptr);
        }
        print(flights);
        char c;
        //TODO std::cout << "[" << user->getUser() << " - Airports]\t\t\t";
        //TODO sysTime->print();
        std::cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t[1] Select Flight"
                  << "\n\t[2] Order By\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1': {
                std::cout << "Enter flight row: ";
                std::string in;
                readInput(in);
                int i = stoi(in);
                if (i < 1 | i > flights.size()) break;
                return flights[i-1];
            }
            case '2': reOrderFlights(flights); break;
            case '0': return FlightPointer(nullptr);
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}

TicketPointer BoardingMenu::selectTicket(std::vector<TicketPointer> t) {
    while (true) {
        header();
        if (t.empty()) {
            std::cout << "\n\t====== No tickets to check ======\n\n";
            system("pause");
            return TicketPointer(nullptr);
        }
        print(t);
        char c;
        std::cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\t[1] Select Ticket"
                  << "\n\t[2] Order By\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        readInput(c);
        switch (c) {
            case '1': {
                std::cout << "Enter ticket row: ";
                std::string in;
                readInput(in);
                int i = stoi(in);
                if (i < 1 | i > t.size()) break;
                return t[i-1];
            }
            case '2': /*reOrderTicket(t);*/ break;
            case '0': return TicketPointer(nullptr);
            default: std::cout << "Invalid Option\n";
        }
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        getchar();
    }
}


/**---Service Menu---*/
void ServiceMenu::mainScreen() {
    header();
    char c;
    while(true) {
        std::cout << "[SERVICE AIRPORT]\n"
                  << "\n\t[1] Create Service"
                  << "\n\t[2] Check Service"
                  << "\n\n\t[0] Log Out\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': createService(this->user->getAirport(), nullptr); break;
            case '2': checkTasks(this->user->getAirport()); break;
            case '0': logOut(); throw LogOut();
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
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