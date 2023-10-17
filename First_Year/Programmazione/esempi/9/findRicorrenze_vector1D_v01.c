#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAXVALUE 5
#define NUMNUMBERS 10

int main()
{

    int vetNumeri[NUMNUMBERS], vetRicorrenze[MAXVALUE+1];
    int i, j, counter;

    /*Per generare numero random float:*/
    //float vetNumeriFloat[NUMNUMBERS];
    //srand((unsigned int)time(NULL));
    //for (i=0; i<NUMNUMBERS; i++)
    //{
    //    //numeroInteroGenerato = valmin + (rand()+time(NULL))%(valmax+1-valmin); // Genera numeri tra valmin e valmax con etremi compresi
    //    vetNumeriFloat[i] = ((float)(rand())/(float)(RAND_MAX)) * (valmax-valmin)+valmin; //per avere un numero float tra [valmin, valmax] con etremi compresi
    //}


    /* Inizializzazione vettore numeri */
    for (i=0; i<NUMNUMBERS; i++)
    {
        //vetNumeri[i] = valmin + (rand()+time(NULL))%(valmax+1-valmin); // Genera numeri tra valmin e valmax con etremi compresi
        vetNumeri[i] = ((rand()+time(NULL)) % (MAXVALUE+1)); //per avere un numero int tra [0, MAXVALUE] con etremi compresi
        //vetNumeri[i] = ((rand()+time(NULL)) % (MAXVALUE)) +1; //per avere un numero int tra [1, MAXVALUE] con etremi compresi
    }

    /* show vector */
    printf("\nVettore: \"vetNumeri\": ");
    for(i=0; i<NUMNUMBERS; i++)
    {
        printf("%d ", vetNumeri[i]);
    }
    printf("\n");

    /* Inizializzazione vettore ricorrenze */
    for (i=0; i<MAXVALUE+1; i++)
    {
        vetRicorrenze[i] = 0;
    }

    /* Analisi elementi vettore numeri */
    //primo ciclo dal I° al penultimo elemento
    for (i=0; i<NUMNUMBERS; i++)
    {

        counter = 1; // contatore delle ricorrenze
        if (vetRicorrenze[vetNumeri[i]]!=0)
        {
            continue;
        }
        else
        {
            // II° ciclo dalla posizione i+1 all'ultimo elemento
            for (j=i+1; j<NUMNUMBERS; j++)
            {
                //se il valore dell'i-esimo elemento è uguale al valore
                //di uno degli elementi successivi counter si incrementa
                if (vetNumeri[i]==vetNumeri[j])
                {
                    counter++;
                }

            }//fine for ciclo j

            vetRicorrenze[vetNumeri[i]]=counter;
        }
    }//fine for ciclo i

    for(i=0; i<NUMNUMBERS; i++)
    {
        printf("Numero: %d\t", vetNumeri[i]);
        printf("Ricorrenze: %d\n", vetRicorrenze[vetNumeri[i]]);
    }

	printf("\n\n");
    system("PAUSE");
    return 1;
}
