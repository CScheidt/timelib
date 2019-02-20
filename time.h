#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date{
    int day;
    int month;
    int year;
    int monthCounter;
};

int day_of_the_year(struct date datum);

struct date input_date(struct date datum);

int get_days_for_month(struct date datum);

int exists_date(struct date datum);

int isLeapyear(struct date datum);

#endif // TIME_H_INCLUDED
