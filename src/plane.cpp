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
    handBag = nullptr;
}

/**-----Cabin-----*/
Cabin::Cabin(uint16_t sRows, uint16_t sPerRow, std::vector<Class*> v, std::queue<std::string> first){
    seatRows = sRows;
    seatsPerRow = sPerRow;
    capacity = seatRows * seatsPerRow;
    for(int i = 0; i < seatRows; i++){
        std::vector<Seat*> load;
        std::string row = getRowLetter(i);
        Class* c;
        if(row == first.front()){
            c = v[0];
            first.pop();
        }
        else c = v[2];
        for(int j = 0; j < seatsPerRow; j++){
            Seat* s = new Seat(row, j + 1, c);
            load.push_back(s);
        }
        seats.push_back(load);
        load.clear();
    }
}

Cabin::Cabin(uint16_t sRows, uint16_t sPerRow, std::vector<Class*> v, std::queue<std::string> &first, std::queue<std::string> &biz) {
    seatRows = sRows;
    seatsPerRow = sPerRow;
    for(int i = 0; i < seatRows; i++){
        std::vector<Seat*> load;
        std::string row = getRowLetter(i);
        Class* c;
        if(row == first.front()){
            c = v[0];
            first.pop();
        }
        else if(row == biz.front()){
            c = v[1];
            biz.pop();
        }
        else c = v[2];
        for(int j = 0; j < seatsPerRow; j++){
            Seat* s = new Seat(row, j + 1, c);
            load.push_back(s);
        }
        seats.push_back(load);
        load.clear();
    }
}

/**Plane*/
Plane::~Plane(){
    for(auto it : classes)
        delete it;
    delete cabin;
}

int Plane::freeSeatNum() const{
    int count = 0;
    for(int i = 0; i < cabin->seatRows; i++){
        for(int j = 0; j < cabin->seatsPerRow; j++)
            if(cabin->seats[i][j]->isFree()) count++;
    }
    return count;
}

void Plane::showSeats() const{
    std::string row;
    for(int j = cabin->seatsPerRow; j >= 0; j--){
        for(int i = 0; i < cabin->seatRows; i++){
            if(j == cabin->seatsPerRow) {
                if(i == 0)std::cout << std::setw(4) << std::setfill(' ') << getRowLetter(i);
                else std::cout << std::setw(4) << std::setfill(' ') << getRowLetter(i);
            }
            else {
                if (i == 0) std::cout << j + 1;
                std::cout << " [";
                if (cabin->seats[i][j]->isFree()) std::cout << 'o';
                else std::cout << 'x';
                std::cout << "]";

            }
        }
        std::cout << '\n';
    }
}

Seat* Plane::bookSeat(std::string code){
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
    if(cabin->seats[row][seat]->isFree()){
        cabin->seats[row][seat]->takeSeat();
        return cabin->seats[row][seat];
    }
    else return nullptr;
}

/**Airbus*/
Airbus::Airbus(std::queue<std::string>& first) {
    std::stringstream ss;
    airbusCount++;
    ss << "ARB" << std::setw(2) << std::setfill('0') << airbusCount;
    plate = ss.str();
    auto *f = new FirstClass();
    auto *e = new EconomyClass();
    classes.push_back(f);
    classes.push_back(nullptr);
    classes.push_back(e);
    grounded = true;
    cabin = new Cabin(26, 6, classes, first);
}

Other::Other(uint16_t rows, uint16_t seatPerRow, std::queue<std::string> first) {
    std::stringstream ss;
    otherCount++;
    ss << "OTR" << std::setw(2) << std::setfill('0') << otherCount;
    plate = ss.str();
    auto *f = new FirstClass();
    auto *e = new EconomyClass();
    classes.push_back(f);
    classes.push_back(nullptr);
    classes.push_back(e);
    grounded = true;
    cabin = new Cabin(rows, seatPerRow, classes, first);
}

Other::Other(uint16_t rows, uint16_t seatPerRow, std::queue<std::string> first, std::queue<std::string> biz) {
    std::stringstream ss;
    otherCount++;
    ss << "OTR" << std::setw(2) << std::setfill('0') << otherCount;
    plate = ss.str();
    auto *f = new FirstClass();
    auto *b = new BusinessClass();
    auto *e = new EconomyClass();
    classes.push_back(f);
    classes.push_back(b);
    classes.push_back(e);
    grounded = true;
    cabin = new Cabin(rows, seatPerRow, classes, first, biz);

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
