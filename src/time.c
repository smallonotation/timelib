/**
 *  Dieses Programm dient zur Bereitstellen verschiedener Zeit-Funktionen.
 *
 *  @author Jesse Kroeske, 20.02.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

/// <summary>
/// Ermöglicht das Eingeben eines Datums, wobei analog überprüft wird, ob diese valide ist.
/// </summary>
/// <param name="date">Datum</param>
void input_date(struct date* newdate)
{
    // Deklaration der Variabeln
    int *daysPerMonth = days_per_months_of_year(newdate->year);

    // Ausgabe / Eingabe
    do
    {
        fflush(stdin);
        printf("Geben Sie Jahr ein: ");
    }
    while (scanf("%i", &(newdate->year)) < 0 || (newdate->year < 0 || newdate->year > 3999));
    do
    {
        fflush(stdin);
        printf("Geben Sie Monat ein: ");
    }
    while (scanf("%i", &(newdate->month)) < 0 || (newdate->month < 1 || newdate->month > 12));

    // Ausgabe / Eingabe
    do
    {
        fflush(stdin);
        printf("Geben Sie Tag ein: ");
    }
    while (scanf("%i", &(newdate->day)) < 0 || (newdate->day < 1 || newdate->day > daysPerMonth[newdate->month - 1]));
}

/// <summary>
/// Überprüft ob das Jahr ein Schaltjahr ist.
/// </summary>
/// <param name="year">Jahr</param>
/// <returns>True wenn das Jahr ein Schaltjahr ist</returns>
int isLeapYear(int year)
{
    // Überprüfen und Schaltjahr bestimmen
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
    return 0;
}

/// <summary>
/// Ermittelt den Tag des Jahres
/// </summary>
/// <param name="date">Datum</param>
/// <returns>Tag des Jahres</returns>
int day_of_the_year(struct date date)
{
    // Deklaration der Variabeln
    int *daysPerMonth = days_per_months_of_year(date.year);
    int dayOfYear = 0;
    // Addieren der Tage
    for (int i = 0; i < date.month - 1; i++)
    {
        dayOfYear += daysPerMonth[i];
    }
    // Addieren der letzten Tagen
    dayOfYear += date.day;
    return dayOfYear;
}

/// <summary>
/// Ermittelt die Tage im Monat im gegebenen Jahr
/// </summary>
/// <param name="year">Jahr</param>
/// <returns>Tage in den Monaten des Jahres</returns>
int *days_per_months_of_year(int year){
    static int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeapYear(year) == 1)
    {
        daysPerMonth[1] = 29;
    }
    return daysPerMonth;
}


