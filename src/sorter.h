//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H

#include "voyage.h"
#include <algorithm>


class LogSorter {
    /**
     * Sorts system logs according to ascending date
     * @param s1 the first log
     * @param s2 the second log
     * @return bool if s1 is before s2, false otherwise
     */
    static bool recent(const std::string& s1, const std::string& s2){
        return s1 < s2;
    }
public:
    /**
     * Sorts DevLogs error vector
     */
    LogSorter() = default;
    void operator()(std::vector<std::string>& data){
        sort(data.begin(), data.end(), recent);
    }
};

/**---Plane Sorter---*/
class PlaneSorter{
    /**
     * Sorts Planes by ascending plate number
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 has a lower plate than p2, false otherwise
     */
    static bool plateAscending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by descending plate number
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 has a higher plate than p2, false otherwise
     */
    static bool plateDescending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by ascending First Class price
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 is less expensive than p2, false otherwise
     */
    static bool fPriceAscending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by descending First Class price
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 is more expensive than p2, false otherwise
     */
    static bool fPriceDescending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by ascending Business Class price
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 is less expensive than p2, false otherwise
     */
    static bool bPriceAscending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by descending Business Class price
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 is more expensive than p2, false otherwise
     */
    static bool bPriceDescending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by ascending Economy Class price
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true is p1 is less expensive than p2, false otherwise
     */
    static bool ePriceAscending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by descending Economy Class price
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true is p1 is more expensive than p2, false otherwise
     */
    static bool ePriceDescending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by ascending free seat number
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 has less free seats than p2, false otherwise
     */
    static bool freeAscending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by descending free seat number
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 has more free seats than p2, false otherwise
     */
    static bool freeDescending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by ascending number of seats
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 has less seats than p2, false otherwise
     */
    static bool seatAscending(const Plane* p1, const Plane* p2);

    /**
     * Sorts Planes by descending number of seats
     * @param p1 the first plane
     * @param p2 the second plane
     * @return true if p1 has more seats than p2, false otherwise
     */
    static bool seatDescending(const Plane* p1, const Plane* p2);
public:
    /**
     * Sorts vectors of type Plane*, allowing different orders of organization
     */
    PlaneSorter() = default;

    /**
     * Takes a vector, a char and a boolean. Parses the char to determine the
     * parameter which will determine the sorting and sorts the vector, in
     * either ascending or descending order, according to the boolean attribute
     * @param data the vector to be sorted
     * @param o the character which determines the sorting parameter
     * @param asc true for ascending, false for descending
     */
    void operator()(std::vector<Plane*>& data, char o, bool asc);
};

/**---Flight Sorter---*/
class FlightSorter{
    /**
     * Sorts Flights by ascending Id
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1 has a lower id than f2, false otherwise
     */
    static bool idAscending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by descending id
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1 has a higher id than f2, false otherwise
     */
    static bool idDescending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by ascending Origin airport ID
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1's origin comes before f2's origin, false otherwise
     */
    static bool originAirportAscending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by descending Origin airport ID
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f2's origin comes after f2's origin, false otherwise
     */
    static bool originAirportDescending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by ascending Origin date
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1 departs before f2, false otherwise
     */
    static bool originDateAscending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by descending Origin date
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1 departs after f2, false otherwise
     */
    static bool originDateDescending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by ascending Destination airport ID
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1's destination airport comes before f2's, false otherwise
     */
    static bool destinationAirportAscending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by descending Destination airport ID
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1's destination airport comes after f2's, false otherwise
     */
    static bool destinationAirportDescending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by ascendig Destination date
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1 lands before f2, false otherwise
     */
    static bool destinationDateAscending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by descnding Destination date
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1 lands after f2, false otherwise
     */
    static bool destinationDateDescending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by ascending Plane ID
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1's plane comes before f2's, false otherwise
     */
    static bool planeAscending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by descending Plane Id
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1's plane comes after f2's, false otherwise
     */
    static bool planeDescending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by ascending number of tickets
     * @param f1 the first flight
     * @param f2 the sceond flight
     * @return true if f1 has less tickets than f2, false otherwise
     */
    static bool ticketAscending(const FlightPointer& f1, const FlightPointer& f2);

    /**
     * Sorts Flights by descending number of tickets
     * @param f1 the first flight
     * @param f2 the second flight
     * @return true if f1 has more tickets than f2, false otherwise
     */
    static bool ticketDescending(const FlightPointer& f1, const FlightPointer& f2);
public:
    /**
     * Sorts vectors of type FlightPointer, allowing different orders of organization
     */
    FlightSorter() = default;

