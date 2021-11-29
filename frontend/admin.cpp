//Created by Pedro Barbeira (up201303693)
#include "admin.h"

/**
 * Admin Menu Interface
 */
void admin(){
    char c;
    bool access;
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
            default: std::cout << "Invalid Option";
                system("pause");
        }
        system("pause");
        if(access) break;
    }
    //Shows real ADMIN menu after user has proven his identity
    system("CLS");
    while(true) {
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Worker Management"
                  << "\n    [2] Plane Management\n"
                  << "\n    [0] Log Out\n"
                  << "\n>";
        std::cin >> c;
        switch(c){
            case '1': std::cout << "Implement Worker Management Menu\n"; break;
            case '2': std::cout << "Implement Plane Management Menu\n"; break;
            case '0': return;
            default: std::cout << "Invalid Option\n";
                system("pause");
        }
        system("pause");
    }
}


