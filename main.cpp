#include "mainmenu.h"
#include "mikeg.h"

/**
 * Airport-related testing
 */

void testAirport(){
    airport();
    /*
    Airport porto("oPo", "Sá Carneiro", "Portugal", "Porto" );
    Date date(10,12,2021);
    Plane *plane = new Plane;
    Staff *staff1 = new Staff("Manel");
    Cleaning *cle1 = new Cleaning(plane);
    Cleaning *cle2 = new Cleaning(plane, date, staff1);
    Date date1(30, 11, 21);
    Date date2(1, 12, 21);
    (*cle1).setResponsible(staff1);
    porto.addService(cle1);
    Maintenance mai3(plane, date2, staff1);
    porto.addService(cle2);
    porto.delService(date2);
    Transport *test1 = new Transport('m', 2);
    Transport *test2 = new Transport('b', 0);
    Transport *test3 = new Transport('b', 1);
    Transport *test4 = new Transport('t', 5);
    Time time1(10, 0, 0);
    Time time2(11, 30, 0);
    Time time3(12, 0, 0);
    Time time4(13, 15, 0);
    Time time5(15, 0, 0);
    (*test1).addTime(time1);
    (*test1).addTime(time2);
    (*test1).addTime(time4);
    (*test2).addTime(time1);
    (*test2).addTime(time2);
    (*test3).addTime(time2);
    (*test3).addTime(time3);
    (*test4).addTime(time1);
    (*test4).addTime(time5);
    porto.setTransport(test1);
    porto.setTransport(test2);
    porto.setTransport(test3);
    porto.setTransport(test4);
    porto.nextTransportMetro(time2);
    porto.nextTransportBus(time1);
    porto.nextTransportTrain(time3);
    Time time6(23, 59, 59);
    porto.nextTransportTrain(time6);
     */
}

/**
 * Voyage-related testing
 */
void testVoyage() {

    std::queue<std::string> first;
    first.push("A");
    first.push("J");
    Airbus *a = new Airbus(100, 150, first);

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
    MikeG main;
    Airport* a1 = new Airport("OPO", "Sa Carneiro", "Portugal", "Porto");
    Airport* a2 = new Airport("BCN", "Barça", "Espanha", "Barcelona");
    TimePlace* t1 = new TimePlace;
    t1->airport = a1;
    TimePlace* t2 = new TimePlace;
    t2->airport = a2;
    Airbus* airb1 = new Airbus(100, 50, std::queue<std::string>({"A", "B"}));
    Flight* f1 = new Flight(t1, t2, airb1);
    Flight* f2 = new Flight(t2, t1, airb1);


    BST<AirportFlightList> b1(AirportFlightList(nullptr));

    if(b1.insert(AirportFlightList(a1))) std::cout << "yo";

    if(main.addAirport(a1)) std::cout << "all good\n";
    if(main.addAirport(a2)) std::cout << "all good too \n";
    if(main.addFlight(f1)) std::cout << "still all good\n";
    if(main.addFlight(f2)) std::cout << "thank god it worked\n";
    if(main.addPlane(airb1)) std::cout << "holy jesus praised by thy name\n";
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
        std::cin.ignore();
        std::cout << "Press enter to continue . . .";
        c = getchar();
    }
}

int main(){
    //testAirport();
    //testVoyage();
    //testPassenger();
    //testMenu();
    testInterface();

    return 0;
}