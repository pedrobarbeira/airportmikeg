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
    //Shows real ADMIN menu after user has proven his identity
    while(true) {
        system(CLEAR);
        std::cout << "[ADMIN]\n"
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

/**
 * Worker Management Menu
 */
void worker(){
    std::cout << "Worker Management Menu\n";
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


////////// Airport menu methods

void createAirport() {
    string id, name, city, country;
    system(CLEAR);
    std::cout << "Please introduce new Airport location:"
              << "\n    Country - ";
    std::cin >> country;
    std::cout << "\n    City - ";
    std::cin >> city;
    std::cout << "\nDefine 3 letter word for airport id: ";
    std::cin >> id;
    std::cout << "\nIntroduce airport name:"
              << "\n    Name - ";
    std::cin >> name;
    Airport airport(id, name, country, city);
    std::cout << "You want to create and add to active airports "
    // ainda não percebi como chamar e adicionar a BST de airport para initroduzir novo;

}

void deleteAirport(){

}

void checkAirport(){

}

void listAirport(){

}