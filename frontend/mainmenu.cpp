//Created by Pedro Barbeira (up201303693);

#include "mainmenu.h"

void menu(){
    Time t;
    char c;
    while(true) {
        t.today();
        system("CLS");
        std::cout << "[MikeG Airlines]\t\t\t";
        t.print(std::cout);
        std::cout << "\n    [1] Workers"
                  << "\n    [2] Clients\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        std::cin >> c;

        switch (c) {
            case '1': workers(); break;
            case '2': clients(); break;
            case '0': exit(0);
        }
    }
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