/**
 *  Dieses Programm dient zur Bereitstellen verschiedener Zeit-Funktionen.
 *
 *  @author Jesse Kroeske, 08.02.2021
 **/

#include <stdio.h>
#include <stdlib.h>

// Fragt nach einem validen Datum ab.
void input_date(int* day, int* month, int* year);
// Überprüft ob ein Datum ein Schaltjahr ist.
int isLeapYear(int year);
// Bestimmt den Tag des Jahres
int day_of_the_year(int day, int month, int year;

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    int day = 0, month = 0, year = 0;
    input_date(&day, &month, &year);
    return 0;
}

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

int day_of_the_year(int day, int month, int year)
{
    // Deklaration der Variabeln
    int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int year = 0;
    int month = 0;
    int day = 0;
    int dayOfYear = 0;
    input_date(&day, &month, &year);
    // Überprüfung ob das Jahr ein Schaltjahr ist
    if(isLeapYear(*year) == 1)
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
