//Created by Pedro Barbeira (up201303693);

#include "mainmenu.h"

std::string DEV = "c3n4";   //Password for the hidden Developer Menu.
int DEVSIZE = 9;           //Size of the --dev c3n4 line

/**
 * Main Menu Interface
 */
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
            case '-':
                if(checkDev()){dev(); break;}
                else{};
            default: std::cout << "Invalid Option\n";
                    system("pause");
        }
    }
}

/**
 * Checks if user is a Dev upon --dev call
 * @return true if yes, false otherwise
 */
bool checkDev() {
    std::string in;
    std::getline(std::cin, in);
    if (in.size() == DEVSIZE)
        if (in.substr(0, 4) == "-dev")
            if (in.substr(5, 4) == DEV)
                return true;
    return false;
}

/**
 * Interface for the hidden Developer Inferface
 */
void dev(){
    char c;
    while(true) {
        system("CLS");
        std::cout << "This is the Dev menu\n"
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

/**
 * Interface function that validates login credentials
 * @param c acts has a three-way flag: 'a' for admins, 'w' for workers and 'c' for clients
 * @return true if login is valid, false otherwise
 */
bool login(char c){
    int authorized;
    authorized = checkCredentials(c);
    if(!authorized) {
        std::cout << "Invalid Credentials\n";
        return false;
    }
    else{
        switch(authorized){
            case 1: std::cout << "Login Accepted\n"; return true;
            case 2: std::cout << "Error Opening Infile\n"; return false;
            default: std::cout << "Unknown Error\n"; return false;
        }
    }
}

/**
 * Checks credentials in the respective credential folder, determined by the value of c.
 * Validates them and returns an integer code.
 * @param c 'a' for admins, 'w' for workers, 'c' for clients
 * @return 0 upon failure, 1 upon success, 2 upon file error
 */
int checkCredentials(char c){
    system("CLS");
    std::ifstream infile;
    std::string fileName = "./credentials/";
    switch(c){
        case 'a': fileName += "admin.txt"; break;
        case 'w': fileName += "worker.txt"; break;
        case 'c': fileName += "client.txt"; break;
        default: std::cout << "Invalid Option\n";
            system("pause");
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

/**
 * Worker Menu Interface
 */
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

/**
 * Client Menu Interface
 */
void clients(){
    char c;
    while(true) {
        system("CLS");
        std::cout << "This is the Client menu\n"
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