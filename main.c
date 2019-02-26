/**
 * Author: Christian Scheidt
 * Date: 07.01.2019
 * Summary: Reads a date and returns the days until given date. Uses time.c library
 * Last modified: 26.02.2019
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main(){

    struct date given_date;

    //Eingabe bis korrektes given_date  eingegeben wurde.
    given_date = input_date(given_date);

    //Rueckgabe der Anzahl der Tage vom angegebenen given_date
    printf("Anzahl Tage: %i \n", day_of_the_year(given_date));

    return 0;
}
