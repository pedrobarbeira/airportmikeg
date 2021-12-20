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
    auto *lisboa = new Airport("LIS", "Portela", "Portugal", "Lisbon");
    auto *timeor = new Time(10, 30, 00);
    auto *timedes = new Time(11, 00, 00);
    auto *ori = new TimePlace(porto, timeor);
    auto *des = new TimePlace(lisboa, timedes);
    auto *plane = new Plane;
    plane->setPlate("123");
    auto *flight = new Flight(ori, des, plane);
    data->addAirport(porto);
    data->addAirport(lisboa);
    data->addPlane(plane);
    data->addFlight(flight);
    porto->setCity("Porto");
    porto->setCountry("Portugal");
    porto->setId("OPO");
    queue<string> first;
    porto->activateTerminal("1");
    porto->activateTerminal("2");
    porto->setTerminal(plane, "1");
    queue<string> temp; temp.push("a"); temp.push("b");
    Airbus *airbus = new Airbus(temp);
    porto->setTerminal(airbus, "2");
    auto *metro = new Transport('m');
    auto *bus = new Transport('b');
    auto *time1 = new Time(10, 00, 00);
    auto *time2 = new Time(11, 00, 00);
    metro->addTime(time1);
    bus->addTime(time1);
    bus->addTime(time2);
    auto *date1 = new Time(18, 12, 21, 0, 0, 0);
    auto *staff1 = new Staff("Manel");
    auto *cle1 = new Cleaning(plane, date1);
    auto *ser1 = new ServiceTicket(plane, 'a');
    cle1->checkFlightDeck();
    cle1->checkFloor();
    //cle1->setResponsible(staff1);
    porto->addService(cle1);
    porto->setName("Francisco Sá Carneiro");
    TransportPointer b(bus);
    TransportPointer m(metro);
    porto->setTransport(b);
    porto->setTransport(m);
    cle1->checkWc();
    auto date2 = new Time(18, 12, 21, 0, 0, 0);
    //cle1->checkSeats();
    //porto->delService(date2);
    porto->addStaff(staff1);
    data->addFlight(flight);
    data->addPlane(airbus);
    data->addPlane(plane);
    Company *admin = new Company("admin", "admin", 'A', porto, plane, staff1);
    AdminMenu *adm = new AdminMenu(admin, data);

    porto->addStaff(staff1);
    Client *client = new Client ("client", "client", 'C');

    porto->addStaff(staff1);

    Company *s2 = new Company(staff1->getId(), staff1->getId(), 'S', porto, plane, staff1);
    data->addCompany(admin);
    data->addClient(client);
    data->addCompany(s2);
    adm->mainScreen();
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
    testAirport();
    testInterface();

    return 0;
}