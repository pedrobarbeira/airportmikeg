/**Will be deleted soon*/

//Created by Pedro Barbeira (up201303693)
#include "company.h"

/**
 * Admin Menu Interface
 */
void admin(MikeG* mg){
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
                  << "\n    [9] Return"
                  << "\n    [0] Log Out\n"
                  << "\n>";
        std::cin >> c;

        switch(c){
            case '1': createAirport(); break;
            case '2': deleteAirport(); break;
            case '3': checkAirport(); break;
            case '4': listAirport(); break;
            case '9': //return to previous menu, credentials needed; break;
            case 'q':
            case '0': throw LogOut();
            default: std::cout << "Invalid Option\n"; system("pause");
        }
    }
}
////////// Airport menu functions

void createAirport() {
    string id, name, city, country;
    char a;
    system(CLEAR);
    std::cout << "Please introduce new Airport location:"
              << "\n    Country - "; std::cin >> country;
    std::cout << "\n    City - "; std::cin >> city;
    std::cout << "\nDefine 3 letter word for airport id: "; std::cin >> id;
    std::cout << "\nIntroduce airport name:"
              << "\n    Name - "; std::cin >> name;
    Airport airport(id, name, country, city);
    std::cout << "You want to create and add to active airports "
              << "\n    Airport '" << airport.getName() << "'"
              << "\n    " << airport.getidCode() << ", " << airport.getCity() << ", " << airport.getCountry()
              << "\n\n  Is this correct? (y/n)"; cin >> a;
    if (a == 'y') {
        cout << "\n\n     Thank you. Airport successfully introduced to database.";
        system("pause");
        return;
    }
    else ;
    // still haven't figured out how to call airport BST;
    return;
}

void deleteAirport(){
    string id, city, country;
    char a;
    system(CLEAR);
    std::cout << "Which method do you prefer to find airport?"
              << "\n    [1] 3 letter code"
              << "\n    [2] City"
              << "\n    [3] Country"
              << "\n\n    [0] Back"; std::cin >> a;
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
        case '0': return;/*return to previous menu*/;
            // In this portion of the menu i have to find the possibilities of deletion and remove it from the BST
            return;
    }

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
        std::cout << "\n    Schedule: " << it->getSchedule().getYear() << "/" << it->getSchedule().getMonth() << "/" << it->getSchedule().getDay();
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
                  << "\n    [3] Check Service"
                  << "\n    [9] Return"
                  << "\n    [0] Log Out\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': addWorker(); break;
            case '2': delWorker(); break;
            case '3': checkService(); break;
            case '9': return;
            case '0': throw LogOut();
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

void workers(){
    char c;
    while(true) {
        system(CLEAR);
        std::cout << "This is the Worker menu\n"
                  << "\n\t[0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c){
            case '1': std::cout << "Placeholder\n"; c = getchar();; break;
            case '0': return;
            default: std::cout << "Invalid Option\n"; c = getchar();;
        }
    }
}

