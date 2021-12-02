//Created by Pedro Barbeira (up201303693);

#include "mainmenu.h"

std::string DEV = "c3n4";   //Password for the hidden Developer Menu.
int DEVSIZE = 9;           //Size of the --dev c3n4 line

/**
 * Main Menu Interface
 */
void menu(MikeG mg){
    Time today;
    char c;
    while(true) {
        today.now();
        system("CLS");
        std::cout << "[MikeG Airlines]\t\t\t";
        today.print(std::cout);
        std::cout << "\n    [1] Company"
                  << "\n    [2] Customer\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        std::cin >> c;
        try {
            switch (c) {
                case '1': company();break;
                case '2': clients; break;
                case '0': return;
                case '-': if (checkDev()) {dev();break;}
                default: std::cout << "Invalid Option\n";
                    system("pause");
            }
        }
        catch(DevLog e){
            e.print();
        }
    }
}

void company(){
    char c, type;
    bool access = false;
    while(true) {
        system("CLS");
        std::cout << "[COMPANY]\n"
                  << "\n    [1] Log In"
                  << "\n    [0] Back\n"
                  <<"\n>";
        std::cin >> c;
        switch(c) {
            case '1':
                access = login('a', type);
                break;
            case '0': return;
            default: std::cout << "Invalid Option\n";
        }
        system("pause");
        if(access) break;
    }try {
        switch (type) {
            case 'A':
                admin();
                break;
                //Insert different cases for different types of workers
            default:
                throw DevLog("Invalid Account Type\n");
        }
    }
    catch (LogOut lo){
        lo.print();
        system("pause");
        return;
    }
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
 * Interface function that validates login data
 * @param c acts has a three-way flag: 'a' for admins, 'w' for workers and 'c' for clients
 * @return true if login is valid, false otherwise
 */
bool login(char c, char& type){
    bool authorized;
    authorized = checkCredentials(c, type);
    if(!authorized) {
        std::cout << "Invalid Credentials\n";
        return authorized;
    }
    else std::cout << "Login Accepted\n"; return authorized;
}

/**
 * Checks data in the respective credential folder, determined by the value of c.
 * Validates them and returns an integer code.
 * @param c 'a' for admins, 'w' for workers, 'c' for clients
 * @return 0 upon failure, 1 upon success, 2 upon file error
 */
bool checkCredentials(char c, char& type){
    system("CLS");
    std::ifstream infile;
    std::string fileName = "./data/";
    switch(c){
        case 'a': fileName += "company.txt"; break;
        case 'b': fileName += "client.txt"; break;
        default: std::cout << "Invalid Option\n";
            system("pause");
    }
    infile.open(fileName);

    if(infile.fail()) throw DevLog("Error opening files in mainmenu.cpp/checkCredentials()");

    std::string user, pass, check;
    bool found = false;
    std::cout << "Username:\n>";
    std::cin >> user;

    while(infile >> check){
        if(user == check){
            found = true;
            break;
        }
        else std::getline(infile, check);
    }

    if(!found) return 0;
    else {
        std::cout << "Password:\n>";
        std::cin >> pass;
        infile >> check;
        if(pass == check) {
            infile >> type;
            return true;
        }
        else return false;
    }
}

/**
 * Stores special system error messages into the DevLogs file, so the company's
 * IT guy can keep it tidy and safe
 */
void DevLog::print() const{
    std::ofstream outfile("./data/devlogs.txt");
    outfile << "*" << error << '\n';
}