using namespace std;

void Notes::enter_note_text() {
    cout << "Please, enter note: " << endl;
    cin.ignore();
    cin.getline(textOfNote, 1000);
}

void Notes::show_note() {
    cout << textOfNote << endl;
}
