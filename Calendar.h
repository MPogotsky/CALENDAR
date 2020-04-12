#ifndef CALENDAR_CALENDAR_H
#define CALENDAR_CALENDAR_H

#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <string>
#include "Notes.h"
#include "Remind.h"


class Calendar {

    enum enMonth {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    time_t now = time(NULL);
    tm *ltm = localtime(&now);

    int amountOfDays;
    int currentDay;
    int currentMonth;
    int currentYear;
    int beginningOfTheMonth;


    int set_calendar_dates();

    int set_start_of_month(int new_month, int new_year);

public:

    vector<Notes> listOfNotes;
    vector<Remind> listOfReminds;
    int whatDay;
    int month;
    int year;

    Calendar() {
        whatDay = currentDay = ltm->tm_mday;
        month = currentMonth = ltm->tm_mon + 1;
        year = currentYear = ltm->tm_year + 1900;
        this->listOfNotes = listOfNotes;
    }

    void output();

    void show_whole_year();

    int changes_in_date();

    int set_to_default();


    void add_note();

    void show_list_of_notes();

    void delete_note();


    int compare_dates(int day, string requirement);

    void save_data();

    void load_data();


    void add_remind();

    void show_list_of_reminds();

    void delete_remind();

    void show_remind_and_notes_for_current_day();

    ~Calendar() {};
};

#include "Calendar.cpp"


#endif //CALENDAR_CALENDAR_H
