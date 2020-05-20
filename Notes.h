#ifndef CALENDAR_NOTES_H
#define CALENDAR_NOTES_H


class Notes : public Template {
public:

    friend class Calendar;

    Notes() {
        this->day = day;
        this->month = month;
        this->year = year;
    };

    void enter_text() override;
    void show() override;
};


#include "Notes.cpp"

#endif //CALENDAR_NOTES_H
