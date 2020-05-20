#ifndef CALENDAR_TEMPLATE_H
#define CALENDAR_TEMPLATE_H


class Template {
protected:

    std::string text;
    std::vector<std::string> list;

    int day;
    int month;
    int year;

public:

    virtual void enter_text();

    virtual void show();

    void delete_element(int n);

    void save_data(std::ostream &File);

    void loading_from_file(std::istream &File);
};

#include "Template.cpp"

#endif //CALENDAR_TEMPLATE_H
