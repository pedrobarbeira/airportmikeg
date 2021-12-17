//Created by Pedro Barbeira
#include "data.h"

/**---Data---*/
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
    AirportPointer airport;
    iteratorBST<AirportPointer> aptr = airports.begin();
    iteratorBST<FlightPointer> flight;
    while(aptr != airports.end()){
        airport = (*aptr);
        std::vector<FlightPointer> load = airport.getFlights();
        ret.insert(ret.end(), load.begin(), load.end());
        aptr++;
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


/**---SaveAirport---*/
void SaveAirport::save() const {
    BST<AirportPointer> save = data->getAirportBST();
    iteratorBST<AirportPointer> it = save.begin();
    while (it != save.end()) {
        try {
            saveAirport((*it));
        }
        catch (DevLog e) {
            e.print();
        }
        it++;
    }
}

void SaveAirport::saveAirport(AirportPointer aptr) const {
    std::ofstream outfile("./data/airports.txt");
    if (!outfile.is_open())
        throw DevLog("SaveAirport::saveAirport() error opening outfile\n");
    Airport *a = aptr.getPointer();
    outfile << a->getidCode() << "(\n"
            << a->getName() << " " << a->getCountry() << " " << a->getCity() << "\n";
    std::vector<Flight *> saveFlights = aptr.getFlightsTo();
    for (auto flight : saveFlights) {
        outfile << flight->getID() << " ";
    }
    std::cout << '\n';
    saveFlights = aptr.getFlightsTo();
    for (auto flight : saveFlights) {
        outfile << flight->getID() << " ";
    }
    std::cout << '\n';
    outfile.close();
    try {
        saveTerminal(a);
    }
    catch(DevLog e){
        e.print();
    }

}

void SaveAirport::saveTerminal(Airport* a) const{
    std::ofstream outfile("./data/airports.txt", ios::app);
    if(!outfile.is_open())
        throw DevLog("SaveAirport::saveTerminal() error opening outfile\n");
    for(auto it : a->getTerminals()){
        outfile << it->getId() << " ";
        if(it->getPlane() == nullptr) outfile << "nullptr";
        else outfile << it->getPlane()->getPlate() << " ";
    }
    std::cout << '\n';
}

void SaveAirport::saveTransport(Airport* a) const{
}

void SaveAirport::saveService(Airport* a) const{}

void SaveAirport::saveStaff(Airport* a) const{
    std::ofstream outfile("./data/service.txt");
    if(!outfile.is_open())
        throw DevLog("SaveAirport::saveStaff error opening outfile\n");

}


/**---SaveUser---*/
void SaveUser::saveAdmin() const{
    std::ofstream outfile("./data/company.txt");
    if(!outfile.is_open())
        throw DevLog("SaveUser::SaveAdmin error opening outfile\n");
    iteratorBST<CompanyPointer> it = data->company.begin();
    while(it != data->company.end()){
        if((*it).getPointer()->getType() == 'A')
            outfile << (*it).getPointer()->getUser() << " "
                    << (*it).getPointer()->getPassword() << " "
                    << (*it).getPointer()->getType() << '\n';
        it++;
    }
}