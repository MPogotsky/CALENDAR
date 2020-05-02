using namespace std;


#include "windows.h"

void Notes::enter_note_text() {

    cout << "Please, enter note: " << endl;
    cin.ignore();
    getline(cin, textOfNote);
    list.push_back(textOfNote);
}

void Notes::show_note() {
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

void Notes::delete_note(int n) {
    list.erase(list.begin() + n);
    cout << "Done." << endl;
}

void Notes::save_data(std::ostream& NotesData) {
    int amountOfDataWhileSaving;
    amountOfDataWhileSaving = list.size();
    NotesData << amountOfDataWhileSaving << endl;
    NotesData << day << endl;
    NotesData << month << endl;
    NotesData << year << endl;
    for (int n = 0; n < list.size(); n++) {
        NotesData << list.at(n) << endl;
    }
}

void Notes::loading_from_file(std::istream& NotesData){
    int amountOfNotesWhileSavingData;
    NotesData >> amountOfNotesWhileSavingData;
    NotesData >> day;
    NotesData >> month;
    NotesData >> year;
    NotesData.ignore();
    for (int i = 0; i < amountOfNotesWhileSavingData; i++) {
        string tmpTextOfNote;
        getline(NotesData, textOfNote);
        list.push_back(textOfNote);
        NotesData.sync();
    }
}