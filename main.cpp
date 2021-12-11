#include "mainmenu.h"

/**
 * Airport-related testing
 */

void testAirport(){


    Airport porto("OPO", "Sá Carneiro", "Portugal", "Porto" );
    Plane *plane = new Plane;
    Staff *staff1 = new Staff("Manel");
    Cleaning *cle1 = new Cleaning(plane);
    Cleaning *cle2 = new Cleaning(plane);
    Date date1(30, 11, 21);
    Date date2(1, 12, 21);
    (*cle1).setResponsible(staff1);
    porto.addService(cle1);
    Service cle3(plane, date2, staff1);
    porto.addService(cle2);
    porto.delService(date2);

}

/**
 * Voyage-related testing
 */
void testVoyage() {

    std::queue<std::string> first;
    first.push("A");
    first.push("J");
    Airbus *a = new Airbus("A523", 100, 150, first);

    std::cout << a->freeSeatNum() << '\n';
    if(a->bookSeat("A03")) std::cout << a->freeSeatNum() << '\n';

    a->showSeats();

}

/**
 * Passenger-related testing
 */
void testPassenger(){
    //Add code here
}

/**
 * Menu-related testing
 */
void testMenu(){
    MikeG* main = new MikeG;

    Airport* porto = new Airport("OPO", "Sa Carneiro", "Portugal", "Porto");
    Airport* gatwick = new Airport("LGW", "Gatwick", "England", "London");

    main->addAirport(porto);
    main->addAirport(gatwick);

    Flight* f1 = new Flight(porto, gatwick);

    main->addFlight(f1);

    menu(main);

}

/**
 * Interfacing for the test framework
 */
void testInterface(){
    while(true) {
        system(CLEAR);
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
        system("pause");
    }
}

int main(){
    testAirport();
    //testVoyage();
    //testPassenger();
    //testMenu();
    testInterface();

    return 0;
}