//#include "mainmenu.h"
#include "mikeg.h"
#include "funcoes.h"
#include "company.h"
#include "menu.h"
//Use vectors and comparator functions to allow for different searches



/**
 * Airport-related testing
 */
void testAirport(){
    Data *data = new Data;
    auto *porto = new Airport;
    porto->setCity("Porto");
    porto->setCountry("Portugal");
    porto->setId("OPO");
    auto *plane = new Plane;
    porto->activateTerminal("1");
    porto->setTerminal(plane, "1");
    auto *metro = new Transport("12", 'm');
    auto *bus = new Transport("10", 'b');
    auto *time1 = new Time(10, 00, 00);
    auto *time2 = new Time(11, 00, 00);
    metro->addTime(time1);
    bus->addTime(time1);
    bus->addTime(time2);
    auto *staff1 = new Staff("Manel");
    auto *cle1 = new Cleaning(plane, time1, staff1);
    auto *ser1 = new ServiceTicket(plane, 'a');
    cle1->checkFlightDeck();
    cle1->checkFloor();
    cle1->setResponsible(staff1);
    porto->addService(cle1);
    porto->setName("Francisco Sá Carneiro");
    TransportPointer b(bus);
    TransportPointer m(metro);
    porto->setTransport(b);
    porto->setTransport(m);
    cle1->checkWc();
    auto date2 = new Time(18, 12, 21, 0, 0, 0);
    cle1->checkSeats();
    porto->delService(date2);
    data->addAirport(porto);
    data->addPlane(plane);
    Admin *admin = new Admin("admin", "admin");
    AdminMenu *adm = new AdminMenu(admin, data);
    adm->mainScreen();
    //admin(data);

    //for (auto it : porto->nextTransportBus(time1)){
    //    std::cout << "\n" << (*it).getHour() << ":" << (*it).getMinute();}

}

/**
 * Voyage-related testing
 */
void testVoyage() {
    std::queue<std::string> first({"A", "M"});
    Airbus* arb1=new Airbus(first);
    Airbus* arb2 = new Airbus(first);
    Airbus* arb3 = new Airbus(first);

    BST<PlanePointer> pbst(PlanePointer(nullptr));

    PlanePointer pptr1(arb1);
    PlanePointer pptr2(arb2);
    PlanePointer pptr3(arb3);

    pbst.insert(pptr2);
    pbst.insert(pptr3);
    pbst.insert(pptr1);

    arb1->showSeats();

}

/**
 * Passenger-related testing
 */
void testPassenger() {
   /* vector<Ticket *> tickets;
    vector<Luggage *> passLugg;
    queue<stack<Luggage*>> bags;
    while (true) {
        cout << "[1] comprar bilhetes" << endl;
        cout << "[2] lista bilhetes" << endl;
        cout << "[3] enviar malas"<< endl;
        cout << "[4] voltar" << endl;
        int escolha;
        cin >> escolha;
        if( escolha==4){
            break;
        }
        switch (escolha) {
            case 1:
                buyTicket(tickets, passLugg);
                break;
            case 2:
                listBilhetes(tickets);
                break;
            case 3:
                fazerpilha(bags,passLugg);
        }
    }*/
}
/**
 * Menu-related testing
 */
void testMenu(){
    MikeG main;
    bool flag = false;
    main.start(flag);
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
        getchar();
    }
}

int main(){
    Time t(10, 25, 00);

    t.print(std::cout);


    testInterface();

    return 0;
}