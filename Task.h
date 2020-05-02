#ifndef CALENDAR_TASK_H
#define CALENDAR_TASK_H


class Task {

    int day;
    int month;
    int year;

    string titleOfTheTaskList;
    string textOfTheTask;
    vector<string> tasksList;

public:

    friend class Calendar;

    Task() {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void add_task();

    void show_tasks();

    void change_status();

    void delete_task();

    void save_data();

    void load_data(string tmpTextOfTheTask);

};

#include "Task.cpp"

#endif //CALENDAR_TASK_H