    /**
     * Takes a vector, a char and a bool. Parses char to select the attribute
     * that'll define the sort. Sorts the vector in ascending or descending
     * order of that attribute, depending on the parameter asc
     * @param data the data vector that'll be sorted
     * @param o the char that determines the sorting parameter
     * @param asc determines if sorting is ascending or descending
     */
    void operator()(std::vector<FlightPointer>& data, char o, bool asc);
};

/**---Voyage Sorter---*/
class VoyageSorter{
    /**
     * Sorts Voyages by ascending ID
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1's Id comes before c2's, false otherwise
     */
    static bool idAscending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by descending ID
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1 comes after c2, false otherwise
     */
    static bool idDescending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by ascending number of flights
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1 has less flights than c2, false otherwise
     */
    static bool routeAscending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by descending number of flights
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1 has more flights than c2, false otherwise
     */
    static bool routeDescending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by ascending Origin airport name
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1's airport comes before c2's, false otherwise
     */
    static bool originAscending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by descending Origin airport name
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c2's airport comes after c2's, false otherwise
     */
    static bool originDescending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by ascending Origin date
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1 departs before c2, false otherwise
     */
    static bool originDateAscending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by descending Origin date
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1 departs after c2, false otherwise
     */
    static bool originDateDescending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by ascending Destination airport ID
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1's airport comes before c2, false otherwise
     */
    static bool destinationAscending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by descending Destination airport ID
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1's airport comes after c2, false otherwise
     */
    static bool destinationDescending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by ascending Destination date
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1 lands before c2, false otherwise
     */
    static bool destinationDateAscending(const Voyage* c1, const Voyage* c2);

    /**
     * Sorts Voyages by descending Destination date
     * @param c1 the first voyage
     * @param c2 the second voyage
     * @return true if c1 lands after c2, false otherwise
     */
    static bool destinationDateDescending(const Voyage* c1, const Voyage* c2);
public:
    /**
     * Sorts vectors of type Voyage*, allowing different orders of organization
     */
    VoyageSorter() = default;

    /**
     * Takes a vector, a char and a bool. Parses char to determine sorting
     * parameter. Sorts vector according to sorting parameter, either ascending
     * or descending according to the asc parameter
     * @param data the vector to be sorted
     * @param c the char that determines sorting order
     * @param asc determines if sorting is ascending or descending
     */
    void operator()(std::vector<Voyage*>& data, char c, bool asc);

};

/**---Airport Sorter---*/
class AirportSorter{
    /**
     * Sorts Airports by ascending number of flights
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has more flights than c2, false otherwise
     */
    static bool flightNumAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending number of flights
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has less flights than c2, false otherwise
     */
    static bool flightNumDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by ascending ID
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's ID comes before c2's, false otherwise
     */
    static bool idAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending ID
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's ID comes after c2's, false otherwise
     */
    static bool idDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by ascending name
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's name comes after c2's, false otherwise
     */
    static bool nameAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending name
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's name comes after c2's, false otherwise
     */
    static bool nameDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airport by ascending city
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's city comes before c2's, false otherwise
     */
    static bool cityAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airport by descending city
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's city comes after c2's, false otherwise
     */
    static bool cityDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorta Airport by ascending country
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's country comes before c2's, false otherwise
     */
    static bool countryAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airport by descending country
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1's country comes after c2's, false otherwise
     */
    static bool countryDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by ascending number of Service Tickets
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has less Service Tickets than c2, false otherwise
     */
    static bool serviceAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending number of Service Tickets
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has more Service Tickets than c2, false otherwise
     */
    static bool serviceDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by ascending number of completed Service Tickets
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has less completed Service Tickets than c2, false otherwise
     */
    static bool completeAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending number of completed Service Tickets
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has more completed Service Tickets than c2, false otherwise
     */
    static bool completeDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by ascending number of terminals
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has less terminals than c2, false otherwise
     */
    static bool terminalsAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending number of terminals
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has more terminals than c2, false otherwise
     */
    static bool terminalsDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by ascending number of empty terminals
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has less empty terminals than c2, false otherwise
     */
    static bool emptyAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending number of empty terminals
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has less empty terminals than c2, false otherwise
     */
    static bool emptyDescending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by ascending number of transports
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has less transports than c2, false otherwise
     */
    static bool transportAscending(const AirportPointer& c1, const AirportPointer& c2);

    /**
     * Sorts Airports by descending number of transports
     * @param c1 the first Airport
     * @param c2 the second Airport
     * @return true if c1 has more transports than c2, false otherwise
     */
    static bool transportDescending(const AirportPointer& c1, const AirportPointer& c2);
public:
    /**
     * Sorts vectors of type AirportPointer, allowing different orders of organization
     */
    AirportSorter() = default;
     /**
      * Receives a vector, a char and a bool. Parses char to determine sorting
      * parameter. Sorts vector according to chosen parameter, either ascending
      * or descending, depending on the asc parameter
      * @param data the vector to be sorted
      * @param c the char that'll determines the sorting parameter
      * @param as determines if sorting is ascending or descending
      */
    void operator()(std::vector<AirportPointer>& data, char c, bool as);
};

