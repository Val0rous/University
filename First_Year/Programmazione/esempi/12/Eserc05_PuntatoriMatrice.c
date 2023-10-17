#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMRIGHE   10
#define NUMCOLONNE 15
#define SALTOMAX 5

#define valmin 1
#define valmax 5

int main()
{
    /* Dichiarazione variabili */
    int matrice2D[NUMRIGHE][NUMCOLONNE];
    int i, j, valore, somma, counter, incrementoRighe, incrementoColonne;

    /* Inizializzazione matrice */
    srand((unsigned int)time(NULL));
    printf("\n");
    for (i=0; i<NUMRIGHE; i++)
    {
        for (j=0; j<NUMCOLONNE; j++)
        {
            valore = valmin + (rand()+time(NULL))%(valmax+1-valmin); // Genera numeri tra valmin e valmax con estremi compresi
            printf("| %d ", valore);
            matrice2D[i][j] = valore;
        }
        printf("\n");
    }

    /* Visualizzazione matrice */
    printf("\n");
    for (i=0; i<NUMRIGHE; i++)
    {
        for (j=0; j<NUMCOLONNE; j++)
        {
            printf("| %d ", *(*(matrice2D+i)+j) );
        }
        printf("\n");
    }

    /* Movimento dentro alla matrice */
    printf("\n");
    i = 0;
    j = 0;
    somma = 0;
    counter = 0;
    incrementoRighe = 0;
    incrementoColonne = 0;
    while(i<NUMRIGHE && j<NUMCOLONNE)
    {
        valore = *(*(matrice2D+i)+j);
        somma += valore;
        counter++;
        if (valore%2==0)
        {
            incrementoRighe = valore;
            incrementoColonne = 0;
        }
        else
        {
            incrementoRighe = 0;
            incrementoColonne = valore;
        }

        printf("Step: %d,\t matrice[%d][%d] = %d,\t somma = %d\n", counter, i+1, j+1, valore, somma);
        i += incrementoRighe;
        j += incrementoColonne;
    }

    printf("\n");
	system("pause");
	return 0;
}
