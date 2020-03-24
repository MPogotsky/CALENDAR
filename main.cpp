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
                "8.Back                 9.Exit" << endl;
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
            for(int i = tmp-1; i<tmp+2; i++){
                calendar.month = i;
                calendar.output();
            }
            calendar.set_to_default();
        }

        if (operation == 4) {
            for (int i = 1; i < 13; i++) {
                calendar.month = i;
                calendar.output();
            }
            calendar.set_to_default();
        }

        if (operation == 5) {
            calendar.year++;
            for (int i = 1; i < 13; i++) {
                calendar.month = i;
                calendar.output();
            }
        }

        if (operation == 6) {
            calendar.year--;
            for (int i = 1; i < 13; i++) {
                calendar.month = i;
                calendar.output();
            }
        }

        if (operation == 8) {
            calendar.set_to_default();
            calendar.output();
        }
    } while (operation != 9);
    return 0;
}