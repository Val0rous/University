/* 2° esempio di utilizzo della funzione printf */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variabileIntera1, variabileIntera2;

    variabileIntera1 = 175;
    variabileIntera2 = 176;

    /*
    stampa di una variabile utilizzando opzioni speciali del comando di conversione, in particolare
    vengono presentati alcuni esempi utilizzando il modificatore e il campo minimo
    */

    /*
    valore 10 per il campo minimo quindi lo spazio (l'area dove viene inserito il valore) è
    composta da 10 caratteri, se il valore stampato è più piccolo dell'area a sinistra del
    valore vengono inseriti degli spazi
    */
    printf("\n valore: %5d %5d",variabileIntera1,variabileIntera2);
    printf("\n valore: %10d %10d",variabileIntera1,variabileIntera2);

    /*
    il modificatore - serve per allineare a sinistra il valore
    */
    printf("\n valore: %-10d %-10d",variabileIntera1,variabileIntera2);

    /*
    il modificatore 0 consente di inserire zeri prima del numero
    */
    printf("\n valore: %010d",variabileIntera1);

    /*
    l'asterisco serve per dar la possibilità di inserire il modificatore attraverso un parametro
    specificato esternamente
    */
    printf("\n valore: %*d",10,variabileIntera1);

    printf("\n\n");
    system("pause");
    return 0;
}
