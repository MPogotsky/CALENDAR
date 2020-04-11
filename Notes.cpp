using namespace std;


#include "windows.h"
void Notes::enter_note_text() {

    cout << "Please, enter note: " << endl;
    cin.ignore();
    getline(cin,textOfNote);
    list.push_back(textOfNote);
}

void Notes::show_note() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_BLUE);
    cout << noteDay<<"."<<noteMonth<<"."<<noteYear<<endl;
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for(int i = 0; i<list.size(); i++){
        cout<<"-"<<i+1<<" ";
        cout << list.at(i) << endl;
    }
}

void Notes::delete_note(int n) {
    list.erase(list.begin() + (n - 1));
    cout<<"Done."<<endl;
}

void Notes::loading_from_file(string tmpTextOfNote) {
     textOfNote = tmpTextOfNote;
     list.push_back(textOfNote);
}