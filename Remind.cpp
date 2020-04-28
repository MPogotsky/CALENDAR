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
    if (remindMonth < 10) {
        cout << remindDay << ".0" << remindMonth << "." << remindYear << endl;
    } else {
        cout << remindDay << "." << remindMonth << "." << remindYear << endl;
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

void Remind::save_data() {
    ofstream RemindsData("RemindsData.txt");
    int amountOfDataWhileSaving = list.size();
    RemindsData << amountOfDataWhileSaving << endl;
    RemindsData << remindDay << endl;
    RemindsData << remindMonth << endl;
    RemindsData << remindYear << endl;
    for (int n = 0; n < list.size(); n++) {
        RemindsData << list.at(n) << endl;
    }
    RemindsData.close();
}

void Remind::loading_from_file(string tmpTextOfRemind) {
    textOfRemind = tmpTextOfRemind;
    list.push_back(textOfRemind);
}

