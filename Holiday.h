#ifndef CALENDAR_HOLIDAY_H
#define CALENDAR_HOLIDAY_H


class Holiday {
private:
    int day;
    int month;
    string textOfHoliday;
public:

    friend class Calendar;

    Holiday() {
        this->day = day;
        this->month = month;
        this->textOfHoliday = textOfHoliday;
    }
    void show_holiday(int year);
};

#include "Holiday.cpp"

#endif //CALENDAR_HOLIDAY_H
