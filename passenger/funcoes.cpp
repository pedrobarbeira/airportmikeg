#include "funcoes.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void comprarBilhete(vector<Ticket*> tickets){
    int numtickets;
    cout<<"quantos bilhetes quer comprar"<<endl;
    cin >> numtickets;
    //if bilhetesdisponiveis>numtickets{
    for (int i = 0; i < numtickets; ++i) {
        Ticket *ticket1=new Ticket(i);
        cout<<"criando bilhete"<< endl;
        tickets.push_back(ticket1);
    }

}

void listBilhetes(vector<Ticket *> tickets) {
    for (int i = 0; i < tickets.size(); ++i) {
        cout<<tickets[i]->getID()<<endl;

    }
}
