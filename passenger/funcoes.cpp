#include "funcoes.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void buyTicket(VoyagePointer voy) {
    int numtickets;
    Voyage *v = voy.getPointer();
    list<FlightPointer> f;
    for (auto i: v->getRoute()) {
        f.push_back(i);
    }

    cout << "How many tickets do you want to buy?" << endl;
    cin >> numtickets;

    for (auto flight: f) {

        Plane *p = flight.getPointer()->getPlane();
        p->showSeats();
        string seatchoice;

        for (int i = 0; i < numtickets; ++i) {
            bool flag;
            do {
                cout << "Choose a Seat" << endl;
                cin >> seatchoice;

                int row, seat;
                for (int i = 0; i < seatchoice.length(); i++) {
                    if (isdigit(seatchoice[i])) {
                        row = getLetterRow(seatchoice.substr(0, i));
                        seat = std::stoi(seatchoice.substr(i)) - 1;
                        break;
                    }
                }
                flag=row > p->getRows() || seat > p->getColumns();
                if(flag){
                    cout<<"Invalid Seat\n";
                }
            }while (flag);

            Seat* s=p->bookSeat(seatchoice);
            Ticket *ticket1 = new Ticket(s);

            //bagagem

            flight.addTicket(ticket1);
        }
    }
}



    //if bilhetesdisponiveis>numtickets{
/*
        tickets.push_back(ticket1);
        cout<<"How many bags do you have?"<<endl;
        cin >> numbags;
        for (int j = 0; j < numbags; ++j) {
            Luggage *luggage2=new Luggage(1,false);
            passLugg.push_back(luggage2);
        }
    }
cout << "passLugg size " << passLugg.size() << endl;
}

void listBilhetes(vector<Ticket *> tickets) {
    for (int i = 0; i < tickets.size(); ++i) {
        cout<<tickets[i]->getID()<<endl;

    }
}

void fazerpilha(queue<stack<Luggage*>> bags, vector<Luggage*> passLugg) {

    int contador=0;
    stack<Luggage*> stacklug;
    cout<<passLugg.size()<<endl;
    for (int i = 0; i < passLugg.size(); i++) {
        cout<<"colocando"<<endl;
        stacklug.push(passLugg[i]);
        cout << " Placing " << passLugg[i] << " in stack" << endl;
        contador++;
        if(contador==4){
            cout<<"Max Stack"<<endl;
            bags.push(stacklug);
            while(!stacklug.empty()){
                stacklug.pop();
            }
            contador=0;
        }
    }
    if(stacklug.size() > 0){
        cout << "Carriage has " << bags.size() << " stacks" << endl;
    }
 //   cout << "Carrinho tem " << bags.size() << " stacks" << endl;
}
*/
