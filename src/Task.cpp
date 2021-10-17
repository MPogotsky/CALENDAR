void Task::add_task() {
    cout << "Please, enter title of your task: " << endl;
    cin.ignore();
    getline(cin, titleOfTheTaskList);
    list.push_back(titleOfTheTaskList);

    cout << "Please, enter your tasks fo the day (press 0 to stop): " << endl;
    do {
        list.push_back("0");
        cout << "*";
        getline(cin, text);
        list.push_back(text);
    } while (text != "0");
    list.pop_back();
    list.pop_back();
    cout << "Your list: " << endl;
    show();
}

void Task::change_status() {
    cout << "Change: ";
    int number;
    cin >> number;
    list.at((number * 2) - 1) = "1";
    cout << "Done." << endl;
}

void Task::show() {
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

    int n = 1;
    for (int i = 0; i < list.size(); i++) {
        if (i % 2 != 0) {
            if (list.at(i) == "1") {
                HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(console, FOREGROUND_RED);
                cout << n << "* ";
                SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            } else {
                cout << n << "* ";
            }
        } else {
            if (i != 0) {
                n++;
            }
            cout << list.at(i) << endl;
        }
    }
    cout << endl;
}

void Task::delete_task() {
    int number;
    cout << "Delete task number: ";
    cin >> number;
    list.erase(list.begin() + ((number * 2) - 1));
    list.erase(list.begin() + (number * 2));
    cout << "Done." << endl;
}

