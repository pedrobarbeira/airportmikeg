//Created by Pedro Barbeira (up201303693)

#include "sorter.h"

std::vector<std::string>LogSorter::sort(){
    std::sort(container.begin(), container.end(), recent);
    return container;
}

