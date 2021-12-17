//
// Created by Lenovo on 15/12/2021.
//

#ifndef MIKEGAIRLINES_FUNCOES_H
#define MIKEGAIRLINES_FUNCOES_H
#include "voyage.h"


void buyTicket(vector<Ticket*> tickets);
/**
 * gives the client the choice to buy multiple tickets and to select the amount of bags they take with them
 * option to select the seat within the defined grid
 * @param bags
 * @param lugvec
 */

void makingstack(queue<stack<Luggage*>> bags, vector<Luggage*> lugvec);

#endif //MIKEGAIRLINES_FUNCOES_H
