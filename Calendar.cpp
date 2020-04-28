using namespace std;

#include <iomanip>
#include <windows.h>


int Calendar::set_to_default() {
    month = currentMonth;
    year = currentYear;
    whatDay = currentDay;
    return 0;
}

int Calendar::changes_in_date() {
    if (month == 13) {  //Next Year
        month = 1;
        year++;
    }
    if (month == 0) {  //Previous Year
        month = 12;
        year--;
    }
    return month, year;
}

int Calendar::set_calendar_dates() {
    switch (month) {
        case January:
            cout << setw(16) << right << "January";
            amountOfDays = 31;
            break;
        case February:
            cout << setw(18) << right << "February";
            if (year % 4 == 0) {
                amountOfDays = 29;
            } else {
                amountOfDays = 28;
            }
            break;
        case March:
            cout << setw(16) << right << "March";
            amountOfDays = 31;
            break;
        case April:
            cout << setw(16) << right << "April";
            amountOfDays = 30;
            break;
        case May:
            cout << setw(15) << right << "May";
            amountOfDays = 31;
            break;
        case June:
            cout << setw(15) << right << "June";
            amountOfDays = 30;
            break;
        case July:
            cout << setw(15) << right << "July";
            amountOfDays = 31;
            break;
        case August:
            cout << setw(16) << right << "August";
            amountOfDays = 31;
            break;
        case September:
            cout << setw(17) << right << "September";
            amountOfDays = 30;
            break;
        case October:
            cout << setw(16) << right << "October";
            amountOfDays = 31;
            break;
        case November:
            cout << setw(17) << right << "November";
            amountOfDays = 30;
            break;
        case December:
            cout << setw(17) << right << "December";
            amountOfDays = 31;
            break;
    }
    cout << ", " << year << endl;
    return amountOfDays;
}

int Calendar::set_start_of_month(int new_month, int new_year) {
    //The algorithm is taken from: https://ru.wikibooks.org
    if (new_month == 1 || new_month == 2) {
        new_year = new_year - 1;
        new_month = new_month + 10;
    } else {
        new_month = new_month - 2;
    }
    beginningOfTheMonth = ((1 + (31 * new_month) / 12 + new_year + new_year / 4 - new_year / 100 + new_year / 400) % 7);

    return beginningOfTheMonth;
}

int Calendar::compare_dates(int day, string requirement) {
    if (requirement == "note" && !listOfNotes.empty()) {
        for (int i = 0; i < listOfNotes.size(); i++) {
            if (listOfNotes.at(i).noteYear == year && listOfNotes.at(i).noteMonth == month &&
                listOfNotes.at(i).noteDay == day) {
                return i;
            }
        }
    }

    if (requirement == "remind" && !listOfReminds.empty()) {
        for (int i = 0; i < listOfReminds.size(); i++) {
            if (listOfReminds.at(i).remindYear == year && listOfReminds.at(i).remindMonth == month &&
                listOfReminds.at(i).remindDay == day) {
                return i;
            }
        }
    }

    if (requirement == "task" && !listOfTasks.empty()) {
        for (int i = 0; i < listOfTasks.size(); i++) {
            if (listOfTasks.at(i).year == year && listOfTasks.at(i).month == month
                && listOfTasks.at(i).day == day) {
                return i;
            }
        }
    }
    return -1;
}

void Calendar::output() {
    changes_in_date();
    set_calendar_dates();
    set_start_of_month(month, year);
    int n = 0; //Counter for listOfNotes

    cout << "Mon" << setw(5) << "Tue" << setw(5) << "Wed" << setw(5) << "Thu" << setw(5) << "Fri" << setw(5) << "Sat"
         << setw(5) << "Sun" << endl;

    for (int day = 1; day <= amountOfDays; day++) {

        if (day == 1 && beginningOfTheMonth != 1) {
            if (beginningOfTheMonth == 0) {
                cout << setw(30) << ' ' << setw(5) << left << day;
                cout << endl;
            } else {
                cout << setw(5 * (beginningOfTheMonth - 1)) << ' ' << setw(5) << left << day;
            }

        } else {
            //Marking current day with RED color
            if (day == currentDay && month == currentMonth && year == currentYear) {
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console, FOREGROUND_RED);
                cout << setw(5) << left << day;
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                //Marking day with note with BLUE color
                if (compare_dates(day, "note") != -1) {
                    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                    cout << setw(5) << left << day;
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                } else {
                    //Marking day with tasks with GREEN color
                    if (compare_dates(day, "task") != -1) {
                        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(console, FOREGROUND_GREEN);
                        cout << setw(5) << left << day;
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    } else {
                        cout << setw(5) << left << day;
                    }
                }
            }
            if (beginningOfTheMonth % 7 == 0) {
                cout << endl;
            }
        }
        beginningOfTheMonth++;
    }
    cout << "\n";
}

void Calendar::show_whole_year() {
    for (int i = 1; i < 13; i++) {
        month = i;
        output();
    }
}