/**---User Sorter---*/
class UserSorter{
protected:
    /**
     * Sorts Users by ascending name
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c1's name comes before c2's, false otherwise
     */
    static bool nameAscending(const User* u1, const User* u2);

    /**
     * Sorts Users by descending name
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c2's name comes after c2's, false otherwise
     */
    static bool nameDescending(const User* u1, const User* u2);

    /**
     * Sorts Users by ascending password
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c1's password comes before c2's, false otherwise
     */
    static bool passAscending(const User* u1, const User* u2);

    /**
     * Sorts Users by descending password
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c1's password comes after c2's, false otherwise
     */
    static bool passDescending(const User* u1, const User* u2);

    /**
     * Sorts Users by ascending type
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c1's type comes before c2's, false otherwise
     */
    static bool typeAscending(const User* u1, const User* u2);

    /**
     * Sorts Users by descending type
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c1's type comes after c2's, false otherwise
     */
    static bool typeDescending(const User* u1, const User* u2);

    /**
     * Sorts Users by registration date
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c1 registered before c2, false otherwise
     */
    static bool dateAscending(const User* u1, const User* u2);

    /**
     * Sorts Users by registration date
     * @param u1 the first User
     * @param u2 the second User
     * @return true if c1 registered after c2, false otherwise
     */
    static bool dateDescending(const User* u1, const User* u2);
public:
    /**
     * Sorts vectors of type User*, allowing different orders of organization
     */
    UserSorter() = default;
    /**
     * Receives a vector, a char and a bool. Parses char to determine sorting
     * parameter. Sorts vector according to chosen parameter, either ascending
     * or descending, depending on the asc parameter
     * @param data the vector to be sorted
     * @param c the char that'll determines the sorting parameter
     * @param as determines if sorting is ascending or descending
     */
    void operator()(std::vector<User*>& data, char c, bool asc);
};

/**---Client Sorter---*/
class ClientSorter : public UserSorter{
    /**
     * Sorts Clients by ascending number of miles
     * @param c1 the first Client
     * @param c2 the second Client
     * @return true if c1 has less miles than c2, false otherwise
     */
    static bool milesAscending(const Client* c1, const Client* c2);

    /**
     * Sorts Clients by descending number of miles
     * @param c1 the first Client
     * @param c2 the second Client
     * @return true if c1 has more miles than c2, false otherwise
     */
    static bool milesDescending(const Client* c1, const Client* c2);

    /**
     * Sorts Clients by ascending passenger name
     * @param c1 the first Client
     * @param c2 the second Client
     * @return true if c1's passenger name comes before c2's, false otherwise
     */
    static bool passengerAscending(const Client* c1, const Client* c2);

    /**
     * Sorts Clients by descending passenger name
     * @param c1 the first Client
     * @param c2 the second Client
     * @return true if c1's passenger name comes after c2's, false otherwise
     */
    static bool passengerDescending(const Client* c1, const Client* c2);

    /**
     * Sorts Clients by ascending number of tickets
     * @param c1 the first Client
     * @param c2 the second Client
     * @return true if c1 has more tickets than c2, false otherwise
     */
    static bool ticketAscending(const Client* c1, const Client* c2);

    /**
     * Sorts Clients by descending number of tickets
     * @param c1 the first Client
     * @param c2 the second Client
     * @return true if c1 has less ticketa than c2, false otherwise
     */
    static bool ticketDescending(const Client* c1, const Client* c2);
public:
    /**
     * Sorts vectors of type Client*, allowing different orders of organization
     */
    ClientSorter() = default;
    /**
     * Receives a Client vector, a char and a bool. Parses char to determine
     * sorting parameter. Sorts vector according to chosen parameter, either
     * ascending or descending, depending on the asc parameter
     * @param data the vector to be sorted
     * @param c the char that'll determines the sorting parameter
     * @param as determines if sorting is ascending or descending
     */
    void operator()(std::vector<Client*>& data, char c, bool asc);

};

/**---Company Sorter---*/
class CompanySorter : public UserSorter{
protected:
    /**
     * Sorts Company Workers by ascending Airport name
     * @param c1 the first Company worker
     * @param c2 the scond Company Worker
     * @return true if c1's airport comes before c2, false otherwise
     */
    static bool airportAscending(const Company* c1, const Company* c2);

