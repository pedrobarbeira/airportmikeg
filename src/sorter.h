//Created by Pedro Barbeira (up201303693)
#ifndef MAIN_CPP_SORTER_H
#define MAIN_CPP_SORTER_H

#include "pointer.h"
#include <algorithm>

template<class T>
class Sorter{
protected:
    T container;
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
    std::vector<string> sort();
    std::vector<std::string> operator()(std::vector<std::string> data){
        container = data;
        return sort();
    }
};


#endif //MAIN_CPP_SORTER_H
