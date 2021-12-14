//Created by Pedro Barbeira (up201303693)
#include "menu.h"
#include "crossplatform.h"

std::ostream& operator<<(ostream& out, const UserPointer& user){
    out << (*user).getUser() << ' ' << (*user).getPassword() << ' ' << (*user).getType() << '\n';
    return out;
}

void Menu::mainScreen() const{
    std::cout << "blabla\n";
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