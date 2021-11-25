//Created by Pedro Barbeira (up2103603693)
#ifndef AIPORTMIKEG_DATE_H
#define AIPORTMIKEG_DATE_H
#include <iostream>
#include <fstream>

class Date{
    uint16_t day;
    uint16_t month;
    uint16_t year;
public:
    Date():day(0), month(0), year(0){};
    Date(uint16_t d, uint16_t m, uint16_t y):
    day(d), month(m), year(y){};

    uint16_t getDay() const{
        return day;};
    uint16_t getMonth() const{
        return month;};
    uint16_t getYear() const{
        return year;};
};

class Time: public Date{
    uint16_t hour;
    uint16_t minute;
    uint16_t second;
private:
    Time(): Date(), hour(0), minute(0), second(0){};
    Time(uint16_t h, uint16_t m, uint16_t s):
    Date(), hour(h), minute(m), second(s){}
    Time(uint16_t d, uint16_t m, uint16_t y, uint16_t h, uint16_t min, uint16_t s):
    Date(d, m, y), hour(h), minute(min), second(s){};

    uint16_t getHour() const{
        return hour;};
    uint16_t getMin() const{
        return minute;};
    uint16_t getSec() const{
        return second;};
    void print(std::ostream& out) const{        //Read up polymorphism and make this proper
        out << this->getHour() << ":" << this->getMin() << ":" << this->getSec() <<
            " " << this->getDay() << "/" << this->getMonth() << "/" << this->getYear();
    }

};

#endif //AIPORTMIKEG_DATE_H
