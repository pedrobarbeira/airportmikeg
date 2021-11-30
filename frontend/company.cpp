//Created by Pedro Barbeira (up201303693)
#include "company.h"

/**
 * Admin Menu Interface
 */
void admin(){
    char c;
    //Shows real ADMIN menu after user has proven his identity
    while(true) {
        system("CLS");
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
            case '3': travel(); break;
            case '4': plane(); break;
            case '0': throw LogOut();
            default: std::cout << "Invalid Option\n";
        }
        system("pause");
    }
}

/**
 * Airport Management Menu
 */
void airport(){
    std::cout << "Airport Management Menu\n";
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
void travel(){
    char c;
    while(true) {
        system("CLS");
        std::cout << "[TRAVEL]\n"
                  << "\n    [1] Voyage"
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
            default: std::cout << "Invalid Option\n";
        }
        system("pause");
    }
}
void voyage(){
    char c;
    while(true) {
        //Insert display of all voyages
        system("CLS");
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
        system("pause");
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
        system("CLS");
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
        system("pause");
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
        system("CLS");
        std::cout << "This is the Worker menu\n"
                  << "\n\t[0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c){
            case '1': std::cout << "Placeholder\n"; system("pause"); break;
            case '0': return;
            default: std::cout << "Invalid Option\n";
                system("pause");
        }
        system("pause");
    }
}


