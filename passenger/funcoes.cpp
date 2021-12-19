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
            Ticket *ticket1 = new Ticket(flight.getPointer(), s);

            //bagagem
            int numbags;
            vector<Luggage*> lugvec;
            for (int j = 0; j < numtickets; ++j) {
                cout<<"How many bags are you taking client seated on  "<< s<<" \n";
                cin>> numbags;
                for (int k = 0; k < numbags; ++k) {
                    Luggage *lug = new Luggage(1, false);
                    lugvec.push_back(lug);

                }
            }

            flight.addTicket(ticket1);
        }
    }
}

/*queue<stack<Luggage*>> makingstack(vector<Luggage*> lugvec) {

    int stackcounter=0;
    stack<Luggage*> stacklug;

    for (int i = 0; i < lugvec.size(); i++) {

        stacklug.push(lugvec[i]);
        cout << " Placing " << lugvec[i] << " in stack" << endl;
        stackcounter++;

        if(stackcounter==4){
            cout<<"Max Stack"<<endl;
            bags.push(stacklug);
            while(!stacklug.empty()){
                stacklug.pop();
            }
            stackcounter=0;
        }
    }
    if(stacklug.size() > 0){
        cout << "Carriage has " << bags.size() << " stacks" << endl;
    }
}
*/