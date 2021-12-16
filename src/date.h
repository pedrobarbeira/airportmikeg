//Created by Pedro Barbeira (up2103603693)
#ifndef AIPORTMIKEG_DATE_H
#define AIPORTMIKEG_DATE_H

#include <iostream>
#include <iomanip>
#include <fstream>

static int MINUTE   =    60;                                  //seconds in a minute
static int  HOUR    =     60 * MINUTE;                         //seconds in an hour
static int DAY      =    24 * HOUR;                           //seconds in a day
static int FEB      =    28 * DAY;                            //seconds in normal year february
static int LFEB     =    29 * DAY;                            //seconds in leap year february
static int SMONTH   =    30 * DAY;                            //seconds in "short" month
static int LMONTH   =    31 * DAY;                            //seconds in "large" month
static int NORMAL   =    7 * LMONTH + 4 * SMONTH + FEB;       //seconds in a normal year
static int LEAP     =    7 * LMONTH + 4 * SMONTH + LFEB;      //seconds in a leap year

class Time;

class Date{
protected:
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
        return day;
    }
    uint16_t getMonth() const{
        return month;
    }
    uint16_t getYear() const{
        return year;
    }
    /**Setters*/
    void setDay(uint16_t d){
        day = d;}
    void setMonth(uint16_t m){
        month = m;}
    void setYear(uint16_t y){
        year = y;}
    virtual void print(std::ostream& out = std::cout) const;
    virtual bool operator==(const Date& rhs) const;
    virtual bool operator==(const Time& rhs) const;
    virtual bool operator<(const Date& rhs) const;
    virtual bool operator<(const Time& rhs) const;
    virtual bool operator<=(const Date& rhs) const{
        return (*this) == rhs || (*this) < rhs;
    }
    virtual bool operator<=(const Time& rhs) const{
        return (*this) == rhs || (*this) < rhs;
    }
    virtual bool operator!=(const Date& rhs) const{
        if((*this) == rhs) return false;
        else return true;
    }
    virtual bool operator!=(const Time& rhs) const{
        if((*this) == rhs) return false;
        else return true;
    }
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
    Date getDate() const{
        return Date(day,month, year);
    }
    void print(std::ostream& out = std::cout) const;
    /**Setters*/
    void setHour(uint16_t h){
        hour = h;};
    void setMinute(uint16_t m){
        minute = m;};
    void setSecond(uint16_t s){
        second = s;};
    void now();
    bool operator==(const Time& rhs) const override;
    bool operator==(const Date& rhs) const override;
    bool operator<(const Time& rhs) const override;
    bool operator<(const Date& rhs) const override;
    bool operator<=(const Time& rhs) const override{
        return (*this) == rhs || (*this) < rhs;
    }
    bool operator<=(const Date& rhs) const override{
        return (*this) == rhs || (*this) < rhs;
    }
    bool operator!=(const Time& rhs) const override{
        if((*this) == rhs) return false;
        else return true;
    }
    bool operator !=(const Date& rhs) const override{
        return this->getDate() != rhs;
    }
};

#endif //AIPORTMIKEG_DATE_H
