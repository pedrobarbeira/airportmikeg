//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H

#include "voyage.h"
#include <algorithm>


class LogSorter {
    static bool recent(const std::string& s1, const std::string& s2){
        return s1 < s2;
    }
public:
    LogSorter() = default;
    void operator()(std::vector<std::string>& data){
        sort(data.begin(), data.end(), recent);
    }
};

/**---Plane Sorter---*/
class PlaneSorter{
    static bool plateAscending(const Plane* p1, const Plane* p2);
    static bool plateDescending(const Plane* p1, const Plane* p2);
    static bool fPriceAscending(const Plane* p1, const Plane* p2);
    static bool fPriceDescending(const Plane* p1, const Plane* p2);
    static bool bPriceAscending(const Plane* p1, const Plane* p2);
    static bool bPriceDescending(const Plane* p1, const Plane* p2);
    static bool ePriceAscending(const Plane* p1, const Plane* p2);
    static bool ePriceDescending(const Plane* p1, const Plane* p2);
    static bool freeAscending(const Plane* p1, const Plane* p2);
    static bool freeDescending(const Plane* p1, const Plane* p2);
    static bool seatAscending(const Plane* p1, const Plane* p2);
    static bool seatDescending(const Plane* p1, const Plane* p2);
public:
    PlaneSorter() = default;
    void operator()(std::vector<Plane*>& data, char o, bool asc);
};

/**---Flight Sorter---*/
class FlightSorter{
    static bool idAscending(const FlightPointer& f1, const FlightPointer& f2);
    static bool idDescending(const FlightPointer& f1, const FlightPointer& f2);
    static bool originAirportAscending(const FlightPointer& f1, const FlightPointer& f2);
    static bool originAirportDescending(const FlightPointer& f1, const FlightPointer& f2);
    static bool originDateAscending(const FlightPointer& f1, const FlightPointer& f2);
    static bool originDateDescending(const FlightPointer& f1, const FlightPointer& f2);
    static bool destinationAirportAscending(const FlightPointer& f1, const FlightPointer& f2);
    static bool destinationAirportDescending(const FlightPointer& f1, const FlightPointer& f2);
    static bool destinationDateAscending(const FlightPointer& f1, const FlightPointer& f2);
    static bool destinationDateDescending(const FlightPointer& f1, const FlightPointer& f2);
    static bool planeAscending(const FlightPointer& f1, const FlightPointer& f2);
    static bool planeDescending(const FlightPointer& f1, const FlightPointer& f2);
    static bool ticketAscending(const FlightPointer& f1, const FlightPointer& f2);
    static bool ticketDescending(const FlightPointer& f1, const FlightPointer& f2);
public:
    FlightSorter() = default;
    void operator()(std::vector<FlightPointer>& data, char o, bool asc);
};

/**---Voyage Sorter---*/
class VoyageSorter{

public:
    VoyageSorter() = default;
    void operator()(std::vector<Voyage*>& data, char c, bool asc);

};

/**---Airport Sorter---*/
class AirportSorter{
    static bool flightNumAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool flightNumDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool idAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool idDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool nameAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool nameDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool cityAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool cityDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool countryAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool countryDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool serviceAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool serviceDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool completeAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool completeDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool terminalsAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool terminalsDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool emptyAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool emptyDescending(const AirportPointer& c1, const AirportPointer& c2);
    static bool transportAscending(const AirportPointer& c1, const AirportPointer& c2);
    static bool transportDescending(const AirportPointer& c1, const AirportPointer& c2);
public:
    AirportSorter() = default;
    void operator()(std::vector<AirportPointer>& data, char c, bool as);
};

/**---User Sorter---*/
class UserSorter{
protected:
    static bool nameAscending(const User* u1, const User* u2);
    static bool nameDescending(const User* u1, const User* u2);
    static bool passAscending(const User* u1, const User* u2);
    static bool passDescending(const User* u1, const User* u2);
    static bool typeAscending(const User* u1, const User* u2);
    static bool typeDescending(const User* u1, const User* u2);
    static bool dateAscending(const User* u1, const User* u2);
    static bool dateDescending(const User* u1, const User* u2);
public:
    UserSorter() = default;
    void operator()(std::vector<User*>& data, char c, bool asc);
};

/**---Client Sorter---*/
class ClientSorter : public UserSorter{
    static bool milesAscending(const Client* c1, const Client* c2);
    static bool milesDescending(const Client* c1, const Client* c2);
    static bool passengerAscending(const Client* c1, const Client* c2);
    static bool passengerDescending(const Client* c1, const Client* c2);
    static bool ticketAscending(const Client* c1, const Client* c2);
    static bool ticketDescending(const Client* c1, const Client* c2);
public:
    ClientSorter() = default;
    void operator()(std::vector<Client*>& data, char c, bool asc);

};

/**---Company Sorter---*/
class CompanySorter : public UserSorter{
protected:
    static bool airportAscending(const Company* c1, const Company* c2);
    static bool airportDescending(const Company* c1, const Company* c2);
public:
    CompanySorter() = default;
    void operator()(std::vector<Company*>& data, char c, bool asc);
};

class ManagerSorter : public CompanySorter{
public:
    ManagerSorter() = default;
    void operator()(std::vector<Manager*>& data, char c, bool asc);
};

/**---Boarding Sorter---*/
class BoardingSorter : public CompanySorter{
    static bool planeAscending(const Boarding* c1, const Boarding* c2);
    static bool planeDescending(const Boarding* c1, const Boarding* c2);
public:
    BoardingSorter() = default;
    void operator()(std::vector<Boarding*>& data, char c, bool asc);
};

/**---Service Sorter---*/
class ServiceSorter : public CompanySorter{
    static bool staffAscending(const Service* c1, const Service* c2);
    static bool staffDescending(const Service* c1, const Service* c2);
    static bool toDoAscending(const Service* c1, const Service* c2);
    static bool toDoDescending(const Service* c1, const Service* c2);
    static bool completedAscending(const Service* c1, const Service* c2);
    static bool completedDescending(const Service* c1, const Service* c2);
public:
    ServiceSorter() = default;
    void operator()(std::vector<Service*>& data, char c, bool asc);
};




#endif //MAIN_CPP_SORTER_H
