/**Will be deleted soon*/

//Created by Pedro Barbeira (up201303693);

#include "mainmenu.h"

std::string DEV = "c3n4";   //Password for the hidden Developer Menu.
int DEVSIZE = 9;            //Size of the --dev c3n4 line


void menu(MikeG* mg){
    char c;
    while(true) {
        mg->setSysTime();
        system(CLEAR);
        std::cout << "[MikeG Airlines]\t\t\t";
        mg->getTime()->print(std::cout);
        std::cout << "\n    [1] Company"
                  << "\n    [2] Customer\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        std::cin >> c;
        try {
            switch (c) {
                case '1': company(mg);break;
                case '2': clients(mg); break;
                case '0': return;
                case '-': if (checkDev()) {dev();break;}
                default: std::cout << "Invalid Option\n";
                    int c = getchar();
            }
        }
        catch(DevLog e){
            e.print();
        }
    }
}

void company(MikeG* mg){
    char c, type;
    bool access = false;
    while(true) {
        system(CLEAR);
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
                admin(mg);
                break;
                //Insert different cases for different types of workers
            default:
                throw DevLog("Invalid Account Type\n");
        }
    }
    catch (LogOut lo){
        lo.print();
        int c = getchar();
        return;
    }
}

void clients(MikeG* mg){
    std::cout << "Clients Menu\n";
    int c = getchar();
}

void dev(){
    char c;
    bool ohBoy;
    while(true) {
        system(CLEAR);
        ohBoy = newErrors();
        std::cout << "[DEV]\n";
        if(ohBoy) {
            std::cout << "\nWarning: Some stuff went south\n"
                      << "\n    [1] New Error List"
                      << "\n    [2] Full Error List";
        }
        else {
            std::cout << "\nThere aren't any new errors\n"
                      << "\n    [1] Error List";
        }
         std::cout << "\n    [0] Back\n"
                   << "\n>";
        std::cin >> c;
        switch(c){
            case '1':
                if(ohBoy) {
                    std::cout << "Placeholder\n";
                    int c = getchar();
                }else {
                    std::cout << "Do something\n";
                } break;
            case '2':
                if(!ohBoy) continue;
                else {
                    std::cout << "Do Something\n"; break;
                }
            case 'q':
            case '0': return;
            default: std::cout << "Invalid Option\n";
                int c = getchar();
        }
        int c = getchar();
    }
}

bool newErrors(){
    std::ifstream infile("./data/devlogs.txt");
    if(!infile.is_open()) {
        std::cout << "Something went VERY wrong - there is no devlogs.txt"
                  << "\nLight the beacons! Call for aid!\n";
        return false;
    }
    else{
        std::string line;
        while(getline(infile, line)) {
            if (line[0] == '*') return true;
        }
        return false;
    }
}

bool checkDev() {
    std::string in;
    std::getline(std::cin, in);
    if (in.size() == DEVSIZE)
        if (in.substr(0, 4) == "-dev")
            if (in.substr(5, 4) == DEV)
                return true;
    return false;
}

bool login(char c, char& type){
    bool authorized;
    authorized = checkCredentials(c, type);
    if(!authorized) {
        std::cout << "Invalid Credentials\n";
        return authorized;
    }
    else std::cout << "\nLogin Accepted\n\n"; return authorized;
}

bool checkCredentials(char c, char& type){
    system(CLEAR);
    std::ifstream infile;
    std::string fileName = "./data/";
    switch(c){
        case 'a': fileName += "company.txt"; break;
        case 'b':
        default: std::cout << "Invalid Option\n";
            system("pause");
    }
    infile.open(fileName);

    if(infile.fail()) throw DevLog("Error opening files in mainmenu.cpp/checkCredentials()", new Time);

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

    if(!found) return false;
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

