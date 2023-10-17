/* 1° esempio di utilizzo della funzione printf */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int    variabileInt;
    float  variabileFloat;
    double variabileDouble;
    long double variabileLongDouble;
    char   variabileChar;

    variabileInt    = 78;
    variabileFloat  = 28.8436;
    variabileDouble = 184.324543625;
    variabileLongDouble = 123.1234567;
    variabileChar   = 'N';

    printf("\n variabileInt: %d",    variabileInt);
    printf("\n variabileFloat: %f",  variabileFloat);
    printf("\n variabileDouble: %f", variabileDouble);
    __mingw_printf("\n variabileLongDouble: %Lf", variabileLongDouble); //la semplice funzione printf con long double con mingw non funziona correttamente
    printf("\n variabileChar: %c",   variabileChar);

   printf("\n\n");
   system("pause");
   return(0);
}
