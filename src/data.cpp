//Created by Pedro Barbeira
#include "data.h"

/**-------Data-------*/
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
std::vector<AirportPointer> Data::getAirports() const{
    std::vector<AirportPointer> ret;
    iteratorBST<AirportPointer> it = airports.begin();
    while(it != airports.end()){
        ret.push_back(*it);
        it++;
    }
    return ret;
}
std::vector<Voyage*> Data::getVoyages() const{
    std::vector<Voyage*> ret;
    iteratorBST<VoyagePointer> it = voyages.begin();
    while(it != voyages.end()){
        ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}
std::vector<FlightPointer> Data::getFlights() const{
    std::vector<FlightPointer> ret;
    iteratorBST<FlightPointer> it = flights.begin();
    while(it != flights.end()){
        ret.push_back((*it));
        it++;
    }
    return ret;
}
std::vector<Plane*> Data::getPlanes() const{
    std::vector<Plane*> ret;
    iteratorBST<PlanePointer> it = planes.begin();
    while(it != planes.end()){
        ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}
std::vector<Ticket*> Data::getTickets() const{
    std::vector<Ticket*> ret;
    iteratorBST<TicketPointer> it = tickets.begin();
    while(it != tickets.end()){
        ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}
std::vector<Client*> Data::getClients() const{
    std::vector<Client*> ret;
    iteratorBST<ClientPointer> it = clients.begin();
    while(it != clients.end()){
        ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}
std::vector<Company*> Data::getCompany() const{
    std::vector<Company*> ret;
    iteratorBST<CompanyPointer> it = company.begin();
    while(it != company.end()){
        ret.push_back((*it).getPointer());
        it++;
    }
    return ret;
}
BST<FlightPointer> Data::getFlightBST() const{
    BST<FlightPointer> ret(FlightPointer(nullptr));
    iteratorBST<AirportPointer> it = airports.begin();
    AirportPointer airport;
    while(it != airports.begin()){
        airport = (*it);
        BST<FlightPointer> flights = airport.getFlightBST();
        iteratorBST<FlightPointer> flight = flights.begin();
        while(flight != flights.end()){
            ret.insert((*flight));
            flight++;
        }
        it++;
    }
    return ret;
}
AirportPointer Data::findAirport(const std::string& id) const{
    Airport* a = new Airport(id);
    AirportPointer find(a);
    return airports.find(find);
}
Voyage* Data::findVoyage(const std::string& id) const{
    Voyage* v = new Voyage(id);
    VoyagePointer find(v);
    find = voyages.find(find);
    return find.getPointer();
}
FlightPointer Data::findFlight(const std::string& id) const{
    FlightPointer ret(nullptr);
    iteratorBST<AirportPointer> it = airports.begin();
    while(it != airports.end()){
        Flight* find = (*it).find(id);
        if((*it).find(id) != nullptr) {
            ret = FlightPointer(find);
            break;
        }
        it++;
    }
    return ret;
}
Plane* Data::findPlane(const std::string& id) const{
    Plane* p = new Plane(id);
    PlanePointer find(p);
    find = planes.find(find);
    return find.getPointer();
}
Ticket* Data::findTicket(const std::string& id) const{
    Ticket* t = new Ticket(id);
    TicketPointer find(t);
    find = tickets.find(find);
    return find.getPointer();
}
Client* Data::findClient(const std::string& id) const{
    Client* c = new Client(id);
    ClientPointer find(c);
    find = clients.find(find);
    return find.getPointer();
}
Company* Data::findCompany(const std::string& id) const{
    Company* c = new Company(id);
    CompanyPointer find(c);
    find = company.find(find);
    return find.getPointer();
}

/**-------SAVE-------*/
/**---Load Airport---*/

/**---Load User---*/
void LoadUser::loadClient(){
    std::ifstream infile("./data/clients.txt");
    if(!infile.is_open())
        throw LoadUserFail();
    std::string line, tickets;
    while(std::getline(infile, line)){
        stringstream name, pass, type, miles, psngr, ticket;
        name << line;
        pass << line;
        type << line;
        miles << line;
        psngr << line;
        std::getline(infile, tickets);
        std::vector<std::string> load;
        if(tickets[0] != '0') {
            while (ticket << tickets) {
                load.push_back(ticket.str());
                ticket.clear();
            }
        }
        Client* c = new Client(name.str(), pass.str(), type.str()[0], stoi(miles.str()), psngr.str());
        c->setTickets(load);
        load.clear();
        data->addClient(c);
    }
}
void LoadUser::load(){
    try{
        loadClient();
    }
    catch(DevLog e){
        throw DevLog(e.getError());
    }
}

/**-------SAVE-------*/
void Save::save() const{
    try{
        SaveAirport airport(data);
        airport.save();
    }
    catch(DevLog e){
        std::cout << "Error saving Airports\n";
        e.print();
    }
    try{
        SaveUser user(data);
        user.save();
    }
    catch(DevLog e){
        std::cout << "Error saving Users\n";
        e.print();
    }
}

/**---Save Airport---*/
void SaveAirport::save() const {
    BST<AirportPointer> save = data->getAirportBST();
    if(!save.isEmpty()) {
        iteratorBST<AirportPointer> it = save.begin();
        std::ofstream outfile("./data/airports.txt");
        if (!outfile.is_open())
            throw SaveAirportFail("save()");
        outfile << "AIRPORT DATA\n";
        outfile.close();
        outfile.open("./data/service.txt");
        if (!outfile.is_open())
            throw SaveAirportFail("save()");
        outfile << "SERVICE DATA\n";
        outfile.close();
        while (it != save.end()) {
            if((*it).getPointer() != nullptr) {
                try {
                    saveAirport((*it));
                }
                catch (DevLog e) {
                    e.print();
                }
                it++;
            }
        }
    }
}
void SaveAirport::saveAirport(AirportPointer aptr) {
    std::ofstream outfile("./data/airports.txt", ios::app);
    if (!outfile.is_open())
        throw SaveAirportFail("saveAirport");
    Airport *a = aptr.getPointer();
    outfile << a->getidCode() << "(\n"
            << a->getName() << " "
            << a->getCountry() << " "
            << a->getCity() << "\n";
    std::vector<Flight *> saveFlights = aptr.getFlightsTo();
    for (auto flight : saveFlights) {
        outfile << flight->getId() << " ";
    }
    outfile << '\n';
    saveFlights = aptr.getFlightsTo();
    for (auto flight : saveFlights) {
        outfile << flight->getId() << " ";
    }
    outfile << '\n';
    outfile.close();
    try {
        saveTerminal(a);
    }
    catch(SaveAirportFail e){
        throw DevLog(e.getError());
    }
    try {
        saveTransport(a);
    }
    catch(SaveAirportFail e){
        throw DevLog(e.getError());
    }
    try {
        saveService(a);
    }
    catch(SaveAirportFail e){
        throw DevLog(e.getError());
    }
    try {
        saveStaff(a);
    }
    catch(SaveAirportFail e){
        throw DevLog(e.getError());
    }
}
void SaveAirport::saveTerminal(Airport* a){
    std::vector<Terminal*> terminals = a->getTerminals();
    if(!terminals.empty()) {
        std::ofstream outfile("./data/airports.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveTerminal");
        for (auto it : terminals) {
            outfile << it->getId() << " ";
            if (it->getPlane() == nullptr) outfile << "nullptr";
            else outfile << it->getPlane()->getPlate() << " ";
        }
        outfile << '\n';
        outfile.close();
    }
}
void SaveAirport::saveTransport(Airport* a){
    std::vector<Transport*> transports = a->getTransport();
    if(!transports.empty()) {
        std::ofstream outfile("./data/airports.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveTransport");
        for (auto it : transports) {
            outfile << it->getId() << " "
                    << it->getType() << " "
                    << it->getDistance() << " "
                    << it->getTime() << " ";
        }
        outfile << '\n';
        outfile.close();
    }
}
void SaveAirport::saveService(Airport* a){
    std::vector<ServiceTicket*> services = a->getServices();
    if(!services.empty()) {
        std::ofstream outfile(".data/airports.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveService");
        for (auto it : services) {
            outfile << it->getPlane()->getPlate() << " "
                    << it->getSchedule() << " "
                    << it->getResponsible()->getId()
                    << " " << it->getType();
        }
        outfile << '\n';
        std::list<ServiceTicket*> completed = a->getCompleteServices();
        if(!completed.empty()) {
            for (auto it : completed) {
                outfile << it->getPlane()->getPlate() << " "
                        << it->getSchedule() << " "
                        << it->getCompleted() << " "
                        << it->getResponsible()->getId() << " "
                        << it->getType();
            }
            outfile << "\n)\n";
            outfile.close();
        }
    }
}
void SaveAirport::saveStaff(Airport* a){
    std::vector<Staff*> staff = a->getStaff();
    if(!staff.empty()) {
        std::ofstream outfile("./data/service.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveStaff");
        outfile << a->getidCode() << "(\n";
        for (auto it : staff) {
            outfile << it->getId() << " "
                    << it->getName() << " "
                    << it->getPhone() << '\n';
        }
        outfile << ")\n";
        outfile.close();
    }
}

/**---Save User---*/
void SaveUser::save() const{
    try{
        saveCompany();
    }
    catch(SaveUserFail e){
        throw DevLog(e.getError());
    }
    try{
        saveClient();
    }
    catch(SaveUserFail e){
        throw DevLog(e.getError());
    }
}
void SaveUser::saveCompany() const{
    try{
        saveAdmin();
    }
    catch(SaveUserFail e){
        throw DevLog(e.getError());
    }
    try{
        saveBoarding();
    }
    catch(SaveUserFail e){
        throw DevLog(e.getError());
    }
    try{
        saveService();
    }
    catch(SaveUserFail e){
        throw DevLog(e.getError());
    }
}
void SaveUser::saveAdmin() const{
    BST<CompanyPointer> bst = data->getCompanyBST();
    if(!bst.isEmpty()) {
        std::ofstream outfile("./data/company.txt");
        if (!outfile.is_open())
            throw SaveUserFail("saveAdmin()");
        iteratorBST<CompanyPointer> it = bst.begin();
        while (it != bst.end()) {
            if ((*it).getPointer() != nullptr) {
                char c = (*it).getPointer()->getType();
                if (c == 'A' || c == 'M')
                    outfile << (*it).getPointer()->getUser() << " "
                            << (*it).getPointer()->getPassword() << " "
                            << c << '\n';
                it++;
            }
        }
        outfile.close();
    }
}
void SaveUser::saveBoarding() const {
    BST<CompanyPointer> bst = data->getCompanyBST();
    if(!bst.isEmpty()) {
        std::ofstream outfile("./data/company.txt", ios::app);
        if (!outfile.is_open())
            throw SaveUserFail("saveBoarding()");
        iteratorBST<CompanyPointer> it = bst.begin();
        while (it != bst.end()) {
            if ((*it).getPointer() != nullptr) {
                if ((*it).getPointer()->getType() == 'B') {
                    Company *c = (*it).getPointer();
                    outfile << c->getUser() << " "
                            << c->getPassword() << " "
                            << c->getType() << " "
                            << c->getAirport()->getidCode() << " "
                            << c->getPlane()->getPlate() << '\n';
                    it++;
                }
            }
        }
        outfile.close();
    }
}
void SaveUser::saveService() const{
    BST<CompanyPointer> bst = data->getCompanyBST();
    if(!bst.isEmpty()) {
        std::ofstream outfile("./data/company.txt", ios::app);
        if (!outfile.is_open())
            throw SaveUserFail("saveBoarding()");
        iteratorBST<CompanyPointer> it = bst.begin();
        while (it != bst.end()) {
            if ((*it).getPointer() != nullptr) {
                if ((*it).getPointer()->getType() == 'B') {
                    Company *c = (*it).getPointer();
                    outfile << c->getUser() << " "
                            << c->getPassword() << " "
                            << c->getType() << " "
                            << c->getAirport()->getidCode() << " "
                            << c->getStaff()->getId() << '\n';
                    it++;
                }
            }
        }
        outfile.close();
    }
}
void SaveUser::saveClient() const {
    BST<ClientPointer> bst = data->getClientsBST();
    if(!bst.isEmpty()) {
        std::ofstream outfile("./data/client.txt");
        outfile << "CLIENT DATA\n";
        if (!outfile.is_open()) {
            throw SaveUserFail("saveClient()");
        }
        iteratorBST<ClientPointer> it = bst.begin();
        while (it != bst.end()) {
            if((*it).getPointer() != nullptr) {
                Client *c = (*it).getPointer();
                outfile << c->getUser() << " "
                        << c->getPassword() << " "
                        << c->getType() << " "
                        << c->getDate() << " "
                        << c->getMiles() << " ";
                if(c->getPassenger() != "")
                    outfile << c->getPassenger();
                else outfile << "null";
                outfile << "\n";
                try {
                    saveTickets(c);
                }
                catch (SaveUserFail e) {
                    throw DevLog(e.getError());
                }
            }
        }
        outfile.close();
    }
}
void SaveUser::saveTickets(Client* c) {
    std::vector<string> tickets = c->getTickets();
    std::ofstream outfile("./data/clients.txt", ios::app);
    if(!tickets.empty()) {
        if (!outfile.is_open())
            throw SaveUserFail("saveTickets()");
        outfile << c->getUser() << " ";
        for (auto it : tickets) {
            outfile << it << " ";
        }
        outfile << "\n";
    }
    else outfile << 0 << '\n';
    outfile.close();
}