/**
 * Author: Christian Scheidt
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    return 0;
}

void input_date(){

}

/// Die Funktion bestimmt für einen gegebenen Monat eines gegebenes Jahres, wie viele Tage der Monat hat.
/// der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
/// @params month: int, year: int
int get_days_for_month(int month, int year){

    int daysInMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return 0;
}

int exists_date(int day, int month, int year){

    return 0;
}


///  Die Funktion überprüft, ob ein eingegebenes Jahr nach den Regeln des gregorianischen
///  Kalendar ein Schaltjahr ist. Bei Jahreszahlen vor dem 1952 wird ein Fehler zurückgegeben.
///  @params year: int
int isLeapyear(int year){

    int leapyearBool = 0;

    if (year < 1582){
        return -1;
    }

    if((year % 4) == 0){

        if((year % 100) == 0){
            if(year % 400){
                leapyearBool = 1;
            } else {
                leapyearBool = 0;
            }
        } else {
            leapyearBool = 1;
        }
    } else {
        leapyearBool = 0;
    }
    return leapyearBool;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));

	int eingabeJahr = 0;

    printf("Geben Sie ein mögliches Schlatjahr ein!\n");
    scanf("%i", &eingabeJahr);

    switch(isLeapyear(eingabeJahr)){
        case 1:
            printf("Eingegebenes Jahr ist ein Schlatjahr");
            break;
        case 0:
            printf("Eingegebenes Jahr ist kein Schlaltjahr");
            break;
        case -1:
            printf("Eingegebenes Jahr liegt vor 1582!");
            break;
    }

    return 0;
}
