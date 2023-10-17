#include <stdio.h>
#include <stdlib.h>

#define RIGHE 3
#define COLONNE 4

int main()
{
    int i, j, somma, rigaMax, sommaMax, verifica;
    int matrice[RIGHE][COLONNE];

    /*Lettura dei valori*/
    for (i=0; i<RIGHE; i++)
    {
        for (j=0; j<COLONNE; j++)
        {
             printf("Inserire valore tra 1 e 99 in posizione (%d,%d): ",i,j);
             verifica = scanf("%d",&matrice[i][j]);
             if (verifica!=1){
                printf("\nError: wrong input value! Program closing.\n");
                exit(1);
            }
        }
    }

    system("cls");

    /*Stampa dei valori*/
    for (i=0; i<RIGHE; i++)
    {
        for (j=0; j<COLONNE; j++)
        {
             printf("| %-2d ", matrice[i][j]);
        }
        printf("| \n");
    }

    rigaMax = 0;
    sommaMax = 0;

    /*calcolo della linea con somma dei valori massimo*/
    for (i=0; i<RIGHE; i++)
    {
        somma = 0;
        for (j = 0; j  < COLONNE; j++)
        {
            somma += matrice[i][j];
        }
        if (somma>sommaMax)
        {
            rigaMax = i+1;
            sommaMax = somma;
        }
    }
    printf("\nLa riga %d e\' quella con somma dei valori massima (corrispondente a: %d)\n",rigaMax,sommaMax);

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
