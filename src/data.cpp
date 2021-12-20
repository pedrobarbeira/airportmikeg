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
        find = airports.find(AirportPointer((*f).getDestination()->airport));
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
std::vector<PlanePointer> Data::getPlanes() const{
    std::vector<PlanePointer> ret;
    iteratorBST<PlanePointer> it = planes.begin();
    while(it != planes.end()){
        ret.push_back((*it));
        it++;
    }
    return ret;
}
std::vector<Ticket*> Data::getTickets() const{
    std::vector<Ticket*> ret;
    iteratorBST<FlightPointer> it = flights.begin();
    BST<TicketPointer> bst(TicketPointer(nullptr));
    while(it != flights.end()) {
        bst = (*it).getTicketBST();
        if (!bst.isEmpty()) {
            iteratorBST<TicketPointer> tick = bst.begin();
            Ticket *t;
            while (tick != bst.end()) {
                t = (*tick).getPointer();
                ret.push_back(t);
                tick++;
            }
        }
        it++;
    }
    return ret;
}
BST<TicketPointer> Data::getTicketBST() const{
    BST<TicketPointer> bst(TicketPointer(nullptr));
    iteratorBST<FlightPointer> it = flights.begin();
    BST<TicketPointer> sub(TicketPointer(nullptr));
    while(it != flights.end()){
        sub = (*it).getTicketBST();
        if(!sub.isEmpty()) {
            iteratorBST<TicketPointer> ticket = sub.begin();
            while(ticket != sub.end()){
                bst.insert((*ticket));
                ticket++;
            }
        }
        it++;
    }
    return bst;
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

AirportPointer Data::findAirport(const std::string& id) const{
    auto a = new Airport(id);
    AirportPointer find(a);
    return airports.find(find);
}
Staff* Data::findStaff(const Airport* a, std::string id){
    std::vector<Staff*> s = a->getStaff();
    std::vector<Staff*>::const_iterator it = s.begin();
    while(it != s.end()){
        if((*it)->getId() == id)
            return (*it);
        else it++;
    }
    return nullptr;
}
Voyage* Data::findVoyage(const std::string& id) const{
    auto v = new Voyage(id);
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
    auto* p = new Plane(id);
    PlanePointer find(p);
    find = planes.find(find);
    return find.getPointer();
}
Ticket* Data::findTicket(const std::string& id) const{
    auto t = new Ticket(id);
    iteratorBST<FlightPointer> it = flights.begin();
    BST<TicketPointer> bst(TicketPointer(nullptr));
    while(it != flights.end()){
        bst = (*it).getTicketBST();
        TicketPointer find(t);
        if(!bst.isEmpty())
            find = bst.find(find);
        if(find.getPointer() == nullptr)
            it++;
        else return find.getPointer();
    }
    return nullptr;
}
Client* Data::findClient(const std::string& id) const{
    auto c = new Client(id);
    ClientPointer find(c);
    find = clients.find(find);
    return find.getPointer();
}
Company* Data::findCompany(const std::string& id) const{
    auto c = new Company(id);
    CompanyPointer find(c);
    find = company.find(find);
    return find.getPointer();
}

FlightPointer Data::findFlight(const Plane* p) const{
    iteratorBST<FlightPointer> it = flights.begin();
    Flight* f;
    while(it != flights.end()){
        f = (*it).getPointer();
        if(f->getPlane() == p)
            return (*it);
        else it++;
    }
    return FlightPointer(nullptr);
}
/**-------LOAD-------*/
void Load::load(){
    try{
        LoadUser load(data);
        load.load();
    }
    catch(const DevLog& e){
        std::cout << "Error loading Users\n";
        throw DevLog(e.getError());
    }
}
/**---Load Airport---*/
void LoadAirport::loadPlane() {
    ifstream infile("./data/planes.txt");
    if (!infile.is_open())
        throw LoadVoyageFail();
    string line;
    std::getline(infile, line);
    if (line != "PLANE DATA")
        throw LoadVoyageFail();
    while (std::getline(infile, line)) {
        std::string plate;
        std::queue<std::string> fClass;
        std::queue<std::string> bClass;
        std::vector<bool> seats;
        int rows = 0, columns = 0,
                fPrice = 0, bPrice = 0, ePrice = 0,
                length, j = 0;
        for (int i = 0; i <= line.length(); i++) {
            if (line[i] == ' ') {
                if (plate.empty()) {
                    plate = line.substr(0, i);
                    j = i + 1;
                } else {
                    length = i - j;
                    if (rows == 0) {
                        rows = stoi(line.substr(j, length));
                        j = i + 1;
                    } else if (columns == 0) {
                        columns = stoi(line.substr(j, length));
                        j = i + 1;
                    } else if (fPrice == 0) {
                        fPrice = stoi(line.substr(j, length));
                        j = i + 1;
                    } else if (bPrice == 0) {
                        bPrice = stoi(line.substr(j, length));
                        j = i + 1;
                    }
                }
            }
            if (i == line.length()) {
                ePrice = stoi(line.substr(j));
            }
        }
        std::getline(infile, line);
        j = 0, length = 0;
        for (int i = 0; i <= line.length(); i++) {
            if (line[i] == ' ') {
                length = i - j;
                fClass.push(line.substr(j, length));
                j = i + 1;
            }
            if (i == line.length()) fClass.push(line.substr(j));
        }
        if (bPrice != 0) {
            std::getline(infile, line);
            for (int i = 0; i <= line.length(); i++) {
                if (line[i] == ' ') {
                    length = i - j;
                    bClass.push(line.substr(j, length));
                    j = i + 1;
                }
                if (i == line.length()) bClass.push(line.substr(j));
            }
        }
        std::getline(infile, line);
        for (int i = 0; i <= line.length(); i += 2) {
            seats.push_back(stoi(line.substr(i, 1)));
        }

        auto p = new Plane;
        if (plate.substr(0, 3) == "ARB") {
            p = new Airbus(fClass);
        } else if (plate.substr(0, 3) == "OTR") {
            if (bPrice == 0) {
                p = new Other(rows, columns, fClass);

            } else {
                p = new Other(rows, columns, fClass, bClass);
                p->setBClassPrice(bPrice);
            }
        }
        p->setFClassPrice(fPrice);
        p->setEClassPrice(ePrice);
        data->addPlane(p);
        plate.clear();
    }
    infile.close();
}

/**---Load Voyage---*/
void LoadVoyage::load(){
    try{
        loadFlight();
    }
    catch(const LoadFlightFail& e){
        throw DevLog(e.getError());
    }
    try{
        loadTicket();
    }
    catch(const LoadFlightFail& e){
        throw DevLog(e.getError());
    }
    try{
        loadVoyage();
    }
    catch(const LoadFlightFail& e){
        throw DevLog(e.getError());
    }
}
void LoadVoyage::loadFlight(){
    ifstream infile("./data/flight.txt");
    if (!infile.is_open())
        throw LoadVoyageFail();
    string line;
    std::getline(infile, line);
    if (line != "FLIGHT DATA")
        throw LoadVoyageFail();
    while (std::getline(infile, line)) {
        std::string voyage, airport, time,  plane;
        TimePlace* o = nullptr;
        TimePlace* d= nullptr;;
        Plane* p= nullptr;;
        int length = 0, j = 0;
        for(int i = 0; i <= line.length(); i++){
            if(line[i] == ' '){
                if(voyage.empty()){
                    voyage = line.substr(j, i);
                    j = i + 1;
                }
                else{
                    length = i - j;
                    if(airport.empty()){
                        airport = line.substr(j, length);
                        j = i + 1;
                        o->airport = data->findAirport(airport).getPointer();
                        airport.clear();
                    }
                    else if(time.empty()){
                        time= line.substr(j, length);
                        j = i + 1;
                        o->time = new Time(time);
                        time.clear();
                    }
                    else if(airport.empty()){
                        airport = line.substr(j, length);
                        j = i + 1;
                        d->airport = data->findAirport(airport).getPointer();
                    }
                    else if(time.empty()){
                        time= line.substr(j, length);
                        j = i + 1;
                        d->time = new Time(time);
                    }
                }
            }
            else if (i == line.length()){
                plane = line.substr(j);
                p = data->findPlane(plane);
            }
        }
        auto f = new Flight(o, d, p);
        AirportPointer aptr = data->findAirport(o->airport->getidCode());
        aptr.addFlight(f);
        aptr = data->findAirport(d->airport->getidCode());
        aptr.addFlight(f);
        data->removeAirport(o->airport->getidCode());
        data->addAirport(aptr);
        data->addFlight(f);
    }
    infile.close();
}
void LoadVoyage::loadVoyage(){
    ifstream infile("./data/voyage.txt");
    if (!infile.is_open())
        throw LoadVoyageFail();
    string line;
    std::getline(infile, line);
    if (line != "VOYAGE DATA")
        throw LoadVoyageFail();
    while (std::getline(infile, line)) {
        std::string id, flightId;
        int j = 0, length = 0;
        Voyage* v;
        Flight* f;
        for(int i = 0; i <= line.length(); i++){
            if(line[i] == ' '){
                if(id.empty()){
                    id = line.substr(0, i);
                    j = i+1;
                    v = new Voyage(id);
                }
                else{
                    length = i - j;
                    flightId = line.substr(j, length);
                    j = i+1;
                    f = data->findFlight(flightId).getPointer();
                    v->addFlight(f);
                }
            }
            if(i == line.length()){
                flightId = line.substr(j);
                f = data->findFlight(flightId).getPointer();
                v->addFlight(f);
            }
        }
        data->addVoyage(v);
    }
    infile.close();
}
void LoadVoyage::loadTicket(){
    ifstream infile("./data/tickets.txt");
    if (!infile.is_open())
        throw LoadVoyageFail();
    string line;
    std::getline(infile, line);
    if (line != "TICKET DATA")
        throw LoadVoyageFail();
    while (std::getline(infile, line)) {
        std::string flightId = line.substr(0, line.length()-1), name, seat;
        std::vector<int> lug;
        int j = 0, length = 0, load;
        FlightPointer fp = data->findFlight(flightId);
        std::getline(infile, line);
        while(line[0] != ')'){
            for(int i = 0; i <= line.length(); i++){
                if (line[i] == ' '){
                    if(name.empty()){
                        name = line.substr(0, i);
                        j = i + 1;
                    }
                    else{
                        length = i - j;
                        if(seat.empty()){
                            seat = line.substr(j, length);
                            j = i + 1;
                        }
                        else{
                            load = stoi(line.substr(j, length));
                            lug.push_back(load);
                            j = i+1;
                        }
                    }
                }
                else if(i == line.length()){
                    load = stoi(line.substr(j));
                    lug.push_back(load);
                }
            }
        }
        Seat* s = fp.getPointer()->getPlane()->bookSeat(seat);
        auto t = new Ticket(fp.getPointer(), s);
        t->setOwner(new Passenger(name));
        data->addTicket(fp, t);
        data->removeFlight(fp.getPointer()->getId());
        data->addFlight(fp);
    }
}

/**---Load User---*/
void LoadUser::loadClient(){
    std::ifstream infile("./data/clients.txt");
    if(!infile.is_open())
        throw LoadUserFail();
    std::string line;
    std::getline(infile, line);
    if(line != "CLIENT DATA")
        throw LoadUserFail();
    std::string name, pass, miles, psngr, ticket;
    std::vector<Ticket*> load;
    char type = '\0';
    while(std::getline(infile, line)){
        int length, j = 0;
        for (int i = 0; i <= line.length(); i++) {
            if (line[i] == ' ') {
                if (name.empty()) {
                    name = line.substr(j, i);
                    j = i + 1;
                } else {
                    length = i - j;
                    if (pass.empty()) {
                        pass = line.substr(j, length);
                        j = i + 1;
                    }
                    else if (type == '\0') {
                        type = line[i-1];
                        j = i+1;
                    }
                    else if (miles.empty()) {
                        miles = line.substr(j, length);
                        j = i + 1;
                    }
                }
            }
            if(i == line.length()) psngr = line.substr(j    );
        }
        j = 0;
        std::getline(infile, line);
        for(int i = 0; i <= line.length(); i++){
            if(line[i] == ' '){
                length = i - j;
                ticket = line.substr(j, i);
                j = i+1;
                Ticket* t = data->findTicket(ticket);
                load.push_back(t);
                ticket.clear();
            }
            else if (i == line.length()){
                ticket = line.substr(j);
                Ticket* t = data->findTicket(ticket);
                load.push_back(t);
            }
        }
        auto c = new Client(name, pass, type, stoi(miles), psngr);
        c->setTickets(load);
        load.clear();
        data->addClient(c);
        name.clear();
        pass.clear();
        miles.clear();
        psngr.clear();
        type = '\0';
    }
    infile.close();
}
void LoadUser::loadCompany(){
    ifstream infile("./data/company.txt");
    if(!infile.is_open())
        throw LoadUserFail();
    std::string line;
    std::getline(infile, line);
    if(line != "COMPANY DATA")
        throw LoadUserFail();
    std::string name, pass;
    char type;
    int length, j = 0;
    while(std::getline(infile, line)) {
        for (int i = 0; i <= line.length(); i++) {
            if (line[i] == ' ') {
                if (name.empty()) {
                    name = line.substr(j, i);
                    j = i + 1;
                } else {
                    length = i - j;
                    if (pass.empty()) {
                        pass = line.substr(j, length);
                        j = i + 1;
                    } else if (type == '\0') {
                        type = line[i - 1];
                        line = line.substr(i + 1);
                        break;
                    }
                }
            } else if (i == line.length()) type = line[i];
        }
        if (type == 'A') {
            auto *c = new Company(name, pass, type);
            data->addCompany(c);
        } else if (type == 'M') {
            Airport *a = data->findAirport(line).getPointer();
            auto *c = new Company(name, pass, type, a);
        } else if (type == 'B') {
            std::string airport, plane;
            for (int i = 0; i < line.length(); i++) {
                if (i == ' ') {
                    airport = line.substr(0, i);
                    plane = line.substr(i + 1);
                    break;
                }
            }
            Airport *a = data->findAirport(airport).getPointer();
            Plane *p = data->findPlane(plane);
            auto *c = new Company(name, pass, type, a, p);
            data->addCompany(c);
        } else if (type == 'S') {
            string airport;
            std::string id;
            for (int i = 0; i < line.length(); i++) {
                if (i == ' ') {
                    airport = line.substr(0, i);
                    id = stoi(line.substr(i + 1));
                    break;
                }
            }
            Airport *a = data->findAirport(airport).getPointer();
            Staff *s = data->findStaff(a, id);
            auto c = new Company(name, pass, type, a, nullptr, s);
            data->addCompany(c);
        } else throw DevLog("Corrupted company.txt data");
        name.clear();
        pass.clear();
        type = '\0';
    }
    infile.close();
}
void LoadUser::load(){
    try{
        loadClient();
    }
    catch(const LoadUserFail& e){
        throw DevLog(e.getError());
    }
    try{
        loadCompany();
    }
    catch(const LoadUserFail& e){
        throw DevLog(e.getError());
    }
}

/**-------SAVE-------*/
void Save::save() const{
    try{
        SaveAirport airport(data);
        airport.save();
    }
    catch(const DevLog& e){
        std::cout << "Error saving Airports\n";
        e.print();
    }
    try{
        SaveUser user(data);
        user.save();
    }
    catch(const DevLog& e){
        std::cout << "Error saving Users\n";
        e.print();
    }
    try{
        SaveVoyage voyage(data);
        voyage.save();
    }
    catch(const DevLog& e){
        std::cout << "Error saving Voyages\n";
        e.print();
    }

    std::cout << "\nPress enter to continue . . .";
    getchar();
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
                catch(const SaveVoyageFail& e){
                    throw DevLog(e.getError());
                }
                catch (const DevLog& e) {
                    throw DevLog(e.getError());
                }
                it++;
            }
        }
    }
}
void SaveAirport::saveAirport(const AirportPointer& aptr) {
    std::ofstream outfile("./data/airports.txt", ios::app);
    if (!outfile.is_open())
        throw SaveAirportFail("saveAirport()");
    Airport *a = aptr.getPointer();
    outfile << a->getidCode() << "(\n"
            << a->getName() << " "
            << a->getCountry() << " "
            << a->getCity() << "\n";
    outfile << '\n';
    outfile.close();
    try {
        saveTerminal(a);
    }
    catch(const SaveAirportFail& e){
        throw DevLog(e.getError());
    }
    try {
        saveTransport(a);
    }
    catch(const SaveAirportFail& e){
        throw DevLog(e.getError());
    }
    try {
        saveService(a);
    }
    catch(const SaveAirportFail& e){
        throw DevLog(e.getError());
    }
    try {
        saveStaff(a);
    }
    catch(const SaveAirportFail& e){
        throw DevLog(e.getError());
    }
}
void SaveAirport::saveTerminal(const Airport* a){
    std::vector<Terminal*> terminals = a->getTerminals();
    if(!terminals.empty()) {
        std::ofstream outfile("./data/airports.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveTerminal()");
        for (auto it : terminals) {
            outfile << it->getId() << " ";
            if (it->getPlane() == nullptr) outfile << "nullptr";
            else outfile << it->getPlane()->getPlate() << " ";
        }
        outfile << '\n';
        outfile.close();
    }
}
void SaveAirport::saveTransport(const Airport* a){
    std::vector<Transport*> transports = a->getTransport();
    if(!transports.empty()) {
        std::ofstream outfile("./data/airports.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveTransport()");
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
            throw SaveAirportFail("saveService()");
        for (auto it : services) {
            outfile << it->getPlane()->getPlate() << " "
                    << it->getCreated() << " "
                    << it->getResponsible()->getId()
                    << " " << it->getType();
        }
        outfile << '\n';
        std::vector<ServiceTicket*> completed = a->getCompleteServices();
        if(!completed.empty()) {
            for (auto it : completed) {
                outfile << it->getPlane()->getPlate() << " "
                        << it->getCreated() << " "
                        << it->getCompleted() << " "
                        << it->getResponsible()->getId() << " "
                        << it->getType();
            }
            outfile << "\n)\n";
            outfile.close();
        }
    }
}
void SaveAirport::saveStaff(const Airport* a){
    std::vector<Staff*> staff = a->getStaff();
    if(!staff.empty()) {
        std::ofstream outfile("./data/service.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveStaff()");
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
    catch(const SaveUserFail& e){
        throw DevLog(e.getError());
    }
    try{
        saveClient();
    }
    catch(const SaveUserFail& e){
        throw DevLog(e.getError());
    }
}
void SaveUser::saveCompany() const{
    ofstream outfile("./data/company.txt");
    if(!outfile.is_open())
        throw SaveUserFail("saveCompany()");
    outfile << "COMPANY DATA\n";
    outfile.close();
    try{
        saveAdmin();
    }
    catch(const SaveUserFail& e){
        throw DevLog(e.getError());
    }
    try{
        saveBoarding();
    }
    catch(const SaveUserFail& e){
        throw DevLog(e.getError());
    }
    try{
        saveService();
    }
    catch(const SaveUserFail& e){
        throw DevLog(e.getError());
    }
}
void SaveUser::saveAdmin() const{
    BST<CompanyPointer> bst = data->getCompanyBST();
    if(!bst.isEmpty()) {
        std::ofstream outfile("./data/company.txt", ios::app);
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
        if (!outfile.is_open()) {
            throw SaveUserFail("saveClient()");
        }
        outfile << "CLIENT DATA\n";
        outfile.close();
        iteratorBST<ClientPointer> it = bst.begin();
        while (it != bst.end()) {
            outfile.open("./data/client.txt");
            if (!outfile.is_open())
                throw SaveUserFail("saveClient()");
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
                outfile.close();
                try {
                    saveTickets(c);
                }
                catch (const SaveUserFail& e) {
                    throw DevLog(e.getError());
                }
            }
        }
        outfile.close();
    }
}
void SaveUser::saveTickets(Client* c) {
    std::vector<Ticket*> tickets = c->getTickets();
    std::ofstream outfile("./data/clients.txt", ios::app);
    if (!outfile.is_open())
        throw SaveUserFail("saveTickets()");
    if(!tickets.empty()) {
        for (auto it : tickets) {
            outfile << it->getID() << " ";
        }
        outfile << "\n";
    }
    else outfile << 0 << '\n';
    outfile.close();
}

