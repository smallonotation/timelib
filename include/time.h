/**
 *  Dieses Programm dient zur Bereitstellen verschiedener Zeit-Funktionen.
 *
 *  @author Jesse Kroeske, 20.02.2021
 **/

#ifndef TIME_H
#define TIME_H

// Fragt nach einem validen Datum ab.
void input_date(int* day, int* month, int* year);
// Überprüft ob ein Datum ein Schaltjahr ist.
int isLeapYear(int year);
// Bestimmt den Tag des Jahres
int day_of_the_year(int day, int month, int year);

#endif // TIME_H
