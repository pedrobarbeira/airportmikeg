/**Will be deleted soon*/


//Created by Pedro Barbeira (up201303693)
#include "clients.h"

/**
 * Client Menu Interface
 */
void clients(){
    char c;
    while(true) {
        system(CLEAR);
        std::cout << "This is the Client menu\n"
                  << "\n\t[0] Back\n"
                  <<"\n$";
        std::cin >> c;
        switch(c){
            case '1': std::cout << "Placeholder\n"; system("pause"); break;
            case '0': return;
            default: std::cout << "Invalid Option\n";
                int c = getchar();
        }
        int c = getchar();
    }
}
