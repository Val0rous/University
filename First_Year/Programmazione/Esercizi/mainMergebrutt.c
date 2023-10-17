/*
Siano dati due vettori di interi di lunghezza differente i cui valori sono inseriti da tastiera.
Scrivere un programma C che generi un terzo vettore contenente l’intersezione tra i due vettori di input.
Se un elemento è comune ai due vettori e presente più volte in un vettore farlo comparire anche nel vettore risultato.

Implementare la variante in cui le ripetizioni non sono presenti nel risultato.

Implementare inoltre anche l'inserimento random dei valori nei vettori.
*/

#include <stdlib.h>
#include <stdio.h>
#define MAX_INDEX 50

int main(){

    int indexA1=0;
    while(1) {
        printf("Choose how many numbers do you want to insert in the first array (max MAX_INDEX):");
        scanf("%d",&indexA1);
        if(indexA1<MAX_INDEX && indexA1>0) break;
        printf("cazzo hai scritto");
    }
    for(int )

    int array1[indexA1+1]={0};     //User's choice?
    int array2[50]={0};     //They gotta be of different length though
    for(int i=0;int<sizeof(array1))

    return 0;
}