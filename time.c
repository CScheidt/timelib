/**
 * Author: Christian Scheidt
 * Date: 07.01.2019
 * Summary: Reads a date and returns the days until given date. Uses time.c library
 * Last modified: 26.02.2019
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

///  Die Funktion Ueberprueft, ob ein eingegebenes Jahr nach den Regeln des gregorianischen
///  Kalendar ein Schaltjahr ist. Bei Jahreszahlen vor dem 1952 wird ein Fehler zurueckgegeben.
/// return: 1 Schaltjahr, 0 kein Schaltjahr, -1 ungueltiges Datum
int is_leapyear ( struct date given_date )
{

    int leapyear_bool = 0;

    if ( ( given_date.year < 1582 ) || ( given_date.year > 2400 ) )
    {
        return -1;
    }

    if ( ( given_date.year % 4 ) == 0 )
    {

        if ( ( given_date.year % 100 ) == 0 )
        {
            if ( given_date.year % 400 )
            {
                leapyear_bool = 1;
            }
            else
            {
                leapyear_bool = 0;
            }
        }
        else
        {
            leapyear_bool = 1;
        }
    }
    else
    {
        leapyear_bool = 0;
    }
    return leapyear_bool;
}

///Die Funktion liest 3 Ganzzahlwerte ein, Tag, Monat und Jahr. Wenn das angegebene Datum ungueltig ist,
///wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
///return: Gefuelltes Struct mit eingegebenem Datum
struct date input_date ( struct date given_date )
{

    do
    {
        printf ( "Keine fuehrende Nullen!\n Tag: " );
        scanf ( "%i", &given_date.day );

        printf ( "\n Monat: " );
        scanf ( "%i", &given_date.month );

        printf ( "\n Jahr: " );
        scanf ( "%i", &given_date.year );

        if ( exists_date ( given_date ) == 0 ) // Solange bis Datum korrekt
        {
            printf ( "Datum ist nicht korrekt! Bitte nochmal eingeben! \n" );
        }

    }
    while ( exists_date ( given_date ) == 0 );

    return given_date;
}

/// Die Funktion berechnet für ein gegebenes Datun des gregorianischen Kalenders bestehend aus Tag, Monat
///und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
///Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
///return: Alle Tage bis zum Darum
int day_of_the_year ( struct date given_date )
{
    int count_days = 0;

    if ( exists_date ( given_date ) == 1 )
    {

        for ( int i = 1; i < given_date.month; i++ )
        {
            given_date.month_counter = i;
            count_days += get_days_for_month ( given_date );
        }

        count_days += given_date.day;
        // Rüchgabe Tag des Jahres
        return count_days;
    }
    else
    {
        printf ( "Ungueltiges given_date \n" );
        return -1;
    }


}


/// Die Funktion bestimmt fuer einen gegebenen Monat eines gegebenes Jahres, wie viele Tage der Monat hat.
/// der Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden beruecksichtigt.
/// return: 1-31 Anzahl Tage; -1  ungueltiges Datum
int get_days_for_month ( struct date given_date )
{

    int days_In_Month[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0}; //Statische Werte für Anzahl Tage im Jahr + puffer

    if ( exists_date ( given_date ) == 1 )
    {

        if ( is_leapyear ( given_date ) == 1 )
        {
            if ( given_date.month_counter == 2 )
            {
                return 29;
            }

        }
        return days_In_Month[given_date.month_counter];
    }
    else
    {
        return -1;
    }
}


///Die Funktion ueberprueft, ob ein eingegebenes Datum gueltig ist. Daten vor dem 1.1.1582 sind ungueltig, genauso
///wie alle Daten nach dem 31.12.2400.
/// return: 1 wenn Datum existiert; 0 wenn Datum ungueltig
int exists_date ( struct date given_date )
{

    if ( ( given_date.day < 1 ) || ( given_date.day > 31 ) )
    {
        return 0;
    }
    else if ( given_date.month < 1 || given_date.month > 12 )
    {
        return 0;
    }
    else if ( given_date.year < 1582 || given_date.year > 2400 )
    {
        return 0;
    }
    else if ( given_date.month == 2 && given_date.day > 28 ) // Sonderfall für Februar
    {
        if ( is_leapyear ( given_date ) == 1 && given_date.day == 29 ) // Nur bei Schlatjahren
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}
