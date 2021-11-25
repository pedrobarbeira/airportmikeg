#include <iostream>
#include "frontend/mainmenu.h"

int main(){
    char c;
    while(true) {
        c = menu();
        switch (c) {
            case '1': workers(); break;
            case '2': clients(); break;
            case '0': exit(0);
        }
    }

    return 0;
}