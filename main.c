/**
 *  Dieses Programm dient zur Bereitstellen verschiedener Zeit-Funktionen.
 *
 *  @author Jesse Kroeske, 08.02.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    int day = 0, month = 0, year = 0;
    input_date(&day, &month, &year);
    return 0;
}
