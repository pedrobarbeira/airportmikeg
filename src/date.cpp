//Created by Pedro Barbeira
#include "date.h"

/**
 * Prints date
 * @param out the output line
 */
void Date::print(std::ostream& out) const {
    out << std::setw(2) << std::setfill('0') << day << "/"
        << std::setw(2) << std::setfill('0') << month << "/"
        << std::setw(4) << std::setfill('0') << year;
}

/**
 * Prints time with date
 * @param out the output line
 */
void Time::print(std::ostream& out) const{        //Read up polymorphism and make this proper
    out << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second << " ";
    if(day != 0 && month != 0) {
        out << std::setw(2) << std::setfill('0') << day << "/"
            << std::setw(2) << std::setfill('0') << month << "/";
        if (year != 0)
            out << std::setw(4) << std::setfill('0') << year;
    }
}

/**
 * Prints time without date
 * @param out the desired output line
 */
void Time::printTime(std::ostream& out) const{
    out << std::setw(2) << std::setfill('0') << hour << ":"
        << std::setw(2) << std::setfill('0') << minute << ":"
        << std::setw(2) << std::setfill('0') << second << " ";
}


/**
 * Determines if a year is a leap year
 * @param y the year to be processed
 * @return true if y is leap, false otherwise
 */
bool isleap(uint32_t y){
    if(y % 400 == 0) return true;
    else {
        if (y % 4 == 0 && y % 100 != 0) return true;
        else return false;
    }
}

/**
 * Calculates today's date and time, updating the Time object with those values
 */
void Time::now(){
    time_t now;
    time(&now);
    uint32_t d = 1, m = 1, y = 1970, h, min, s;
    //Gets year counter to current year
    for (int i = 2; now > NORMAL; i++) {
        if ((i % 4) == 0) now -= LEAP;
        else now -= NORMAL;
        y++;
    }
    //Gets month counter to current month
    bool leap = isleap(y);
    for (int i = 1; now > LMONTH && i < 13; i++) {
        switch (i) {
            case 1:case 3:case 5:case 7:case 8:case 10:
            case 12: now -= LMONTH; break;
            case 4:case 6:case 9:
            case 11: now -= SMONTH;break;
            case 2:
                if (leap) now -= LFEB;
                else now -= FEB;
                break;
            default: continue;
        }
        m++;
    }
    //Calculates current day
    d += now / DAY;
    now -= ((d-1) * DAY);
    //Calculates current hour
    h = now / HOUR;
    now -= (h * HOUR);
    //Calculates current minute
    min = now / MINUTE;
    //Calculates current second
    s = now - (min * MINUTE);
    //Updates Time object accordingly
    this->setYear(y);
    this->setMonth(m);
    this->setDay(d);
    this->setHour(h);
    this->setMinute(min);
    this->setSecond(s);
}

bool Date::operator==(const Date& rhs) const{
    return year == rhs.year && month == rhs.month && day == rhs.day;
}

bool Date::operator==(const Time& rhs) const{
    return (*this) == rhs.getDate();
}

bool Date::operator<(const Date& rhs) const {
    if (year == rhs.year) {
        if (month == rhs.month) {
            return day < rhs.day;
        } else return month < rhs.month;
    } else return year < rhs.year;
}

bool Date::operator<(const Time& rhs) const{
    return (*this) < rhs.getDate();
}

bool Time::operator==(const Time& rhs) const{
    bool flag = true;
    if(this->getDate().getDay() != 0 && rhs.getDate().getDay() != 0) {
        flag &= this->getDate() == rhs.getDate();
    }
    flag &= hour == rhs.hour && minute == rhs.minute && second == rhs.second;
    return flag;
}

bool Time::operator==(const Date& rhs) const{
    return this->getDate() == rhs;
}

bool Time::operator<(const Date& rhs) const{
    return this->getDate() < rhs;
}

bool Time::operator<(const Time& rhs) const{
    if(this->getDate().getDay() != 0 && rhs.getDate().getDay() != 0){
        if(this->getDate() != rhs.getDate()){
            return (*this) < rhs.getDate();
        }
    }
    if(hour == rhs.hour){
        if(minute == rhs.minute)
            return second < rhs.second;
        else return minute < rhs.minute;
    }
    else return hour < rhs.hour;
}
