#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valoreIntero;
    float valoreDecimale;
    char valoreCarattere;

    printf(" inserire un numero intero, un carattere e un numero decimale separati da uno spazio e premere invio: ");
    scanf("%d %c %f",&valoreIntero, &valoreCarattere, &valoreDecimale);
    fflush(stdin);

    printf("\n\n i valori inseriti sono: %d  %c %f", valoreIntero, valoreCarattere, valoreDecimale);

    /*
    I VALORI DEVONO ESSERE INSERITI DELLE TIPOLOGIE RICHIESTE ALTRIMENTI IL SISTEMA NON SI COMPORTA A DOVERE
    */

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