void Calendar::set_date_to_add_note() {
    cout << "Year: ";
    cin >> year;
    while (year > currentYear + 20 || year < currentYear - 200) {
        cout << "Invalid data, please, try again " << endl;
        cin >> year;
    }
    show_whole_year();


    cout << "\nMonth: ";
    cin >> month;
    while (month > 12 || month < 0) {
        cout << "Invalid data, please, try again " << endl;
        cin >> month;
    }
    output();


    cout << "\nDay: ";
    cin >> whatDay;
    while (whatDay < 0 || whatDay > 31) {
        cout << "Invalid data, please, try again " << endl;
        cin >> whatDay;
    }

}

//Functions with Notes

void Calendar::add_note() {
    Notes note;
    cout << "Please, enter the date where we will place your note:" << endl;

    set_date_to_add_note();

    note.noteYear = year;
    note.noteMonth = month;
    note.noteDay = whatDay;

    int requirement = 0;
    for (int n = 0; n < listOfNotes.size(); n++) {
        if (note.noteYear == listOfNotes.at(n).noteYear &&
            note.noteMonth == listOfNotes.at(n).noteMonth &&
            note.noteDay == listOfNotes.at(n).noteDay) {
            listOfNotes.at(n).enter_note_text();
            requirement = 1;
        }
    }
    cout << endl;
    if (requirement == 0) {
        note.enter_note_text();
        listOfNotes.push_back(note);
    }
}

void Calendar::show_list_of_notes() {
    if (!listOfNotes.empty()) {
        for (int i = 0; i < listOfNotes.size(); i++) {
            cout << "#" << i + 1 << " ";
            listOfNotes.at(i).show_note();
        }
    } else {
        cout << "List of notes is empty" << endl;
    }
}

void Calendar::delete_note() {
    int n = 0;
    cout << "Please, chose date: " << endl;

    show_list_of_notes();

    cin >> n;
    listOfNotes.at(n - 1).show_note();
    if (listOfNotes.at(n - 1).list.size() == 1) {
        cout << "Deleted." << endl;
        listOfNotes.erase(listOfNotes.begin() + (n - 1));
    } else {
        cout << "Please, enter number of the note: " << endl;
        int k = 0;
        cin >> k;
        listOfNotes.at(n - 1).delete_note(k - 1);
    }
}

// Functions with reminds

void Calendar::add_remind() {
    Remind remind;
    cout << "Please, enter the date where we will place your remind:" << endl;

    set_date_to_add_note();

    remind.remindYear = year;
    remind.remindMonth = month;
    remind.remindDay = whatDay;

    int requirement = 0;
    for (int n = 0; n < listOfReminds.size(); n++) {
        if (remind.remindYear == listOfReminds.at(n).remindYear &&
            remind.remindMonth == listOfReminds.at(n).remindMonth &&
            remind.remindDay == listOfReminds.at(n).remindDay) {
            listOfReminds.at(n).enter_text_of_remind();
            requirement = 1;
        }
    }
    cout << endl;
    if (requirement == 0) {
        remind.enter_text_of_remind();
        listOfReminds.push_back(remind);
    }
}

void Calendar::show_list_of_reminds() {
    if (!listOfReminds.empty()) {
        for (int i = 0; i < listOfReminds.size(); i++) {
            cout << "#" << i + 1 << " ";
            listOfReminds.at(i).show_remind();
        }
    } else {
        cout << "List of reminds is empty" << endl;
    }
}

void Calendar::delete_remind() {
    int n = 0;
    cout << "Please, chose date: " << endl;

    show_list_of_reminds();

    cin >> n;
    listOfReminds.at(n - 1).show_remind();
    if (listOfReminds.at(n - 1).list.size() == 1) {
        cout << "Deleted." << endl;
        listOfReminds.erase(listOfReminds.begin() + (n - 1));
    } else {
        cout << "Please, enter number of the remind: " << endl;
        int k = 0;
        cin >> k;
        listOfReminds.at(n - 1).delete_remind(k - 1);
    }
}

void Calendar::show_remind_and_notes_for_current_day() {
    int requirementForCycleOrPos;
    int plusDay = 1;
    while (plusDay < 4) {
        requirementForCycleOrPos = compare_dates(currentDay + plusDay, "remind");
        if (requirementForCycleOrPos != -1) {
            cout << "You have some upcoming events: " << endl;
            listOfReminds.at(requirementForCycleOrPos).show_remind();
        } else {
            plusDay++;
        }
    }

    requirementForCycleOrPos = compare_dates(currentDay, "remind");
    if (requirementForCycleOrPos != -1) {
        cout << "Don`t forget about: " << endl;
        listOfReminds.at(requirementForCycleOrPos).show_remind();
    }
    requirementForCycleOrPos = compare_dates(currentDay, "note");
    if (requirementForCycleOrPos != -1) {
        cout << "Notes for this day: " << endl;
        listOfNotes.at(requirementForCycleOrPos).show_note();
    }

    requirementForCycleOrPos = compare_dates(currentDay, "task");
    if (requirementForCycleOrPos != -1) {
        cout << "Tasks: " << endl;
        listOfTasks.at(requirementForCycleOrPos).show_tasks();
    }


}

