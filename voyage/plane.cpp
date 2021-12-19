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
/*
Seat::~Seat(){
    delete classe;
    delete handBag;
}
*/
/**Plane*/
Plane::~Plane(){
    for(auto it : classes)
        delete it;
    for(auto it: cabin->seats)
        for(auto seat: it)
            delete seat;
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
Airbus::Airbus(std::queue<std::string> first) {
    std::stringstream ss;
    airbusCount++;
    ss << "ARB" << std::setw(2) << std::setfill('0') << airbusCount;
    plate = ss.str();
    cabin = new Cabin;
    cabin->seatRows = 26;
    cabin->seatsPerRow = 6;
    vector<Class*> loadClass(3, nullptr);
    auto *f = new FirstClass();
    auto *e = new EconomyClass();
    loadClass[0] = f;
    loadClass[2] = e;
    grounded = true;
    for(int i = 0; i < cabin->seatRows; i++){
        std::vector<Seat*> load;
        std::string row = getRowLetter(i);
        Class* c = new Class;
        if(row == first.front()){
            c = f;
            first.pop();
        }
        else c = e;
        for(int j = 0; j < cabin->seatsPerRow; j++){
            Seat* s = new Seat(row, j + 1, c);
            load.push_back(s);
        }
        cabin->seats.push_back(load);
        load.clear();
    }

}

Other::Other(uint16_t rows, uint16_t seatPerRow, uint16_t fClassPrice, uint16_t eClassPrice, std::queue<std::string> first) {
    std::stringstream ss;
    otherCount++;
    ss << "OTR" << std::setw(2) << std::setfill('0') << otherCount;
    plate = ss.str();
    this->cabin = new Cabin;
    cabin->seatRows = rows;
    cabin->seatsPerRow = seatPerRow;
    auto *f = new FirstClass(fClassPrice);
    auto *e = new EconomyClass(eClassPrice);
    classes.push_back(f);
    classes.push_back(e);
    grounded = true;
    for(int i = 0; i < cabin->seatRows; i++){
        std::vector<Seat*> load;
        std::string row = getRowLetter(i);
        Class* c;
        if(row == first.front()){
            c = f;
            first.pop();
        }
        else c = e;
        for(int j = 0; j < cabin->seatsPerRow; j++){
            Seat* s = new Seat(row, j + 1, c);
            load.push_back(s);
        }
        cabin->seats.push_back(load);
        load.clear();
    }
}

Other::Other(uint16_t rows, uint16_t seatPerRow, uint16_t fClassPrice, uint16_t bClassPrice, uint16_t eClassPrice,
             std::queue<std::string> first, std::queue<std::string> biz) {
    std::stringstream ss;
    otherCount++;
    ss << "OTR" << std::setw(2) << std::setfill('0') << otherCount;
    plate = ss.str();
    cabin->seatRows = rows;
    cabin->seatsPerRow = seatPerRow;
    auto *f = new FirstClass(fClassPrice);
    auto *b = new BusinessClass(bClassPrice);
    auto *e = new EconomyClass(eClassPrice);
    classes.push_back(f);
    classes.push_back(e);
    grounded = true;
    for(int i = 0; i < cabin->seatRows; i++){
        std::vector<Seat*> load;
        std::string row = getRowLetter(i);
        Class* c;
        if(row == first.front()){
            c = f;
            first.pop();
        }
        else if(row == biz.front()){
            c = b;
            biz.pop();
        }
        else c = e;
        for(int j = 0; j < cabin->seatsPerRow; j++){
            Seat* s = new Seat(row, j + 1, c);
            load.push_back(s);
        }
        cabin->seats.push_back(load);
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
