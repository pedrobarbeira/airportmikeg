//Created by Pedro Barbeira
#include "data.h"

/**-------Data-------*/
bool Data::addFlight(Flight* f){
    FlightPointer fptr(f);
    bool flag = flights.insert(fptr);
    AirportPointer find = airports.find(AirportPointer((*f).getOrigin()->airport));
    if(find.getPointer() == nullptr){
        std::cout << "Error: origin airport not found\n"
                  << "Press enter to continue . . . ";
        int c = getchar();
        return false;
    }
    else{
        AirportPointer& addIn = find;
        airports.remove(find); //nao percebo porque e necessario remover airport da data
        flag &= addIn.addFlight(f) && airports.insert(addIn);
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
    Voyage* v = findVoyage(f);
    if(v == nullptr){
        v = new Voyage(f);
        f->setVoyage(v->getId());
        addVoyage(v);
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
    if(!flights.isEmpty()) {
        iteratorBST<FlightPointer> it = flights.begin();
        BST<TicketPointer> sub(TicketPointer(nullptr));
        while (it != flights.end()) {
            sub = (*it).getTicketBST();
            if (!sub.isEmpty()) {
                iteratorBST<TicketPointer> ticket = sub.begin();
                while (ticket != sub.end()) {
                    bst.insert((*ticket));
                    ticket++;
                }
            }
            it++;
        }
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
    if(!airports.isEmpty()) {
        find = airports.find(find);
        return find;
    }
    else return AirportPointer(nullptr);
}
Staff* Data::findStaff(const Airport* a, const std::string& id){
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
    if(!voyages.isEmpty()) {
        find = voyages.find(find);
        return find.getPointer();
    }
    else return nullptr;
}
Voyage* Data::findVoyage(const Flight *f) const {
    iteratorBST<VoyagePointer> it = voyages.begin();
    Voyage* v;
    while(it != voyages.end()) {
        v = (*it).getPointer();
        if (v->getRoute().size() == 1)
            if (v->getRoute().front().getPointer() == f)
                return v;
        it++;
    }
    return nullptr;
}
FlightPointer Data::findFlight(const std::string& id) const{
    FlightPointer ret(nullptr);
    if(!flights.isEmpty()) {
        iteratorBST<AirportPointer> it = airports.begin();
        while (it != airports.end()) {
            FlightPointer find = (*it).find(id);
            if ((*it).find(id).getPointer() != nullptr) {
                ret = find;
                break;
            }
            it++;
        }
    }
    return ret;
}
FlightPointer Data::findFlight(const Plane* p) const{
    if(!flights.isEmpty()) {
        iteratorBST<FlightPointer> it = flights.begin();
        Flight *f;
        while (it != flights.end()) {
            f = (*it).getPointer();
            if (f->getPlane() == p)
                return (*it);
            else it++;
        }
    }
    return FlightPointer(nullptr);
}
Plane* Data::findPlane(const std::string& id) const{
    auto* p = new Plane(id);
    PlanePointer find(p);
    if(!planes.isEmpty()) {
        find = planes.find(find);
        return find.getPointer();
    }
    return nullptr;
}
Ticket* Data::findTicket(const std::string& id) const{
    auto t = new Ticket(id);
    if(!flights.isEmpty()) {
        iteratorBST<FlightPointer> it = flights.begin();
        BST<TicketPointer> bst(TicketPointer(nullptr));
        while (it != flights.end()) {
            bst = (*it).getTicketBST();
            TicketPointer find(t);
            if (!bst.isEmpty())
                find = bst.find(find);
            if (find.getPointer() == nullptr)
                it++;
            else return find.getPointer();
        }
    }
    return nullptr;
}
Client* Data::findClient(const std::string& id) const{
    auto c = new Client(id);
    ClientPointer find(c);
    if(!clients.isEmpty()) {
        find = clients.find(find);
        return find.getPointer();
    }
    else return nullptr;
}
Company* Data::findCompany(const std::string& id) const{
    auto c = new Company(id);
    CompanyPointer find(c);
    if(!company.isEmpty()) {
        find = company.find(find);
        return find.getPointer();
    }
    else return nullptr;
}


/**-------LOAD-------*/
void Load::load(){
    try{
        LoadAirport load(data);
        load.load();
    }
    catch(const LoadAirportFail& e){
        std::cout << "Error loading Airport\n";
        throw DevLog(e.getError());
    }
    catch(const DevLog& e){
        std::cout << "Error loading Airport\n";
        throw DevLog(e.getError());
    }
    try{
        LoadVoyage load(data);
        load.load();
    }
    catch(const DevLog& e){
        std::cout << "Error loading Voyages\n";
        throw DevLog(e.getError());
    }
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
void LoadAirport::load(){
    try{
        loadPlane();
    }
    catch (LoadAirportFail e){
        std::cout << "Error loading Planes\n";
        throw DevLog(e.getError());
    }
    try{
        loadAirport();
    }catch (LoadAirportFail e){
        std::cout << "Error loading Airports\n";
        throw DevLog(e.getError());
    }
    catch (DevLog e){
        throw DevLog(e.getError());
    }
}
void LoadAirport::loadPlane() {
    ifstream infile("./data/planes.txt");
    if (!infile.is_open())
        throw LoadAirportFail();
    string line;
    std::getline(infile, line);
    if (line != "PLANE DATA")
        throw LoadVoyageFail();
    Plane* p = new Plane;
    std::string plate;
    std::queue<std::string> fClass;
    std::queue<std::string> bClass;
    while (std::getline(infile, line)) {
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
        }
        if (bPrice != -1) {
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
        for(int i = 0; i < fClass.size(); i++)
            fClass.pop();
        for(int i = 0; i < bClass.size(); i++)
            bClass.pop();
    }
    infile.close();
}
void LoadAirport::loadAirport() {
    ifstream infile("./data/airports.txt");
    if (!infile.is_open())
        throw LoadAirportFail();
    std::string line;
    std::getline(infile, line);
    if (line != "AIRPORT DATA")
        throw LoadAirportFail();
    std::string id, name, country, city, terminal, plane, transport, service, completed, staff;
    std::vector<std::string> terminalData;
    Airport *a;
    while (std::getline(infile, line)) {
        id = line.substr(0, line.length() - 1);
        std::getline(infile, line);
        int length, j = line.length();
        for (int i = line.length(); i >= 0; i--) {
            if (line[i] == ' ') {
                if (city.empty()) {
                    length = j - i;
                    city = line.substr(i + 1, length);
                    j = i - 1;
                } else if (country.empty()) {
                    length = j - i;
                    country = line.substr(i + 1, length);
                    j = i - 1;
                } else name = line.substr(0, j + 1);
            }
            if(!country.empty()) name = line.substr(0, j+1);
        }
        a = new Airport(id, name, country, city);
        std::getline(infile, line);

        j = 0;
        for (int k = 0; k <= line.length(); k++) {
            if (line[k] == ' ') {
                if (terminal.empty()) {
                    length = k - j;
                    terminalData.push_back(line.substr(j, length));
                    j = k + 1;
                }
            }
            else if (k == line.length())
                terminalData.push_back(line.substr(j));
        }
        try {
            loadTerminal(a, terminalData);
        }
        catch (const LoadAirportFail &e) {
            std::cout << "Error loading Terminals\n";
            throw DevLog(e.getError());
        }
        getline(infile, transport);
        getline(infile, service);
        getline(infile, completed);
        getline(infile, staff);
        getline(infile, line);
        try {
            loadService(a, service, completed);
        }
        catch (const LoadAirportFail &e) {
            std::cout << "Error loading Services\n";
            throw DevLog(e.getError());
        }
        try {
            loadTransport(a, transport);
        }
        catch (const LoadAirportFail &e) {
            std::cout << "Error loading Transports\n";
            throw DevLog(e.getError());
        }
        try{
            loadStaff(a, staff);
        }
        catch(const LoadAirportFail& e){
            throw DevLog(e.getError());
        }
        staff.clear();
        terminalData.clear();
        id.clear();
        name.clear();
        city.clear();
        country.clear();
        terminal.clear();
        plane.clear();
        service.clear();
        transport.clear();
        completed.clear();
        data->addAirport(a);
    }
    infile.close();
}
void LoadAirport::loadTerminal(Airport* a, std::vector<std::string>& tData){
    std::vector<Terminal*> v = a->getTerminals();
    int i = 0, j = 1;
    for(auto it : v){
        if(it->getId() == tData[i]){
            if(tData[j] != "nullptr"){
                Plane* p = data->findPlane(tData[j]);
                it->setPlane(p);
            }
            else it->setPlane(nullptr);
        }
        if(j > tData.size() -1)
            throw LoadAirportFail();
        i+=2;
        j+=2;
    }
    tData.clear();
}
void LoadAirport::loadStaff(Airport* a, const std::string& line){
    std::string id, name, phone;
    int length, j = 0;
    Staff* s;
    for(int i = 0; i <= line.length(); i++){
        if(line[i] == ' '){
            if(id.empty()){
                id = line.substr(j, i);
                j = i+1;
            }
            else{
                length = i - j;
                if(name.empty()){
                    name = line.substr(j, length);
                    j = i +1;
                }
                else if(phone.empty()){
                    phone = line.substr(j, length);
                    j = i + 1;
                }
            }
        }
        else if (i == line.length()){
            phone = line.substr(j);
        }
        if(!id.empty() && ! name.empty() && ! phone.empty()){
            s = a->findStaff(id);
            s->setName(name);
            s->setPhone(stoi(phone));
            id.clear();
            name.clear();
            phone.clear();
            s = nullptr;
        }
    }
}
void LoadAirport::loadService(Airport* a, const std::string& l, const std::string& l2) {
    Plane *p;
    Time *t1;
    Staff *s = nullptr;
    ServiceTicket *load;
    std::string plate, time, id;
    char type = '\0';
    int length;
    int j = 0;
    if(!l.empty()) {
        for (int i = 0; i <= l.length(); i++) {
            if (l[i] == ' ') {
                length = i - j;
                if (plate.empty()) {
                    plate = l.substr(j, length);
                    p = data->findPlane(plate);
                    j = i + 1;
                } else {
                    if (time.empty()) {
                        time = l.substr(j, TIME_STRING_LENGTH + 1);
                        t1 = new Time(time);
                        j += TIME_STRING_LENGTH + 1;
                        i = j - 1;
                    } else if (id.empty()) {
                        id = l.substr(j, length);
                        if (!a->getStaff().empty()) {
                            s = a->findStaff(id);
                            if (s == nullptr) {
                                s = new Staff(id);
                                s->setId(id);
                                s->setName("");
                                a->addStaff(s);
                            }
                        } else {
                            s = new Staff(id);
                            s->setId(id);
                            s->setName("");
                            a->addStaff(s);
                        }
                        j = i + 1;
                    } else if (type == '\0') {
                        type = l[i - 1];
                        j = i + 1;
                    }
                }
            }
            if (type != '\0') {
                switch (type) {
                    case 'c' :
                        load = new Cleaning(p, t1, s);
                        break;
                    case 'm' :
                        std::cout << "Added maintenance on " << a->getidCode() << '\n';
                        load = new Maintenance(p, t1, s);
                        break;
                    default :
                        throw LoadAirportFail();
                }
                a->addService(load);
                plate.clear();
                time.clear();
                id.clear();
                type = '\0';
                s = nullptr;
                load = nullptr;
            }
        }
    }
    if(!l2.empty()) {
        Time *t2 = new Time;
        j = 0;
        for (int i = 0; i <= l2.length(); i++) {
            if (l2[i] == ' ') {
                length = i - j;
                if (plate.empty()) {
                    plate = l2.substr(j, length);
                    p = data->findPlane(plate);
                    j = i + 1;
                } else {
                    if (time.empty()) {
                        time = l2.substr(j, TIME_STRING_LENGTH);
                        if (t2 == nullptr) {
                            t2 = new Time(time);
                        } else {
                            t1 = new Time(time);
                            t2 = nullptr;
                            time.clear();
                        }
                        j += TIME_STRING_LENGTH + 1;
                        i = j - 1;
                    } else if (id.empty()) {
                        id = l2.substr(j, length);
                        s = a->findStaff(id);
                        j = i + 1;
                    } else if (type == '\0') {
                        type = l2[i - 1];
                        j = i + 1;
                    }
                }
            }
            if (type != '\0') {
                switch (type) {
                    case 'c' :
                        load = new Cleaning(p, t1, t2, s);
                        break;
                    case 'm' :
                        load = new Maintenance(p, t1, t2, s);
                        break;
                    default :
                        throw LoadAirportFail();
                }
                a->addCompletedService(load);
                plate.clear();
                time.clear();
                id.clear();
                type = '\0';
                s = nullptr;
                load = nullptr;
                p = nullptr;
            }
        }
    }
}
void LoadAirport::loadTransport(Airport* a, std::string& l){
    Transport* t;
    if(!l.empty()) {
        Time* t1 = nullptr;
        char c = '\0';
        int d = -1, length, j = 0;
        std::string time;
        for (int i = 0; i <= l.length(); i++) {
            if (l[i] == ' '){
                length = i - j;
                if(c == '\0') {
                    c = l[i - 1];
                    j = i + 1;
                }
                else if (d == -1){
                    d = stoi(l.substr(j, length));
                    j = i+1;
                }
                else if (time.empty()){
                    time = l.substr(j, TIME_STRING_LENGTH);
                    t1 = new Time(time);
                    j += TIME_STRING_LENGTH + 1;
                    i = j-1;
                }
            }
            if(c != '\0' && d != -1 && t1 != nullptr){
                t = new Transport(c, d, t1);
                a->addTransport(t);
                c = '\0';
                d = -1;
                t1 = nullptr;
                time.clear();
                t = nullptr;
            }
        }
    }
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
    catch(const LoadVoyageFail& e){
        throw DevLog(e.getError());
    }
}
void LoadVoyage::loadFlight(){
    ifstream infile("./data/flights.txt");
    if (!infile.is_open())
        throw LoadVoyageFail();
    string line;
    std::getline(infile, line);
    if (line != "FLIGHT DATA")
        throw LoadVoyageFail();
    std::string voyage, airport, time,  plane;
    TimePlace* o = new TimePlace(nullptr, nullptr);
    TimePlace* d= new TimePlace(nullptr, nullptr);
    Plane* p= nullptr;;
    while (std::getline(infile, line)) {
        int length = 0, j = 0;
        for(int i = 0; i <= line.length(); i++){
            if(line[i] == ' '){
                if(voyage.empty()){
                    voyage = line.substr(j, i);
                    j = i + 1;
                }
                else{
                    length = i - j;
                    if(o->airport == nullptr){
                        airport = line.substr(j, length);
                        j = i + 1;
                        AirportPointer find = data->findAirport(airport);
                        o->airport = find.getPointer();
                        airport.clear();
                    }
                    else if(o->time == nullptr){
                        time= line.substr(j, TIME_STRING_LENGTH);
                        j += TIME_STRING_LENGTH + 1;
                        i = j - 1;
                        o->time = new Time(time);
                        time.clear();
                    }
                    else if(d->airport == nullptr){
                        airport = line.substr(j, length);
                        j = i + 1;
                        AirportPointer find = data->findAirport(airport);
                        d->airport = find.getPointer();
                    }
                    else if(d->time == nullptr){
                        time= line.substr(j, TIME_STRING_LENGTH);
                        j += TIME_STRING_LENGTH + 1;
                        i = j - 1;
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
        airport = o->airport->getidCode();
        data->addFlight(f);
        voyage.clear();
        airport.clear();
        time.clear();
        plane.clear();
        o = new TimePlace(nullptr, nullptr);
        d= new TimePlace(nullptr, nullptr);
        p = nullptr;
    }
    infile.close();
}
void LoadVoyage::loadVoyage(){
    ifstream infile("./data/voyages.txt");
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
    catch(const DevLog& e){
        throw DevLog(e.getError());
    }
}
void LoadUser::loadClient(){
    std::ifstream infile("./data/client.txt");
    if(!infile.is_open())
        throw LoadUserFail();
    std::string line;
    std::getline(infile, line);
    if(line != "CLIENT DATA")
        throw LoadUserFail();
    std::string name, pass, date, miles, psngr, ticket;
    std::vector<Ticket*> load;
    Date* reg;
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
                    else if(date.empty()){
                        date = line.substr(j, length);
                        reg = new Date(date);
                        j = i+1;
                    }
                    else if (miles.empty()) {
                        miles = line.substr(j, length);
                        j = i + 1;
                    }
                }
            }
            if(i == line.length()) psngr = line.substr(j);
        }
        j = 0;
        std::getline(infile, line);
        Ticket* t = nullptr;
        if(line[0] != 0) {
            for (int i = 0; i <= line.length(); i++) {
                if (line[i] == ' ') {
                    length = i - j;
                    ticket = line.substr(j, i);
                    j = i + 1;
                    if (!data->getTicketBST().isEmpty())
                        t = data->findTicket(ticket);
                    if (t != nullptr) {
                        load.push_back(t);
                        ticket.clear();
                    }
                } else if (i == line.length()) {
                    ticket = line.substr(j);
                    if (!data->getTicketBST().isEmpty())
                        t = data->findTicket(ticket);
                    if (t != nullptr) load.push_back(t);
                }
            }
        }
        auto c = new Client(name, pass, type, reg, stoi(miles), psngr);
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
    Company *c;
    char type;
    while(std::getline(infile, line)) {
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
                    } else if (type == '\0') {
                        type = line[i - 1];
                        line = line.substr(i + 1);
                        break;
                    }
                }
            } else if (i == line.length() - 1) type = line[i];
        }
        if (type == 'A') {
            c = new Company(name, pass, type);
            CompanyPointer cptr(c);
            data->company.insert(cptr);
        } else if (type == 'M') {
            Airport *a = data->findAirport(line).getPointer();
            c = new Company(name, pass, type, a);
        }else if (type == 'B') {
            std::string airport, plane;
            for (int i = 0; i < line.length(); i++) {
                if (i == ' ') {
                    airport = line.substr(0, i);
                    plane = line.substr(i + 1);
                    break;
                }
            }
            Airport* a = data->findAirport(airport).getPointer();
            Plane* p = data->findPlane(plane);
            c = new Company(name, pass, type, a, p);
            data->addCompany(c);
        } else if (type == 'S') {
            string airport;
            std::string id;
            for (int i = 0; i < line.length(); i++) {
                if (i == ' ') {
                    airport = line.substr(0, i);
                    id = line.substr(i + 1);
                    break;
                }
            }
            Airport *a = data->findAirport(airport).getPointer();
            Staff *s = data->findStaff(a, id);
            c = new Company(name, pass, type, a, nullptr, s);
            data->addCompany(c);
        } else throw DevLog("Corrupted company.txt data");
        name.clear();
        pass.clear();
        type = '\0';
        j = 0;
        length = 0;
    }
    infile.close();
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
        outfile << "AIRPORT DATA";
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
                catch(const SaveAirportFail& e){
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
    outfile << '\n' << a->getidCode() << "(\n"
            << a->getName() << " "
            << a->getCountry() << " "
            << a->getCity() << "\n";
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
            if (it->getPlane() == nullptr) outfile << "nullptr" << " ";
            else outfile << it->getPlane()->getPlate() << " ";
        }
        outfile << '\n';
        outfile.close();
    }
}
void SaveAirport::saveTransport(const Airport* a){
    std::vector<Transport*> transports = a->getTransport();
    std::ofstream outfile("./data/airports.txt", ios::app);
    if (!outfile.is_open())
        throw SaveAirportFail("saveTransport()");
    if(!transports.empty()) {
        for (auto it : transports) {
            outfile << it->getType() << " "
                    << it->getDistance() << " ";
            it->getTime()->print(outfile);
            outfile << " ";
        }
    }
    outfile << '\n';
    outfile.close();
}
void SaveAirport::saveService(Airport* a){
    std::vector<ServiceTicket*> services = a->getServices();
    std::ofstream outfile("./data/airports.txt", ios::app);
    if (!outfile.is_open())
        throw SaveAirportFail("saveService()");
    if(!services.empty()) {
        for (auto it : services) {
            outfile << it->getPlane()->getPlate() << " ";
            it->getCreated()->print(outfile);
            outfile << " "
                    << it->getResponsible()->getId() << " "
                    << it->getType() << " ";
        }
        std::vector<ServiceTicket*> completed = a->getCompleteServices();
        outfile << '\n';
        if(!completed.empty()) {
            for (auto it : completed) {
                outfile << it->getPlane()->getPlate() << " ";
                it->getCreated()->print(outfile);
                outfile << " ";
                it->getCompleted()->print(outfile);
                outfile << " "
                        << it->getResponsible()->getId() << " "
                        << it->getType() << " ";
            }
        }
    }
    else outfile << '\n';
    outfile << "\n";
    outfile.close();
}
void SaveAirport::saveStaff(const Airport* a){
    std::vector<Staff*> staff = a->getStaff();
    if(!staff.empty()) {
        std::ofstream outfile("./data/airports.txt", ios::app);
        if (!outfile.is_open())
            throw SaveAirportFail("saveStaff()");
        for (auto it : staff) {
            outfile << it->getId() << " "
                    << it->getName() << " "
                    << it->getPhone() << ' ';
        }
        outfile << "\n)";
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
                            << c;
                if(c == 'M') outfile << " " << (*it).getPointer()->getAirport()->getidCode();
                outfile << '\n';
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
            outfile.open("./data/client.txt", ios::app);
            if (!outfile.is_open())
                throw SaveUserFail("saveClient()");
            if((*it).getPointer() != nullptr) {
                Client *c = (*it).getPointer();
                outfile << c->getUser() << " "
                        << c->getPassword() << " "
                        << c->getType() << " ";
                c->getDate()->print(outfile);
                outfile << " " << c->getMiles() << " ";
                if(c->getPassenger().empty())
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
            it++;
        }
        outfile.close();
    }
}
void SaveUser::saveTickets(Client* c) {
    std::vector<Ticket*> tickets = c->getTickets();
    std::ofstream outfile("./data/client.txt", ios::app);
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
            f = v->getRoute();
            if(v != nullptr) {
                outfile << v->getId();
                Flight* temp;
                for (const auto& flight : f) {
                    temp = flight.getPointer();
                    outfile << " " << temp->getId();
                }
                outfile << '\n';
            }
            it++;
        }
    }
    outfile.close();
}
void SaveVoyage::saveFlight() const{
    BST<FlightPointer> bst = data->getFlightBST();
    ofstream outfile("./data/flights.txt");
    if(!outfile.is_open())
        throw SaveVoyageFail("saveFlight()");
    outfile << "FLIGHT DATA\n";
    outfile.close();
    Flight* f;
    if(!bst.isEmpty()){
        iteratorBST<FlightPointer> it = bst.begin();
        while(it != bst.end()) {
            outfile.open("./data/flights.txt", ios::app);
            if(!outfile.is_open())
                throw SaveVoyageFail("saveFlight()");
            f = (*it).getPointer();
            if(f != nullptr) {
                outfile << f->getVoyageId() << " "
                        << f->getId() << " "
                        << f->getOrigin()->airport->getidCode() << " ";
                f->getOrigin()->time->print(outfile);
                outfile << " "<< f->getDestination()->airport->getidCode() << " ";
                f->getDestination()->time->print(outfile);
                outfile << " " << f->getPlane()->getPlate() << '\n';
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
                        outfile << getRowLetter(i) << " ";
                    }
                    if(!flag && s[i][0]->getClass()->getType() == 'B') flag = true;
                }
                std::cout << '\n';
                if(flag) {
                    for (int i = 0; i < rows; i++) {
                        if (s[i][0]->getClass()->getType() == 'B')
                             outfile << getRowLetter(i) << " ";
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