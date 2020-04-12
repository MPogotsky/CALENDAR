#ifndef CALENDAR_NOTES_H
#define CALENDAR_NOTES_H


class Notes {
    std::string textOfNote;
    std::vector<std::string> list;

    int noteDay;
    int noteMonth;
    int noteYear;

public:

    friend class Calendar;

    Notes() {
        this->noteDay = noteDay;
        this->noteMonth = noteMonth;
        this->noteYear = noteYear;
    };
    void enter_note_text();

    void show_note();

    void delete_note(int n);

    void loading_from_file(std::string tmpTextOfNote);
};


#include "Notes.cpp"

#endif //CALENDAR_NOTES_H
