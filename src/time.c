/**
 *  Dieses Programm dient zur Bereitstellen verschiedener Zeit-Funktionen.
 *
 *  @author Jesse Kroeske, 20.02.2021
 **/

#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// Ermöglicht das Eingeben eines Datums, wobei analog überprüft wird, ob diese valide ist.
/// </summary>
/// <param name="day">Tag</param>
/// <param name="month">Monat</param>
/// <param name="year">Jahr</param>
void input_date(int* day, int* month, int* year)
{
    // Deklaration der Variabeln
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Ausgabe / Eingabe
    do
    {
        fflush(stdin);
        printf("Geben Sie Jahr ein: ");
    }
    while (scanf("%i", year) < 0 || (*year < 0 || *year > 3999));
    do
    {
        fflush(stdin);
        printf("Geben Sie Monat ein: ");
    }
    while (scanf("%i", month) < 0 || (*month < 1 || *month > 12));

    // Überprüfung ob das Jahr ein Schaltjahr ist
    if(isLeapYear(*year) == 1)
    {
        daysPerMonth[1] = 29;
    }

    // Ausgabe / Eingabe
    do
    {
        fflush(stdin);
        printf("Geben Sie Tag ein: ");
    }
    while (scanf("%i", day) < 0 || (*day < 1 || *day > daysPerMonth[*month - 1]));
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
/// <param name="day">Tag</param>
/// <param name="month">Monat</param>
/// <param name="year">Jahr</param>
/// <returns>Tag des Jahres</returns>
int day_of_the_year(int day, int month, int year)
{
    // Deklaration der Variabeln
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dayOfYear = 0;
    input_date(&day, &month, &year);
    // Überprüfung ob das Jahr ein Schaltjahr ist
    if(isLeapYear(year) == 1)
    {
        daysPerMonth[1] = 29;
    }
    // Addieren der Tage
    for (int i = 0; i < month - 1; i++)
    {
        dayOfYear += daysPerMonth[i];
    }
    // Addieren der letzten Tagen
    dayOfYear += day;
    return dayOfYear;
}
