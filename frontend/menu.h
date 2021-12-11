//Created by Pedro Barbeira
#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <iostream>

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

class JustBuy : public Menu{
public:
    JustBuy(){
        user = nullptr;
    }
    void mainScreen() const;
};



#endif //MAIN_CPP_MENU_H
