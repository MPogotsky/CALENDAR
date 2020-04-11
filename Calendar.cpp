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

int Calendar::compare_dates(int day) {
    if (!listOfNotes.empty()) {
        for (int i = 0; i < listOfNotes.size(); i++) {
            if (listOfNotes.at(i).noteYear == year && listOfNotes.at(i).noteMonth == month &&
                listOfNotes.at(i).noteDay == day) {
                return 1;
            }
        }
    }
    return 0;
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
            //If current day contains note -> marking with PURPLE color
            if (compare_dates(day) == 1 && day == currentDay && month == currentMonth && year == currentYear) {
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE);
                cout << setw(5) << left << day;
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                //Marking current day with RED color
                if (day == currentDay && month == currentMonth && year == currentYear) {
                    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(console, FOREGROUND_RED);
                    cout << setw(5) << left << day;
                    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                } else {
                    //Marking day with note with BLUE color
                    if (compare_dates(day) == 1) {
                        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(console, FOREGROUND_BLUE);
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

//Functions with Notes

void Calendar::add_note() {
    Notes note;
    cout << "Please, the date where we will place your note:" << endl;

    cout << "Year: ";
    cin >> year;
    while (year > currentYear + 20 || year < currentYear - 200) {
        cout << "Invalid data, please, try again " << endl;
        cin >> year;
    }
    show_whole_year();
    note.noteYear = year;

    cout << "\nMonth: ";
    cin >> month;
    while (month > 12 || month < 0) {
        cout << "Invalid data, please, try again " << endl;
        cin >> month;
    }
    output();
    note.noteMonth = month;

    cout << "\nDay: ";
    cin >> whatDay;
    while (whatDay < 0 || whatDay > 31) {
        cout << "Invalid data, please, try again " << endl;
        cin >> whatDay;
    }
    note.noteDay = whatDay;

    int requirement = false;
    for (int n = 0; n < listOfNotes.size(); n++) {
        if (note.noteYear == listOfNotes.at(n).noteYear &&
            note.noteMonth == listOfNotes.at(n).noteMonth &&
            note.noteDay == listOfNotes.at(n).noteDay) {
            listOfNotes.at(n).enter_note_text();
            requirement = true;
        }
    }
    cout << endl;
    if (requirement == false) {
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
    cout << "Please, enter number of the note: " << endl;
    int k = 0;
    cin >> k;
    listOfNotes.at(n - 1).delete_note(k - 1);
}

void Calendar::save_data() {
    int amountOfNotesWhileSavingData;

    ofstream NotesData("NotesData.txt");
    for (int i = 0; i < listOfNotes.size(); i++) {
        amountOfNotesWhileSavingData = listOfNotes.at(i).list.size();
        NotesData << amountOfNotesWhileSavingData << endl;
        NotesData << listOfNotes.at(i).noteDay << endl;
        NotesData << listOfNotes.at(i).noteMonth << endl;
        NotesData << listOfNotes.at(i).noteYear << endl;
        for (int n = 0; n < listOfNotes.at(i).list.size(); n++) {
            NotesData << listOfNotes.at(i).list.at(n).textOfNote << endl;
        }
    }
    NotesData.close();
}


void Calendar::load_data() {



    ifstream NotesData("NotesData.txt");
    if (NotesData.is_open()) {
        int amountOfNotesWhileSavingData;
        while (!NotesData.eof()) {
            Notes note;
            NotesData >> amountOfNotesWhileSavingData;
            NotesData >> note.noteDay;
            NotesData >> note.noteMonth;
            NotesData >> note.noteYear;
            string tmpTextOfNote;
            for (int i = 0; i < amountOfNotesWhileSavingData; i++) {
            getline(NotesData,tmpTextOfNote);
                    note.loading_from_file(tmpTextOfNote);
                    std::string clear(tmpTextOfNote);
                    amountOfNotesWhileSavingData --;
            }
            amountOfNotesWhileSavingData = 0;
            listOfNotes.push_back(note);
        }
        NotesData.close();
        listOfNotes.pop_back();
    } else {
        cout << "Can't find file. No saved data yet." << endl;
    }
}
