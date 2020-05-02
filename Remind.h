#ifndef CALENDAR_REMIND_H
#define CALENDAR_REMIND_H

class Remind {
    std::string textOfRemind;
    std::vector<std::string> list;
    int day;
    int month;
    int year;

public:

    friend class Calendar;

    Remind(){
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }

    void enter_text_of_remind();

    void show_remind();

    void delete_remind(int n);

    void save_data();

    void loading_from_file(string tmpTextOfRemind);

};

#include "Remind.cpp"

#endif //CALENDAR_REMIND_H
