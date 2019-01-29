#include <stdio.h>
#include <stdlib.h>
#include "time.h"

///  Die Funktion Ueberprueft, ob ein eingegebenes Jahr nach den Regeln des gregorianischen
///  Kalendar ein Schaltjahr ist. Bei Jahreszahlen vor dem 1952 wird ein Fehler zurueckgegeben.
/// return: 1 Schaltjahr, 0 kein Schaltjahr, -1 ungueltiges Datum
int isLeapyear(int year){

    int leapyearBool = 0;

    if ((year < 1582) || (year > 2400)){
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

///Die Funktion liest 3 Ganzzahlwerte ein, Tag, Monat und Jahr. Wenn das angegebene Datum ungueltig ist,
///wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
void input_date(int *day, int *month, int *year){

    do{
        printf("Keine fuehrende Nullen!\n Tag: ");
        scanf("%i", day);

        printf("\n Monat: ");
        scanf("%i", month);

        printf("\n Jahr: ");
        scanf("%i", year);

    }while(exists_date(*day, *month, *year) == 0);
}

/// Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
///und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
///Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
///return: Alles Tage bis zum angegebenen Datum
int day_of_the_year(int day, int month, int year){
    int countDays = 0;

    if(exists_date(day, month, year) == 1){

        for(int i = 1; i < month; i++ ){
            countDays += get_days_for_month(i, year);
        }

        countDays += day;
        // Rüchgabe Tag des Jahres
        return countDays;
    }else {
        printf("Ungueltiges Datum \n");
        return -1;
    }


}


/// Die Funktion bestimmt fuer einen gegebenen Monat eines gegebenes Jahres, wie viele Tage der Monat hat.
/// der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden beruecksichtigt.
/// return: 1-31 Anzahl Tage; -1  ungueltiges Datum
int get_days_for_month(int month, int year){

    int daysInMonth[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

    if(exists_date(01, month, year) == 1) {

        if(isLeapyear(year) == 1){
            if(month == 2){
                return 29;
            }

        }
        return daysInMonth[month];
    } else {
        return -1;
    }
}


///Die Funktion ueberprueft, ob ein eingegebenes Datum gueltig ist. Daten vor dem 1.1.1582 sind ungueltig, genauso
///wie alle Daten nach dem 31.12.2400.
/// return: 1 for valid Date and 0 for not valid Date
int exists_date(int day, int month, int year){

    if((day < 1) || (day > 31)){
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
