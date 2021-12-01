//Created by Pedro Barbeira
#include "date.h"

uint32_t MINUTE = 60;                               //seconds in a minute
uint32_t HOUR = 60 * MINUTE;                        //seconds in an hour
uint32_t DAY = 24 * HOUR;                           //seconds in a day
uint32_t FEB = 28 * DAY;                            //seconds in normal year february
uint32_t LFEB = 29 * DAY;                           //seconds in leap year february
uint32_t SMONTH = 30 * DAY;                         //seconds in "short" month
uint32_t LMONTH = 31 * DAY;                         //seconds in "large" month
uint32_t NORMAL = 7 * LMONTH + 4 * SMONTH + FEB;    //seconds in a normal year
uint32_t LEAP = 7 * LMONTH + 4 * SMONTH + LFEB;     //seconds in a leap year

/**
 * Prints date to desired output line
 * @param out the output line
 */
void Time::print(std::ostream& out) const{        //Read up polymorphism and make this proper
    out << std::setw(2) << std::setfill('0') <<this->getHour() << ":"
        << std::setw(2) << std::setfill('0') << this->getMinute() << ":"
        << std::setw(2) << std::setfill('0') << this->getSecond() <<" "
        << std::setw(2) << std::setfill('0') << this->getDay() << "/"
        << std::setw(2) << std::setfill('0') << this->getMonth() << "/"
        << std::setw(4) << std::setfill('0')  << this->getYear()
        << '\n';
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
Date * Time::now(){
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