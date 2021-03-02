/**
 *  Dieses Programm dient zur Bereitstellen verschiedener Zeit-Funktionen.
 *
 *  @author Jesse Kroeske, 20.02.2021
 **/

#ifndef TIME_H
#define TIME_H

typedef struct date{
    int day;
    int month;
    int year;
};

// Fragt nach einem validen Datum ab.
void input_date(struct date* date);
// Überprüft ob ein Datum ein Schaltjahr ist.
int isLeapYear(int year);
// Bestimmt den Tag des Jahres.
int day_of_the_year(struct date date);
// Gibt die Tage der Monate im Jahr zurück.
int *days_per_months_of_year(int year);

#endif // TIME_H
