//Created by Pedro Barbeira (up2103603693)
#ifndef AIPORTMIKEG_DATE_H
#define AIPORTMIKEG_DATE_H
#include <iostream>
#include <iomanip>
#include <fstream>

class Date{
    uint16_t day;
    uint16_t month;
    uint16_t year;
public:
    /**Constructors*/
    Date():day(0), month(0), year(0){};
    Date(uint16_t d, uint16_t m, uint16_t y):
    day(d), month(m), year(y){};
    /**Getters*/
    uint16_t getDay() const{
        return day;};
    uint16_t getMonth() const{
        return month;};
    uint16_t getYear() const{
        return year;};
    /**Setters*/
    void setDay(uint16_t d){
        day = d;};
    void setMonth(uint16_t m){
        month = m;};
    void setYear(uint16_t y){
        year = y;};
};

class Time: public Date{
    uint16_t hour;
    uint16_t minute;
    uint16_t second;
public:
    /**Constructors*/
    Time(): Date(), hour(0), minute(0), second(0){};
    Time(uint16_t h, uint16_t m, uint16_t s):
    Date(), hour(h), minute(m), second(s){}
    Time(uint16_t d, uint16_t m, uint16_t y, uint16_t h, uint16_t min, uint16_t s):
    Date(d, m, y), hour(h), minute(min), second(s){};
    /**Getters*/
    uint16_t getHour() const{
        return hour;};
    uint16_t getMinute() const{
        return minute;};
    uint16_t getSecond() const{
        return second;};
    void print(std::ostream& out) const{        //Read up polymorphism and make this proper
        out << std::setw(2) << std::setfill('0') <<this->getHour() << ":"
            << std::setw(2) << std::setfill('0') << this->getMinute() << ":"
            << std::setw(2) << std::setfill('0') << this->getSecond() <<" "
            << std::setw(2) << std::setfill('0') << this->getDay() << "/"
            << std::setw(2) << std::setfill('0') << this->getMonth() << "/"
            << std::setw(4) << std::setfill('0')  << this->getYear()
            << '\n';
    }
    /**Setters*/
    void setHour(uint16_t h){
        hour = h;};
    void setMinute(uint16_t m){
        minute = m;};
    void setSecond(uint16_t s){
        second = s;};
    void now();

};

#endif //AIPORTMIKEG_DATE_H
