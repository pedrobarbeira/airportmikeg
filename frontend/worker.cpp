//Created by Pedro Barbeira (up2012303693)
#include "worker.h"

/**
 * Worker Menu Interface
 */
void workers(){
    char c;
    while(true) {
        system("CLS");
        std::cout << "This is the Worker menu\n"
                  << "\n\t[0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c){
            case '1': std::cout << "Placeholder\n"; system("pause"); break;
            case '0': return;
            default: std::cout << "Invalid Option\n";
                system("pause");
        }
        system("pause");
    }
}
