//Created by Pedro Barbeira (up201303693)
#include "menu.h"

/**---Parent Menu---*/
void Menu::mainScreen() {
    std::cout << "blabla\n";
}

void Menu::print(std::vector<AirportPointer> v) const{
    for(int i = 0; i < v.size(); i++){
        std::cout << '[' << std::setw(2) << std::setfill(' ') << i+1 << ']'
                  << v[i] << '\n';
    }
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
        else
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

void ClientMenu::reOrderAirports(std::vector<AirportPointer>& v){
    AirportSorter sort;

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
        print(airports);
        system(CLEAR);
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
    std::cout << "we are @ Admin\n"
              << "Press enter to continue . . .";
    char c = getchar();
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