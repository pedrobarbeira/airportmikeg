//Created by Pedro Barbeira (up201303693)

#include "plane.h"

/**Seat*/
Seat::Seat(std::string row, int column, Class* c){
    id = "    ";
    if(row.length() == 1){
        id[0] = ' ';
        id[1] = row[0];
    }
    else{
        id[0] = row[0];
        id[1] = row[1];
    }
    id[2] = char((column / 10) + '0');
    id[3] = char((column % 10) + '0');
    free = true;
    classe = c;
}

Seat::~Seat(){
    delete classe;
}

/**Plane*/
Plane::~Plane(){
    for(auto it : classes)
        delete it;
    for(auto it: seats)
        for(auto seat: it)
            delete seat;
}

int Plane::freeSeatNum() const{
    int count = 0;
    for(int i = 0; i < seatRows; i++){
        for(int j = 0; j < seatsPerRow; j++)
            if(seats[i][j]->isFree()) count++;
    }
    return count;
}

void Plane::showSeats() const{
    std::string row;
    for(int j = seatsPerRow; j >= 0; j--){
        for(int i = 0; i < seatRows; i++){
            if(j == seatsPerRow) {
                if(i == 0)std::cout << std::setw(4) << std::setfill(' ') << getRowLetter(i);
                else std::cout << std::setw(4) << std::setfill(' ') << getRowLetter(i);
            }
            else {
                if (i == 0) std::cout << j + 1;
                std::cout << " [";
                if (seats[i][j]->isFree()) std::cout << 'o';
                else std::cout << 'x';
                std::cout << "]";

            }
        }
        std::cout << '\n';
    }
}

bool Plane::bookSeat(std::string code){
    std::string rowCode;
    int row, seat;
    for(int i = 0; i < code.length(); i++){
        if(isdigit(code[i])) {
            rowCode = code.substr(0, i);
            seat = std::stoi(code.substr(i)) - 1;
            break;
        }
    }
    row = getLetterRow(rowCode);
    if(seats[row][seat]->isFree()){
        seats[row][seat]->free = false;
        return true;
    }
    else return false;
}

/**Airbus*/
Airbus::Airbus(uint16_t fClassPrice, uint16_t eClassPrice, std::queue<std::string> first) {
    std::stringstream ss;
    airbusCount++;
    ss << "ARB" << std::setw(2) << std::setfill('0') << airbusCount;
    plate = ss.str();
    seatRows = 26;
    seatsPerRow = 6;
    auto *f = new FirstClass(fClassPrice);
    auto *e = new EconomyClass(eClassPrice);
    classes.push_back(f);
    classes.push_back(e);
    grounded = true;
    for(int i = 0; i < seatRows; i++){
        std::vector<Seat*> load;
        std::string row = getRowLetter(i);
        Class* c = new Class;
        if(row == first.front()){
            c = new FirstClass;
            first.pop();
        }
        else c = new EconomyClass;
        for(int j = 0; j < seatsPerRow; j++){
            Seat* s = new Seat(row, j + 1, c);
            load.push_back(s);
        }
        seats.push_back(load);
        load.clear();
    }

}

/**Helpers*/
std::string getRowLetter(int i){
    std::string ret;
    if (i <= 26) ret = char(i + 'A');
    else ret = char((i / 26) + 'A') + char((i%26) + 'A');
    return ret;
}

int getLetterRow(std::string l){
    if(l.length() == 1) return l[0] - 'A';
    else return (l[0] - 'A') * LETTER_MAX + (l[1] - 'A');
}
