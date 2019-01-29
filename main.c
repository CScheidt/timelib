/**
 * Author: Christian Scheidt
 * Date: 07.01.2019
 * Content: erechnet fuer ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 * und Jahr die Nummer des Tages, gezaehlt von Jahresbeginn (1. Januar) an.
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main(){
    int day;
    int month;
    int year;

    //Eingabe bis korrektes Datum  eingegeben wurde.
    input_date(&day, &month, &year);

    //Rueckgabe der Anzahl der Tage vom angegebenen Datum
    printf("Anzahl Tage: %i \n", day_of_the_year(day, month, year));

    return 0;
}
