#ifndef CALENDAR_TASK_H
#define CALENDAR_TASK_H


class Task : public Template {

    string titleOfTheTaskList;

public:

    friend class Calendar;

    Task() {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void add_task();

    void show() override;

    void change_status();

    void delete_task();

};

#include "Task.cpp"

#endif //CALENDAR_TASK_H
