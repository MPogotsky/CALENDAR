using namespace std;

#include "windows.h"

void Remind::enter_text_of_remind() {
    cout << "Please, enter remind: " << endl;
    cin.ignore();
    getline(cin, textOfRemind);
    list.push_back(textOfRemind);
}

void Remind::show_remind() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_GREEN);
    if (month < 10 && day <10) {
        cout << "0" << day << ".0" << month << "." << year << endl;
    }else{
        if (month < 10) {
            cout << day << ".0" << month << "." << year << endl;
        }else{
            if (day < 10) {
                cout << "0" << day << month << "." << year << endl;
            }else{
                cout << day << "." << month << "." << year << endl;
            }
        }
    }
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < list.size(); i++) {
        cout << "-" << i + 1 << " ";
        cout << list.at(i) << endl;
    }
}

void Remind::delete_remind(int n) {
    list.erase(list.begin() + n);
    cout << "Done." << endl;
}

void Remind::save_data(std::ostream& RemindsData) {
    int amountOfDataWhileSaving = list.size();
    RemindsData << amountOfDataWhileSaving << endl;
    RemindsData << day << endl;
    RemindsData << month << endl;
    RemindsData << year << endl;
    for (int n = 0; n < list.size(); n++) {
        RemindsData << list.at(n) << endl;
    }

}

void Remind::loading_from_file(std::istream& RemindsData) {
    int amountOfRemindsWhileSavingData;
    RemindsData >> amountOfRemindsWhileSavingData;
    RemindsData >> day;
    RemindsData >> month;
    RemindsData >> year;
    RemindsData.ignore();
    for (int i = 0; i < amountOfRemindsWhileSavingData; i++) {
        string tmpTextOfRemind;
        getline(RemindsData, textOfRemind);
        list.push_back(textOfRemind);
        RemindsData.sync();
    }
}

