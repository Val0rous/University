#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
	int elenco[MAX];
	int i, temp, trovato;
	int primo, posPrimo, secondo, posSencondo, verifica;

	printf("INSERIMENTO VALORI\n");
	for (i = 0; i < MAX; i++)
	{
		printf("inserire valore %d: ",i);
		verifica = scanf("%d",&elenco[i]);
		fflush(stdin);
        if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }
	}

	printf("\n\n primo valore da spostare: ");
	verifica = scanf("%d",&primo);
	fflush(stdin);
    if (verifica!=1){
        printf("\nError: wrong input value! Program closing.\n");
        exit(1);
    }
	trovato = 0;
	for (i = 0; i < MAX; i++)
	{
		if (elenco[i] == primo)
		{
		    trovato = 1;
		    posPrimo = i;
            break;
        }
	}

   	if (trovato)
   	{
		printf("\n\n secondo valore da spostare: ");
		verifica = scanf("%d",&secondo);
		fflush(stdin);
        if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }
		if (primo == secondo)
			printf(" Il secondo valore e\' uguale al primo!");
		else
		{
        	trovato = 0;
			for (i = 0; i < MAX; i++)
			{
				if (elenco[i] == secondo)
				{
				    trovato = 1;
				    posSencondo = i;
            		break;
	        	}
			}

			temp = elenco[posPrimo];
			elenco[posPrimo] = elenco[posSencondo];
			elenco[posSencondo] = temp;

			printf("\n\n Stampa del vettore :");
			for (i = 0; i < MAX; i++)
				printf("\n elenco[%d] = %d",i,elenco[i]);
		}
	}
	else
		printf(" valore inserito non trovato!");

	printf("\n\n");
    system("PAUSE");
    return 0;
}


