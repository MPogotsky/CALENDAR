using namespace std;

#include "Windows.h"

void Remind::enter_text() {
    cout << "Please, enter text of remind: " << endl;
    cin.ignore();
    getline(cin, text);
    list.push_back(text);
}

void Remind::show() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_GREEN);
    if (month < 10 && day < 10) {
        cout << "0" << day << ".0" << month << "." << year << endl;
    } else {
        if (month < 10) {
            cout << day << ".0" << month << "." << year << endl;
        } else {
            if (day < 10) {
                cout << "0" << day << month << "." << year << endl;
            } else {
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

