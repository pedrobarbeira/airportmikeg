#include <iostream>
#include "frontend/mainmenu.h"

void testTube(){
    Time t1;
    Time t2(1, 1, 1);
    Time t3(10, 1, 2013, 3, 3, 3);
    t1.print(std::cout);
    t2.print(std::cout);
    t3.print(std::cout);
}

int main(){
    testTube();

    return 0;
}