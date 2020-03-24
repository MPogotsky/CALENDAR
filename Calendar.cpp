using namespace std;

#include <iomanip>
#include <windows.h>

int Calendar::set_to_default() {
    month = currentMonth;
    year = currentYear;
    whatDay = currentDay;
    return month, year, whatDay;
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
    cout << ", " << currentYear << endl;
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
                //Marking days with notes using BLUE color
                    if (listOfNotes.size()!=0 && n<listOfNotes.size() && day == listOfNotes.at(n).noteDay && month == listOfNotes.at(n).noteMonth &&
                        year == listOfNotes.at(n).noteYear) {
                        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(console, FOREGROUND_BLUE);
                        cout << setw(5) << left << day;
                        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        n++;
                    }
                else {
                    cout << setw(5) << left << day;
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

void Calendar::add_note() {
    Notes note;
    cout << "Please, the date where we will place your note:" << endl;

    cout << "Year: ";
    cin >> year;
    show_whole_year();
    note.noteYear = year;

    cout << "\nMonth: ";
    cin >> month;
    output();
    note.noteMonth = month;

    cout << "\nDay: ";
    cin >> whatDay;
    cout << endl;
    note.noteDay = whatDay;

    note.enter_note_text();
    listOfNotes.push_back(note);
}

void Calendar::show_list_of_notes() {
    for (int i = 0; i < listOfNotes.size(); i++) {
        listOfNotes.at(i).show_note();
    }
}