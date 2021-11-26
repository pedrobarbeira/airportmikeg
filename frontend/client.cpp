//Created by Pedro Barbeira
#include "client.h"

/**
 * Client Menu Interface
 */
void clients(){
    char c;
    while(true) {
        system("CLS");
        std::cout << "This is the Client menu\n"
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
