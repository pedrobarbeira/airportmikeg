//Created by Pedro Barbeira (up201303693)

#include "iostream"
#include "mikeg.h"

ostream& operator<<(ostream& out, Fail lf){
    out << lf.getError();
    return out;
}

bool MikeG::loadScreen(bool&flag){
    char c;
    if(!flag) {
        std::cout << "Loading data\n";
        try {
            load();
            flag = true;
            std::cout << "Load successful\n";
            std::cout << "Press enter to continue . . .";
            std::cin.ignore();
            c = getchar();
            return true;
        }
        catch (DevLog& e) {
            do {
                std::cout << "Continue[y/n]?";
                readInput(c);
                if (c == 'N' || c == 'n') flag = false;
                else if (c == 'Y' || c == 'y') flag = true;
            } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
            e.print();
            return false;
        }
    }
}

void MikeG::start(bool& flag) {
    this->setSysTime();
    system(CLEAR);
    bool keep = false;
    while (true) {
        char c;
        if(!flag) {
            flag = loadScreen(keep);
            if(!keep) return;
        }
        system(CLEAR);
        std::cout << "[MikeG Airlines]\t\t\t";
        sysTime->print(std::cout);
        std::cout << "\n\n    [1] Ticket Area"
                  << "\n    [2] Register"
                  << "\n    [3] Log In\n"
                  << "\n    [0] Exit\n"
                  << "\n>";
        readInput(c);
        try {
            switch (c) {
                case '1' : menu = new ClientMenu(nullptr); break;
                case '2': newAccount();
                case '3': menu = logIn(); break;
                case '0': return;
                case '-':
                    if (checkDev()) {
                        menu = new Dev; break;
                    }
                default:
                    std::cout << "Inval1d Option\n\n"
                              << "Press enter to continue . . .";
                    readInput(c);
            }
            if(menu != nullptr) menu->mainScreen();
            else{
                std::cout << "Invalid credentials\n\n"
                          << "Press enter to continue . . .";
                readInput(c);
            }
        }
        catch (DevLog e) {
            e.print();
        }
    }
}

Menu* MikeG::logIn() {
    system(CLEAR);
    std::string user, pass;
    std::cin.ignore();
    std::cout << "Username\n>";
    readInput(user);
    std::cout << "Password\n>";
    readInput(pass);
    bool flag = true;
    Company* searchCompany = data->findCompany(user);
    char c;
    if (searchCompany == nullptr) {
        Client* searchClient;
        searchClient = data->findClient(user);
        if (searchClient != nullptr) {
            if ((*searchClient).getPassword() == pass)
                return new ClientMenu(searchClient, data);
        }
    } else {
        if ((*searchCompany).getPassword() == pass) {
            c = (*searchCompany).getType();
            switch (c) {
                case 'A' : return new AdminMenu(searchCompany, data);
                case 'M' : return new ManagerMenu(searchCompany, data);
                case 'B' : return new BoardingMenu(searchCompany, data);
                case 'S' : return new ServiceMenu(searchCompany, data);
            }
        }
    }
    return nullptr;
}

bool MikeG::newAccount(){
    {
        bool flag;
        system(CLEAR);
        std::string user, pass, check;
        std::cout << "Username: ";
        readInput(user);
        std::cout << "Password: ";
        readInput(pass);
        std::cout << "Retype password: ";
        readInput(check);
        flag = pass == check;
        if (!flag) {
            std::cout << "Passwords don't match. Try again\n"
                      << "Press enter to continue . . .";
            getchar();
            return false;
        } else {
            Client *c = data->findClient(user);
            if (c == nullptr) {
                c = new Client(user, pass, 'c', 0, "");
                data->addClient(c);
                std::cout << "Account successfully created\n"
                          << "Press enter to continue . . .";
                getchar();
                return true;
            } else {
                std::cout << "Account already exists\n"
                          << "Press enter to continue . . .";
                getchar();
                return false;
            }
        }
    }
}

bool MikeG::save() const {
    return true;
}

bool MikeG::load(){
    Load main(data);
    try{
        main.load();
    }
    catch(DevLog e){
        e.print();
    }
}

bool MikeG::checkDev() {
    int DEVSIZE = 9;
    std::string DEV = "c3n4";
    std::string in;
    std::getline(std::cin, in);
    if (in.size() == DEVSIZE)
        if (in.substr(0, 4) == "-dev")
            if (in.substr(5, 4) == DEV)
                return true;
    return false;
}

void DevLog::print() const{
    std::ofstream outfile("./data/devlogs.txt", ios::app);
    if(date != nullptr) {
        outfile << "*[";
        (*date).print(outfile);
        outfile << "] ";
    }
    outfile << error << '\n';
    outfile.close();
}
