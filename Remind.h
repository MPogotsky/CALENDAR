#ifndef CALENDAR_REMIND_H
#define CALENDAR_REMIND_H

class Remind : public Template {
public:

    friend class Calendar;

    Remind(){
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }

    void enter_text() override;
    void show() override;

};
#include "Remind.cpp"

#endif //CALENDAR_REMIND_H
