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
    struct date date;
    input_date(&date);
    printf("Tag des Jahres: %i\n", day_of_the_year(date));
    return 0;
}
