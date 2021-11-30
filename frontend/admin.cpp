//Created by Pedro Barbeira (up201303693)
#include "admin.h"

/**
 * Admin Menu Interface
 */
void admin(){
    char c;
    bool access = false;
    //Acts as a barrier to ensure only credited personnel can access admin
    //management functions
    while(true) {
        system("CLS");
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Log In"
                  << "\n    [0] Back\n"
                  <<"\n>";
        std::cin >> c;
        switch(c) {
            case '1':
                access = login('a');
                break;
            case '0': return;
            default: std::cout << "Invalid Option\n";
        }
        system("pause");
        if(access) break;
    }
    //Shows real ADMIN menu after user has proven his identity
    while(true) {
        system("CLS");
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Airport Management"
                  << "\n    [2] Worker Management"
                  << "\n    [3] Voyage Management"
                  << "\n    [4] Plane Management\n"
                  << "\n    [0] Log Out\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': airport(); break;
            case '2': worker(); break;
            case '3': voyage(); break;
            case '4': plane(); break;
            case '0': return;
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
 * Voyage Management Menu
 */
void voyage(){
    std::cout << "Voyage Management Menu\n";
}

/**
 * Plane Management Menu
 */
void plane(){
    std::cout << "Plane Management Menu\n";
}


