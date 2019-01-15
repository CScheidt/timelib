/**
 * Author: Christian Scheidt
 * Date: 07.01.2019
 * Content: erechnet f�r ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 * und Jahr die Nummer des Tages, gez�hlt von Jahresbeginn (1. Januar) an.
 **/

#include <stdio.h>
#include <stdlib.h>

///
///
///
int day_of_the_year(int day, int month, int year)
{
    int countDays = 0;

    if(exists_date(day, month, year) == 1){

        for(int i = 1; i < month; i++ ){
            countDays += get_days_for_month(i, year);
        }
    }

    countDays += day;

    return countDays;
}

void input_date(){

}

/// Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenes Jahres, wie viele Tage der Monat hat.
/// der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden ber�cksichtigt.
/// @params month: int, year: int
int get_days_for_month(int month, int year){

    int daysInMonth[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

    if(exists_date(01, month, year) == 1) {

        if(isLeapyear(year) == 1){
            daysInMonth[2] = 29;
        }
        return daysInMonth[month];
    } else {
        return -1;
    }
}

///
///
///
int exists_date(int day, int month, int year){

    if(day < 1 || day > 31){
        return 0;
    } else if(month < 1 || month > 12){
        return 0;
    } else if(year < 1582 || year > 2400){
        return 0;
    } else if(month == 2 && day > 28){
        if(isLeapyear(year) == 1 && day == 29){
            return 1;
        }else {
            return 0;
        }
    }

    return 1;
}


///  Die Funktion �berpr�ft, ob ein eingegebenes Jahr nach den Regeln des gregorianischen
///  Kalendar ein Schaltjahr ist. Bei Jahreszahlen vor dem 1952 wird ein Fehler zur�ckgegeben.
///  @params year: int
int isLeapyear(int year){

    int leapyearBool = 0;

    if (year < 1582 || year > 2400){
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
    printf("Tag des Jahres: %i\n", day_of_the_year(12, 01, 2018));

	int eingabeJahr = 0;

    printf("Geben Sie ein m�gliches Schlatjahr ein!\n");
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
