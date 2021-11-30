#include "mainmenu.h"
struct MikeG{
    std::vector<Airport*> airports;
    std::vector<Voyage*> voyages;
    std::vector<Flight*> flight;
};

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
void testVoyage() {
    Airport *porto;
    Airport *barcelona;
    Airport *lisboa;
    Airport *londres;

    Flight *f2 = new Flight("OPOLIS", porto, lisboa);
    Flight *f3 = new Flight("LISLON", lisboa, londres);
    Flight *f4 = new Flight("LISBCN", lisboa, barcelona);
    Flight *f5 = new Flight("BCNLON", barcelona, londres);
    Flight *f6 = new Flight("LONOPO", londres, porto);

    Voyage v1(porto, londres);

    try {
        Connection c1(f2, f3);
        if(!v1.addConnection(c1)) std::cout << "oh boy\n";
    }
    catch(Error e){
        e.print(std::cout);
    }
    v1.printRoute(std::cout);
    std::cout << '\n';
    try {
        Connection c1(f2, f5);
        if(!v1.addConnection(c1)) std::cout << "oh boy\n";
    }
    catch(Error e){
        e.print(std::cout);
    }
    std::cout << '\n';
    try {
        Connection c1(f4, f5);
        if(!v1.addConnection(c1)) std::cout << "oh boy\n";
    }
    catch(Error e){
        e.print(std::cout);
    }
    v1.printRoute(std::cout);
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
    menu();
}

/**
 * Interfacing for the test framework
 */
void testInterface(){
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
        system("pause");
    }
}

int main(){
    testInterface();

    return 0;
}