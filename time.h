/**
 * Author: Christian Scheidt
 * Date: 18.12.2018
 * Summary: Prototypes for time.c library
 * Last modified: 26.02.2019
 **/

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

struct date{
    int day;
    int month;
    int year;
    int month_counter;
};

int day_of_the_year(struct date given_date);

struct date input_date(struct date given_date);

int get_days_for_month(struct date given_date);

int exists_date(struct date given_date);

int is_leapyear(struct date given_date);

#endif // TIME_H_INCLUDED
