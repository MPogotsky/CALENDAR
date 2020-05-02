void Holiday::show_holiday(int year) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
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
    SetConsoleTextAttribute(console,
                            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << textOfHoliday << endl;

}

void Holiday::load_data(std::istream& Holidays){
    Holidays >> day;
    Holidays >> month;
    Holidays.ignore();
    getline(Holidays, textOfHoliday);
    Holidays.sync();
}