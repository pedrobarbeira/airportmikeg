//#include "mainmenu.h"
#include "mikeg.h"
#include "funcoes.h"
#include "company.h"
#include "menu.h"
//Use vectors and comparator functions to allow for different searches



/**
 * General testing
 */
void test(){
    Data *data = new Data;
    queue<string> temp; temp.push("a"); temp.push("b");

    auto *porto = new Airport("OPO", "Francisco Sa Carneiro", "Portugal", "Porto");
    porto->activateTerminal("1");
    porto->activateTerminal("2");
    auto *lisboa = new Airport("LIS", "Portela", "Portugal", "Lisbon");
    lisboa->activateTerminal("1");
    lisboa->activateTerminal("2");
    auto *madrid = new Airport("MAD", "Barajas", "Spain", "Madrid");
    madrid->activateTerminal("1");
    madrid->activateTerminal("2");
    data->addAirport(lisboa);

    data->addAirport(porto);
    data->addAirport(madrid);

    auto *time1030 = new Time(20, 12, 2021, 10, 30, 00);
    auto *time1100 = new Time(20, 12, 2021, 11, 00, 00);
    auto *time1130 = new Time(20, 12, 2021, 11, 30, 00);
    auto *time1200 = new Time(20, 12, 2021, 12, 00, 00);
    auto *time1230 = new Time(20, 12, 2021, 12, 30, 00);
    auto *time1300 = new Time(20, 12, 2021, 13, 00, 00);
    auto *time1330 = new Time(20, 12, 2021, 13, 30, 00);
    auto *time1400 = new Time(20, 12, 2021, 14, 00, 00);
    auto *timenow = new Time; timenow->now();
    auto *ori1 = new TimePlace(porto, time1030);
    auto *des1 = new TimePlace(lisboa, time1100);
    auto *ori2 = new TimePlace(porto, time1200);
    auto *des2 = new TimePlace(madrid, time1300);
    auto *ori3 = new TimePlace(lisboa, time1130);
    auto *des3 = new TimePlace(madrid, time1230);

    auto *airb1 = new Airbus(temp);
    porto->setTerminal(airb1, "1");
    auto *airb2 = new Airbus(temp);
    porto->setTerminal(airb2, "2");
    auto *airb3 = new Airbus(temp);
    auto *plane = new Plane;
    data->addPlane(airb1);
    data->addPlane(airb2);
    data->addPlane(airb3);
    data->addPlane(plane);

    auto *opolis = new Flight(ori1, des1, airb1);
    auto *opomad = new Flight(ori2, des2, airb2);
    auto *lismad = new Flight(ori3, des3, airb1);
    data->addFlight(opolis);
    data->addFlight(opomad);
    data->addFlight(lismad);

    auto *metro = new Transport('m'); metro->addTime(time1300);
    TransportPointer m(metro);
    auto *bus1 = new Transport('b'); bus1->addTime(time1100);
    TransportPointer b1(bus1);
    auto *bus2 = new Transport('b'); bus2->addTime(time1200);
    TransportPointer b2(bus2);
    auto *train = new Transport('t'); train->addTime(time1200);
    TransportPointer t(train);
    porto->setTransport(m); porto->setTransport(b1); porto->setTransport(b2); porto->setTransport(t);
    lisboa->setTransport(m); lisboa->setTransport(b1); lisboa->setTransport(b2); lisboa->setTransport(t);
    madrid->setTransport(m); madrid->setTransport(b1); madrid->setTransport(b2); madrid->setTransport(t);

    auto *staff1 = new Staff("Conceicao"); staff1->setPhone(923456789);
    porto->addStaff(staff1);
    auto *staff2 = new Staff("Jesus"); staff2->setPhone(912345678);
    lisboa->addStaff(staff2);
    auto *staff3 = new Staff("Ancelotti"); staff3->setPhone(934567890);
    madrid->addStaff(staff3);

    auto *cle1 = new Cleaning(airb1, time1030, staff1);
    porto->addService(cle1);
    auto *cle2 = new Cleaning(airb1, time1130, staff2);
    lisboa->addService(cle2);
    auto *mai = new Maintenance(airb1, time1400, staff3);
    madrid->addService(mai);


    auto *admin = new Company("admin", "admin", 'A', nullptr, nullptr, staff1);
    data->addCompany(admin);
    auto *managerP = new Company("manager", "manager", 'M', porto, nullptr, staff1);
    data->addCompany(managerP);
    auto *serviceP = new Company("service", "service", 'S', porto, nullptr, staff1);
    data->addCompany(serviceP);
    auto *boardingP = new Company("boarding", "boarding", 'B', porto, airb1, staff1);
    data->addCompany(boardingP);
    auto *managerL = new Company("manager", "manager", 'M', porto, nullptr, staff2);
    data->addCompany(managerL);
    auto *serviceL = new Company("service", "service", 'S', porto, nullptr, staff2);
    data->addCompany(serviceL);
    auto *boardingL = new Company("boarding", "boarding", 'B', porto, airb1, staff2);
    data->addCompany(boardingL);
    auto *managerM = new Company("manager", "manager", 'M', porto, nullptr, staff3);
    data->addCompany(managerM);
    auto *serviceM = new Company("service", "service", 'S', porto, nullptr, staff3);
    data->addCompany(serviceM);
    auto *boardingM = new Company("boarding", "boarding", 'B', porto, airb1, staff3);
    data->addCompany(boardingM);
    auto *client = new Client ("client", "client", 'C');
    data->addClient(client);

    auto *adm = new AdminMenu(admin, data);
    auto *mngP = new ManagerMenu(managerP, data);
    auto *brdP = new BoardingMenu(boardingP, data);
    auto *srvP = new ServiceMenu(serviceP, data);
    auto *mngL = new ManagerMenu(managerL, data);
    auto *brdL = new BoardingMenu(boardingL, data);
    auto *srvL = new ServiceMenu(serviceL, data);
    auto *mngM = new ManagerMenu(managerM, data);
    auto *brdM = new BoardingMenu(boardingM, data);
    auto *srvM = new ServiceMenu(serviceM, data);
    auto *clt = new ClientMenu(client, data);

    adm->mainScreen(); //TESTING ADMIN MENU
    //mngP->mainScreen(); //TESTING PORTO MANAGER MENU
    //mngL->mainScreen(); //TESTING LISBON MANAGER MENU
    //mngM->mainScreen(); //TESTING MADRID MANAGER MENU
    //brdP->mainScreen(); //TESTING PORTO BOARDING MENU
    //brdL->mainScreen(); //TESTING LISBOA BOARDING MENU
    //brdM->mainScreen(); //TESTING MADRID BOARDING MENU
    //srvP->mainScreen(); //TESTING PORTO SERVICE MENU
    //srvL->mainScreen(); //TESTING LISBOA SERVICE MENU
    //srvM->mainScreen(); //TESTING MADRID SERVICE MENU
    //clt->mainScreen(); //TESTING CLIENT MENU
}

/**
 * Airport-related testing
 */
void testAirport(){

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
    test();

    testInterface();

    return 0;
}