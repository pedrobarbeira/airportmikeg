//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MIKEG_H
#define MAIN_CPP_MIKEG_H


#include "menu.h"

/**
 * System Interface
 */
class MikeG {
    Time *sysTime;
    Data *data;
    Menu *menu;
public:
    /**-----Constructor-----*/
    MikeG() {
        sysTime = new Time;
        data = new Data;
        menu = nullptr;
    }
    /**-----Getters-----*/
    /** Actualizes current system time and returns it
     * @return Time pointer with current system time
     */
    Time *getTime() const {
        sysTime->now();
        return sysTime;
    };

    Data *getData() const {
        return data;
    }
    //need to add remaining classes
    /**Modifiers*/
    void setSysTime() {
        sysTime->now();
    };
    /*bool addTicket(Ticket* t) {
        if (!data->flights.empty()) {
            for (auto it : data->tickets) {
                if (it == t) return false;
            }
        }
        data->tickets.push_back(t);
        return true;
    }*/
    /**-----Load/Save-----*/
    bool save() const;

    bool load();

    bool loadScreen(bool &flag);

    bool checkDev();

    /**
     * LogIn function. Reads credentials from input and searches for a corresponding
     * account in the data.clients and data.company bst's. Once it finds a match,
     * compares input password with the password saved in the system data. If the
     * data checks out, returns corresponding Menu. If not, outputs "Invalid credentials"
     * and returns nullptr.
     * @return the proper menu if the account data is in the system, nullptr otherwise.
     */
    Menu *logIn();

    bool newAccount();

    void start(bool &flag);
};




#endif //MAIN_CPP_MIKEG_H
