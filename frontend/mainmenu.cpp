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
    int authorized;
    while(true) {
        system("CLS");
        std::cout << "[ADMIN]\n"
                  << "\n    [1] Log In"
                  << "\n    [0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c) {
            case '1':
                authorized = login('a');
                if(!authorized) std::cout << "Invalid Credentials\n";
                else{
                    switch(authorized){
                        case 1: std::cout << "Login Accepted\n"; break;
                        case 2: std::cout << "Error Opening Infile\n";
                        default: std::cout << "Unknown Error\n";
                    }
                }
                break;
            case '0': return;
        }
        system("pause");
    }
}

int login(char c){
    system("CLS");
    std::ifstream infile;
    std::string fileName = "./credentials/";
    switch(c){
        case 'a': fileName += "admin.txt"; break;
        case 'w': fileName += "worker.txt"; break;
        case 'c': fileName += "client.txt"; break;
    }
    infile.open(fileName);

    if(infile.fail()) return 2;

    std::string user, pass, check;
    bool found = false;
    std::cout << "Username:\n>";
    std::cin >> user;

    while(infile >> check){
        if(user == check){
            found = true;
            break;
        }
        else infile >> check;
    }

    if(!found) return 0;
    else {
        std::cout << "Password:\n>";
        std::cin >> pass;
        infile >> check;
        if(pass == check) return 1;
        else return 0;
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