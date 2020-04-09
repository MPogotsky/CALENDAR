using namespace std;


#include "windows.h"
void Notes::enter_note_text() {
    note_structure new_note;
    cout << "Please, enter note: " << endl;
    cin.ignore();
    cin.getline(new_note.textOfNote, 1000);
    list.push_back(new_note);
}

void Notes::show_note() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
    cout << noteDay<<"."<<noteMonth<<"."<<noteYear<<endl;
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for(int i = 0; i<list.size(); i++){
        cout<<"-"<<i+1<<" ";
        cout << list.at(i).textOfNote << endl;
    }
}

void Notes::delete_note(int n) {
    list.erase(list.begin() + (n - 1));
    cout<<"Done."<<endl;
}
