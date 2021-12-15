//Created by Pedro Barbeira (up201303693)

#include "sorter.h"


bool minor(std::string s1, std::string s2){
    return s1 < s2;
}

std::vector<std::string>LogSorter::sort(){
    std::sort(container.begin(), container.end(), minor);
    return container;
}

