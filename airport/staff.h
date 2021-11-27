//
// Created by Joao on 27/11/21.
//

#ifndef MIKEGAIRLINES_STAFF_H
#define MIKEGAIRLINES_STAFF_H


#include<list>
#include<string>

using namespace std;

/** Aqui gostava de tentar implementar uma list/vector com os serviços realizados pelo funcionario por referencia,
 * mas torna-se uma pescadinha de rabo na boca por causa dos includes entre service.h <--> staff.h
 */

class Staff{
    string name;
public:
    Staff(string name);
};

#endif //MIKEGAIRLINES_STAFF_H


