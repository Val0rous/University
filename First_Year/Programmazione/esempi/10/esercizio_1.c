#include <stdio.h>
#include <stdlib.h>

#define RIGHE 3
#define COLONNE 4

int main()
{
    int i, j, somma, verifica;
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

    somma = 0;
    /*calcolo della somma*/
    for (i=0; i<RIGHE; i++)
    {
        for (j = 0; j  < COLONNE; j++)
        {
            somma += matrice[i][j];
        }
    }
    printf("\nLa somma dei valori della matrice e\' %d\n",somma);

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
