#ifndef CALENDAR_NOTES_H
#define CALENDAR_NOTES_H


class Notes {
    struct note_structure{
        char textOfNote[1000];
    };
    std::vector<note_structure> list;

public:
    friend class Calendar;
    int noteDay;
    int noteMonth;
    int noteYear;

    Notes() {
        this->noteDay = noteDay;
        this->noteMonth = noteMonth;
        this->noteYear = noteYear;
    };

    void enter_note_text();

    void show_note();

};

#include "Notes.cpp"

#endif //CALENDAR_NOTES_H
