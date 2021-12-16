/**Will be deleted soon*/

//Created by Pedro Barbeira (up201303693)
#include "company.h"

/**
 * Admin Menu Interface
 */
void admin(MikeG *mg) {
    char c;
    //Shows real ADMIN menu after user has proven his identity
    while(true) {
        system(CLEAR);
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Airport Management"
                  << "\n    [2] Worker Management"
                  << "\n    [3] Travel Management"
                  << "\n    [0] Log Out\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': airport(); break;
            case '2': worker(); break;
            case '3': travel(mg); break;
            case '4': plane(); break;
            case 'q':
            case '0': throw LogOut();
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

/**
 * Airport Management Menu
 */

void airport(){
    char c;
    std::cout << "Airport Management Menu\n";
    while(true) {
        system(CLEAR);
        std::cout << "[AIRPORT]\n"
                  << "\n    [1] Add Airport"
                  << "\n    [2] Delete Airport"
                  << "\n    [3] Check Airport"
                  << "\n    [4] List of active Airport"
                  << "\n    [0] Back\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': createAirport(); break;
            case '2': deleteAirport(); break;
            case '3': checkAirport(); break;
            case '4': listAirport(); break;
            case 'q':
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}
////////// Airport menu functions

void createAirport() {
    Airport *airport = new Airport;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    system(CLEAR);
    string id, name, city, country;
    char a;
    std::cout << "\n    Airport creation menu"
              << "\n\n      Introduce Airport Location:"
              << "\n        Country > "; std::getline(std::cin, country);
    std::cout << "\n        City > "; std::getline(std::cin, city);
    std::cout << "\n        Name > "; std::getline(std::cin, name);
    std::cout << "\n        Identification code (3 letter word) > "; std::cin >> id;
    std::cout << "\n\n      Airport (" << id << ") " << name
              << "\n        at " << city << ", " << country
              << "\n    Is this information correct(y/n)?\n\n >"; std::cin >> a;
    if (tolower(a) == 'y') {
        airport->setId(id); airport->setCountry(country); airport->setCity(city); airport->setName(name);
    }
    else {
        std::cout << "\n\nOperation cancelled, returning to Airport management menu";
        system("pause");
    }
    return;
}

void deleteAirport(){
    string id, city, country;
    char a;
    Airport *airport = selectAirport();
    if (airport == nullptr){
        std::cout << "Canceled deletion operation. Returning to Airport Management menu.\n";
        system("pause");
        return;
    } else
        std::cout << "Temporary placeholder for working magic";
    //search airport in BST and remove it;
    return;
}


void checkAirport(){
    string id;
    Airport *temp = new Airport;
    system(CLEAR);
    std::cout << "Introduce airport code: "; std::cin >> id;
    // find airport by id
    std::cout << temp->getName()
              << "\n" << temp->getidCode() << ", " << temp->getCity() << ", " << temp->getCountry()
              << "\n    Occupied terminals: ";
    for (auto it : temp->getTerminals()){
        cout << it << " ";
    }
    cout << ";";
    std::cout << "\n    Pending services:";
    for (auto it : temp->getServices()){
        std::cout << "\n    Responsible: " << it->getResponsible()
                  << "\n    Operation type: "; if (it->getType() == 'c') std::cout << "Cleaning"; else std::cout << "Maintenance";
        std::cout << "\n    Schedule: " << it->getSchedule()->getYear() << "/" << it->getSchedule()->getMonth() << "/" << it->getSchedule()->getDay();
        std::cout << "\n    Operations left:"
                  << "\n    / ";
        for (auto inf : it->getTasksLeft()) cout << inf << "/ ";
        system("pause");
    }
    return;
}

void listAirport(){
    system(CLEAR);
    std::cout << "Here is the list of the active airports:";
    //iteration over the BST of the airports
}

/**
 * Worker Management Menu
 */
void worker(){
    char c;
    while(true) {
        system(CLEAR);
        std::cout << "[WORKER]\n"
                  << "\n    [1] Add Worker"
                  << "\n    [2] Delete Worker"
                  << "\n    [3] Check ServiceTicket"
                  << "\n    [0] Back\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': addWorker(); break;
            case '2': delWorker(); break;
            case '3': checkService(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}

/////////////////// Worker menu functions

void addWorker(){
    char c;
    string name;
    int phone;
    system(CLEAR);
    std::cout << "\n    Please Insert Worker Name: "; std::cin >> name;
    Staff *person = new Staff(name);
    std::cout << "\n    Please insert phone: "; std::cin >> phone;
    try{
        person->setPhone(phone);
        throw InvalidNumber();
    }catch (string n){
        n = "A valid phone number should have 9 digits starting at (9)********";
        std::cout << n;
    }
    system("pause");
    return;
}

void delWorker(){
    std::cout << "Menu option to remove worker form database";
    system("pause");
    return;
}

void checkService(){
    std::cout << "Menu option to list all services pending (total or by airport)";
    system("pause");
    return;
}

///////////////////////////////////////////////

/**
 * Travel Management Menu
 */
void travel(MikeG* mg){
    char c;
    while(true) {
        system(CLEAR);
        std::cout << "[TRAVEL]\n";
        std::cout << "\n    [1] Voyage"
                  << "\n    [2] Flight"
                  << "\n    [3] Plane"
                  << "\n    [0] Back\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': voyage(); break;
            case '2': flight(); break;
            case '3': plane(); break;
            case '0': return;
            case 'Q':
            case 'q': throw LogOut(); break;
            default: std::cout << "Invalid Option\n"; int c = getchar();
        }
    }
}

void voyage(){
    char c;
    while(true) {
        //Insert display of all voyages
        system(CLEAR);
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Create"
                  << "\n    [2] Change"
                  << "\n    [3] Delete"
                  << "\n    [0] Back\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': createVoyage(); break;
            case '2': changeVoyage(); break;
            case '3': deleteVoyage(); break;
            case '0': return;
            case 'Q':
            case 'q': throw LogOut(); break;
            default: std::cout << "Invalid Option\n";
        }
        int c = getchar();
    }
}

void createVoyage(){
    std::cout << "Create Voyage\n";
}
void changeVoyage(){
    std::cout << "Change Voyage\n";
}
void deleteVoyage(){
    std::cout << "Delete Voyage\n";
}

void flight(){
    char c;
    while(true) {
        //Insert display of all flights
        system(CLEAR);
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Create"
                  << "\n    [2] Change"
                  << "\n    [3] Delete"
                  << "\n    [0] Back\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': createFlight(); break;
            case '2': changeFlight(); break;
            case '3': deleteFlight(); break;
            case '0': return;
            case 'Q':
            case 'q': throw LogOut(); break;
            default: std::cout << "Invalid Option\n";
        }
        int c = getchar();
    }
}

void createFlight(){
    std::cout << "Create Flight\n";
}
void changeFlight(){
    std::cout << "Change Flight\n";
}
void deleteFlight(){
    std::cout << "Delete Flight\n";
}

void plane(){
    std::cout << "Plane Management Menu\n";
}

/**
 * Functions to navigate menus in workers optics
 */
void workers(){
    char c;
    while(true) {
        system(CLEAR);
        std::cout << "[WORKERS MENU]\n"
                  << "\nWelcome guest\n" // depending on time we can personalize welcome message
                  << "\n    [1] Retrieve Pending Services"
                  << "\n    [2] Create ServiceTicket Ticket"
                  << "\n    [3] Resolve ServiceTicket Ticket"
                  << "\n    [4] Retrieve Completed Services (registered users only)"
                  << "\n    [0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c){
            case '1': pendingServices(); break;
            case '2': createService(); break;
            case '3': resolveService(); break;
            case '4': historyService(); break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; c = getchar();
        }
    }
}

void pendingServices(){
    char c;
    Airport *airport = new Airport;
    std::cout << "Pending Services Menu\n"
              << "\n    [1] List all pending services"
              << "\n    [2] Select Airport"
              << "\n    [0] Back"
              << "\n    >"; std::cin >> c;
    switch (c){
        case '1': /*search in data all airports and respective next service*/ break;
        case '2': airport = selectAirport(); break;
        case '0': return;
        default: std::cout << "Invalid Option\n"; c = getchar();
    }
    if (c == '1'){
        std::cout << "Placeholder for working magic finding airport";
        system("pause");
        return;
    }
    else if (c == '2'){
        if (airport == nullptr){
            std::cout << "\n    Canceled Pending Services Search."
                      << "\n    Returning to Workers Menu.";
            system("pause");
            return;
        }
        printService(airport);
    }
    system("pause");
    return;
}



void createService(){


}

void resolveService(){

}

void historyService(){
    std::cout << "No credentials yet";
    system("pause");
    return;
}

Airport* selectAirport(){
    Airport *airport = new Airport;
    char a; string city, country, id;
    std::cout << "Which method do you prefer to find airport?"
              << "\n    [1] 3 letter code"
              << "\n    [2] City"
              << "\n    [3] Country"
              << "\n    [0] Back"; std::cin >> a;
    switch(a){
        case '1': cout << "\n\n    Introduce 3 letter code: "; std::cin >> id;
            //iterate over airport BST to find and erase idName
            break;
        case '2': cout << "\n\n    Introduce city: "; std::cin >> city;
            //iterate over airport BST to find and erase airport.getName() == city; ambiguous
            // more then one airport per city
            break;
        case '3': cout << "\n\n     Introduce country: "; std::cin >> country;
            //iterate over airport BST and find all airports in country and select which to delete
            break;
        case '0': return nullptr;/*return to previous menu*/
            // In this portion of the menu i have to find the possibilities of deletion and remove it from the BST
        default: std::cout << "Invalid Option\n";
            }
        return airport;
    }

//////////////Print functions

void printAirport(Airport *airport){
    std::cout << "\n\nInformation for (" << airport->getidCode() << ") " << airport->getName() << ":"
              << "\n    Located at " << airport->getCity() << ", " << airport->getCountry();
    if (airport->getTerminals().empty()) std::cout << "\n   Has no terminals attributted to MikeGAirlines";
    else if (!airport->getTerminals().empty()){
        bool o = false;
        for (auto i: airport->getTerminals()){
            if (i->getOccupied()==true){
                std::cout << "\n    with terminal " << i->getTerminalNumber() << "with plane " << i->getPlane();
                o = true;
            }
        }
        if (o == false) std::cout << "\n    with " << airport->getTerminals().size() << " unoccupied";
    }
}

void printService(Airport *airport){
    char s; string name;
    system(CLEAR);
    std::cout << "\n    At " << airport->getName()
              << "\n    located at (" << airport->getidCode() << ") " << airport->getCity() << ", " << airport->getCountry();
    if (airport->getServices().empty()) {
        std::cout << "\n    there are no pending services.";
        system("pause");
        return;
    }
    else{
        std::cout << "\n    Next service is a ";
        if (airport->nextService()->getType() == 'c') std::cout << "Cleaning service.\n";
        else if (airport->nextService()->getType() == 'm') std::cout << "Maintenance service.\n";
        if (airport->nextService()->getResponsible() == nullptr) {
            std::cout << "\n   No responsible designated. Do you want to attribute one? (y/n)";
            std::cin >> s;
            switch (s){
                //TODO
                case 'y': std::cout << "\n   not implemented yet: "; std::cin >> name;
                case 'n': break;
                default: std::cout << "Invalid Option\n";
            }
        }
    }
    std::cout << "\n    The services yet to be completed are:\n"
              << "\n    / ";
    for (auto it : airport->nextService()->getTasksLeft()) std::cout << it << " / ";
    system ("pause");
    return;

}

void printStaff(Staff *staff){

}

void printTransport(Airport *airport){
    vector<Transport*> temp = airport->getTransport();
    char i = 'i';
    for (auto it: temp){
        if (it->getType() != i){
            i = it->getType();
            std::cout << "\n    " << it->getTransport() << it->getTime()->getHour() << ":" << it->getTime()->getMinute();
        }
        std::cout << "\n        ";
    }
}
