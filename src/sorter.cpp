//Created by Pedro Barbeira (up201303693)
#include "sorter.h"

/**---Plane Sorter---*/
bool PlaneSorter::plateAscending(const Plane* p1, const Plane* p2){
    return *p1 < *p2;
}
bool PlaneSorter::plateDescending(const Plane* p1, const Plane* p2) {
    return *p2 < *p1;
}
bool PlaneSorter::fPriceAscending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->getClasses()[0]->getPrice();
    int comp2 = p2->getClasses()[0]->getPrice();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *p1 < *p2;
}
bool PlaneSorter::fPriceDescending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->getClasses()[0]->getPrice();
    int comp2 = p2->getClasses()[0]->getPrice();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *p2 < *p1;
}
bool PlaneSorter::bPriceAscending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->getClasses()[1]->getPrice();
    int comp2 = p2->getClasses()[1]->getPrice();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *p1 < *p2;
}
bool PlaneSorter::bPriceDescending(const Plane* p1, const Plane* p2) {
    int comp1= p1->getClasses()[1]->getPrice();
    int comp2 = p2->getClasses()[1]->getPrice();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *p2 < *p1;
}
bool PlaneSorter::ePriceAscending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->getClasses()[2]->getPrice();
    int comp2 = p2->getClasses()[2]->getPrice();
    if(comp1!= comp2)
        return comp1 < comp2;
    else return *p1 < *p2;
}
bool PlaneSorter::ePriceDescending(const Plane* p1, const Plane* p2) {
    int comp1= p1->getClasses()[2]->getPrice();
    int comp2 = p2->getClasses()[2]->getPrice();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *p2 < *p1;
}
bool PlaneSorter::freeAscending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->freeSeatNum();
    int comp2 = p2 ->freeSeatNum();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *p1 < *p2;
}
bool PlaneSorter::freeDescending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->freeSeatNum();
    int comp2 = p2 ->freeSeatNum();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *p2 < *p1;
}
bool PlaneSorter::seatAscending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->getSeats().size();
    int comp2 = p2->getSeats().size();
    if(comp1!= comp2 )
        return comp1 < comp2 ;
    else return *p1 < *p2;
}
bool PlaneSorter::seatDescending(const Plane* p1, const Plane* p2) {
    int comp1 = p1->getSeats().size();
    int comp2 = p2->getSeats().size();
    if(comp1!= comp2 )
        return comp2 < comp1;
    else return *p2 < *p1;
}
void PlaneSorter::operator()(std::vector<Plane*>& data, char o = '\0', bool asc = true) {
    switch(o) {
        case '0' :
            if(asc) sort(data.begin(), data.end(), plateAscending);
            else sort(data.begin(), data.end(), plateDescending);
            break;
        case '1' :
            if(asc) sort(data.begin(), data.end(), fPriceAscending);
            else sort(data.begin(), data.end(), fPriceDescending);
            break;
        case '2' :
            if(asc) sort(data.begin(), data.end(), bPriceAscending);
            else sort(data.begin(), data.end(), bPriceDescending);
            break;
        case '3' :
            if(asc) sort(data.begin(), data.end(), ePriceAscending);
            else sort(data.begin(), data.end(), ePriceDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), seatAscending);
            else sort(data.begin(), data.end(), seatDescending);
            break;
        case '5' :
            if(asc) sort(data.begin(), data.end(), freeAscending);
            else sort(data.begin(), data.end(), freeDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Flight Sorter---*/
bool FlightSorter::idAscending(const FlightPointer& f1, const FlightPointer& f2) {
    return *f1 < *f2;
}
bool FlightSorter::idDescending(const FlightPointer& f1, const FlightPointer& f2){
    return *f2 < *f1;
}
bool FlightSorter::originAirportAscending(const FlightPointer& f1, const FlightPointer& f2){
    Airport* comp1 = f1.getPointer()->getOrigin()->airport;
    Airport* comp2 = f2.getPointer()->getOrigin()->airport;
    if(*comp1 != *comp2)
        return *comp1 < *comp2;
    else return *f1 < *f2;
}
bool FlightSorter::originAirportDescending(const FlightPointer& f1, const FlightPointer& f2){
    Airport* comp1 = f1.getPointer()->getOrigin()->airport;
    Airport* comp2 = f2.getPointer()->getOrigin()->airport;
    if(*comp1 != *comp2)
        return *comp2 < *comp1;
    else return *f2 < *f1;
}
bool FlightSorter::originDateAscending(const FlightPointer& f1, const FlightPointer& f2){
    Date* comp1 = f1.getPointer()->getOrigin()->time;
    Date* comp2 = f2.getPointer()->getOrigin()->time;
    if(*comp1 != *comp2)
        return *comp1 < *comp2;
    else return *f1 < *f2;
}
bool FlightSorter::originDateDescending(const FlightPointer& f1, const FlightPointer& f2){
    Date* comp1 = f1.getPointer()->getOrigin()->time;
    Date* comp2 = f2.getPointer()->getOrigin()->time;
    if(*comp1 != *comp2)
        return *comp2 < *comp1;
    else return *f2 < *f1;
}
bool FlightSorter::destinationAirportAscending(const FlightPointer& f1, const FlightPointer& f2){
    Airport* comp1 = f1.getPointer()->getDestination()->airport;
    Airport* comp2 = f2.getPointer()->getDestination()->airport;
    if(*comp1 != *comp2)
        return *comp1 < *comp2;
    else return *f1 < *f2;
}
bool FlightSorter::destinationAirportDescending(const FlightPointer& f1, const FlightPointer& f2){
    Airport* comp1 = f1.getPointer()->getDestination()->airport;
    Airport* comp2 = f2.getPointer()->getDestination()->airport;
    if(*comp1 != *comp2)
        return *comp2 < *comp1;
    else return *f2 < *f1;
}
bool FlightSorter::destinationDateAscending(const FlightPointer& f1, const FlightPointer& f2){
    Date* comp1 = f1.getPointer()->getDestination()->time;
    Date* comp2 = f2.getPointer()->getDestination()->time;
    if(*comp1 != *comp2)
        return *comp1 < *comp2;
    else return *f1 < *f2;
}
bool FlightSorter::destinationDateDescending(const FlightPointer& f1, const FlightPointer& f2){
    Date* comp1 = f1.getPointer()->getDestination()->time;
    Date* comp2 = f2.getPointer()->getDestination()->time;
    if(*comp1 != *comp2)
        return *comp2 < *comp1;
    else return *f2 < *f1;
}
bool FlightSorter::planeAscending(const FlightPointer& f1, const FlightPointer& f2){
    Plane* comp1 = f1.getPointer()->getPlane();
    Plane* comp2 = f2.getPointer()->getPlane();
    if(*comp1 != *comp2)
        return comp1 < comp2;
    else return *f1 < *f2;
}
bool FlightSorter::planeDescending(const FlightPointer& f1, const FlightPointer& f2){
    Plane* comp1 = f1.getPointer()->getPlane();
    Plane* comp2 = f2.getPointer()->getPlane();
    if(*comp1 != *comp2)
        return *comp2 < *comp1;
    else return *f2 < *f1;
}
bool FlightSorter::ticketAscending(const FlightPointer& f1, const FlightPointer& f2){
    int comp1 = f1.getTickets().size();
    int comp2 = f2.getTickets().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *f1 < *f2;
}
bool FlightSorter::ticketDescending(const FlightPointer& f1, const FlightPointer& f2){
    int comp1 = f1.getTickets().size();
    int comp2 = f2.getTickets().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *f2 < *f1;
}
void FlightSorter::operator()(std::vector<FlightPointer>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), idAscending);
            else sort(data.begin(), data.end(), idDescending);
            break;
        case '1':
            if(asc) sort(data.begin(), data.end(), originAirportAscending);
            else sort(data.begin(), data.end(), originAirportDescending);
            break;
        case '2':
            if(asc) sort(data.begin(), data.end(), destinationAirportAscending);
            else sort(data.begin(), data.end(), destinationAirportDescending);
            break;
        case '3':
            if(asc) sort(data.begin(), data.end(), originDateAscending);
            else sort(data.begin(), data.end(), originDateDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), destinationDateAscending);
            else sort(data.begin(), data.end(), destinationDateDescending);
            break;
        case '5':
            if(asc) sort(data.begin(), data.end(), planeAscending);
            else sort(data.begin(), data.end(), planeDescending);
            break;
        case '6':
            if(asc) sort(data.begin(), data.end(), ticketAscending);
            else sort(data.begin(), data.end(), ticketDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Voyage Sorter---*/
bool VoyageSorter::idAscending(const Voyage* c1, const Voyage* c2){
    return *c1 < *c2;
}
bool VoyageSorter::idDescending(const Voyage* c1, const Voyage* c2){
    return *c2 < *c1;
}
bool VoyageSorter::routeAscending(const Voyage* c1, const Voyage* c2){
    int comp1 = c1->getRoute().size();
    int comp2 = c2->getRoute().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool VoyageSorter::routeDescending(const Voyage* c1, const Voyage* c2){
    int comp1 = c1->getRoute().size();
    int comp2 = c2->getRoute().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
bool VoyageSorter::originAscending(const Voyage* c1, const Voyage* c2){
    Airport* comp1 = c1->getRoute().front().getPointer()->getOrigin()->airport;
    Airport* comp2 = c2->getRoute().front().getPointer()->getOrigin()->airport;
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool VoyageSorter::originDescending(const Voyage* c1, const Voyage* c2){
    Airport* comp1 = c1->getRoute().front().getPointer()->getOrigin()->airport;
    Airport* comp2 = c2->getRoute().front().getPointer()->getOrigin()->airport;
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
bool VoyageSorter::originDateAscending(const Voyage* c1, const Voyage* c2){
    Time* comp1 = c1->getRoute().front().getPointer()->getOrigin()->time;
    Time* comp2 = c2->getRoute().front().getPointer()->getOrigin()->time;
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool VoyageSorter::originDateDescending(const Voyage* c1, const Voyage* c2){
    Time* comp1 = c1->getRoute().front().getPointer()->getOrigin()->time;
    Time* comp2 = c2->getRoute().front().getPointer()->getOrigin()->time;
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
bool VoyageSorter::destinationAscending(const Voyage* c1, const Voyage* c2){
    Airport* comp1 = c1->getRoute().front().getPointer()->getDestination()->airport;
    Airport* comp2 = c2->getRoute().front().getPointer()->getDestination()->airport;
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool VoyageSorter::destinationDescending(const Voyage* c1, const Voyage* c2){
    Airport* comp1 = c1->getRoute().front().getPointer()->getDestination()->airport;
    Airport* comp2 = c2->getRoute().front().getPointer()->getDestination()->airport;
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
bool VoyageSorter::destinationDateAscending(const Voyage* c1, const Voyage* c2){
    Time* comp1 = c1->getRoute().front().getPointer()->getDestination()->time;
    Time* comp2 = c2->getRoute().front().getPointer()->getDestination()->time;
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool VoyageSorter::destinationDateDescending(const Voyage* c1, const Voyage* c2){
    Time* comp1 = c1->getRoute().front().getPointer()->getDestination()->time;
    Time* comp2 = c2->getRoute().front().getPointer()->getDestination()->time;
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
void VoyageSorter::operator()(std::vector<Voyage*>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), idAscending);
            else sort(data.begin(), data.end(), idDescending);
            break;
        case '1':
            if(asc) sort(data.begin(), data.end(), originAscending);
            else sort(data.begin(), data.end(), originDescending);
            break;
        case '2':
            if(asc) sort(data.begin(), data.end(), destinationAscending);
            else sort(data.begin(), data.end(), destinationDescending);
            break;
        case '3':
            if(asc) sort(data.begin(), data.end(), originDateAscending);
            else sort(data.begin(), data.end(), originDateDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), destinationDateAscending);
            else sort(data.begin(), data.end(), destinationDateDescending);
            break;
        case '5':
            if(asc) sort(data.begin(), data.end(), routeAscending);
            else sort(data.begin(), data.end(), routeDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Airport Sorter---*/
bool AirportSorter::idAscending(const AirportPointer& c1, const AirportPointer& c2){
    return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::idDescending(const AirportPointer& c1, const AirportPointer& c2){
    return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::flightNumAscending(const AirportPointer& c1, const AirportPointer& c2){
    uint32_t comp1 = c1.getFlightsFrom().size() + c1.getFlightsTo().size();
    uint32_t comp2 = c2.getFlightsFrom().size() + c2.getFlightsTo().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::flightNumDescending(const AirportPointer& c1, const AirportPointer& c2){
    uint32_t comp1 = c1.getFlightsFrom().size() + c1.getFlightsTo().size();
    uint32_t comp2 = c2.getFlightsFrom().size() + c2.getFlightsTo().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::nameAscending(const AirportPointer& c1, const AirportPointer& c2){
    std::string comp1 = c1.getPointer()->getName();
    std::string comp2 = c2.getPointer()->getName();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::nameDescending(const AirportPointer& c1, const AirportPointer& c2){
    std::string comp1 = c1.getPointer()->getName();
    std::string comp2 = c2.getPointer()->getName();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::cityAscending(const AirportPointer& c1, const AirportPointer& c2){
    std::string comp1 = c1.getPointer()->getCity();
    std::string comp2 = c2.getPointer()->getCity();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::cityDescending(const AirportPointer& c1, const AirportPointer& c2){
    std::string comp1 = c1.getPointer()->getCity();
    std::string comp2 = c2.getPointer()->getCity();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::countryAscending(const AirportPointer& c1, const AirportPointer& c2){
    std::string comp1 = c1.getPointer()->getCountry();
    std::string comp2 = c2.getPointer()->getCountry();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::countryDescending(const AirportPointer& c1, const AirportPointer& c2){
    std::string comp1 = c1.getPointer()->getCountry();
    std::string comp2 = c2.getPointer()->getCountry();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::serviceAscending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getServices().size();
    int comp2 = c2.getPointer()->getServices().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::serviceDescending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getServices().size();
    int comp2 = c2.getPointer()->getServices().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::completeAscending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getCompleteServices().size();
    int comp2 = c2.getPointer()->getCompleteServices().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::completeDescending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getCompleteServices().size();
    int comp2 = c2.getPointer()->getCompleteServices().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::terminalsAscending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getTerminals().size();
    int comp2 = c2.getPointer()->getTerminals().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::terminalsDescending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getTerminals().size();
    int comp2 = c2.getPointer()->getTerminals().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::emptyAscending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getEmptyTerminals().size();
    int comp2 = c2.getPointer()->getEmptyTerminals().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::emptyDescending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getEmptyTerminals().size();
    int comp2 = c2.getPointer()->getEmptyTerminals().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
bool AirportSorter::transportAscending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getTransport().size();
    int comp2 = c2.getPointer()->getTransport().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return (*c1.getPointer()) < (*c2.getPointer());
}
bool AirportSorter::transportDescending(const AirportPointer& c1, const AirportPointer& c2){
    int comp1 = c1.getPointer()->getTransport().size();
    int comp2 = c2.getPointer()->getTransport().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return (*c2.getPointer()) < (*c1.getPointer());
}
void AirportSorter::operator()(std::vector<AirportPointer>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), idAscending);
            else sort(data.begin(), data.end(), idDescending);
            break;
        case '1':
            if(asc) sort(data.begin(), data.end(), flightNumAscending);
            else sort(data.begin(), data.end(), flightNumDescending);
            break;
        case '2':
            if(asc) sort(data.begin(), data.end(), nameAscending);
            else sort(data.begin(), data.end(), nameDescending);
            break;
        case '3':
            if(asc) sort(data.begin(), data.end(), cityAscending);
            else sort(data.begin(), data.end(), cityDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), countryAscending);
            else sort(data.begin(), data.end(), countryDescending);
            break;
        case '5':
            if(asc) sort(data.begin(), data.end(), serviceAscending);
            else sort(data.begin(), data.end(), serviceDescending);
            break;
        case '6':
            if(asc) sort(data.begin(), data.end(), completeAscending);
            else sort(data.begin(), data.end(), completeDescending);
            break;
        case '7':
            if(asc) sort(data.begin(), data.end(), terminalsAscending);
            else sort(data.begin(), data.end(), terminalsDescending);
            break;
        case '8':
            if(asc) sort(data.begin(), data.end(), emptyAscending);
            else sort(data.begin(), data.end(), emptyDescending);
            break;
        case '9':
            if(asc) sort(data.begin(), data.end(), transportAscending);
            else sort(data.begin(), data.end(), transportDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---User Sorter---*/
bool UserSorter::nameAscending(const User *u1, const User *u2) {
    return *u1 < *u2;
}
bool UserSorter::nameDescending(const User *u1, const User *u2) {
    return *u2 < *u1;
}
bool UserSorter::passAscending(const User *u1, const User *u2) {
    std::string comp1 = u1->getPassword();
    std::string comp2 = u2->getPassword();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *u1 < *u2;
}
bool UserSorter::passDescending(const User *u1, const User *u2) {
    std::string comp1 = u1->getPassword();
    std::string comp2 = u2->getPassword();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *u2 < *u1;
}
bool UserSorter::typeAscending(const User *u1, const User *u2) {
    char comp1 = u1->getType();
    char comp2 = u2->getType();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *u1 < *u2;
}
bool UserSorter::typeDescending(const User *u1, const User *u2) {
    char comp1 = u1->getType();
    char comp2 = u2->getType();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *u2 < *u1;
}
bool UserSorter::dateAscending(const User *u1, const User *u2) {
    Date* comp1 = u1->getDate();
    Date* comp2 = u2->getDate();
    if(*comp1 != *comp2)
        return *comp1 < *comp2;
    else return *u1 < *u2;
}
bool UserSorter::dateDescending(const User *u1, const User *u2) {
    Date* comp1 = u1->getDate();
    Date* comp2 = u2->getDate();
    if(*comp1 != *comp2)
        return *comp2 < *comp1;
    else return *u2 < *u1;
}
void UserSorter::operator()(std::vector<User*>& data, char c, bool asc) {
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), nameAscending);
            else sort(data.begin(), data.end(), nameDescending);
            break;
        case '1' :
            if(asc) sort(data.begin(), data.end(), passAscending);
            else sort(data.begin(), data.end(), passDescending);
            break;
        case '2' :
            if(asc) sort(data.begin(), data.end(), typeAscending);
            else sort(data.begin(), data.end(), typeDescending);
            break;
        case '3' :
            if(asc) sort(data.begin(), data.end(), dateAscending);
            else sort(data.begin(), data.end(), dateDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Client Sorter---*/
bool ClientSorter::milesAscending(const Client* c1, const Client* c2){
    int comp1 = c1->getMiles();
    int comp2 = c2->getMiles();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool ClientSorter::milesDescending(const Client* c1, const Client* c2){
    int comp1 = c1->getMiles();
    int comp2 = c2->getMiles();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
bool ClientSorter::passengerAscending(const Client* c1, const Client* c2){
    return c1->getPassenger() < c2->getPassenger();
}
bool ClientSorter::passengerDescending(const Client* c1, const Client* c2){
    return c2->getPassenger() < c1->getPassenger();
}
bool ClientSorter::ticketAscending(const Client* c1, const Client* c2){
    int comp1 = c1->getTickets().size();
    int comp2 = c2->getTickets().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool ClientSorter::ticketDescending(const Client* c1, const Client* c2){
    int comp1 = c1->getTickets().size();
    int comp2 = c2->getTickets().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
void ClientSorter::operator()(std::vector<Client*>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), nameAscending);
            else sort(data.begin(), data.end(), nameDescending);
            break;
        case '1' :
            if(asc) sort(data.begin(), data.end(), passAscending);
            else sort(data.begin(), data.end(), passDescending);
            break;
        case '2' :
            if(asc) sort(data.begin(), data.end(), typeAscending);
            else sort(data.begin(), data.end(), typeDescending);
            break;
        case '3' :
            if(asc) sort(data.begin(), data.end(), dateAscending);
            else sort(data.begin(), data.end(), dateDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), milesAscending);
            else sort(data.begin(), data.end(), milesDescending);
            break;
        case '5':
            if(asc) sort(data.begin(), data.end(), passengerAscending);
            else sort(data.begin(), data.end(), passengerDescending);
            break;
        case '6':
            if(asc) sort(data.begin(), data.end(), ticketAscending);
            else sort(data.begin(), data.end(), ticketDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Company Sorter---*/
bool CompanySorter::airportAscending(const Company* c1, const Company* c2){
    Airport* comp1 = c1->getAirport();
    Airport* comp2 = c2->getAirport();
    if(comp1 != comp2)
        return *comp1 < *comp2;
    else return *c1 < *c2;
}
bool CompanySorter::airportDescending(const Company* c1, const Company* c2){
    Airport* comp1 = c1->getAirport();
    Airport* comp2 = c2->getAirport();
    if(comp1 != comp2)
        return *comp2 < *comp1;
    else return *c2 < *c1;
}
void CompanySorter::operator()(std::vector<Company*>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), nameAscending);
            else sort(data.begin(), data.end(), nameDescending);
            break;
        case '1' :
            if(asc) sort(data.begin(), data.end(), passAscending);
            else sort(data.begin(), data.end(), passDescending);
            break;
        case '2' :
            if(asc) sort(data.begin(), data.end(), typeAscending);
            else sort(data.begin(), data.end(), typeDescending);
            break;
        case '3' :
            if(asc) sort(data.begin(), data.end(), dateAscending);
            else sort(data.begin(), data.end(), dateDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), airportAscending);
            else sort(data.begin(), data.end(), airportDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Manager Sorter---*/
void ManagerSorter::operator()(std::vector<Company*>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), nameAscending);
            else sort(data.begin(), data.end(), nameDescending);
            break;
        case '1' :
            if(asc) sort(data.begin(), data.end(), passAscending);
            else sort(data.begin(), data.end(), passDescending);
            break;
        case '2' :
            if(asc) sort(data.begin(), data.end(), typeAscending);
            else sort(data.begin(), data.end(), typeDescending);
            break;
        case '3' :
            if(asc) sort(data.begin(), data.end(), dateAscending);
            else sort(data.begin(), data.end(), dateDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), airportAscending);
            else sort(data.begin(), data.end(), airportDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Boarding Sorter---*/
bool BoardingSorter::planeAscending(const Company* c1, const Company* c2){
    Plane* comp1 = c1->getPlane();
    Plane* comp2 = c2->getPlane();
    if(comp1 != comp2)
        return *comp1 < *comp2;
    else return *c1 < *c2;
}
bool BoardingSorter::planeDescending(const Company* c1, const Company* c2){
    Plane* comp1 = c1->getPlane();
    Plane* comp2 = c2->getPlane();
    if(comp1 != comp2)
        return *comp2 < *comp1;
    else return *c2 < *c1;
}
void BoardingSorter::operator()(std::vector<Company*>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), nameAscending);
            else sort(data.begin(), data.end(), nameDescending);
            break;
        case '1' :
            if(asc) sort(data.begin(), data.end(), passAscending);
            else sort(data.begin(), data.end(), passDescending);
            break;
        case '2' :
            if(asc) sort(data.begin(), data.end(), typeAscending);
            else sort(data.begin(), data.end(), typeDescending);
            break;
        case '3' :
            if(asc) sort(data.begin(), data.end(), dateAscending);
            else sort(data.begin(), data.end(), dateDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), airportAscending);
            else sort(data.begin(), data.end(), airportDescending);
            break;
        case '5':
            if(asc) sort(data.begin(), data.end(), planeAscending);
            else sort(data.begin(), data.end(), planeDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}

/**---Service Sorter---*/
bool ServiceSorter::staffAscending(const Company* c1, const Company* c2){
    Staff* comp1 = c1->getStaff();
    Staff* comp2 = c2->getStaff();
    if(comp1 != comp2)
        return *comp1 < *comp2;
    else return *c1 < *c2;
}
bool ServiceSorter::staffDescending(const Company* c1, const Company* c2){
    Staff* comp1 = c1->getStaff();
    Staff* comp2 = c2->getStaff();
    if(comp1 != comp2)
        return *comp2 < *comp1;
    else return *c2 < *c1;
}
bool ServiceSorter::toDoAscending(const Company* c1, const Company* c2){
    int comp1 = c1->getService().size();
    int comp2 = c2->getService().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool ServiceSorter::toDoDescending(const Company* c1, const Company* c2){
    int comp1 = c1->getService().size();
    int comp2 = c2->getService().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
bool ServiceSorter::completedAscending(const Company* c1, const Company* c2){
    int comp1 = c1->getCompleted().size();
    int comp2 = c2->getCompleted().size();
    if(comp1 != comp2)
        return comp1 < comp2;
    else return *c1 < *c2;
}
bool ServiceSorter::completedDescending(const Company* c1, const Company* c2){
    int comp1 = c1->getCompleted().size();
    int comp2 = c2->getCompleted().size();
    if(comp1 != comp2)
        return comp2 < comp1;
    else return *c2 < *c1;
}
void ServiceSorter::operator()(std::vector<Company*>& data, char c, bool asc){
    switch(c){
        case '0' :
            if(asc) sort(data.begin(), data.end(), nameAscending);
            else sort(data.begin(), data.end(), nameDescending);
            break;
        case '1' :
            if(asc) sort(data.begin(), data.end(), passAscending);
            else sort(data.begin(), data.end(), passDescending);
            break;
        case '2' :
            if(asc) sort(data.begin(), data.end(), typeAscending);
            else sort(data.begin(), data.end(), typeDescending);
            break;
        case '3' :
            if(asc) sort(data.begin(), data.end(), dateAscending);
            else sort(data.begin(), data.end(), dateDescending);
            break;
        case '4':
            if(asc) sort(data.begin(), data.end(), airportAscending);
            else sort(data.begin(), data.end(), airportDescending);
            break;
        case '5':
            if(asc) sort(data.begin(), data.end(), staffAscending);
            else sort(data.begin(), data.end(), staffDescending);
            break;
        case '8':
            if(asc) sort(data.begin(), data.end(), toDoAscending);
            else sort(data.begin(), data.end(), toDoDescending);
            break;
        case '7':
            if(asc) sort(data.begin(), data.end(), completedAscending);
            else sort(data.begin(), data.end(), completedDescending);
            break;
        default:
            std::cout << "Invalid sorting order\n\n"
                      << "Press enter to continue . . .";
            cin.ignore();
            getchar();
            return;
    }
}