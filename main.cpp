#include <iostream>
#include "Calendar.h"

int main() {

    Calendar calendar;
    calendar.load_data();
    calendar.output();
    calendar.show_remind_and_notes_for_current_day();
    int mainMenuOperation;
    const int back = 9;
    const int exit = 0;
    int tmp;
    do {
        cout << endl;
        cout << "Main menu: \n"
                "1.Previous Month       2.Next Month\n"
                "3.Previous&Next Month  4.Year\n"
                "5.Notes(Blue)          6.Reminds(Green)\n"
                "7.Tasks                9.Back \n"
                "0.Exit" << endl;
        cin >> mainMenuOperation;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
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
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

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
            do {
                cout << "Notes menu: \n"
                        "1.Add note       2.Show list of notes\n"
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
                }

                if (notesMenuOperation == 3) {
                    calendar.delete_note();
                }

            } while (notesMenuOperation != back);
            calendar.set_to_default();
            calendar.output();
        }

        if (mainMenuOperation == 6) {
            int remindsMenuOperation;
            do {
                cout << "Remind menu: \n"
                        "1.Add remind       2.Show list of reminds\n"
                        "3.Delete remind\n"
                        "9.Back to main menu" << endl;
                cin >> remindsMenuOperation;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

                if (remindsMenuOperation == 1) {
                    calendar.add_remind();
                    calendar.set_to_default();
                }

                if (remindsMenuOperation == 2) {
                    calendar.show_list_of_reminds();
                }

                if (remindsMenuOperation == 3) {
                    calendar.delete_remind();
                }
            } while (remindsMenuOperation != back);
            calendar.set_to_default();
            calendar.output();
        }

        if (mainMenuOperation == 7) {
            int tasksMenuOperation;

            do {
                cout << "Task menu: \n"
                        "1.New task                    2.Show list of tasks\n"
                        "3.Change status of the task   4.Delete task\n"
                        "9.Back to main menu" << endl;
                cin >> tasksMenuOperation;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;

                if (tasksMenuOperation == 1) {
                    calendar.add_task_list();
                    calendar.set_to_default();
                }

                if (tasksMenuOperation == 2) {
                    calendar.show_list_of_tasks();
                }

                if (tasksMenuOperation == 3) {
                    calendar.change_task_status();
                }

                if (tasksMenuOperation == 4) {
                    calendar.delete_task();
                }

            } while (tasksMenuOperation != back);
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