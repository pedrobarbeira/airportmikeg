//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_EXCEPTION_H
#define MAIN_CPP_EXCEPTION_H

#include <iostream>
#include "date.h"

/**Exception classes*/
/**
* Stores special system error messages into the DevLogs file, so the company's
* amazing and much valued "IT guy" can keep everything running smoothly.
* Has a tring variable that stores the error and a Date* variable that stores
* the time of the ocurrence.
*/
class DevLog : public std::exception {
    std::string error;
    Date* date;
public:
    explicit DevLog(std::string e) : error(std::move(e)){
        Time* t;
        t->now();
        date = t;
    };
    void print() const;
    std::string getError() const{
        return error;
    }
    Date* getDate() const{
        return date;
    }
};

/**
 * Interface class for Fail exceptions.
 * Created and called whenever a backend problem hapens.
 * Has a string variable that stores the error
 */
class Fail : public std::exception{
protected:
    /**
     * The error that caused the exception
     */
    std::string error;
public:
    /**
     * Empty constructor used to initialize subclasses
     */
    Fail(){
        error.clear();
    }
    /**
     * Returns the error stored in the error variable
     * @return the error stored in the error variable
     */
    std::string getError() const{
        return error;
    }
};

/**
 * Used to ommunicate to DevLogs any problem that may happen while
 * loading Airport data
 */
class LoadAirportFail : public Fail{
public:
    LoadAirportFail(){
        error = "Failed to load Airports";
    }
};
/**
 * Used to ommunicate to DevLogs any problem that may happen while
 * loading Voyage data
 */
class LoadVoyageFail : public Fail{
public:
    LoadVoyageFail(){
        error = "Failed to load Voyages";
    }
};
/**
 * Used to ommunicate to DevLogs any problem that may happen while
 * loading Flight data
 */
class LoadFlightFail : public Fail{
public:
    LoadFlightFail() {
        error = "Failed to load flights";
    };
};
/**
 * Used to ommunicate to DevLogs any problem that may happen while
 * loading Plane data
 */
class LoadPlaneFail : public Fail{
public:
    LoadPlaneFail() {
        error = "Failed to load Planes";
    };
};
/**
 * Used to ommunicate to DevLogs any problem that may happen while
 * loading Ticket data
 */
class LoadTicketFail : public Fail{
public:
    LoadTicketFail() {
        error = "Failed to load Tickets";
    };
};
/**
 * Used to ommunicate to DevLogs any problem that may happen while
 * loading User data
 */
class LoadUserFail : public Fail{
public:
    LoadUserFail(){
        error = "Failed to load Users";
    };
};

/**
 * Used to communicate with DevLogs any problem that might happen
 * while saving Airport data
 */
class SaveAirportFail : public Fail{
public:
    /**
     * Constructor for the SaveAirportFail expection
     * @param id the function where the error happened
     */
    explicit SaveAirportFail(const std::string& id){
        error = "SaveAirportFail::" + id + " error opening outfile\n";
    }
};
/**
 * Used to communicate with DevLogs any problem that might happen
 * while saving Voyage data
 */
class SaveVoyageFail: public Fail{
public:
    /**
     * Constructor for the SaveVoyageFail exception
     * @param id the functio where the error happened
     */
    explicit SaveVoyageFail(const std::string& id){
        error = "SaveVoyageFail::::" + id + " error opening outfile\n";
    }
};
/**
 * Used to communicate with DevLogs any problem that might happen
 * while saving User data
 */
class SaveUserFail : public Fail{
public:
    /**
     * Constructor the for SaveUserFail exception
     * @param id the function where the error happened
     */
    explicit SaveUserFail(const std::string& id){
        error = "SaveUser::" + id + " error opening outfile\n";
    }
};

/**
 * Acts as a goto to quickly logout in any layer of the system
 */
class LogOut : public std::exception{
    std::string message;
public:
    /**
     * Constructor for the LogOut exception class
     */
    LogOut(): message("Logging Out"){};

    /**
     * Prints "Logging out"
     */
    void print() const{
        std::cout << message << '\n';
    }
};

class InvalidConnection : public std::exception{
    std::string error;
public:
    /**
     * Constructor for the InvalidConnection exception. Automatically
     * attributes the error, in order to make it easier for the programmer.
     * This class is thrown in case a connection isn't valid - i.e the origin
     * date is larger then the destination date.
     */
    InvalidConnection():error("Invalid Connection"){};

    /**
     * Prints the error to the desired ostream
     * @param out the desired ostream
     */
    void print(std::ostream& out) const{
        out << error << '\n';};
};


#endif //MAIN_CPP_EXCEPTION_H
