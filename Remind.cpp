using namespace std;

#include "windows.h"

void Remind::enter_text_of_remind(){
    cout << "Please, enter remind: " << endl;
    cin.ignore();
    getline(cin,textOfRemind);
    list.push_back(textOfRemind);
}

void Remind::show_remind(){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_GREEN);
    cout << remindDay<<"."<<remindMonth<<"."<<remindYear<<endl;
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for(int i = 0; i<list.size(); i++){
        cout<<"-"<<i+1<<" ";
        cout << list.at(i) << endl;
    }
}

void Remind::delete_remind(int n) {
    list.erase(list.begin() + n);
    cout<<"Done."<<endl;
}

void Remind::loading_from_file(string tmpTextOfRemind) {
    textOfRemind = tmpTextOfRemind;
    list.push_back(textOfRemind);
}

