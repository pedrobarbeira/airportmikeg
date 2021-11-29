
#include "mainmenu.h"
/**
 * Airport-related testing
 */
void testAirport(){
    Airport porto("Sá Carneiro", "Portugal", "Porto" );
    Plane plane;
    Staff staff1("Manel");
    Date date1(30, 11, 21);
    Date date2(1, 12, 21);
    Service cle1(plane, date1);
    cle1.setResponsible(staff1);
    porto.addService(cle1);
    Service cle2(plane, date2, staff1);
    porto.addService(cle2);
    porto.delService(date2);
}

/**
 * Voyage-related testing
 */
void testVoyage(){
    //Found some problems with how to implement the flight connections
    //Will have to figure this out later
}

/**
 * Passenger-related testing
 */
void testPassenger(){}

/**
 * Menu-related testing
 */
void testMenu(){
    menu();
}

int main(){
    while(true) {
        system("CLS");
        char c;
        std::cout << "[RunTests]\n"
                  << "\n\t[1] Airport"
                  << "\n\t[2] Voyage"
                  << "\n\t[3] Passenger"
                  << "\n\t[4] Menu\n"
                  << "\n\t[0] Exit\n"
                  << "\n>";
        std::cin >> c;
        switch (c) {
            case '1': testAirport(); break;
            case '2': testVoyage(); break;
            case '3': testPassenger(); break;
            case '4': testMenu(); break;
            case '0': exit(0);
            default: std::cout << "Invalid Option\n";
        }
    }

    return 0;
}