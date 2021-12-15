//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H

#include "pointer.h"
#include <algorithm>

template<class T>
class Sorter{
protected:
    T container;
    bool func(T a, T b);
public:
    explicit Sorter(){};
    explicit Sorter(T data){
        container = data;
    }
};

class LogSorter : public Sorter<std::vector<std::string>>{
public:
    LogSorter(){
        container.clear();
    };
    static bool recent(std::string s1, std::string s2){
        return s1 < s2;
    }
    std::vector<string> sort();
    std::vector<std::string> operator()(std::vector<std::string> data){
        container = data;
        return sort();
    }
};


#endif //MAIN_CPP_SORTER_H
