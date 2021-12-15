//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_MIKEG_H
#define MAIN_CPP_MIKEG_H

#include <iostream>
#include <fstream>
#include "menu.h"

/**
 * System Interface
 */
class MikeG{
    Time* sysTime;
    Data* data;
    Menu* menu;
public:
    /**-----Constructor-----*/
    MikeG(){
        sysTime = new Time;
        data = new Data;
        menu = nullptr;
    }
    /**-----Getters-----*/
    /** Actualizes current system time and returns it
     * @return Time pointer with current system time
     */
    Time* getTime() const{
        sysTime->now();
        return sysTime;};
    Data* getData() const{
        return data;
    }
    //need to add remaining classes
    /**Modifiers*/
    void setSysTime(){
        sysTime->now();};
    /*bool addTicket(Ticket* t) {
        if (!data->flights.empty()) {
            for (auto it : data->tickets) {
                if (it == t) return false;
            }
        }
        data->tickets.push_back(t);
        return true;
    }*/
    /**Load/Save*/
    bool save() const;
    bool loadAirport();
    bool loadVoyage();
    bool loadFlight();
    bool loadPlane();
    bool loadTicket();
    void loadUsers();
    bool load();
    bool loadScreen(bool& flag);
    bool checkDev();

    Menu* logIn();
    bool newAccount();
    void start(bool& flag);
};




#endif //MAIN_CPP_MIKEG_H