    /**
     * Sorts Company Workers by descending Airport name
     * @param c1 the first Company Worker
     * @param c2 the second Company Worker
     * @return true if c1's airport comes after c2, false otherwise
     */
    static bool airportDescending(const Company* c1, const Company* c2);
public:
    /**
     * Sorts vectors of type Company*, allowing different orders of organization
     */
    CompanySorter() = default;

    /**
     * Receives a Company vector, a char and a bool. Parses char to determine
     * sorting parameter. Sorts vector according to chosen parameter, either
     * ascending or descending, depending on the asc parameter
     * @param data the vector to be sorted
     * @param c the char that'll determines the sorting parameter
     * @param as determines if sorting is ascending or descending
    */
    virtual void operator()(std::vector<Company*>& data, char c, bool asc);
};

/**---Manager Sorter---*/
class ManagerSorter : public CompanySorter{
public:
    /**
     * Sorts vectors of type Manager*, allowing different orders of organization
     */
    ManagerSorter() = default;

    /**
     * Receives a Comapny vector, a char and a bool. Parses char to determine
     * sorting parameter. Sorts vector according to chosen parameter, either
     * ascending or descending, depending on the asc parameter
     * @param data the vector to be sorted
     * @param c the char that'll determines the sorting parameter
     * @param as determines if sorting is ascending or descending
     */
    void operator()(std::vector<Company*>& data, char c, bool asc) override;
};

/**---Boarding Sorter---*/
class BoardingSorter : public CompanySorter{
    /**
     * Sorts Boarding Workers by ascending Plane ID
     * @param c1 the first Boarding Worker
     * @param c2 the second Boarding Worker
     * @return true if c1's plane comes before c2, false otherwise
     */
    static bool planeAscending(const Company* c1, const Company* c2);

    /**
     * Sorts Boarding Workers by descnding Plane ID
     * @param c1 the first Boarding Worker
     * @param c2 the second Boarding Worker
     * @return true if c1's plane comes after c2, false otherwise
     */
    static bool planeDescending(const Company* c1, const Company* c2);
public:
    /**
     * Sorts vectors of type Boarding*, allowing different orders of organization
     */
    BoardingSorter() = default;

    /**
     * Receives a Company vector, a char and a bool. Parses char to determine
     * parameter. Sorts vector according to chosen parameter, either ascending
     * or descending, depending on the asc parameter
     * @param data the vector to be sorted
     * @param c the char that'll determines the sorting parameter
     * @param as determines if sorting is ascending or descending
     */
    void operator()(std::vector<Company*>& data, char c, bool asc) override;
};

/**---Service Sorter---*/
class ServiceSorter : public CompanySorter{
    /**
     * Sorts Service Workers by ascending Staff name
     * @param c1 the fist Service Worker
     * @param c2 the second Service Worker
     * @return true if c1 comes before c2, false otherwise
     */
    static bool staffAscending(const Company* c1, const Company* c2);

    /**
     * Sorts Service Workers by descending Staff name
     * @param c1 the first Service Worker
     * @param c2 the second Service worker
     * @return true if c1 comes after c2, false otherwise
     */
    static bool staffDescending(const Company* c1, const Company* c2);

    /**
     * Sorts Service Workers by ascending number of Service Tickets
     * @param c1 the first Service Worker
     * @param c2 the second Service Worker
     * @return true if c1 has less Service Tickets than c2, false otherwise
     */
    static bool toDoAscending(const Company* c1, const Company* c2);

    /**
     * Sorts Service Workers by descending number of Service Tickets
     * @param c1 the first Service Worker
     * @param c2 the second Service Worker
     * @return true if c1 has more Service Tickets than c2, false otherwise
     */
    static bool toDoDescending(const Company* c1, const Company* c2);

    /**
     * Sorts Service Workers by ascending number of completed Service Tickets
     * @param c1 the first Service Worker
     * @param c2 the second Service Worker
     * @return true if c1 has less completed Service Tickets than c2, false otherwise
     */
    static bool completedAscending(const Company* c1, const Company* c2);

    /**
     * Sorts Service Workers by descnding number of completed Service Tickets
     * @param c1 the first Service Worker
     * @param c2 the second Service Worker
     * @return true if c1 has more completed Service Tickets than c2, false otherwise
     */
    static bool completedDescending(const Company* c1, const Company* c2);
public:
    /**
     * Sorts vectors of type Service*, allowing different orders of organization
     */
    ServiceSorter() = default;

    /**
     * Receives a Company vector, a char and a bool. Parses char to determine
     * sorting parameter. Sorts vector according to chosen parameter, either
     * ascending or descending, depending on the asc parameter
     * @param data the vector to be sorted
     * @param c the char that'll determines the sorting parameter
     * @param as determines if sorting is ascending or descending
     */
    void operator()(std::vector<Company*>& data, char c, bool asc) override;
};

#endif //MAIN_CPP_SORTER_H
