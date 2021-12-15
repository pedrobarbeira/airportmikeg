//Created by Pedro Barbeira
#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H

#include <iostream>
#include "bst.h"

/**
 * User parent class. Acts as an Interface for it's subclasses.
 */
class User{
protected:
    std::string username;
    std::string password;
    char type; //Create
    friend class UserPointer;
    friend class CompanyPointer;
    friend class ClientPointer;
public:
    explicit User(std::string u = "", std::string p = "", char t = '\0'):
            username(std::move(u)), password(std::move(p)), type(t){};
    std::string getUser() const{
        return username;
    }
    std::string getPassword() const{
        return password;
    }
    char getType() const{
        return type;
    }
};
//Lets keep this on the "maybe pile" for now
class Client : public User{
    uint16_t miles;
    friend class ClientPointer;
public:
    explicit Client(std::string u = "", std::string p = "", char t = '\0', uint16_t m = 0) : miles(m){
        username = u;
        password = p;
        type = t;
    }
};

class Company : public User{
public:
    explicit Company(std::string u = "", std::string p = "", char t = '\0'){
        username = std::move(u);
        password = std::move(p);
        type = t;
    }
};

class Admin : public Company{
public:
    explicit Admin(std::string u = "", std::string p = "", char t = '\0'){
        username = u;
        password = p;
        type = t;
    }
};

class Manager : public Company{
public:
    explicit Manager(std::string u = "", std::string p = "", char t = '\0'){
        username = u;
        password = p;
        type = t;
    }
};

class Boarding : public Company{
public:
    explicit Boarding(std::string u = "", std::string p = "", char t = '\0'){
        username = u;
        password = p;
        type = t;
    }
};

class ServiceW : public Company{
public:
    explicit ServiceW(std::string u = "", std::string p = "", char t = '\0'){
        username = u;
        password = p;
        type = t;
    }
};

class UserPointer : public BSTPointer<User>{
public:
    explicit UserPointer(User* u = nullptr){
        pointer = u;
    }
    bool operator==(const UserPointer& rhs) const{
        return pointer->username == rhs.pointer->username;
    }
    bool operator<(const UserPointer& rhs) const{
        return pointer->username < rhs.pointer->username;
    }
};

class ClientPointer : public UserPointer{
public:
    explicit ClientPointer(Client* u = nullptr){
        pointer = u;
    }
    bool operator==(const ClientPointer & rhs) const{
        return pointer->username == rhs.pointer->username;
    }
    bool operator<(const ClientPointer& rhs) const{
        return pointer->username < rhs.pointer->username;
    }
};

class CompanyPointer : public UserPointer{
public:
    explicit CompanyPointer(Company* u = nullptr){
        pointer = u;
    }
};

#endif //MAIN_CPP_USER_H
