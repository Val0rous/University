/* Chiedere all'utente di inserire dieci parole, ciascuna di lunghezza massima 20 caratteri. Memorizzare le parole in una matrice.
Verifica se tra le parole inserite dall'utente ci sono parole ripetute */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERO_PAROLE 10
#define LUNGHEZZA_PAROLA 21

int main()
{
    int i, iold, j, numParoleRipetute;
    char elencoParole[NUMERO_PAROLE][LUNGHEZZA_PAROLA];
    int idParoleRipetute[NUMERO_PAROLE]; /*invece di memorizzare da un'altra parte le parole si tiene traccia degli indici*/

    /*Memorizzazione delle parole*/
    for (i=0; i<NUMERO_PAROLE; i++)
    {
        idParoleRipetute[i] = 0; /*inizializzazione a 0 del vettore*/
        fflush(stdin); /*viene liberato il buffer di lettura*/
        printf("Inserire parola %2d/%d (max %d lettere): ", i+1, NUMERO_PAROLE, LUNGHEZZA_PAROLA-1);
        scanf("%s",&elencoParole[i]);
    }

    /*Cercare parole ripetute*/
    numParoleRipetute = 0;
    iold = -1;
    for (i=0; i<(NUMERO_PAROLE-1); i++)
    {
        if (idParoleRipetute[i]==0)
        {
            for (j=i+1; j<NUMERO_PAROLE; j++)
            {
                if ((strcmp(elencoParole[j],elencoParole[i]) == 0) )
                {
                    if (i!=iold)
                    {
                        numParoleRipetute = numParoleRipetute+1;
                        iold = i;
                    }
                    idParoleRipetute[i] = numParoleRipetute;
                    idParoleRipetute[j] = numParoleRipetute;
                }
            }
        }
    }

    /*Mostrare parole ripetute*/
    if (numParoleRipetute > 0)
    {
        printf("\nLe parole ripetute sono %d, precisamente:\n", numParoleRipetute);
        for (i=1; i<=numParoleRipetute; i++)
        {
            for (j=0; j<NUMERO_PAROLE; j++)
            {
                if (idParoleRipetute[j]==i)
                {
                    printf("%s\n",elencoParole[j]);
                    break;
                }
            }
        }
    }
    else
    {
        printf("Non ci sono parole ripetute\n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
