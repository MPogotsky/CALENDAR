using namespace std;

#include "windows.h"

void Template::enter_text() {
    cout << "Please, enter text: " << endl;
    cin.ignore();
    getline(cin, text);
    list.push_back(text);
}

void Template::show() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
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

void Template::delete_element(int n) {
    list.erase(list.begin() + n);
    cout << "Done." << endl;
}

void Template::save_data(std::ostream &File) {
    int amountOfDataWhileSaving;
    amountOfDataWhileSaving = list.size();
    File << amountOfDataWhileSaving << endl;
    File << day << endl;
    File << month << endl;
    File << year << endl;
    for (int n = 0; n < list.size(); n++) {
        File << list.at(n) << endl;
    }
}

void Template::loading_from_file(std::istream &File){
    int amountOfNotesWhileSavingData;
    File >> amountOfNotesWhileSavingData;
    File >> day;
    File >> month;
    File >> year;
    File.ignore();
    for (int i = 0; i < amountOfNotesWhileSavingData; i++) {
        string tmpTextOfNote;
        getline(File, text);
        list.push_back(text);
        File.sync();
    }
}