/**-------Save Voyage-------*/
void SaveVoyage::save() const{
    try{
        saveVoyage();
    }
    catch (const SaveVoyageFail& e){
        throw DevLog(e.getError());
    }
    try{
        saveFlight();
    }
    catch(const SaveVoyageFail& e){
        throw DevLog(e.getError());
    }
    catch(const DevLog& e){
        throw DevLog(e.getError());
    }
    try{
        savePlane();
    }
    catch(const SaveVoyageFail& e){
        throw DevLog(e.getError());
    }
}
void SaveVoyage::saveVoyage() const {
    ofstream outfile("./data/voyages.txt");
    if (!outfile.is_open())
        throw SaveVoyageFail("saveVoyage()");
    outfile << "VOYAGE DATA\n";
    BST<VoyagePointer> bst = data->getVoyageBST();
    if(!bst.isEmpty()) {
        iteratorBST<VoyagePointer> it = bst.begin();
        Voyage *v;
        std::list<FlightPointer> f;
        while(it != bst.end()) {
            v = (*it).getPointer();
            if(v != nullptr) {
                outfile << v->getId();
                for (const auto& flight : f)
                    outfile << " " << flight.getPointer()->getId();
                outfile << '\n';
            }
            it++;
        }
    }
    outfile.close();
}
void SaveVoyage::saveFlight() const{
    BST<FlightPointer> bst = data->getFlightBST();
    ofstream outfile("./data/flight.txt");
    if(!outfile.is_open())
        throw SaveVoyageFail("saveFlight()");
    outfile << "FLIGHT DATA\n";
    outfile.close();
    Flight* f;
    if(!bst.isEmpty()){
        iteratorBST<FlightPointer> it = bst.begin();
        while(it != bst.end()) {
            outfile.open("./data/flight.txt", ios::app);
            if(!outfile.is_open())
                throw SaveVoyageFail("saveFlight()");
            f = (*it).getPointer();
            if(f != nullptr) {
                outfile << f->getVoyageId() << " "
                        << f->getOrigin()->airport->getidCode() << " "
                        << f->getOrigin()->time << " "
                        << f->getDestination()->airport->getidCode() << " "
                        << f->getDestination()->time << " "
                        << f->getPlane();
                outfile.close();
                try {
                    saveTicket((*it));
                }
                catch (const SaveVoyageFail& e) {
                    throw DevLog(e.getError());
                }
            }
            it++;
        }
    }
    outfile.close();
}
void SaveVoyage::saveTicket(const FlightPointer& fp) {
    BST<TicketPointer> bst = fp.getTicketBST();
    if (!bst.isEmpty()) {
        ofstream outfile("./data/tickets.txt");
        if (!outfile.is_open())
            throw SaveVoyageFail("saveTicket()");
        outfile << "TICKET DATA\n";
        iteratorBST<TicketPointer> it = bst.begin();
        Ticket *t;
        vector<Luggage *> l;
        while (it != bst.end()) {
            t = (*it).getPointer();
            if (t != nullptr) {
                outfile << fp.getPointer()->getId() << "(\n";
                l = t->getLuggage();
                outfile << t->getOwner()->getName() << " "
                        << t->getSeat()->getId() << "\n";
                for (auto lug : l) {
                    outfile << lug->getWeight();
                }
                outfile << "\n";
            }
            it++;
        }
        outfile << ")\n";
        outfile.close();
    }
}
void SaveVoyage::savePlane() const{
    BST<PlanePointer> bst = data->getPlaneBST();
    ofstream outfile("./data/planes.txt");
    if(!outfile.is_open())
        throw SaveVoyageFail("savePlane()");
    outfile << "PLANE DATA\n";
    if(!bst.isEmpty()){
        iteratorBST<PlanePointer> it = bst.begin();
        Plane* p;
        std::vector<Class*> c;
        std::vector<std::vector<Seat*>> s;
        int rows, columns;
        while(it != bst.end()) {
            p = (*it).getPointer();
            if(p != nullptr) {
                c = p->getClasses();
                s = p->getSeats();
                rows = p->getRows();
                columns = p->getColumns();
                outfile << p->getPlate() << " "
                        << rows << " "
                        << columns << " "
                        << c[0]->getPrice() << " ";
                if (c[1] == nullptr) outfile << -1 << " ";
                else outfile << c[1]->getPrice() << " ";
                outfile << c[2]->getPrice() << '\n';
                bool flag = false;
                for(int i = 0; i < rows; i++){
                    if(s[i][0]->getClass()->getType() == 'F') {
                        outfile << getRowLetter(i);
                    }
                    if(!flag && s[i][0]->getClass()->getType() == 'B') flag = true;
                }
                std::cout << '\n';
                if(flag) {
                    for (int i = 0; i < rows; i++) {
                        if (s[i][0]->getClass()->getType() == 'B')
                             outfile << getRowLetter(i);
                    }
                    std::cout << '\n';
                }
                outfile << '\n';
            }
            it++;
        }
    }
    outfile.close();
}