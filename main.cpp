#include <iostream>
#include "Calendar.h"

int main() {

    Calendar calendar;
    calendar.load_data();
    calendar.output();
    int mainMenuOperation = 0;
    const int back = 9;
    const int exit = 0;
    int tmp = 0;
    do {
        cout << endl;
        cout << "Main menu: \n"
                "1.Previous Month       2.Next Month\n"
                "3.Previous&Next Month  4.Year\n"
                "5.Notes                9.Back \n"
                "0.Exit" << endl;
        cin >> mainMenuOperation;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        if (mainMenuOperation == 1) {
            calendar.month--;
            calendar.output();
        }

        if (mainMenuOperation == 2) {
            calendar.month++;
            calendar.output();
        }

        if (mainMenuOperation == 3) {
            tmp = calendar.month;
            for (int i = tmp - 1; i < tmp + 2; i++) {
                calendar.month = i;
                calendar.output();
            }
            calendar.set_to_default();
        }

        if (mainMenuOperation == 4) {
            int yearMenuOperation;
            calendar.show_whole_year();
            do {
                cout << "1.Next Year      2.Previous Year\n"
                        "9.Back to main menu" << endl;
                cin >> yearMenuOperation;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

                if (yearMenuOperation == 1) {
                    calendar.year++;
                    calendar.show_whole_year();
                }

                if (yearMenuOperation == 2) {
                    calendar.year--;
                    calendar.show_whole_year();
                }

            } while (yearMenuOperation != back);
            calendar.set_to_default();
            calendar.output();
        }

        if (mainMenuOperation == 5) {
            int notesMenuOperation;
            calendar.show_whole_year();
            do {
                cout << "1.Add note       2.Show list of notes\n"
                        "3.Delete note\n"
                        "9.Back to main menu" << endl;
                cin >> notesMenuOperation;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

                if (notesMenuOperation == 1) {
                    calendar.add_note();
                    calendar.set_to_default();
                }

                if (notesMenuOperation == 2) {
                    calendar.show_list_of_notes();
                    calendar.set_to_default();
                }

                if(notesMenuOperation == 3){
                    calendar.delete_note();
                    calendar.set_to_default();
                }

            } while (notesMenuOperation != back);
            calendar.set_to_default();
            calendar.output();
        }

        if (mainMenuOperation == back) {
            calendar.set_to_default();
            calendar.output();
        }

    } while (mainMenuOperation != exit);
    calendar.save_data();
    return 0;
}