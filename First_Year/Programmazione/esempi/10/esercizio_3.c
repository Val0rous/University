#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int main()
{
    int i, j, somma, sommaPrimaRiga;
    int matrice[MAX][MAX];
    int matriceMagica, verifica;

    /*
    Esempio matrice magica 4x4
    16 03 02 13
    05 10 11 08
    09 06 07 12
    04 15 14 01
    */

    /*Lettura dei valori*/
    for (i=0; i<MAX; i++)
    {
        for (j=0; j<MAX; j++)
        {
            printf("Inserire valore tra 1 e 99 in posizione (%d,%d): ",i,j);
            verifica = scanf("%d",&matrice[i][j]);
            if (verifica!=1){
                printf("\nError: wrong input value! Program closing.\n");
                exit(1);
            }
        }
    }

    /*Stampa dei valori*/
    system("cls");
    for (i=0; i<MAX; i++)
    {
        for (j=0; j<MAX; j++)
        {
             printf("| %-2d ", matrice[i][j]);
        }
        printf("| \n");
    }

    matriceMagica = 1;

    /*Calcolo somma prima riga*/
    sommaPrimaRiga = 0;
    for (j=0; j<MAX; j++)
    {
        sommaPrimaRiga += matrice[0][j];
    }

    /*controllo a livello di riga*/
    for (i=0; i<MAX && matriceMagica; i++)
    {
        somma = 0;
        for (j = 0; j < MAX; j++)
        {
            somma += matrice[i][j];
        }
        if (somma != sommaPrimaRiga)
        {
            matriceMagica = 0;
        }
    }

    /*controllo a livello di colonna*/
    for (j=0; j<MAX && matriceMagica; j++)
    {
        somma = 0;
        for (i=0; i<MAX; i++)
        {
            somma += matrice[i][j];
        }
        if (somma!=sommaPrimaRiga)
        {
            matriceMagica = 0;
        }
    }

    /*controllo diagonale principale*/
    if (matriceMagica)
    {
        somma = 0;
        for (i=0; i<MAX; i++)
        {
            somma += matrice[i][i];
        }
        if (somma!=sommaPrimaRiga)
        {
            matriceMagica = 0;
        }
    }

    /*controllo diagonale secondaria*/
    if (matriceMagica)
    {
        somma = 0;

        for (i=0, j=MAX-1; i<MAX; i++, j--)
        {
            somma += matrice[i][j];
        }

        if (somma!=sommaPrimaRiga)
        {
            matriceMagica = 0;
        }
    }

    if (matriceMagica)
    {
        printf("\nLa matrice e\' magica!\n\n");
    }
    else
    {
        printf("\nLa matrice NON e\' magica!\n\n");
    }

    printf("\n\n\n");
    system("PAUSE");
    return 0;
}
