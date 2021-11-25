//Created by Pedro Barbeira (up201303693);

#include "mainmenu.h"

void menu(){
    Time today;
    char c;
    while(true) {
        today.now();
        system("CLS");
        std::cout << "[MikeG Airlines]\t\t\t";
        today.print(std::cout);
        std::cout << "\n    [1] Admin"
                  << "\n    [2] Workers"
                  << "\n    [2] Clients\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        std::cin >> c;

        switch (c) {
            case '1': admin(); break;
            case '2': workers(); break;
            case '3': clients(); break;
            case '0': exit(0);
        }
    }
}

void admin(){
    char c;
    while(true) {
        system("CLS");
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Log In"
                  << "\n    [0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c){
            case '1': login('a');
            case '0': return;
        }
        system("pause");
    }
}

void login(char c){
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
            case '0': return;
        }
        system("pause");
    }
}

void clients(){
    char c;
    while(true) {
        system("CLS");
        std::cout << "This is the Client menu\n"
                  << "\n\t[0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c){
            case '0': return;
        }
        system("pause");
    }
}