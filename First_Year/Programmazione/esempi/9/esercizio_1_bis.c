#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	int elenco[MAX];
	int i, temp, numValori, verifica;

	printf("quanti valori vuoi inserire? ");
	verifica = scanf("%d",&numValori);
	fflush(stdin);
    if (verifica!=1){
        printf("\nError: wrong input value! Program closing.\n");
        exit(1);
    }

	if (numValori < MAX)
	{
		for (i = 0; i < numValori; i++)
		{
			printf("inserire valore %d: ",i);
			verifica = scanf("%d",&elenco[i]);
			fflush(stdin);
            if (verifica!=1){
                printf("\nError: wrong input value! Program closing.\n");
                exit(1);
            }
		}

		/*inversione valore*/
		for (i = 0; i < (numValori/2); i++)
		{
			temp = elenco[i];
			elenco[i] = elenco[numValori-1-i];
			elenco[numValori-1-i] = temp;
		}

		printf("\n\nStampa del vettore invertito:");
		for (i = 0; i < numValori; i++)
			printf("\n elenco[%d] = %d",i,elenco[i]);
	}
	else
		printf("Valore troppo grande!");

	printf("\n\n");
    system("PAUSE");
    return 0;
}


