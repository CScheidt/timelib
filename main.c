/**
 * Author: Christian Scheidt
 * Date: 07.01.2019
 * Content: erechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 * und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an.
 **/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(12, 01, 2018));

    return 0;
}