// Functions with tasks

void Calendar::add_task_list() {
    Task task;
    cout << "Please, enter the date where we will place your task:" << endl;

    set_date_to_add_note();

    task.year = year;
    task.month = month;
    task.day = whatDay;

    cout << endl;
    task.add_task();
    listOfTasks.push_back(task);
}

void Calendar::show_list_of_tasks() {
    if (!listOfTasks.empty()) {
        for (int i = 0; i < listOfTasks.size(); i++) {
            cout << "#" << i + 1 << " ";
            listOfTasks.at(i).show_tasks();
        }
    } else {
        cout << "List of tasks is empty" << endl;
    }
}

void Calendar::change_task_status() {
    int number;
    show_list_of_tasks();
    cout << "Please, chose list (#): " << endl;
    cin >> number;
    if (number > listOfTasks.size() || number < 1) {
        cout << "Invalid data. Please, try again." << endl;
        cin >> number;
    }
    listOfTasks.at(number - 1).change_status();
}

void Calendar::delete_task() {
    int number;
    show_list_of_tasks();
    cout << "Do want to delete whole list or only task? " << endl;
    cout << "\t1.List\t2.Only task" << endl;
    cin >> number;
    if (number == 1) {
        cout << "Please, chose list you want to delete (#): " << endl;
        cin >> number;
        if (number > listOfTasks.size() || number < 1) {
            cout << "Invalid data. Please, try again." << endl;
            cin >> number;
        }
        listOfTasks.erase(listOfTasks.begin() + (number - 1));
    }

    if (number == 2) {
        cout << "Please, chose list (#): " << endl;
        cin >> number;
        if (number > listOfTasks.size() || number < 1) {
            cout << "Invalid data. Please, try again." << endl;
            cin >> number;
        }
        listOfTasks.at(number - 1).delete_task();
    }

}

void Calendar::save_data() {
    for (int i = 0; i < listOfNotes.size(); i++) {
        listOfNotes.at(i).save_data();
    }

    for (int i = 0; i < listOfReminds.size(); i++) {
        listOfReminds.at(i).save_data();
    }

    for (int i = 0; i < listOfTasks.size(); i++) {
        listOfTasks.at(i).save_data();
    }
}

void Calendar::load_data() {

    ifstream NotesData("NotesData.txt");
    if (NotesData.is_open()) {
        while (!NotesData.eof()) {
            int amountOfNotesWhileSavingData;
            Notes note;
            NotesData >> amountOfNotesWhileSavingData;
            NotesData >> note.noteDay;
            NotesData >> note.noteMonth;
            NotesData >> note.noteYear;
            NotesData.ignore();
            for (int i = 0; i < amountOfNotesWhileSavingData; i++) {
                string tmpTextOfNote;
                getline(NotesData, tmpTextOfNote);
                note.loading_from_file(tmpTextOfNote);
                NotesData.sync();
            }
            listOfNotes.push_back(note);
        }
        NotesData.close();
        listOfNotes.pop_back();
    } else {
        cout << "Can't find file for loading notes. No saved data yet." << endl;
    }

    ifstream RemindsData("RemindsData.txt");
    if (RemindsData.is_open()) {
        while (!RemindsData.eof()) {
            int amountOfRemindsWhileSavingData;
            Remind remind;
            RemindsData >> amountOfRemindsWhileSavingData;
            RemindsData >> remind.remindDay;
            RemindsData >> remind.remindMonth;
            RemindsData >> remind.remindYear;
            RemindsData.ignore();
            for (int i = 0; i < amountOfRemindsWhileSavingData; i++) {
                string tmpTextOfRemind;
                getline(RemindsData, tmpTextOfRemind);
                remind.loading_from_file(tmpTextOfRemind);
                RemindsData.sync();
            }
            listOfReminds.push_back(remind);
        }
        RemindsData.close();
        listOfReminds.pop_back();
    } else {
        cout << "Can't find file for loading reminds. No saved data yet." << endl;
    }

    ifstream TasksData("TasksData.txt");
    if (TasksData.is_open()) {
        while (!TasksData.eof()) {
            int amountOfTasksWhileSavingData;
            Task task;
            TasksData >> amountOfTasksWhileSavingData;
            TasksData >> task.day;
            TasksData >> task.month;
            TasksData >> task.year;
            TasksData.ignore();
            for (int i = 0; i < amountOfTasksWhileSavingData; i++) {
                string tmpTextOfTheTask;
                getline(TasksData, tmpTextOfTheTask);
                task.load_data(tmpTextOfTheTask);
                TasksData.sync();
            }
            listOfTasks.push_back(task);
        }
        TasksData.close();
        listOfTasks.pop_back();
    } else {
        cout << "Can't find file for loading tasks. No saved data yet." << endl;
    }

}