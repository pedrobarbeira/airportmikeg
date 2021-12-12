//Created by Pedro Barbeira
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <iostream>

/**
 * User parent class. Acts as an Interface for it's subclasses.
 */
class User{
    std::string username;
    std::string password;
    char type;
public:
    User(){
        username.clear();
        password.clear();
        type = '\0';
    };
    User(std::string u, std::string p, char t):
            username(std::move(u)), password(std::move(p)), type(t){};
};

/**
 * Frontend class that handles Generic Menus. Acts as an Interface for it's subclasses
 */
class Menu{
protected:
    User* user;
public:
    Menu(){
        user = nullptr;
    }
    explicit Menu(User* u): user(u){};
    bool setUser(User* u){
        if(user != nullptr) return false;
        user = u;
        return true;
    }
    virtual void mainScreen() const;
};

/**
 * Frontend class that handles Unregistered Client menus
 */
class JustBuy : public Menu{
public:
    JustBuy(){
        user = nullptr;
    }
    void mainScreen() const;
};

/**
 * Frontend class that handles Registered Client menus
 */
class Client : public Menu{
};

/**
 * Frontend class that handles Company menus
 */
class Company : public Menu{

};

/**
 * Frontend class that handles Admin menus
 */
class Admin : public Company{

};

/**
 * Frontend class that handles Manager menus
 */
class Manager : public Company{

};

/**
 * Frontend class that handles Boarding Crew menus
 */
class Boarding : public Company{

};

/**
 * Frontend class that handles Service Worker menus
 */
class Service : public Company{

};


#endif //MAIN_CPP_MENU_H
