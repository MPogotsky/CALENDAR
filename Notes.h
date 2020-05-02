#ifndef CALENDAR_NOTES_H
#define CALENDAR_NOTES_H


class Notes {

    std::string textOfNote;
    std::vector<std::string> list;

    int day;
    int month;
    int year;

public:

    friend class Calendar;

    Notes() {
        this->day = day;
        this->month = month;
        this->year = year;
    };

    void enter_note_text();

    void show_note();

    void delete_note(int n);

    void save_data(std::ostream& NotesData);

    void loading_from_file(std::istream& NotesData);
};


#include "Notes.cpp"

#endif //CALENDAR_NOTES_H
