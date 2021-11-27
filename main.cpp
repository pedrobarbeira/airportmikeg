#include "mainmenu.h"

void testTube(){
    menu();
}

int main(){
    Airport porto("Sá Carneiro", "Portugal", "Porto" );
    Plane plane;
    Staff staff1("Manel");
    Date date1(30, 11, 21);
    Date date2(1, 12, 21);
    Service cle1(plane, date1);
    cle1.setResponsible(staff1);
    porto.addService(cle1);
    Service cle2(plane, date2, staff1);
    porto.addService(cle2);
    porto.delService(date2);
    testTube();

    return 0;
}