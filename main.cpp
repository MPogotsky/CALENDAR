#include <iostream>
#include "Calendar.h"

int main() {

    Calendar calendar;
    calendar.output();
    int operation = 0;
    int tmp = 0;
    do {
        cout << endl;
        cout << "1.Previous Month       2.Next Month\n"
                "3.Previous&Next Month  4.Year\n"
                "5.Next Year            6.Previous Year\n"
                "8.Back                 9.Add note\n"
                "0.Exit" << endl;
        cin >> operation;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        if (operation == 1) {
            calendar.month--;
            calendar.output();
        }

        if (operation == 2) {
            calendar.month++;
            calendar.output();
        }

        if (operation == 3) {
            tmp = calendar.month;
            for (int i = tmp - 1; i < tmp + 2; i++) {
                calendar.month = i;
                calendar.output();
            }
            calendar.set_to_default();
        }

        if (operation == 4) {
            calendar.show_whole_year();
            calendar.set_to_default();
        }

        if (operation == 5) {
            calendar.year++;
            calendar.show_whole_year();
        }

        if (operation == 6) {
            calendar.year--;
            calendar.show_whole_year();
        }

        if (operation == 8) {
            calendar.set_to_default();
            calendar.output();
        }

        if (operation == 9) {
            calendar.add_note();
            calendar.show_list_of_notes();

            calendar.set_to_default();
        }
    } while (operation != 0);
    return 0;
}