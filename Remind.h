#ifndef CALENDAR_REMIND_H
#define CALENDAR_REMIND_H



class Remind {
    std::string textOfRemind;
    std::vector<std::string> list;
    int remindDay;
    int remindMonth;
    int remindYear;
public:

    friend class Calendar;

    Remind(){
        this -> remindDay = remindDay;
        this -> remindMonth = remindMonth;
        this -> remindYear = remindYear;
    }

    void enter_text_of_remind();

    void show_remind();

    void delete_remind(int n);

    void loading_from_file(string tmpTextOfRemind);

};

#include "Remind.cpp"

#endif //CALENDAR_REMIND_H
