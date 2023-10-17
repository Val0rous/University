#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main()
{
	int elenco1[MAX], elenco2[MAX];
	int i, uguale, verifica;

	printf("INSERIMENTO VALORI PRIMO VETTORE\n");
	for (i = 0; i < MAX; i++)
	{
		printf("inserire valore %d: ",i);
		verifica = scanf("%d",&elenco1[i]);
		if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }

	}

	printf("\n\nINSERIMENTO VALORI SECONDO VETTORE\n");
	for (i = 0; i < MAX; i++)
	{
		printf("inserire valore %d: ",i);
		verifica = scanf("%d",&elenco2[i]);
		if (verifica!=1){
            printf("\nError: wrong input value! Program closing.\n");
            exit(1);
        }

	}

	uguale = 1;
	for (i = 0; i < MAX; i++)
	{
		if (elenco1[i] != elenco2[i])
		{
		    uguale = 0;
            break;
        }
	}
	if (uguale)
		printf("\n\nI due vettori sono ugiali");
	else
		printf("\n\nI due vettori sono diversi");

	printf("\n\n");
    system("PAUSE");
    return 0;
}


