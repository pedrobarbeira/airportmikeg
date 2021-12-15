#include "funcoes.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void buyTicket(vector<Ticket*> tickets){
    int numtickets;
    int numbags;
    cout<<"How many tickets do you want to buy?"<<endl;
    cin >> numtickets;
    //if bilhetesdisponiveis>numtickets{
    for (int i = 0; i < numtickets; ++i) {
        Ticket *ticket1=new Ticket();
       // cout<<"criando bilhete"<< endl;
        tickets.push_back(ticket1);
    /*    cout<<"How many bags do you have?"<<endl;
        cin >> numbags;
        for (int j = 0; j < numbags; ++j) {
            Luggage *luggage2=new Luggage(j);
            luggage.push_back(luggage2);
        }
        */
    }

}

void listBilhetes(vector<Ticket *> tickets) {
    for (int i = 0; i < tickets.size(); ++i) {
        cout<<tickets[i]->getID()<<endl;

    }
}
