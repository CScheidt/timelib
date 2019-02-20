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

    struct date datum;

    //Eingabe bis korrektes Datum  eingegeben wurde.
    datum = input_date(datum);

    //Rueckgabe der Anzahl der Tage vom angegebenen Datum
    printf("Anzahl Tage: %i \n", day_of_the_year(datum));

    return 0;
}
