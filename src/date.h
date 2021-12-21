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
    /**-----Constructors-----*/
    /**
     * Constructor for Date objects. Doubles as a default constructor if
     * no parameters are given
     * @param d the day
     * @param m the month
     * @param y the year
     */
    explicit Date(uint16_t d = 0, uint16_t m = 0, uint16_t y = 0):
    day(d), month(m), year(y){};
    /**-----Getters-----*/
    /**
     * Getter for the day attribute
     * @return the day attribute
     */
    uint16_t getDay() const{
        return day;
    }

    /**
     * Getter for the month attribute
     * @return the month attribute
     */
    uint16_t getMonth() const{
        return month;
    }

    /**
     * Getter for the year attribute
     * @return the year attribute
     */
    uint16_t getYear() const{
        return year;
    }
    /**-----Setters-----*/
    /**
     * Setter for the day attribute
     * @param d the new day
     */
    void setDay(uint16_t d){
        day = d;}

    /**
     * Setter for the month attribute
     * @param m the new month
     */
    void setMonth(uint16_t m){
        month = m;}

    /**
     * Setter for the year attribute
     * @param y the new year
     */
    void setYear(uint16_t y){
        year = y;}
    /**
     * Prints date
     * @param out the desired output line
     */
    virtual void print(std::ostream& out) const;

    /**
     * Compares two dates to see if they are equal
     * @param rhs the right side of the comparison
     * @return true if dates are equal, false otherwise
     */
    virtual bool operator==(const Date& rhs) const;

    /**
     * Compares a Date and a Time to see if they are equal
     * @param rhs the right side of the comparion
     * @return true if they are equal, false otherwise
     */
    virtual bool operator==(const Time& rhs) const;

    /**
     * Compares two dates to see if which ones is larger
     * @param rhs the right side of the comparison
     * @return true if left side is smaller then rhs, false otherwise
     */
    virtual bool operator<(const Date& rhs) const;

    /**
     * Compares a Date and a Time to see which one is larger
     * @param rhs the right side of the comparison
     * @return true if left side is less than right side, false otherwise
     */
    virtual bool operator<(const Time& rhs) const;

    /**
     * Compares two Dates to see if right side is smaller or equal to right side
     * @param rhs the right side of the comparison
     * @return true if left side is less than or equal the right side, false otherwise
     */
    virtual bool operator<=(const Date& rhs) const{
        return (*this) == rhs || (*this) < rhs;
    }

    /**
     * Compares a Date and a Time to see if right side is smaller oe equal to
     * right side
     * @param rhs the right side of the comparison
     * @return true if left side is less than or equall to the right side, false
     * otherwise
     */
    virtual bool operator<=(const Time& rhs) const{
        return (*this) == rhs || (*this) < rhs;
    }

    /**
     * Compares two Dates to see if they are different
     * @param rhs the right side of the comparison
     * @return true if they are different, false otherwise
     */
    virtual bool operator!=(const Date& rhs) const{
        if((*this) == rhs) return false;
        else return true;
    }

    /**
     * Compares a Date and a Time to see if they are different
     * @param rhs the right side of the comparison
     * @return true if they are different, false otherwise
     */
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
    /**-----Constructors-----*/
    /**
     * Base constructor for the Time class. Initializes an empty date and
     * creates a Time object with the given hour, minute and second. Doubles
     * as a default constructor if no parameters are given
     * @param h the hour
     * @param m the minute
     * @param s the second
     */
    explicit Time(uint16_t h = 0, uint16_t m = 0, uint16_t s = 0):
    Date(), hour(h), minute(m), second(s){}

    /**
     * Constructor for the Time class. Allows user to initialize a Time object
     * with specific Date and Time. Initializes the Date parent object with the
     * given parameters
     * @param d the day
     * @param m the month
     * @param y the year
     * @param h the hour
     * @param min the minute
     * @param s the second
     */
    Time(uint16_t d, uint16_t m, uint16_t y,
         uint16_t h, uint16_t min, uint16_t s):
        Date(d, m, y), hour(h), minute(min), second(s){};

    /**
     * Constructor for the Time class. Receives a string with a date and time
     * in the HH:MM:SS DD/MM/YYYY format and parses it, converting it into a
     * proper Time object. Used in the Data Load module
     * @param s the string with the time and date
     */
    Time(const std::string& s);

    /**-----Getter-----*/
    /**
     * Getter for the hour attribute
     * @return the hour attribute
     */
    uint16_t getHour() const{
        return hour;};

    /**
     * Getter for the minute attribute
     * @return the minute attribute
     */
    uint16_t getMinute() const{
        return minute;};

    /**
     * Getter for the second attribute
     * @return the second attribute
     */
    uint16_t getSecond() const{
        return second;};

    /**
     * Getter for the Date of the object
     * @return the Date of the object
     */
    Date getDate() const{
        return Date(day,month, year);
    }

    /**
     * Prints time with date
     * @param out the output line
      */
    void print(std::ostream& out) const override;

    /**
     * Prints time without date
     * @param out the desired output line
     */
    void printTime(std::ostream& out = std::cout) const;

    /**
     * Prints date without time
     * @param out the desired output line
     */
    void printDate(std::ostream& out = std::cout) const;

    /**-----Setters-----*/
    /**
     * Setter for the hour attribute
     * @param h the new hour
     */
    void setHour(uint16_t h){
        hour = h;};

    /**
     * Setter for the minute attribute
     * @param m the new minute
     */
    void setMinute(uint16_t m){
        minute = m;};

    /**
     * Setter for the second attribute
     * @param s the new second
     */
    void setSecond(uint16_t s){
        second = s;};

    /**
     * Uses ctime to calculate how many second have passed since January 1st
     * 1970. Parses result using the macros defined at the top of date.h in
     * order to reach the date and time when it was called. Updates the
     * Time object accordingly, setting it with the values refering to the
     * date and time when the method was called.
     */
    void now();

    /**
     * Compares two Time objects to see if they are equal
     * @param rhs the right side of the comparion
     * @return true if they are equal, false otherwise
     */
    bool operator==(const Time& rhs) const override;

    /**
     * Compares a Time and a Date to see if they are equal
     * @param rhs the right side of the comparison
     * @return true if both Dates are equal, false otherwise
     */
    bool operator==(const Date& rhs) const override;

    /**
     * Compares two Time objects to see if left side is less than right side
     * @param rhs the right side of the comparison
     * @return true if left side is less than right side, false otherwise
     */
    bool operator<(const Time& rhs) const override;

    /**
     * Compares a Time and a Date object to see if left side is less than
     * right side
     * @param rhs the right side of the comparison
     * @return true if left side's Date is less than right side, false otherwise
     */
    bool operator<(const Date& rhs) const override;

    /**
     * Compares two Time objects to see if left side is less than or
     * equal to the right side
     * @param rhs the right side of the comparison
     * @return true if left side is less than or equal to right side,
     * false otherwise
     */
    bool operator<=(const Time& rhs) const override{
        return (*this) == rhs || (*this) < rhs;
    }

    /**
     * Compares a Time and a Date object to see if left side's date is
     * less than or equal to rigth side
     * @param rhs the right side of the comparison
     * @return true if left side's Date is less than or equal to the right side,
     * false otherwise
     */
    bool operator<=(const Date& rhs) const override{
        return (*this) == rhs || (*this) < rhs;
    }

    /**
     * Compares two Time objects to see if they are different
     * @param rhs the right side of the comparison
     * @return true if they are different, false otherwise
     */
    bool operator!=(const Time& rhs) const override{
        if((*this) == rhs) return false;
        else return true;
    }

    /**
     * Compares a Time and a Date to see if they are different
     * @param rhs the right side of the comparison
     * @return true if this Date is different from right side, false otherwise
     */
    bool operator !=(const Date& rhs) const override{
        return this->getDate() != rhs;
    }
};

#endif //AIPORTMIKEG_DATE_H
