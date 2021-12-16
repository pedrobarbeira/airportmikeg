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

class FlightSorter{
    static bool idAscending(const Flight* f1, const Flight* f2);
    static bool idDescending(const Flight* f1, const Flight* f2);
    static bool originAirportAscending(const Flight* f1, const Flight* f2);
    static bool originAirportDescending(const Flight* f1, const Flight* f2);
    static bool originDateAscending(const Flight* f1, const Flight* f2);
    static bool originDateDescending(const Flight* f1, const Flight* f2);
    static bool destinationAirportAscending(const Flight* f1, const Flight* f2);
    static bool destinationAirportDescending(const Flight* f1, const Flight* f2);
    static bool destinationDateAscending(const Flight* f1, const Flight* f2);
    static bool destinationDateDescending(const Flight* f1, const Flight* f2);
    static bool planeAscending(const Flight* f1, const Flight* f2);
    static bool planeDescending(const Flight* f1, const Flight* f2);
public:
    FlightSorter() = default;
    void operator()(std::vector<Flight*>& data, char o, bool asc);
};

class VoyageSorter{

};

class AirportSorter{

};

class UserSorter{
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

class ClientSorter : public UserSorter{
    static bool milesAscending(const Client& c1, const Client& c2);
    static bool milesDescending(const Client& c1, const Client& c2);
    static bool passengerAscending(const Client& c1, const Client& c2);
    static bool passengerDescending(const Client& c1, const Client& c2);
    static bool ticketAscending(const Client& c1, const Client& c2);
    static bool ticketDescending(const Client& c1, const Client& c2);
public:
    ClientSorter() = default;
    void operator()(std::vector<Client*>& data, char c, bool asc);

};

class CompanySorter : public UserSorter{
    static bool airportAscending(const Company& c1, const Company& c2);
    static bool airportDescending(const Company& c1, const Company& c2);
};

class ManagerSorter : public CompanySorter{

};

class BoardingSorter : public CompanySorter{
    static bool planeAscending(const Plane* c1, const Plane* c2);
    static bool planeDescending(const Plane* c1, const Plane* c2);
};

class ServiceSorter : public CompanySorter{
    static bool staffAscending(const Staff* c1, const Staff* c2);
    static bool staffDescending(const Staff* c1, const Staff* c2);
    static bool toDoAscending(const Service* c1, const Service* c2);
    static bool toDoDescending(const Service* c1, const Service* c2);
    static bool completedAscending(const std::list<ServiceTicket*>& c1, const std::list<ServiceTicket*>& c2);
    static bool completedDescending(const const std::list<ServiceTicket*>& c1, const std::list<ServiceTicket*>& c2);
};




#endif //MAIN_CPP_SORTER_H
