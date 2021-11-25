//Created by Pedro Barbeira (up201303693);

#include "mainmenu.h"

char menu(){
    char c;
    system("CLS");
    std::cout << "This is a test main menu\n"
            << "\n\t[1] Workers"
            << "\n\t[2] Clients\n"
            << "\n\t[0] Exit\n"
            <<"\n$";
    std::cin >> c;
    return c;
}

void workers(){
    system("CLS");
    std::cout << "This is the Worker menu\n";
    system("pause");
}

void clients(){
    system("CLS");
    std::cout << "This is the Client menu\n";
    system("pause");
}