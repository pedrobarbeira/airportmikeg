//Created by Pedro Barbeira (up201303693)
#include "menu.h"
#include "crossplatform.h"

void readInput(char& in){
    std::cin >> in;
}

void readInput(std::string& in){
    std::string line;
    std::getline(std::cin, line);
    if(line[0] == '-') std::cout << "Process syscalls\n";
    else in = line;
}

std::ostream& operator<<(ostream& out, const UserPointer& user){
    out << (*user).getUser() << ' ' << (*user).getPassword() << ' ' << (*user).getType() << '\n';
    return out;
}

//TODO
bool Data::addFlight(Flight* f){
    //Test this bish
    bool flag;
    AirportPointer find = airports.find(AirportPointer((*f).getOrigin()->airport));
    if(find.getPointer() == nullptr){
        std::cout << "Error: origin airport not found\n"
                  << "Press enter to continue . . . ";
        int c = getchar();
        return false;
    }
    else{
        AirportPointer& addIn = find;
        airports.remove(find);
        flag = addIn.addFlight(f) && airports.insert(addIn);
    }
    if(flag) {
        AirportPointer find = airports.find(AirportPointer((*f).getDestination()->airport));
        if (find.getPointer() == nullptr) {
            std::cout << "Error: destination airport not found\n"
                      << "Press enter to continue . . . ";
            int c = getchar();
            return false;
        }
        else{
            AirportPointer& addOut = find;
            airports.remove(find);
            flag &= addOut.addFlight(f) && airports.insert(addOut);
        }
        if(!flag){
            std::cout << "Error adding out flight\n"
                      << "Press enter to continue . . . ";
            int c = getchar();
            return false;
        }
    }
    else{

        std::cout << "Error adding in flight\n"
                  << "Press enter to continue . . . ";
        int c = getchar();
        return false;
    }
    return true;
}

void Menu::mainScreen() const{
    std::cout << "blabla\n";
}

void ClientMenu::mainScreen() const{
    std:cout << "Here we are\n";
}

void JustBuy::mainScreen() const {
    //Add error check
    system(CLEAR);
    std::cout << "[Buy Ticket]\t\t\t";
    std::string origin, destination, oDate, dDate;
    //Get Origin
    std::cout << "\nFrom:\n>";
    std::cin >> origin;
    std::cin.ignore();
    std::cout << "\nDate [DD/MM]:\n>";
    if(getchar() == '\n') oDate = "";
    else std::cin >> oDate;
    //Get Destination
    std::cout << "\nTo:\n>";
    std::cin >> destination;
    std::cin.ignore();
    std::cout << "\nDate:\n>";
    if(getchar() == '\n') dDate = "";
    else std::cin >> dDate;
    std::cout << origin << " " << oDate << " "
              << destination << " " << dDate << '\n';
    system("pause");
}

void AdminMenu::mainScreen() const{
    std::cout << "we are @ Admin\n"
              << "Press enter to continue . . .";
    char c = getchar();
}

void ManagerMenu::mainScreen() const{
    std::cout << "we are @ Manager\n"
              << "Press enter to continue . . .";
    char c = getchar();
}

void BoardingMenu::mainScreen() const{
    std::cout << "we are @ Boarding\n"
              << "Press enter to continue . . .";
    char c = getchar();
}

void ServiceMenu::mainScreen() const{
    std::cout << "we are @ Service\n"
              << "Press enter to continue . . .";
    char c = getchar();
}