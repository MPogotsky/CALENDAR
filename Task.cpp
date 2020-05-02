void Task::add_task() {
    cout << "Please, enter title of your task: " << endl;
    cin.ignore();
    getline(cin, titleOfTheTaskList);
    tasksList.push_back(titleOfTheTaskList);

    cout << "Please, enter your tasks fo the day (press 0 to stop): " << endl;
    do {
        tasksList.push_back("0");
        cout << "*";
        getline(cin, textOfTheTask);
        tasksList.push_back(textOfTheTask);
    } while (textOfTheTask != "0");
    tasksList.pop_back();
    tasksList.pop_back();
    cout << "Your list: " << endl;
    show_tasks();
}

void Task::change_status() {
    cout << "Change: ";
    int number;
    cin >> number;
    tasksList.at((number * 2) - 1) = "1";
    cout << "Done." << endl;
}

void Task::show_tasks() {
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
    for (int i = 0; i < tasksList.size(); i++) {
        if (i % 2 != 0) {
            if (tasksList.at(i) == "1") {
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
            cout << tasksList.at(i) << endl;
        }
    }
    cout << endl;
}

void Task::delete_task() {
    int number;
    cout << "Delete task number: ";
    cin >> number;
    tasksList.erase(tasksList.begin() + ((number * 2) - 1));
    tasksList.erase(tasksList.begin() + (number * 2));
    cout << "Done." << endl;
}

void Task::save_data(std::ostream& TasksData){
    int amountOfDataWhileSaving = tasksList.size();
    TasksData << amountOfDataWhileSaving << endl;
    TasksData << day <<endl;
    TasksData << month << endl;
    TasksData << year << endl;
    for(int i = 0; i<tasksList.size(); i++){
        TasksData << tasksList.at(i) << endl;
    }
}

void Task::load_data(std::istream& TasksData) {
    int amountOfTasksWhileSavingData;
    TasksData >> amountOfTasksWhileSavingData;
    TasksData >> day;
    TasksData >> month;
    TasksData >> year;
    TasksData.ignore();
    for (int i = 0; i < amountOfTasksWhileSavingData; i++) {
        string tmpTextOfTheTask;
        getline(TasksData, textOfTheTask);
        tasksList.push_back(textOfTheTask);
        TasksData.sync();
    }
}

