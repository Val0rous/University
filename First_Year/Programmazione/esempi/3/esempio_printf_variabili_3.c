#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numeroA;
    double numeroB;

    numeroA = 22.12345;
    numeroB = 22.123456789012345;

    /*
    stampa di una variabile utilizzando opzioni speciali del comando di conversione, in particolare
    vengono presentati alcuni esempi utilizzando la precisione
    */

    printf("\n valore: %f",numeroA);
    printf("\n valore: %.15e",numeroA);
    printf("\n valore: %.15e",numeroB);
    printf("\n valore: %.5f",numeroA);
    printf("\n valore: %8.2f",numeroA); /*8 cifre per il numero se il numero non raggiunge le cifre vengono inseriti degli spazi a sinistra*/
    printf("\n valore: %08.2f",numeroA);
    printf("\n valore: %08.5f",numeroA);

    printf("\n\n");
    system("pause");
    return 0;
}
